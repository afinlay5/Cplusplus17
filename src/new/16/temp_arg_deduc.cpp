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

/* #16 Class template argument deduction */
#include<iostream>
#include<tuple>

template<typename Tn> class sample {
	public:
		sample (Tn x, Tn y, Tn z)	 {
			std::cout << "\tx:{" <<x << "}\t"
				<< "y:{" << y << "}\t" << "z:{"
				<< z << "}\t" << std::endl;
		}
};


int main() {
	std::cout << std::endl;

	//Declaration that specifies initialization
	//of a variable and variable template
	std::tuple _tuple('c', "monk", 9L, 1.2222);
	std::cout << '\t' << std::get<0>(_tuple) << '\t'
		<< std::get<1>(_tuple) << '\t' << std::get<2>(_tuple)
		<< '\t' << std::get<3>(_tuple) << '\t' << std::endl;

	//Dynamic allocator Expression
	auto _sample = new sample("Adrian", "D", "Finlay");
	auto _sample2 = new sample (99999, 322, 21000);
	//This won't compile. Types must be the same.
	// auto_sample = new sample(99, "Monk", 32);

	std::cout <<std::endl;
	return 0;
}

// clang++ temp_arg_deduc.cpp -std=c++17 -o temp_arg_deduc
// g++ temp_arg_deduc.cpp -std=c++17 -o temp_arg_deduc
// ./temp_arg_deduc