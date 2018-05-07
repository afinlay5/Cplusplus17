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

#include<string>
#include<locale>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

//LPCTSR
typedef const char * LPCTSTR;

//Is Windows
bool isWindows = false;

//Function Protoype
void runWin32Process (LPCTSTR APP);
void handleSelection (char, int);
void runNix (string);

//if Windows
#if defined(_WIN32) || defined (_WIN64) 
	isWindows = true;
	void runWin32Process (LPCTSTR APP) {
		
		#include<windows.h>

		//Run Windows Executables
		void runWin32Process (LPCTSTR APP) {
		//Startup Info, Process Info
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		//Set Structure Size
		ZeroMemory( &si, sizeof(si) );
		si.cb = sizeof(si);
		ZeroMemory( &pi, sizeof(pi) );

		// Create the process
		CreateProcess( APP,   // the path
		NULL,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
		);

	    // Close process and thread handles. 
	    CloseHandle( pi.hProcess );
	    CloseHandle( pi.hThread );
	}
#else
	void runWin32Process (LPCTSTR APP) { }
#endif

//main ()
int main (int argc, char* argv[], char* envp[]) {

	string type, selection_entry;
	int selection;

	cout << "\nNew Language Features & Language Changes in C++17 (http://bit.ly/Cplusplus17Ft) ~ Adrian D." << endl;
	cout << "Enter 'exit' at anytime to terminate the application." << endl;
	
	/* Prompt #1 */
	cout << "\nWould you like to view deprecated or new language features?(D/N): ";
	cin >> type;
	//exit?
	transform(type.begin(), type.end(), type.begin(), ::tolower);
	if (type.compare("exit") ==0) return 0;

	while (type.compare("d") !=0 & type.compare("n") !=0) {
		cout << "The entry you have provided is invalid.\n" << endl;;
		cout << "\nWould you like to view deprecated or new language features?(D/N): ";
		cin >> type;
		transform(type.begin(), type.end(), type.begin(), ::tolower);
		if (type.compare("exit") ==0) return 0;
	}
	
	/* Prompt #2 */
	cout << "Please enter the number representing the language feature: ";
	cin >> selection_entry;
		
	//exit?
	if (selection_entry.compare("exit") ==0) { return 0;}
	transform(selection_entry.begin(), selection_entry.end(), selection_entry.begin(), ::tolower);

	//Single Digit
	SINGLE: 
	while (! isdigit(selection_entry[0])) {
		cout << "\nThe entry you have provided is invalid.\n" << endl;
		cout << "Please enter the number representing the language feature: ";
		cin >> selection_entry;
		cout << "]" << endl;
		transform(selection_entry.begin(), selection_entry.end(), selection_entry.begin(), ::tolower);
		if (selection_entry.compare("exit") ==0) return 0;
		else if (selection_entry.length() == 2) goto DOUBLE;
	}

	//Double digit
	DOUBLE:
	while (selection_entry.length()>1 && ! isdigit(selection_entry[1])) {
		cout << "\nThe entry you have provided is invalid.\n" << endl;
		cout << "Please enter the number representing the language feature: ";
		cin >> selection_entry;
		if (selection_entry.compare("exit") ==0) return 0;
		else if (selection_entry.length() == 1) goto SINGLE;
	}


	//No negative selections or 0
	while (stoi (selection_entry) <= 0) {
		if (selection_entry.compare("exit") ==0) return 0;
		else if(! isdigit(selection_entry[0])) goto SINGLE;
		else if(selection_entry.length() == 1 && ! isdigit(selection_entry[1]) ) goto DOUBLE;
		else {
			cout << "The entry you have provided is invalid.\n" << endl;;
			cout << "\nPlease enter the number representing the language feature: ";
			cin >> selection_entry;
			cout << "]" << endl;
			selection = stoi(selection_entry);
		}
	}

	//Deprecated
	if (type.compare("d")) {
		//Invalid Selection
		while (selection > 4) {
			goto SINGLE;
		}
		selection = stoi(selection_entry);
	}
	//New
	else { 
		//Invalid Selection
		while (selection > 33) {
			goto SINGLE;
		}
		selection = stoi(selection_entry);
	}

	//Handle Selection
	handleSelection(type[0], selection);
}

//Function Definitions
void handleSelection (char type, int selection) {
	//Old Language Features
	if (type == 'D' || type == 'd' ){
		switch (selection) {
			case 1:
				cout << "/* #1 Removal of Trigraphs */" << endl;
				cout << "Please see the source file located at ~/CPlusPlus17/src/old/1/trigraphs.cpp." << endl;
				cout << "Compile against -std=c++14 to build." << endl;
				break;
			case 2:
				cout << "/* #2 Removal of deprecated Increment Operator(++) for bool type */" << endl;
				cout << "Please see the source file located at ~/CPlusPlus17/src/old/2/bool++_dep.cpp." << endl;
				cout << "Compile against -std=c++14 to build." << endl;
				break;
			case 3:
				cout << "/* #3 Removal of deprecated register keyword */" << endl;
				cout << "Please see the source file located at ~/CPlusPlus17/src/old/3/register.cpp." << endl;
				cout << "Compile against -std=c++14 to build." << endl;				
				break;
			case 4:
				cout << "/* #4 Removal of deprecated Dynamic Exception Specifications */" << endl;
				cout << "Please see the source file located at ~/CPlusPlus17/src/old/4/dynam_except.cpp." << endl;
				cout << "Compile against -std=c++14 to build." << endl;
				break;
		}
		return;
	}
	//New Language Features
	else {
		switch(selection){
			case 1:
				cout << "/* #1 Addition of __has_include macro */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/1/hasinclude.cpp." << endl;
				if (isWindows)
					runWin32Process("hasinclude");
				else
					runNix("hasinclude");
				break;
			case 2:
				cout << "/* #2 UTF 8 Character Literals */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/2/utf8.cpp." << endl;
				if (isWindows)
					runWin32Process("utf8");
				else
					runNix("utf8");
				break;
			case 3:
				cout << "/* #3 Hexadecimal Floating Point Literals */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/3/hex.cpp." << endl;
				if (isWindows)
					runWin32Process("hex");
				else
					runNix("hex");
				break;
			case 4:
				cout << "/* #4 New rules for deduction of single member list using auto */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/4/auto_deduc.cpp." << endl;
				if (isWindows)
					runWin32Process("auto_deduc");
				else
					runNix("auto_deduc");
				break;
			case 5:
				cout << "/* #5 Update to __cplusplus value */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/5/cppvc.cpp." << endl;
				if (isWindows)
					runWin32Process("cppvc");
				else
					runNix("cppvc");
				break;
			case 6:
				cout << "/* #6 Inline variables */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/6/inline.cpp." << endl;
				if (isWindows)
					runWin32Process("inline");
				else
					runNix("inline");
				break;
			case 7:
				cout << "/* #7 New Syntax for Nested Namespace definitions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/7/namespace.cpp." << endl;
				if (isWindows)
					runWin32Process("namespace");
				else
					runNix("namespace");
				break;
			case 8:
				cout << "/* #8  Initializers added to if/switch statements */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/8/init_if_sw.cpp." << endl;
				if (isWindows)
					runWin32Process("init_if_sw");
				else
					runNix("init_if_sw");
				break;
			case 9:
				cout << "/* #9 constexpr if */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/9/constexpr_if.cpp." << endl;
				if (isWindows)
					runWin32Process("constexpr_if");
				else
					runNix("constexpr_if");
				break;
			case 10:
				cout << "/* #10 New standard attributes [[fallthrough]], [[maybe_unused]] & [[nodiscard]] */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/10/attributes.cpp." << endl;
				if (isWindows)
					runWin32Process("attributes");
				else
					runNix("attributes");
				break;
			case 11:
				cout << "/* #11 Attributes for Enumerator & Namespaces */"<< endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/11/attributes2.cpp." << endl;
				if (isWindows)
					runWin32Process("attributes2");
				else
					runNix("attributes2");
				break;
			case 12:
				cout << "/* #12 Error message for static_assert now optional */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/12/static_assert.cpp." << endl;
				if (isWindows)
					runWin32Process("static_assert");
				else
					runNix("static_assert");
				break;
			case 13:
				cout << "/* #13 Structured binding declarations */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/13/tuple_pack.cpp." << endl;
				if (isWindows)
					runWin32Process("tuple_pack");
				else
					runNix("tuple_pack");
				break;
			case 14:
				cout << "/* #14 Keyword typename now allowed in lieu of class in a template’s template paramater */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/14/templ_param.cpp." << endl;
				if (isWindows)
					runWin32Process("templ_param");
				else
					runNix("templ_param");
				break;
			case 15:
				cout << "/* #15 Constant evaluation for non-type template arguments */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/15/const_nontype.cpp." << endl;
				if (isWindows)
					runWin32Process("const_nontype");
				else
					runNix("const_nontype");
				break;
			case 16:
				cout << "/* #16 Class template argument deduction */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/16/temp_arg_deduc.cpp." << endl;
				if (isWindows)
					runWin32Process("temp_arg_deduc");
				else
					runNix("temp_arg_deduc");
				break;
			case 17:
				cout << "/* #17 Extensions on over-aligned Memory Allocation */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/17/over_align.cpp." << endl;
				if (isWindows)
					runWin32Process("over_align");
				else
					runNix("over_align");
				break;
			case 18:
				cout << "/* #18 Fold Expressions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/18/fold_expr.cpp." << endl;
				if (isWindows)
					runWin32Process("fold_expr");
				else
					runNix("fold_expr");
				break;
			case 19:
				cout << "/* #19 List-style Initialization of Enumerations */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/19/enum_list.cpp." << endl;
				if (isWindows)
					runWin32Process("enum_list");
				else
					runNix("enum_list");
				break;
			case 20:
				cout << "/* #20 Specifying non-type template parameters with auto */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/20/auto_temp.cpp." << endl;
				if (isWindows)
					runWin32Process("auto_temp");
				else
					runNix("auto_temp");
				break;
			case 21:
				cout << "/* #21  constexpr lambda expressions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/21/constexpr_lambda.cpp." << endl;
				if (isWindows)
					runWin32Process("constexpr_lambda");
				else
					runNix("constexpr_lambda");
				break;
			case 22:
				cout << "/* #22 Lambda this by value (*this) */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/22/lambda_this.cpp." << endl;
				if (isWindows)
					runWin32Process("lambda_this");
				else
					runNix("lambda_this");
				break;
			case 23:
				cout << "/* #23 Extending Aggregate Initialization to Base Types */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/23/aggregate.cpp." << endl;
				if (isWindows)
					runWin32Process("aggregate");
				else
					runNix("aggregate");
				break;
			case 24:
				cout << "/* #24 Unknown Attributes Required to be Ignored */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/24/unknw_attr.cpp." << endl;
				if (isWindows)
					runWin32Process("unknw_attr");
				else
					runNix("unknw_attr");
				break;
			case 25:
				cout << "/* #25 Pack Expansions legal in using declarations */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/25/using_pack.cpp." << endl;
				if (isWindows)
					runWin32Process("using_pack");
				else
					runNix("using_pack");
				break;
			case 26:
				cout << "/* #26 Generalization of Range-based for loop */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/26/range_for.cpp." << endl;
				if (isWindows)
					runWin32Process("range_for");
				else
					runNix("range_for");
				break;
			case 27:
				cout << "/* #27 The byte data type */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/27/byte.cpp." << endl;
				if (isWindows)
					runWin32Process("byte");
				else
					runNix("byte");
				break;
			case 28:
				cout << "/* #28 Using attribute namespaces without repetition */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/28/using_attr.cpp." << endl;
				if (isWindows)
					runWin32Process("using_attr");
				else
					runNix("using_attr");
				break;
			case 29:
				cout << "/* #29 Stricter Order of Evaluation Rules */" << endl;
				cout << "Please see the text file located at ~/CPlusPlus17/src/new/29/eval_order.txt." << endl;
				if (isWindows)
					runWin32Process("eval_order.txt");
				else
					runNix("eval_order.txt");
				break;
			case 30:
				cout << "/* #30 Exception Specifications are part of type definitions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/30/throw_type.cpp." << endl;
				if (isWindows)
					runWin32Process("throw_type");
				else
					runNix("throw_type");
				break;
			case 31:
				cout << "/* #31 Template-Template Parameters match compatible arguments */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/31/templ_match.cpp." << endl;
				if (isWindows)
					runWin32Process("templ_match");
				else
					runNix("templ_match");
				break;
			case 32:
				cout << "/* #31 Guaranteed Copy Elision */" << endl;
				cout << "Please see the text file located at~/CPlusPlus17/src/new/32/templ_match.txt" << endl;
				if (isWindows)
					runWin32Process("templ_match.txt");
				else
					runNix("templ_match.txt");
				break;
			case 33:
				cout << "/* #33 Changes to Specification on Inheriting Constructors */" << endl;
				cout << "Please see the text file located at~/CPlusPlus17/src/new/33/using_constr.cpp" << endl;
				if (isWindows)
					runWin32Process("using_constr");
				else
					runNix("using_constr");
				break;
		}
		return;
	}
}

//Run *Nix Executable
void runNix (string app) {
	string exc = "./" + app;
	system(exc.c_str());
}