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

/* #9 constexpr if */
#include <iostream>
#include <string>
#include <ctime>

int main(int argc, char* argv[]) {
	/*	An example of an if condition that can be 
		evaluated at compile-time. This will succeed
		with constexpr if as well as a regular if. */
	std::string ANS;
	if constexpr (9-9>2) ANS = "Compile-Time Evaluation with \'if constexpr\'.";
	else ANS = "Compile-Time Evaluation with \'if constexpr\'.";
	std::cout << '\n' << ANS << std::endl;

	/*	Two example of runtime evaluated conditions.
		These will fail with constexpr if but will
		succeed with regular if. */

	//The time is only known at runtime
	std::time_t time = std::time(NULL);
	//if constexpr (std::time (NULL) == time) {
	if (std::time (NULL) == time ) {
		std::cout << "Runtime-Evaluated:\t" <<
		std::asctime(std::localtime(&time));
	}
	//Args are only known at runtime
	//if constexpr (argc == 4) {
	if (argc == 4) {
		std::cout << "Your CMD/Terminal Args (4) are: \""
		<< argv[0] << "\", \"" << argv[1] << "\", \"" << argv[2]
		<< "\", and \"" << argv[3] << "\".\n" << std::endl;
	}
	std::cout << std::endl;
}

// clang++ constexpr_if.cpp -std=c++17 -o constexpr_if
// g++ constexpr_if.cpp -std=c++17 -o constexpr_if
// ./constexpr_if