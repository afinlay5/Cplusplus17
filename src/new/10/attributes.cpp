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

/* #10 New standard attributes [[fallthrough]], [[maybe_unused]] & [[nodiscard]] */
#include <iostream>

// [[maybe_unused]]
class [[maybe_unused]] Unused {
	public:
		Unused () {
			std::cout << "Unused object" << std::endl;
		}
};
// [[nodiscard]]
enum [[nodiscard]] Sports { BASKETBALL, FOOTBALL, SOCCER, BADNITON };

//Function Prototype
Sports nodiscard_eg ();

// [[nodiscard]]
Sports nodiscard_eg () { return BASKETBALL; }

//main
int main() {
	std::cout << std::endl;
	// [[maybe_unused]]
	Unused ob2; //Stack
	Unused *ob1 = new Unused(); //Heap

	// [[nodiscard]]
	nodiscard_eg();

	//[[fallthrough]]
	switch (1) {
		case 1:
			std::cout << "This fall through is intentional.\n" << std::endl;
			[[fallthrough]];
		case 2:
			break;
	}
}

// clang++ attributes.cpp -std=c++17 -o attributes
// g++ attributes.cpp -std=c++17 -o attributes
// ./attributes