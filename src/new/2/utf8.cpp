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

/* #2 UTF 8 Character Literals */

#include<iostream>

int main() {
	/*You may need to the locale to UTF-8.
	Alternatively --> setLocale(LC_ALL, ""): */

	//Usage #1 -- Basic Escape Sequence
	std::wcout << u8'\n' << "#1) The preceeding new line was "
			<< "created with a UTF-8 Character Literal.";
	//Usage #2 -- Basic Source Character Set
	std::wcout << "\n#2) A character from the 96 Characters of The "
				<< "Basic Source Character Set: \"" << u8'%' << '\"'
				<< "." << std::endl;
	//Usage #3 -- Usage of Universal Character Name

	/*
		Universal Character Names
		Basic Latin or C0 Controls Unicode block
		U+0800 -> U+007F, 128 Codepoints
	*/
	char LEFTP = u8'\u0028';
	char RIGHTP = u8'\u0029';
	char BASE = u8'\u0038';
	char POWER = u8'\u005E';
	char EXP = u8'\u0039';
	char EQ = u8'\u003D';
	char AS = u8'\u002A';
	char TWO = u8'\u0032';
	char LT = u8'\u003C';
	char RES1 = u8'\u0038';
	char RES2 = u8'\u0032';
	char SPACE = u8'\u0020';
	char QUES = u8'\u003F';

	std::wcout << "#3) Universal Character Names: " << "\t\"Is " << LEFTP << BASE << POWER << EXP << RIGHTP
				<<SPACE << LT << SPACE << RES1 << RES2 << SPACE << QUES << '\"' << "\tNO." << std::endl;

	//Bonus: Unicode Emoji's
	std::wcout << "\nCurious about Emoji's too?\nCheck out a few:  " << u8'\n' << u8'\n';

	//Same Emojis
	wchar_t NERD_FACE = L'\U0001F913';
	wchar_t MONEY_MOUTH_FACE = L'\U0001F911';
	wchar_t SIGN_OF_THE_HORNS = L'\U0001F918';
	wchar_t UNICORN_FACE = L'\U0001F984';
	wchar_t MUSIC_GCLEF = L'\U0001D11E';
	wchar_t BANANA = L'\U0001F34C';

	//Let's print them.
	std::wcout<< "Unicode 6.0--\t\t\"BANANA\"\t\t\t(U+1D11E): \t\t" <<
				BANANA << std::endl;
	std::wcout<< "Unicode 8.0--\t\t\"NERD FACE\"\t\t\t(U+1F913): \t\t" <<
				NERD_FACE << std::endl;
	std::wcout<< "Unicode 8.0--\t\t\"UNICORN FACE\"\t\t\t(U+1F984): \t\t" <<
				UNICORN_FACE << '\n';
	std::wcout<< "Unicode 8.0--\t\t\"UNICORN FACE\"\t\t\t(U+1F911): \t\t" <<
				MONEY_MOUTH_FACE << '\n';
	std::wcout<< "Unicode 8.0--\t\t\"SIGN OF THE HORNS\"\t\t(U+1F918): \t\t" <<
				SIGN_OF_THE_HORNS << '\n';
	std::wcout<< "Unicode 3.1--\t\t\"MUSICAL SYMBOL G CLEF\"\t\t(U+1D11E): \t\t" <<
				MUSIC_GCLEF << '\n' << std::endl;
}

// clang++ utf8.cpp -std=c++17 -o utf8
// g++ utf8.cpp -std=c++17 -o utf8
// ./utf8