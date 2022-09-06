#include <cstring>
#include "pystring.h"
#include <iostream>
#include <vector>

//--------------------------------------------//
// BASE
//--------------------------------------------//

// Constructor
PyString::PyString(const char *input_str) : str{nullptr}
{
    if (input_str == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(input_str) + 1];
        std::strcpy(str, input_str);
    }
}

// Copy Constructor
PyString::PyString(const PyString &source_string)
    : str{nullptr}
{
    str = new char[std::strlen(source_string.str) + 1];
    std::strcpy(str, source_string.str);
}

// Move Constructor
PyString::PyString(PyString &&source_string)
    : str{source_string.str}
{
    source_string.str = nullptr;
}

// Destructor
PyString::~PyString()
{
    delete[] str;
}

// Copy Assignment
PyString &PyString::operator=(const PyString &rhs)
{
    // std::cout << "Copy Assignment" << std::endl;

    if (this == &rhs)
    {
        return *this;
    }

    delete[] str;

    str = new char[std::strlen(rhs.str) + 1];
    strcpy(str, rhs.str);

    return *this;
}

// Move Assignment
PyString &PyString::operator=(PyString &&rhs)
{
    // std::cout << "Move Assignment" << std::endl;

    if (this == &rhs)
    {
        return *this;
    }

    delete[] str;
    str = rhs.str;

    rhs.str = nullptr;

    return *this;
}

//--------------------------------------------//
// UNARY OPERATORS
//--------------------------------------------//

bool PyString::operator!()
{
    if ((int)length() == 0)
    {
        return true;
    }

    return false;
}

//--------------------------------------------//
// BINARY OPERATORS
//--------------------------------------------//

PyString PyString::operator+(const PyString &rhs)
{
    size_t str_len{std::strlen(str)};
    size_t rhs_str_len{std::strlen(rhs.str)};
    size_t total_len{str_len + rhs_str_len + 1};

    char *buff = new char[total_len];

    for (size_t i{0}; i < total_len; i++)
    {
        if (i < str_len)
        {
            buff[i] = str[i];
        }
        else
        {
            buff[i] = rhs.str[i - str_len];
        }
    }

    PyString temp(buff);

    delete[] buff;

    return temp;
}

bool PyString::operator==(const PyString &rhs)
{
    return (std::strcmp(str, rhs.str) == 0);
}

std::ostream &operator<<(std::ostream &os, const PyString &rhs)
{
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &is, PyString &rhs)
{
    char *buff = new char[1000];
    is >> buff;
    rhs = buff;
    delete[] buff;
    return is;
}

//--------------------------------------------//
// PUBLIC METHODS
//--------------------------------------------//

size_t PyString::length() const
{
    return std::strlen(str);
}

PyString PyString::strip()
{

    size_t string_start = 0;
    size_t buff_size = length();

    for (size_t i{0}; i < length(); i++)
    {
        if (str[i] == ' ')
        {
            string_start++;
            buff_size--;
        }
        else
        {
            break;
        }
    }

    for (size_t i{length() - 1}; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            buff_size--;
        }
        else
        {
            break;
        }
    }

    size_t final_buff_size = buff_size + 1;

    char *buff = new char[final_buff_size];

    for (size_t i{0}, j{string_start}; i < final_buff_size; i++, j++)
    {
        if (i == (buff_size))
        {
            buff[i] = '\0';
            break;
        }

        buff[i] = str[j];
    }

    PyString temp(buff);
    delete[] buff;
    return temp;
}

PyString PyString::title() // TODO Finish title function
{

    size_t final_buff_size = length() + 1;
    char *buff = new char[final_buff_size];

    for (size_t i{0}; i < final_buff_size; i++)
    {
        bool is_upper_char{false};

        if (str[i] != ' ')
        {
            if (i == 0)
            {
                is_upper_char = true;
            }
            else
            {

                if (str[i - 1] == ' ')
                {
                    is_upper_char = true;
                }
            }
        }

        if (is_upper_char)
        {
            buff[i] = std::toupper(str[i]);
        }
        else
        {
            buff[i] = str[i];
        }
    }

    PyString title_string(buff);
    delete[] buff;
    return title_string;
}

