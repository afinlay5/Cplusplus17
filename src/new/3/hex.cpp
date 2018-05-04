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

/* #3 Hexadecimal Floating Point Literals */

#include<iostream>

int main() {
	std::cout << "\nC++17 introduced Hexadecimal Floating Point Literals "
			<<"in three different formats.\n\n" 
			<<"\"0x|0x hex-digit-seq\":\t\t\t\t" << "0x1ffp96:\t\t" << 0x1ffp96 << '\n'
			<<"\"0x|0x hex-digit-seq . \":\t\t\t" << "0xa.p-2:\t\t" << 0xa.p-2 << '\n'
			<<"\"0x|0X hex-digit-seq . hex-digit-seq\":\t\t" << "0x1.743p-3:\t\t" << 0x1.743p-3 << '\n'
		<< '\n' << std::endl;
}
// clang++ hex.cpp -std=c++17 -o hex
// g++ hex.cpp -std=c++17 -o hex
// ./hex