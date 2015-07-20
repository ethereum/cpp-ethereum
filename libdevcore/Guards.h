/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file Guards.h
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 */

#pragma once

#include <mutex>
#include <memory>
#include <atomic>
#include <boost/thread.hpp>

namespace dev
{

using Mutex = std::mutex;
using RecursiveMutex = std::recursive_mutex;
using SharedMutex = boost::shared_mutex;

using Guard = std::lock_guard<std::mutex>;
using RecursiveGuard = std::lock_guard<std::recursive_mutex>;
using ReadGuard = boost::shared_lock<boost::shared_mutex>;
using UpgradableGuard = boost::upgrade_lock<boost::shared_mutex>;
using UpgradeGuard = boost::upgrade_to_unique_lock<boost::shared_mutex>;
using WriteGuard = boost::unique_lock<boost::shared_mutex>;

template <class GuardType, class MutexType>
struct GenericGuardBool: GuardType
{
	GenericGuardBool(MutexType& _m): GuardType(_m) {}
	bool b = true;
};
template <class MutexType>
struct GenericUnguardBool
{
	GenericUnguardBool(MutexType& _m): m(_m) { m.unlock(); }
	~GenericUnguardBool() { m.lock(); }
	bool b = true;
	MutexType& m;
};
template <class MutexType>
struct GenericUnguardSharedBool
{
	GenericUnguardSharedBool(MutexType& _m): m(_m) { m.unlock_shared(); }
	~GenericUnguardSharedBool() { m.lock_shared(); }
	bool b = true;
	MutexType& m;
};

/** @brief Simple lock that waits for release without making context switch */
class SpinLock
{
public:
	SpinLock() { m_lock.clear(); }
	void lock() { while (m_lock.test_and_set(std::memory_order_acquire)) {} }
	void unlock() { m_lock.clear(std::memory_order_release); }
private:
	std::atomic_flag m_lock;
};
using SpinGuard = std::lock_guard<SpinLock>;

/** @brief Simple block guard.
 * The expression/block following is guarded though the given mutex.
 * Usage:
 * @code
 * Mutex m;
 * unsigned d;
 * ...
 * ETH_(m) d = 1;
 * ...
 * ETH_(m) { for (auto d = 10; d > 0; --d) foo(d); d = 0; }
 * @endcode
 *
 * There are several variants of this basic mechanism for different Mutex types and Guards.
 *
 * There is also the UNGUARD variant which allows an unguarded expression/block to exist within a
 * guarded expression. eg:
 *
 * @code
 * Mutex m;
 * int d;
 * ...
 * ETH_GUARDED(m)
 * {
 *   for (auto d = 50; d > 25; --d)
 *     foo(d);
 *   ETH_UNGUARDED(m)
 *     bar();
 *   for (; d > 0; --d)
 *     foo(d);
 * }
 * @endcode
 */

#define DEV_GUARDED(MUTEX) \
	for (GenericGuardBool<Guard, Mutex> __eth_l(MUTEX); __eth_l.b; __eth_l.b = false)
#define DEV_READ_GUARDED(MUTEX) \
	for (GenericGuardBool<ReadGuard, SharedMutex> __eth_l(MUTEX); __eth_l.b; __eth_l.b = false)
#define DEV_WRITE_GUARDED(MUTEX) \
	for (GenericGuardBool<WriteGuard, SharedMutex> __eth_l(MUTEX); __eth_l.b; __eth_l.b = false)
#define DEV_RECURSIVE_GUARDED(MUTEX) \
	for (GenericGuardBool<RecursiveGuard, RecursiveMutex> __eth_l(MUTEX); __eth_l.b; __eth_l.b = false)
#define DEV_UNGUARDED(MUTEX) \
	for (GenericUnguardBool<Mutex> __eth_l(MUTEX); __eth_l.b; __eth_l.b = false)
#define DEV_READ_UNGUARDED(MUTEX) \
	for (GenericUnguardSharedBool<SharedMutex> __eth_l(MUTEX); __eth_l.b; __eth_l.b = false)
#define DEV_WRITE_UNGUARDED(MUTEX) \
	for (GenericUnguardBool<SharedMutex> __eth_l(MUTEX); __eth_l.b; __eth_l.b = false)

template <class Class, class GuardType, class MutexType>
class GuardContainer
{
public:
	GuardContainer(Class& _object, MutexType& _mutex): m_guard(new GuardType(_mutex)), m_object(&_object) {}
	GuardContainer(GuardContainer&&) = default;
	GuardContainer& operator=(GuardContainer&&) = default;

	Class* operator->() { return m_object; }
	Class& operator*() { return *m_object; }

private:
	//@todo make the guard movable without pointer
	std::unique_ptr<GuardType> m_guard;
	Class* m_object;
};

/**
 * Helper class to prevent unlocked access to an object.
 */
template <class Class, class MutexType = Mutex>
class LockedObject: boost::noncopyable
{
	using Container = GuardContainer<Class, Guard, MutexType>;
public:
	LockedObject() {}
	LockedObject(Class&& _object): m_object(std::move(_object)) {}
	/// Use *lockedObject to access a guard which releases the lock on destruction and allows
	/// to access the object via ->.
	Container operator*() { return guard<Guard>(); }
	/// Use -> to access the object for a single, locked access.
	Container operator->() { return guard<Guard>(); }

	GuardContainer<Class, ReadGuard, MutexType> read() { return guard<ReadGuard>(); }
	GuardContainer<Class, WriteGuard, MutexType> write() { return guard<WriteGuard>(); }

	template <class GuardType>
	GuardContainer<Class, GuardType, MutexType> guard() { return GuardContainer<Class, GuardType, MutexType>(m_object, m_mutex); }

	Class& unsafeAccess() { return m_object; }

private:
	Class m_object;
	MutexType m_mutex;
};

}
