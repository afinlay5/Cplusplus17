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

using std::cout;
using std::endl;
using std::string;

//LPCTSR
typedef const char * LPCTSTR;

//Is Windows
bool isWindows = false;

//Function Protoypes
void runWin32Process (LPCTSTR APP);
void handleSelection (char, int);
void runNix (string);
bool displayFtTypePrompt();
bool displayFtNumPrompt(string);

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
	void runWin32Process (LPCTSTR APP) {
	}
#endif

//main ()
int main (int argc, char* argv[], char* envp[]) {

	//ENV
	string ENV, OS, ARCH;

	//Windows
	if (isWindows) {
		OS = getenv("OS");
		ARCH = getenv("PROCESSOR_ARCHITECTURE");
		ENV = OS + ARCH;
	}
	//Linux
	else if (string(getenv("OSTYPE")).compare("linux") == 0) {
		ENV = getenv("MACHTYPE");
	}
	//Mac
	else if (string(getenv("TERM_PROGRAM")).compare("Apple_Terminal") == 0) {
		ENV = "macOS/Mac OSX, x86-64/x64";
	}
	//BSD
	else if (string(getenv("OSTYPE")).compare("bsd") == 0) {
		ENV = getenv("MACHTYPE");
	}
	//Unknown
	else
		ENV = "Unknown";

	//Prompt
	cout << "\nNew Language Features & Language Changes in C++17 (http://bit.ly/Cplusplus17Ft) ~ Adrian D." << endl;
	cout << "Enter 'exit' at anytime to terminate the application." << endl;
	cout << "Env. " << ENV << endl;
	
	//Display Prompts
	while (true) {
		if (displayFtTypePrompt())
			break;
	}

	return 0;
}

