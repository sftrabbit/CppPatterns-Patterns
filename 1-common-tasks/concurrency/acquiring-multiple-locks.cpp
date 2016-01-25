// Acquire multiple locks
// C++11

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

struct account
{
	double balance = 0.0;
	std::mutex mutex;
};

void transfer(account& fr_acct, account& to_acct, double amount)
{
	std::lock(fr_acct.mutex, to_acct.mutex);
	std::lock_guard<std::mutex> fr_acct_lock{fr_acct.mutex, std::adopt_lock};
	std::lock_guard<std::mutex> to_acct_lock{to_acct.mutex, std::adopt_lock};
	
	fr_acct.balance -= amount;
	to_acct.balance += amount;
}

constexpr int num_payments = 3;

void do_transfers(account& f, account& t,
		std::array<double, num_payments> payments)
{
	std::for_each(std::begin(payments), std::end(payments),
		[&f, &t](double a) { transfer(f, t, a); });
}

int main()
{
	account acct_1;
	account acct_2;
	
	acct_1.balance = 1000.0;
	acct_2.balance = 1000.0;
	
	std::array<double, num_payments> payments_1 = { 923.54, -453.19, 501.01 };
	std::array<double, num_payments> payments_2 = { 268.44, 840.19, -733.15 };
	
	std::thread t1{do_transfers, std::ref(acct_1), std::ref(acct_2), payments_1};
	std::thread t2{do_transfers, std::ref(acct_2), std::ref(acct_1), payments_2};
	
	t1.join();
	t2.join();
	
	std::cout << "Account 1 balance = " << acct_1.balance << '\n';
	std::cout << "Account 2 balance = " << acct_2.balance << '\n';
}

// Acquire multiple locks safely.
// 
// We should always be wary of locks in code. While they are usually
// a necessary evil, they are often cause performance bottlenecks
// and - worse - can lead to deadlocks if we are not very careful.
// 
// On [17-25] we have a function that transfers funds between two
// accounts. If this is a large system with millions of accounts and
// thousands of transactions happening every second, we wouldn't want
// to use a global lock - we couldn't afford to lock up the entire
// bank for every single transaction. Instead, we handle
// synchronization on a per-account basis; each account has its own
// mutex, and we only lock the ones we are working with at the moment.
// Other transactions involving other accounts can continue
// concurrently.
// 
// Suppose we tried to lock the mutexes in the two accounts involved
// in the transaction individually - first we lock `fr_acct`, then
// `to_acct`. Notice that on [47-48], we have two threads each doing
// transfers with those two accounts, but `t1` is doing transactions
// *from* account 1 *to* account 2, while `t2` is doing them *to*
// account 1 *from* account 2. That means that the `transfer()`
// function in `t1` locks account 1 first, then account 2; while `t2`
// locks account 2 first, then account 1. Imagine that `t1` is
// running, and it locks account 1, then gets halted by the operating
// system. While `t1` is waiting to be restarted, `t2` now comes
// along, locks account 2, then tries to lock account 1. `t2`
// discovers that some other thread (`t1`) already has a lock on it,
// so it blocks and waits for that other thread to release its lock on
// account 1. But *then* `t1` is allowed to run again, and it
// continues what it was doing, and tries to lock account 2. Now `t1`
// discovers that account 2 is already locked by another thread
// (`t2`). So it blocks and waits for it. See what's happened? `t1`
// owns the lock on account 1, and is waiting for account 2... `t2`
// owns the lock on account 2, and is waiting for account 1. Deadlock.
// 
// [`std::lock()`](cpp/thread/lock) prevents this from happening. It
// can take any number of lockable objects (like mutexes), and safely
// acquire locks on all of them. If we always use `std::lock()` to
// lock multiple mutexes, we will never have to worry about order of
// acquisition deadlocks.
// 
// First we acquire all the locks with `std::lock()` on [19]. When
// `std::lock()` returns, we own *all* the locks. Then we create
// [`std::lock_guard`](cpp/thread/lock_guard) objects for each lock
// ([20-21]) - we want to do this because `std::lock_guard`s are safe,
// RAII lock owner objects that will do the right thing even if an
// exception is thrown. The trick is to have the `std::lock_guard`s
// take over ownership of the locks *without unlocking them*; to do
// that we use the [`std::adopt_lock`](cpp/thread/lock_tag) tag.
// 
// Once all that is done, we can safely do our updates to both
// accounts ([23-24]). The locks get released automatically when the
// function exits.
