/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#include "PrintBook.h"

// Constructors
PrintBook::PrintBook() : Book() {
    totalCopies = 0;
    availableCopies = 0;
}
PrintBook::PrintBook(std::string t, std::string a, long long isbn, int y, int tc, int ac) : Book(t, a, isbn, y) {
    totalCopies = tc;
    availableCopies = ac;
}

// overridden function, takes in printed book isbn and searches books.txt for book.  
// Checks avaliability if no copies are avaliables outputs `No avaliables copies` and returns false.  
// If availiable changes available copies and returns true
bool PrintBook::checkout(long long isbn) {
    std::string type;
    std::string ISBN;
    std::string temp;
    std::string avaCopies;
    std::streampos pos;
    std::string newVal;

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "Printed") {
            getline(books, ISBN);
            if (isbn == stoll(ISBN)) {
                getline(books, temp); // title
                getline(books, temp); // author
                getline(books, temp); // year
                getline(books, temp); //total copies
                pos = books.tellg();
                getline(books, avaCopies);

                if (stoi(avaCopies) <= 0) {
                    std::cout << "No avaliable copies";
                    books.clear();
                    books.seekg(0, std::ios::beg);
                    return false;
                }
                else {
                    books.clear();
                    books.seekp(pos);
                    newVal = std::to_string(stoi(avaCopies) - 1);
                    books << "0" << newVal;
                }

                books.clear();
                books.seekg(0, std::ios::beg);
                return true;
            }
        }
    }
    books.clear();
    books.seekg(0, std::ios::beg);
    return false;
}

// overridden funciton, takes in printed book isbn and searches books.txt for book.  Increments availiable copies by one.
void PrintBook::returnBook(long long isbn) {
std::string type;
std::string temp;
std::streampos pos;
std::string ISBN;
std::string avaCopies;
std::string newVal;

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "Printed") {
            getline(books, ISBN);
            if (isbn == stoll(ISBN)) {
                getline(books, temp); // title
                getline(books, temp); // author
                getline(books, temp); // year
                getline(books, temp); //total copies
                pos = books.tellg();
                getline(books, avaCopies);
                books.clear();
                books.seekp(pos);
                newVal = std::to_string(stoi(avaCopies) + 1);
                books << "0" << newVal;
                books.clear();
                books.seekg(0, std::ios::beg);
                return;
            }
        }
    }
}

// overridden funciton, displays all infromation of printed book
void PrintBook::display() {
    std::cout << "Title: " << title << std::endl
    << "Author: " << author << std::endl
    << "ISBN: " << ISBN << std::endl
    << "Year Published: " << yearPub << std::endl
    << "Type: Printed Book" << std::endl
    << "Total Copies: " << totalCopies << std::endl
    << "Available Copies: " << availableCopies << std::endl << std::endl;
}

// Takes in isbn of printed book checks if there are available copies, returns true if there is, false if not.
bool PrintBook::checkAvailability(long long isbn) {
    std::string type;
    std::string ISBN;
    std::string temp;
    std::string avaCopies;

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "Printed") {
            getline(books, ISBN);
            if (isbn == stoll(ISBN)) {
                getline(books, temp); // title
                getline(books, temp); // author
                getline(books, temp); // year
                getline(books, temp); //total copies
                getline(books, avaCopies);

                if (stoi(avaCopies) <= 0) {
                    std::cout << "No avaliable copies\n";
                    books.clear();
                    books.seekg(0, std::ios::beg);
                    return false;
                }
                else {
                    books.clear();
                    books.seekg(0, std::ios::beg);
                    return true;
                }
            }
        }
    }
    return false;  
}