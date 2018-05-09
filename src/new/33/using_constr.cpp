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

#include<iostream>

/* #33 Changes to Specification on Inheriting Constructors */

struct BASE1 {
	BASE1(double x) { };
};
struct BASE2 {
	BASE2(double x) { };
};

struct DERIVED : BASE1, BASE2 {
	using BASE1::BASE1;
	using BASE2::BASE2;
	/*
		Per ordinary overloading rules, 
		DERIVED(double) overloads BASE1(double)
		and BASE2(double). IN C++17 this call is not
		ambiguous. using CLASS:CONSTRUCTOR is different
		because instead of declaring a new set of constructors
		the base class constructors are now visible, to make
		overloading possible.
	*/
	DERIVED (double);
};

int main () {
	//DERIVED:DOUBLE() CALLED
	DERIVED D(1.2);
	/*
		Because DERIVED:DOUBLE is not defined, linking fails, in our example. 
		
		GCC:
		/tmp/ccHKCmX1.o: In function `main':
		using_constr.cpp:(.text+0x20): undefined reference to `DERIVED::DERIVED(double)'
		collect2: error: ld returned 1 exit status


		CLANG:
		/tmp/using_constr-6d7816.o: In function `main':
		using_constr.cpp:(.text+0x15): undefined reference to `DERIVED::DERIVED(double)'
		clang-6.0: error: linker command failed with exit code 1 (use -v to see invocation)

	*/
}

// clang++ using_constr.cpp -std=c++17 -o using_constr
// g++ using_constr.cpp -std=c++17 -o using_constr
// ./using_constr