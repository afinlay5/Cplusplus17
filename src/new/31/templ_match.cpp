/*
Copyright (C) 2018 Adrian D. Finlay. All rights reserved.

Licensed under the MIT License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    https://opensource.org/licenses/MIT

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER INCLUDING AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
==============================================================================
**/

/* #31 Template-Template Parameters match compatible arguments */

template <class T1> class A { };
template <class T2, class Y = T2> class B { };
template <class... T3> class C { };

template< template<class> class Z> class D { };
//template<class> class Z {} is the parameter.
//template <class T1> class A matches it perfectly, for example.

/*
	Takes a bit of eye stretching, follow it closely.
	Now that the parameter is separated (above), it should
	be easier to see how they match.
*/

int main () {
	D <A> eg;	//This is the way you are likely accustomed to.
	D <B> eg2; 	//B is at LEAST as compatible with D's parameters.
	D <C> eg3; 	//Same thing with C, that accepts several as as a variadic arg
	return 0;
}

// clang++ templ_match.cpp -std=c++17 -o templ_match
// g++ templ_match.cpp -std=c++17 -o templ_match
// ./templ_match