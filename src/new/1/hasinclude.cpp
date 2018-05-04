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

/* #1 Addition of __has_include macro */

#include <iostream>

#if defined (__has_include) // Does your compiler have __has_include?
	//Do you have the any class in your libraru?
	#if __has_include (<any>) && __cplusplus > 201402L
	//GCC, LLVM/Clang included support for "__has_include before C++17."
	//Consequently, this is not a reliable sign that the 
	//prescence of __has_include means that your compiler is C++18
	//compliant. As a result, we must validate that before attempting use of C++17 API.
		#include <any>
		#define ANSWER "\nWE HAVE THE HEADER / SAFE TO USE HEADER.\n\n"
	#else
		#define ANSWER "\nWE DO NOTHAVE THE HEADER / NOT SAFE TO USE HEADER.\n\n"
	#endif
#else //Compiler does not have __has_include
	#define ANSWER "\nThe\"__has_include\" macro is not included in your compiler\n\n"
#endif

int main () { std::cout << ANSWER; }

// clang++ hasinclude.cpp -std=c++17 -o hasinclude
// g++ hasinclude.cpp -std=c++17 -o hasinclude
// ./hasinclude