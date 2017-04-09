// Passkey
// C++11

class foo {
        class Key {
            friend class baz;
            Key() {}
        };
    public:
        explicit foo(Key);

        void qux(Key) {
            bar();
        }

    private:
        void bar();
};

class baz {
    public:
        void quaz() {
            foo f({});

            f.qux({});
        }
};

// Allow granular access to a class' constructors and its methods by
// requiring friendship of a passkey.
//
// Friendship in C++ is all-or-nothing; classes cannot befriend only
// some parts of another class. The [Passkey
// idiom](https://arne-mertz.de/2016/10/passkey-idiom/) works around
// that by "tagging" exposed methods with a `Key` parameter. If a
// caller class such as `baz` wants to call `foo`'s constructor or
// methods, it must be a friend of `Key`.
//
// The `Key` class defined on [5-8] does not need to be private or
// even defined within `foo`. To disallow `Key` from being created via
// [aggregate initialization](cpp/aggregate_initialization), we must
// explicitly define its default constructor. 
//
// The `qux` function ([12-14]) is an example of a method that can
// only be called by `baz`. However, `foo`'s private methods (such as
// `bar()` on [17]) and variables stay private. This demonstrates how
// the Passkey idiom preserves encapsulation.
//
// [23-25] show how the caller would construct `foo` and call its
// member function `qux`. We simply pass a temporary object of type
// `Key` as a parameter using C++11's brace syntax.
