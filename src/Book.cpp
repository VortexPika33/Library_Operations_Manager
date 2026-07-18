/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#include "Book.h"

// Constructors
Book::Book() {
    title = "";
    author = "";
    ISBN = 0;
}
Book::Book(std::string t, std::string a, long long isbn, int y) {
    title = t;
    author = a;
    ISBN = isbn;
    yearPub = y;
}
    
// Getter
std::string Book::getTitle() const{
    return title;
}

// Pure Virtual Functions
bool checkout();
void returnBook();
void display();