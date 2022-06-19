#include <iostream>
#include <string>
#include <exception>


class DeckFileNotFound : public std::runtime_error {
    public :
    DeckFileNotFound() : 
    std::runtime_error("Deck File Error: File not found")
    {}
};

class DeckFileFormatError : public std::runtime_error {
    public :
    DeckFileFormatError(const std::string& lineNumber) :
    std::runtime_error(std::string("Deck File Error: File format error in line ")+ lineNumber)
    {}
};

class DeckFileInvalidSize : public std::runtime_error {
    public :
    DeckFileInvalidSize() :
    std::runtime_error("Deck File Error: Deck size is invalid")
    {}
};