/*Function Protoype*/
bool displayFtTypePrompt() {
	//Variables
	string FtType;

	//Prompt #2
	cout << "\nWould you like to view deprecated or new language features?(D/N): ";
	std::getline (std::cin, FtType);

	//Check if user entered a number.
	if (std::atoi(FtType.c_str()) != 0)
		return false;

	//First convert to lowercase
	transform(FtType.begin(), FtType.end(), FtType.begin(), ::tolower);

	//First Check for exit
	if (FtType.compare("exit")==0 )
		return true;
	//New language features
	else if (FtType.compare("n") == 0) {
		return displayFtNumPrompt("n");
	}
	//Old language features
	else if (FtType.compare("d") == 0) {
		return displayFtNumPrompt("d");
	}
	//Invalid input
	else 
		cout << "\nInvalid input." << endl;
		return false;
}
bool displayFtNumPrompt(string FtType) {
	//Variables
	string FtNum;
	int ftNum;

	/* Prompt #2 */
	cout << "Please enter the number representing the language feature: ";
	std::getline(std::cin, FtNum);

	//Convert to int
	ftNum = std::atoi (FtNum.c_str());

	//First Check for exit
	if (FtNum.compare("exit")==0)
		return true;
	//Invalid Entry
	else if (ftNum == 0 && FtNum.compare("exit") !=0)  {
		cout << "\nInvalid input." << endl;
		return false;
	}
	//New Language Feature
	else if (FtType.compare("n") ==0 && ftNum>0 && ftNum<34) {
		handleSelection ('n', ftNum);
		return false;
	}
	//Old Language Feature
	else if (FtType.compare("d") ==0 && ftNum>0 && ftNum<5) {
		handleSelection ('d', ftNum);
		return false;
	}
	else
		cout << "\nInvalid input." << endl;
		return false;
}
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
	}
	//New Language Features
	else {
		switch(selection){
			case 1:
				cout << "/* #1 Addition of __has_include macro */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/1/hasinclude.cpp." << endl;
				if (isWindows)
					runWin32Process("new/1/hasinclude");
				else
					runNix("new/1/hasinclude");
				break;
			case 2:
				cout << "/* #2 UTF 8 Character Literals */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/2/utf8.cpp." << endl;
				if (isWindows)
					runWin32Process("new/2/utf8");
				else
					runNix("new/2/utf8");
				break;
			case 3:
				cout << "/* #3 Hexadecimal Floating Point Literals */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/3/hex.cpp." << endl;
				if (isWindows)
					runWin32Process("new/3/hex");
				else
					runNix("new/3/hex");
				break;
			case 4:
				cout << "/* #4 New rules for deduction of single member list using auto */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/4/auto_deduc.cpp." << endl;
				if (isWindows)
					runWin32Process("new/4/auto_deduc");
				else
					runNix("new/4/auto_deduc");
				break;
			case 5:
				cout << "/* #5 Update to __cplusplus value */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/5/cppvc.cpp." << endl;
				if (isWindows)
					runWin32Process("new/5/cppvc");
				else
					runNix("new/5/cppvc");
				break;
			case 6:
				cout << "/* #6 Inline variables */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/6/inline.cpp." << endl;
				if (isWindows)
					runWin32Process("new/6/inline");
				else
					runNix("new/6/inline");
				break;
			case 7:
				cout << "/* #7 New Syntax for Nested Namespace definitions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/7/namespace.cpp." << endl;
				if (isWindows)
					runWin32Process("new/7/namespace");
				else
					runNix("new/7/namespace");
				break;
			case 8:
				cout << "/* #8  Initializers added to if/switch statements */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/8/init_if_sw.cpp." << endl;
				if (isWindows)
					runWin32Process("new/8/init_if_sw");
				else
					runNix("new/8/init_if_sw");
				break;
			case 9:
				cout << "/* #9 constexpr if */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/9/constexpr_if.cpp." << endl;
				if (isWindows)
					runWin32Process("new/9/constexpr_if");
				else
					runNix("new/9/constexpr_if");
				break;
			case 10:
				cout << "/* #10 New standard attributes [[fallthrough]], [[maybe_unused]] & [[nodiscard]] */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/10/attributes.cpp." << endl;
				if (isWindows)
					runWin32Process("new/10/attributes");
				else
					runNix("new/10/attributes");
				break;
			case 11:
				cout << "/* #11 Attributes for Enumerator & Namespaces */"<< endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/11/attributes2.cpp." << endl;
				if (isWindows)
					runWin32Process("new/11/attributes2");
				else
					runNix("new/11/attributes2");
				break;
			case 12:
				cout << "/* #12 Error message for static_assert now optional */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/12/static_assert.cpp." << endl;
				if (isWindows)
					runWin32Process("new/12/static_assert");
				else
					runNix("new/12/static_assert");
				break;
			case 13:
				cout << "/* #13 Structured binding declarations */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/13/tuple_pack.cpp." << endl;
				if (isWindows)
					runWin32Process("new/13/tuple_pack");
				else
					runNix("new/134/tuple_pack");
				break;
			case 14:
				cout << "/* #14 Keyword typename now allowed in lieu of class in a template’s template paramater */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/14/templ_param.cpp." << endl;
				if (isWindows)
					runWin32Process("new/14/templ_param");
				else
					runNix("new/14/templ_param");
				break;
			case 15:
				cout << "/* #15 Constant evaluation for non-type template arguments */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/15/const_nontype.cpp." << endl;
				if (isWindows)
					runWin32Process("new/15/const_nontype");
				else
					runNix("new/15/const_nontype");
				break;
			case 16:
				cout << "/* #16 Class template argument deduction */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/16/temp_arg_deduc.cpp." << endl;
				if (isWindows)
					runWin32Process("new/16/temp_arg_deduc");
				else
					runNix("new/16/temp_arg_deduc");
				break;
			case 17:
				cout << "/* #17 Extensions on over-aligned Memory Allocation */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/17/over_align.cpp." << endl;
				if (isWindows)
					runWin32Process("new/17/over_align");
				else
					runNix("new/17/over_align");
				break;
			case 18:
				cout << "/* #18 Fold Expressions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/18/fold_expr.cpp." << endl;
				if (isWindows)
					runWin32Process("new/18/fold_expr");
				else
					runNix("new/18/fold_expr");
				break;
			case 19:
				cout << "/* #19 List-style Initialization of Enumerations */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/19/enum_list.cpp." << endl;
				if (isWindows)
					runWin32Process("new/19/enum_list");
				else
					runNix("new/19/enum_list");
				break;
			case 20:
				cout << "/* #20 Specifying non-type template parameters with auto */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/20/auto_temp.cpp." << endl;
				if (isWindows)
					runWin32Process("new/20/auto_temp");
				else
					runNix("new/20/auto_temp");
				break;
			case 21:
				cout << "/* #21  constexpr lambda expressions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/21/constexpr_lambda.cpp." << endl;
				if (isWindows)
					runWin32Process("new/21/constexpr_lambda");
				else
					runNix("new/21/constexpr_lambda");
				break;
			case 22:
				cout << "/* #22 Lambda this by value (*this) */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/22/lambda_this.cpp." << endl;
				if (isWindows)
					runWin32Process("new/22/lambda_this");
				else
					runNix("new/22/lambda_this");
				break;
			case 23:
				cout << "/* #23 Extending Aggregate Initialization to Base Types */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/23/aggregate.cpp." << endl;
				if (isWindows)
					runWin32Process("new/23/aggregate");
				else
					runNix("new/23/aggregate");
				break;
			case 24:
				cout << "/* #24 Unknown Attributes Required to be Ignored */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/24/unknw_attr.cpp." << endl;
				if (isWindows)
					runWin32Process("new/24/unknw_attr");
				else
					runNix("new/24/unknw_attr");
				break;
			case 25:
				cout << "/* #25 Pack Expansions legal in using declarations */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/25/using_pack.cpp." << endl;
				if (isWindows)
					runWin32Process("new/25/using_pack");
				else
					runNix("new/25/using_pack");
				break;
			case 26:
				cout << "/* #26 Generalization of Range-based for loop */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/26/range_for.cpp." << endl;
				if (isWindows)
					runWin32Process("new/26/range_for");
				else
					runNix("new/26/range_for");
				break;
			case 27:
				cout << "/* #27 The byte data type */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/27/byte.cpp." << endl;
				if (isWindows)
					runWin32Process("new/27/byte");
				else
					runNix("new/27/byte");
				break;
			case 28:
				cout << "/* #28 Using attribute namespaces without repetition */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/28/using_attr.cpp." << endl;
				if (isWindows)
					runWin32Process("new/28/using_attr");
				else
					runNix("new/28/using_attr");
				break;
			case 29:
				cout << "/* #29 Stricter Order of Evaluation Rules */" << endl;
				cout << "Please see the text file located at ~/CPlusPlus17/src/new/29/eval_order.txt." << endl;
				if (isWindows)
					runWin32Process("new/29/eval_order.txt");
				else
					runNix("new/29/eval_order.txt");
				break;
			case 30:
				cout << "/* #30 Exception Specifications are part of type definitions */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/30/throw_type.cpp." << endl;
				if (isWindows)
					runWin32Process("new/30/throw_type");
				else
					runNix("new/30/throw_type");
				break;
			case 31:
				cout << "/* #31 Template-Template Parameters match compatible arguments */" << endl;
				cout << "The source file is located at ~/CPlusPlus17/src/new/31/templ_match.cpp." << endl;
				if (isWindows)
					runWin32Process("new/31/templ_match");
				else
					runNix("new/31/templ_match");
				break;
			case 32:
				cout << "/* #31 Guaranteed Copy Elision */" << endl;
				cout << "Please see the text file located at~/CPlusPlus17/src/new/32/templ_match.txt" << endl;
				if (isWindows)
					runWin32Process("new/32/templ_match.txt");
				else
					runNix("new/32/templ_match.txt");
				break;
			case 33:
				cout << "/* #33 Changes to Specification on Inheriting Constructors */" << endl;
				cout << "Please see the text file located at~/CPlusPlus17/src/new/33/using_constr.cpp" << endl;
				if (isWindows)
					runWin32Process("new/33/using_constr");
				else
					runNix("new/33/using_constr");
				break;
		}
	}
}
void runNix (string app) {
	string exc = "./" + app;
	system(exc.c_str());
}