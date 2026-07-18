/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#ifndef EBOOK_H
#define EBOOK_H

#include <iostream>
#include <string>
#include "Book.h"

class EBook : public Book {
    public:
    EBook();
    EBook(std::string, std::string, long long, int);

    bool checkout(long long) override;
    void returnBook(long long) override;
    void display() override;
};

#endif