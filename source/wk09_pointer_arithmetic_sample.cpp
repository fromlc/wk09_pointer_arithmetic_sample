//------------------------------------------------------------------------------
// wk09_pointer_arithmetic_sample.cpp
// 
// This program demonstrates 
//		1) a pointer variable referencing a class instance, and
//		2) pointer arithmetic
// 
// Author: Prof. Linda C
//------------------------------------------------------------------------------
#include "TextDraw.h"

#include <iostream>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int NUM_LINES   = 10;
constexpr int NUM_SPACES  = 0;
constexpr char DRAW_SPACE = ' ';
constexpr char DRAW_CHAR  = 'x';
constexpr char CRLF       = '\n';

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void checkpoint94();		// exercise in Gaddis 9E on pp. 518-519

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {

	cout << "\nLet's draw some text art..\n\n";

	// if user typed a command line argument, use it for drawing
	char char2draw = argc > 1 ? *(argv[1]) : DRAW_CHAR;

	//--------------------------------------------------------------------------
	// allocate a block of memory (an array) for some screen positions
	//--------------------------------------------------------------------------
	TextDraw* pDrawLines = new TextDraw[NUM_LINES];
	
	// save the original pointer, use a different pointer to traverse the array
	TextDraw* p = pDrawLines;

	//--------------------------------------------------------------------------
	// traverse the array to set the spaces and text to draw on each line
	//		++i adds 1 to i
	//		++p adds the size of a TextDraw instance to p
	//--------------------------------------------------------------------------

	for (int i = 0; i < NUM_LINES; ++i, ++p) {
		p->spaces = i + NUM_SPACES;
		p->numchars = i;
	}

	// display an 'x' at each screen position in the array

	// again, use a different pointer to traverse the array
	p = pDrawLines;

	// pointer p will increase by the size of a TextDraw instance
	for (int i = 0; i < NUM_LINES; ++i, ++p) {

		string indent(p->spaces, DRAW_SPACE);
		string text(p->numchars, char2draw);

		cout << "Line " << i << ':' << indent << text << CRLF;
	}

	// release dynamically allocated array memory
	delete[] pDrawLines;

	// do Checkpoint Exercise 9.4
	checkpoint94();

	// console app window will stay until user types any key
	cin.get();

	return 0;
}

//------------------------------------------------------------------------------
// Gaddis 9E Checkpoint Exercise 9.4 on pp.518-519
//------------------------------------------------------------------------------
void checkpoint94() {

	cout << "\nGaddis 9E Checkpoint Exercise 9.4 on pp. 518-519\n\n";

	int x = 50, y = 60, z = 70;
	int* ptr = nullptr;

	cout << x << ' ' << y << ' ' << z << '\n';

	ptr = &x;
	*ptr *= 10;

	ptr = &y;
	*ptr *= 5;

	ptr = &z;
	*ptr *= 2;

	cout << x << ' ' << y << ' ' << z << '\n';
}