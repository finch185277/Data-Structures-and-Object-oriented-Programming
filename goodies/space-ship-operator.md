# spaceship operator <=> (formally Three-way comparison)

What is spaceship operator?

This operator trys to solve the this problem:

If I can define `operator <`

    class apple1 {
        bool operator < (apple1 const & rhs) { return size() < rhs.size(); }
    };

I know when I have `A < B`,

`A > B`, `A != B`, `A >= B` ... could be automatic avalable.

but the current language standard (standards before C++20) doesn't

have direct support of this kind of behavour(though some library did

implement it, such as boost)

# <=> Solution

You can define a spaceship operator like this

    class apple2 {
        auto operator <=> (apple2 const & rhs) { return size() < rhs.size(); }
    };

Where the return value should be
- `< 0` if `A < B`
- `== 0` of `A == B`
- `> 0` if `A > B`

Or another convenient way:

    class apple3 {
        bool operator < (apple3 const & rhs) { return size() < rhs.size(); }
        auto operator<=>(apple3 const &) = default;
    };

Let compiler generate for you.


So what if I write `Apple a, b; if (a > b) { ... }`, what will the compiler generate the code ?

The compiler will make like:
- if the type apple3 have operator have `operator >` => use it
- else if the type apple3 have operator have `operator <=>` => use it, than compare it to 0
- else giveup

Some useful link.
- [cppref](https://en.cppreference.com/w/cpp/language/operator_comparison)
- [stackoverflow](https://stackoverflow.com/questions/47466358/what-is-the-operator-in-c)