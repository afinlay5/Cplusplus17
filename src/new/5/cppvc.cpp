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

/* #5 Update to __cplusplus value */

#include<iostream>

int main() {
	
	std::cout << "\n";

	switch (__cplusplus) {
		//C++17
		case 201500L:
		case 201703L: {
			std::cout << "The C++ vs. is:\t" << "C++17 Standard Compliant.\n";
			break;
		}
		//C++14
		case 201402L:
		case 201406L: {
			std::cout << "The C++ vs. is:\t" << "C++14 Standard Compliant.\n";
			break;
		}
		//C++11
		case 201103L: {
			std::cout << "The C++ vs. is:\t" << "C++11 Standard Compliant.\n";
			break;
		}
		//C++98
		case 199711L: { //Notice that this went unchanced for C++03
			std::cout << "The C++ vs. is:\t" << "C++98 Standard Compliant.\n";
			break;
		}
		//Some other version 
		default: {
			std::cout << "The C++ vs. is:\t" << "C++? Some other version.\n";
			break;
		}
	}

	std::cout << "The \"__cplusplus\" code is:  "<< __cplusplus << ".\n\n";
}

// clang++ cppvc.cpp -std=c++17 -o cppvc
// g++ cppvc.cpp -std=c++17 -o cppvc
// ./cppvc