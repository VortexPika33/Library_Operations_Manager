/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
    protected:
    std::string title;
    std::string author;
    long long ISBN;
    int yearPub;
    
    public:
    Book();
    Book(std::string, std::string, long long, int);
    
    std::string getTitle() const;
    
    virtual bool checkout(long long) = 0;
    virtual void returnBook(long long) = 0;
    virtual void display() = 0;
};

#endif