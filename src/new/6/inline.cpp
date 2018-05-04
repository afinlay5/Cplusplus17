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

/* #6 Inline variables */

#include<iostream>

//In the interest of brevity, let's pile this all in here
struct StructI { int val; };
inline StructI inline_struct = StructI{55};

class ClassI {
	public:
		//Member
		int val;
		static constexpr int inl = 9; //Implicitly inline

		//Constructor 
		ClassI(int val) { this->val = val; }
};
inline ClassI inline_class (99);

int main() {
	std::cout << "\nThe Class:\t\t\t" << inline_class.val;
	std::cout << "\nThe Struct:\t\t\t" << inline_struct.val;
	std::cout << "\nThe Static Class Member:\t" << ClassI::inl << '\n' << std::endl;
}

// clang++ inline.cpp -std=c++17 -o inline
// g++ inline.cpp -std=c++17 -o inline
// ./inline