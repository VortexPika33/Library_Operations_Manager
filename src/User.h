/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "PrintBook.h"
#include "EBook.h"

class User {
    protected:
    std::string name;
    int ID;
    float feesOwed;
    std::vector<std::string> checkedBooks;
    
    public:
    std::fstream users{"Data/users.txt", std::ios::in | std::ios::out | std::ios::binary};
    std::fstream books{"Data/books.txt", std::ios::in | std::ios::out | std::ios::binary};

    User();
    User(std::string, int);
    User(std::string, int, float, std::string);

    std::string getName() const;

    void display() const;
    bool searchPrintBookI(long long);
    void searchPrintBookT(std::string);
    void searchPrintBookA(std::string);
    bool searchEBookI(long long);
    void searchEBookT(std::string);
    void searchEBookA(std::string);
    void checkoutPBook(long long);
    void checkoutEBook(long long);
    float calculateFees(std::string);
    void returnPBook(long long);
    void returnEBook(long long);
    User login(int);
};

#endif