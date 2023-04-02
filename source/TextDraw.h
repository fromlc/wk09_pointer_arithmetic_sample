//------------------------------------------------------------------------------
// TextDraw.h : class declaration and definition
//------------------------------------------------------------------------------

#pragma once
//------------------------------------------------------------------------------
// TextDraw
//------------------------------------------------------------------------------
class TextDraw {
public:
    int spaces;
    int numchars;

    // constructors
    TextDraw() : spaces(0), numchars(0) { }

    TextDraw(int _spaces, int _numchars) {
        this->spaces = _spaces;
        this->numchars = _numchars;
    }
};

