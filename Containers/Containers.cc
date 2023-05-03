/* Copyright 2022 An Nguyen anetw@uw.edu*/


#include <algorithm>  // for std:: sort
#include <iostream>   // for EXIT_FAILURE
#include <fstream>    // for std::ifstream
#include <map>        // for std::map
#include <sstream>    // for istringstream

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;
using std::istringstream;


template <typename T> bool ReadValue(ifstream& in, T* output);

int main(int argc, char** argv) {
    // Check if the input command is valid
    if (argc != 2) {
        cerr << "invalid input: ./ex8 filename" << endl;
        return EXIT_FAILURE;
    }

    std::ifstream infile(argv[1], ifstream::in);
    if (!infile) {
        cerr << "file could not be opened" << endl;
        return EXIT_FAILURE;
    }
    map<string, size_t> countmap;
    // assign the next token from infile to word
    string word;
    while (ReadValue<string>(infile, &word)) {
            countmap[word]++;
    }
    if (!infile.eof()) {
        cerr << "error reading file" << endl;
        return EXIT_FAILURE;
    }

    // Loop through every token in 'count map'
    // and print their keys and values
    for (const auto i : countmap) {
        cout << i.first << " " << i.second << endl;
    }
    return EXIT_SUCCESS;
}

template <typename T> bool ReadValue(ifstream& in, T* output) {
    T token;
    // Read the next token of 'in' to 'token'
    in >> token;
    if (!in.good()) {
        // if it's the end of line return false but don't print message;
        if (in.eof()) {
            return false;
            }
        cerr << "reading failed, conversion error, or EOF." << endl;
        return false;
    }
    // Assign the converted token to output
    *output = token;
    return true;
}
