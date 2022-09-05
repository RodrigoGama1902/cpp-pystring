#ifndef _PYSTRING_H_
#define _PYSTRING_H_

#include <iostream>
#include <vector>

class PyString
{
    friend std::ostream &operator<<(std::ostream &os, const PyString &rhs);
    friend std::istream &operator>>(std::istream &is, PyString &rhs);

private:
    char *str;

public:
    //--------------------------------------------//
    // BASE
    //--------------------------------------------//

    PyString(const char *s);                 // Constructor
    PyString(const PyString &source_string); // Copy Constructor
    PyString(PyString &&source_string);      // Move Constructor
    ~PyString();                             // Destructor

    PyString &operator=(const PyString &rhs); // Copy Assignment
    PyString &operator=(PyString &&rhs);      // Move Assignment

    //--------------------------------------------//
    // UNARY OPERATORS
    //--------------------------------------------//

    bool operator!(); // "-" Unary operator that returns true if the string is empty

    //--------------------------------------------//
    // BINARY OPERATORS
    //--------------------------------------------//

    bool operator==(const PyString &rhs);
    PyString operator+(const PyString &rhs); // "+" binary operator the join two MyStrings

    //--------------------------------------------//
    // PUBLIC METHODS
    //--------------------------------------------//

    size_t length() const;                                               // Return the length of the string
    PyString &strip();                                                   // Returns a trimmed version of the string
    PyString &title();                                                   // Converts the first character of each word to upper case
    PyString &replace(const char *find, const char *replace);            // Returns a string where a specified value is replaced with a specified value
    PyString &insert(size_t index, const char *string);                  // Insert a string in the given index
    PyString &remove(size_t index, size_t until_index);                  // Removes a slice of the string from the first index until the next
    PyString slice(int index_start, int index_end);                      // Returns a string slice between two indexes
    int find(const char *find_string, size_t start = 0, size_t end = 0); // Searches the string for a specified value and returns the position of where it was found
    int count(const char *find_string);                                  // Returns the number of times a specified value occurs in a string
    std::vector<PyString> split(const char *separator);                  // Splits the string at the specified separator, and returns a vector
    PyString lower();                                                    // Converts a string into lower case
    PyString upper();                                                    // Converts a string into upper case

    // Not implemented yet

    PyString &capitalize();                            // Converts the first character to upper case
    PyString &center(int total_chars, char fill_char); // Returns a centered string
    bool endswith();                                   // Returns true if the string ends with the specified value
    bool isdigit();                                    // Returns True if all characters in the string are digits
    PyString zfill(int fill_count);                    // Fills the string with a specified number of 0 values at the beginning
};

#endif
