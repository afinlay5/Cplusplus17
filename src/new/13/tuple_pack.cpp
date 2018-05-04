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

/* #13 Structured binding declarations */
#include <iostream>
#include <tuple>

int main() {
	//A tuple with four elements
	std::tuple <const char *, const char *,
		const char *, int> _tuple = std::make_tuple ("Dog", "Cat", "Hyena", 99);

	//C++17
	auto [a,b,c,d] = _tuple;
	std::cout << std::endl;
	std::cout << "Contents of the tuple:\t" << a << ", " << b << ", " << c
				<< ", " << d << "." << std::endl;
	std::cout << std::endl;
}

// clang++ tuple_pack.cpp -std=c++17 -o tuple_pack
// g++ tuple_pack.cpp -std=c++17 -o tuple_pack
// ./tuple_pack