PyString PyString::slice(int index_start = 0, int index_end = 0)
{

    int buff_size{index_end - index_start};
    char *buff = new char[buff_size + 1];

    for (int i{index_start}, j{0}; i < index_end; i++, j++)
    {
        buff[j] = str[i];
    }

    buff[buff_size] = '\0';

    PyString string_slice(buff);
    delete[] buff;
    return string_slice;
}

PyString PyString::insert(size_t index, const char *string)
{

    PyString slice_1(slice(0, index));
    PyString slice_2(slice(index, length()));
    PyString insert_string(string);

    PyString final_string(slice_1 + insert_string + slice_2);

    return final_string;
}

PyString PyString::remove(size_t index, size_t until_index)
{

    PyString slice_1(slice(0, index));
    PyString slice_2(slice(index + until_index, length()));
    PyString final_string(slice_1 + slice_2);

    // std::cout << final_string << std::endl;

    return final_string;
}

int PyString::find(const char *find_string, size_t start, size_t end)
{
    if (end == 0)
    {
        end = length() - 1;
    }

    for (size_t i{start}; i <= end; i++)
    {
        if (str[i] != find_string[0])
        {
            continue;
        }

        // Found index with first char in "find" parameter

        size_t find_index{i};
        size_t check_index{0};

        for (size_t c{0}; c < std::strlen(find_string); c++) // Keep iterating over the next chars, to check all chars corresponds to the find char
        {
            check_index = find_index + c;

            if (str[check_index] != find_string[c]) // If not, continue
            {
                continue;
            }

            if (c == (std::strlen(find_string) - 1)) // When all next chars was checked, execute the remove and replace operation
            {
                return i;
            }
        }
    }

    return -1;
}

PyString PyString::replace(const char *find, const char *replace)
{

    PyString replaced_string(str);
    int current_start{0};
    int current_found{0};

    while (current_found != -1)
    {
        current_found = replaced_string.find(find, current_start, 0);

        if (current_found == -1)
        {
            break;
        }

        replaced_string = replaced_string.remove(current_found, std::strlen(find)); // remove the old string find
        replaced_string = replaced_string.insert(current_found, replace);           // insert the replace string

        current_start = current_found + std::strlen(replace);
    }

    return replaced_string;
}

int PyString::count(const char *find_string)
{

    int current_start{0};
    int current_found{0};
    int count{0};

    while (current_found != -1)
    {
        current_found = find(find_string, current_start, 0);

        if (current_found == -1)
        {
            break;
        }

        count++;
        current_start = current_found + 1;
    }

    return count;
}

std::vector<PyString> PyString::split(const char *separator)
{
    std::vector<PyString> final_vector;

    int current_start{0};
    int current_found{0};

    while (current_found != -1 && current_start < (int)length())
    {
        current_found = find(separator, current_start, 0);

        if (current_found == -1)
        {
            PyString final_slice = slice(current_start, length());
            final_vector.push_back(final_slice); // Pushback the last splitted item, since there is no more separators
            break;
        }

        PyString splitted_string = slice(current_start, current_found);
        current_start = current_found + std::strlen(separator);

        if (!splitted_string) // Ignoring empty strings
        {
            continue;
        }

        final_vector.push_back(splitted_string); // Adding to the vector
    }

    return final_vector;
}

PyString PyString::lower()
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);

    for (size_t i{0}; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]);
    }

    PyString temp(buff);

    delete[] buff;

    return temp;
}

PyString PyString::upper()
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);

    for (size_t i{0}; i < std::strlen(buff); i++)
    {
        buff[i] = std::toupper(buff[i]);
    }

    PyString temp(buff);

    delete[] buff;

    return temp;
}

PyString PyString::capitalize()
{

    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);

    for (size_t i{0}; i < std::strlen(buff); i++)
    {
        if (buff[i] != ' ')
        {
            buff[i] = std::toupper(buff[i]);
            break;
        }
    }

    PyString temp(buff);

    delete[] buff;

    return temp;
}