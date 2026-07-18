/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#ifndef PRINTBOOK_H
#define PRINTBOOK_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Book.h"

class PrintBook : public Book {
    private:
    int totalCopies;
    int availableCopies;
    std::fstream books{"Data/books.txt", std::ios::in | std::ios::out | std::ios::binary};

    public:
    PrintBook();
    PrintBook(std::string, std::string, long long, int, int, int);

    bool checkout(long long) override;
    void returnBook(long long) override;
    void display() override;
    bool checkAvailability(long long);
};

#endif