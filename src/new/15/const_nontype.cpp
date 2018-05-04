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

/* #15 Constant evaluation for non-type template arguments */
#include<iostream>

static int k =0;

//An Example of a Template Class
//with a pointer to a member as a template argument
template<int *i> class EG {
	public:
		void talk() {
			if (k>0) {
				std::cout << "Hello, again. #" << k << std::endl;
			}
			else std::cout << "\nHello." << std::endl;
			k++;
		}	
};

//EG #1, #3
int i =9;

//EG #2
constexpr int *x () { return &i; }


int main() {
	EG<&i> eg;
	eg.talk();

	EG<x()> eg2; 
	eg2.talk();

	EG<&i> eg3;
	eg3.talk();

	std::cout<<std::endl;
}

// clang++ const_nontype.cpp -std=c++17 -o const_nontype
// g++ const_nontype.cpp -std=c++17 -o const_nontype
// ./const_nontype