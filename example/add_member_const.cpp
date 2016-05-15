/*<-
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
->*/

#include <callable_traits/config.hpp>
#ifdef CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS
int main(){ return 0; }
#else

//[ add_member_const
#include <type_traits>
#include <callable_traits/add_member_const.hpp>

namespace ct = callable_traits;

struct foo {};

int main() {

    {
        using pmf = int(foo::*)();
        using expect = int(foo::*)() const;
        using test = ct::add_member_const<pmf>;
        static_assert(std::is_same<test, expect>::value, "");
    } {
        // add_member_const doesn't change anything when
        // the function type is already const.
        using pmf = int(foo::*)() const &&;
        using expect = int(foo::*)() const &&;
        using test = ct::add_member_const<pmf>;
        static_assert(std::is_same<test, expect>::value, "");
    } {
        using pmf = int(foo::*)() volatile &;
        using expect = int(foo::*)() const volatile &;
        using test = ct::add_member_const<pmf>;
        static_assert(std::is_same<test, expect>::value, "");
    } {
        // add_member_const can also be used with "abominable"
        // function types.
        using f = int();
        using expect = int() const;
        using test = ct::add_member_const<f>;
        static_assert(std::is_same<test, expect>::value, "");
    }

    // A substitution failure will occur if add_member_const is used
    // with function pointers, function references, function objects,
    // or member data pointers.
}
//]
#endif //#ifdef CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS
