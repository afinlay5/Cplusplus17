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

/* #4 New rules for deduction of single member list using auto */

#include<iostream>
#include<cstring>
#include<typeinfo>

int main() {
	auto _int {9};
	auto _str {"Marc-Elie"};
	auto _dbl {23.5};
	//It's a shame std::initializer_list<> is not subscriptable :/
	auto _listinit = { "List", "Init"};
	std::string _int_type,_str_type,_dbl_type,_listinit_type;

	/* This solution is not portable across compilers--
		The result of std::type_info.name() is mangled
		on gcc and clang but IBM, Oracle, and MSVC
		provide human readable names. */

	if ( std::strcmp((typeid(_int).name()), "i") == 0 ) { _int_type = "int"; }
	else { _int_type = "unknown/non-gcc/clang compiler"; }

	if ( std::strcmp((typeid(_dbl).name()), "d") == 0 ) { _dbl_type = "double"; }
	else { _dbl_type = "unknown/non-gcc/clang compiler"; }

	if ( std::strcmp((typeid(_str).name()), "PKc") == 0 ) { _str_type = "std::string"; }
	else { _str_type = "unknown/non-gcc/clang compiler"; }

	if ( std::strcmp((typeid(_listinit).name()), "St16initializer_listIPKcE") == 0 ) 
		 { _listinit_type = "std::initializer_list<char const*>"; }
	else { _listinit_type = "unknown/non-gcc/clang compiler"; }

	//Print the values and their types
	std::cout << "\n"
		<<"\"_int\": " << _int << " is an " << _int_type << ".\n"
		<<"\"_dbl\": " << _int << " is an " << _dbl_type << ".\n"
		<<"\"_str\": " << _int << " is an " << _str_type << ".\n"
		<<"\"_listinit\": " << "{\"List\", \"Init\"}"<< " is an " << _listinit_type << ".\n"
		<<std::endl;
}

// clang++ auto_deduc.cpp -std=c++17 -o auto_deduc
// g++ auto_deduc.cpp -std=c++17 -o auto_deduc
// ./auto_deduc