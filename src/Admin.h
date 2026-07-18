/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "User.h"

class Admin : public User {
    private:
    std::ifstream admins{"Data/admins.txt"};

    public:
    Admin();
    Admin(std::string, int);

    Admin loginA(int);
    void logout();

    void displayA() const;
    void searchUserN(std::string);
    bool searchUserI(int);
    void addPBook(std::string, std::string, std::string, int, int, int);
    void deletePBook(long long);
    void addEBook(std::string, std::string, std::string, int);
    void deleteEBook(long long);
    void addUser(std::string, int);
    void deleteUser(int);
};

#endif