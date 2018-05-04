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

/* #22 Lambda this by value (*this) */
#include<iostream>
#include<string>

class Obj {
	private:
		std::string name = "Adrian";
	public:
		//Lambda by Reference, Pre-c++17
		auto byRef () {
			return [this] { return name; };
		}

		//Lambda by value, C++17
		auto byVal () {
			return [*this] { return name; };
		}

		//Set name
		void setName(std::string name) {
			std::cout<<"Let's change the value.\n";
			this->name = name;
		}
};

int main() {
	Obj ob;

	auto val = ob.byRef();
	std::cout << '\n' << "The name, by value: " << val() << ".\n";
	//Let's change name.
	ob.setName("Sydni");

	auto ref = ob.byVal();
	std::cout << "The name, by reference: " << ref() << ".\n";

	std::cout << std::endl;
}

// clang++ lambda_this.cpp -std=c++17 -o lambda_this
// g++ lambda_this.cpp -std=c++17 -o lambda_this
// ./lambda_this