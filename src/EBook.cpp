/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#include "EBook.h"
// Constructors
EBook::EBook() : Book() {}

EBook::EBook(std::string t, std::string a, long long isbn, int y) : Book(t, a, isbn, y) {}

// Overridden Functions
bool EBook::checkout(long long isbn) {
    // nothing need to be done because no restriction with amount of copies
    return true;
}
void EBook::returnBook(long long isbn) {
    // nothing need to be done because no restriction with amount of copies
}

// overridden function, displays all information of Ebook
void EBook::display() {
    std::cout << "Title: " << title << std::endl
    << "Author: " << author << std::endl
    << "ISBN: " << ISBN << std::endl
    << "Year Published: " << yearPub << std::endl
    << "Type: EBook" << std::endl << std::endl;
}