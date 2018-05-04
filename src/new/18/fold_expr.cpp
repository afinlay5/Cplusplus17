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

/* #18 Fold Expressions */
#include<iostream>

/* Function Prototypes */

//Unary Right Fold ( pack op ... )
template<typename ...varargs> void UR_MULT (varargs... x);
//Unary Left Fold ( ... op pack )
template<typename ...varargs> void UL_DIVIDE (varargs... x);
//Binary Right Fold ( pack op ... op init )
template<typename ...varargs> void BR_XOR (varargs... x);
//Binary Right Fold ( op init ... pack op )
template<typename ...varargs> void BL_X (varargs... x);

//Function Definitions
template<typename ...varargs>
void UR_MULT (varargs... x) {
	std::cout << "\nUNARY RIGHT FOLD:\tUL_MULT():\t" << (... * x) << '.';
}
template<typename ...varargs>
void UL_DIVIDE (varargs... x) {
	std::cout << "\nUNARY LEFT FOLD:\tUL_DIVIDE():\t" << (... / x) << '.';
}
template<typename ...varargs>
void BR_XOR (varargs... x) {
	std::cout << "\nBINARY RIGHT FOLD:\tBR_ADD():\t" 
		<< (x ^ ... ^ 12) << '.';
}
template <typename ...varargs>
void BR_SOR (varargs... x) {
	std::cout<< "\nBINARY LEFT FOLD:\tBR_ADD():\t";
	bool result = (false || ... ||  x);
	if (result == 1)
		std::cout<< "true" << '.';
	else
		std::cout<< "false" << '.';
}

//main()
int main() {
	std::cout<<std::endl;

	//UNARY RIGHT FOLD
	UR_MULT(9,3,4,5);

	//UNARY LEFT FOLD
	UL_DIVIDE(90,2,9,1); //Note that this would have failed it had it been a right fold.

	//BINARY RIGHT FOLD
	BR_XOR(12,3,5);

	//BINARY LEFT FOLD
	BR_SOR(); //Empty pack is false by default so (false || true) = true

	std::cout << '\n' << std::endl;
	return 0;
}

// clang++ fold_expr.cpp -std=c++17 -o fold_expr
// g++ fold_expr.cpp -std=c++17 -o fold_expr
// ./fold_expr