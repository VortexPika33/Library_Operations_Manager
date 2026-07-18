/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/
#include "Admin.h"

// Constuctors
Admin::Admin() : User() {}

Admin::Admin(std::string n, int id) : User(n, id) {}

Admin Admin::loginA(int id) {
    std::string tempName;
    std::string tempID;
    
    admins.clear();
    admins.seekg(0, std::ios::beg);
    
    while (getline(admins, tempName)) {
        if (tempName.empty()) continue;
        getline(admins, tempID);
        if (stoi(tempID) == id) {
            Admin newAdmin(tempName, std::stoi(tempID));
            admins.clear();
            admins.seekg(0, std::ios::beg);
            return newAdmin;
        }
    }
    admins.clear();
    admins.seekg(0, std::ios::beg);
    Admin nullAdmin;
    return nullAdmin;
}


std::string toLowerCaseA(std::string in) {
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    return in;
}

// Closes admins file
void Admin::logout() {
    admins.close();
    return;
}

// displays information of admin currently logged in 
void Admin::displayA() const {
    std::cout << "Showing info for " << name << std::endl;
    std::cout << "ID#: " << ID << std::endl;
}

// searches users.txt for user's name that matches or contains passed string
void Admin::searchUserN(std::string nameIn) {
    std::string tempName;
    std::string tempID;
    std::string tempFees;
    std::string tempBooks;
    std::string tempDates;
    bool foundUser = false;

    nameIn = toLowerCaseA(nameIn);

    while (getline(users, tempName)) {
        if (tempName.empty()) continue;
        tempName.erase(std::remove(tempName.begin(), tempName.end(), '\r'), tempName.end());
        if (toLowerCaseA(tempName).find(nameIn) != std::string::npos) {
            getline(users, tempID);
            getline(users, tempFees);
            getline(users, tempBooks);
            getline(users, tempDates);
            getline(users, tempDates);
            User user(tempName, std::stoi(tempID), std::stof(tempFees), tempBooks);
            user.display();
            foundUser = true;
        }
        else {
            getline(users, tempID);
            getline(users, tempFees);
            getline(users, tempBooks);
            getline(users, tempDates);
            getline(users, tempDates);
        }
    }
    if (!foundUser) {
        std::cout << "User could not be found\n";
    }
    users.clear();
    users.seekg(0, std::ios::beg);
}

// searches users.txt for user's id that matches passed int
bool Admin::searchUserI(int idIn) {
    std::string tempName;
    std::string tempID;
    std::string tempFees;
    std::string tempBooks;
    std::string tempDates;

    while (getline(users, tempName)) {
        if (tempName.empty()) continue;
        tempName.erase(std::remove(tempName.begin(), tempName.end(), '\r'), tempName.end());
        getline(users, tempID);
        if (tempID == std::to_string(idIn)) {
            getline(users, tempFees);
            getline(users, tempBooks);
            getline(users, tempDates);
            getline(users, tempDates);
            User foundUser(tempName, std::stoi(tempID), std::stof(tempFees), tempBooks);
            users.clear();
            users.seekg(0, std::ios::beg);
            foundUser.display();
            return true;
        }
        else {
            getline(users, tempFees);
            getline(users, tempBooks);
            getline(users, tempDates);
            getline(users, tempDates);
        }
    }
    std::cout << "User could not be found\n";
    users.clear();
    users.seekg(0, std::ios::beg);
    return false;
}

// Takes in title, author, isbn, year published, total copies, and avaliable copies of new printed book. 
// Makes sure book does not already exist before adding information to books.txt
void Admin::addPBook(std::string isbn, std::string title, std::string author, int year, int tCopies, int aCopies) {
    if (searchPrintBookI(stoll(isbn))) {
        std::cout << "Book already exits\n";
        return;
    }
    else {
        books.seekg(0, std::ios::end);
        books << "\nPrinted\n" << isbn << std::endl;
        books << std::left << std::setw(50) << title << std::endl;
        books << std::left << std::setw(50) << author << std::endl;
        books << year << std::endl;
        if (tCopies > 0 && tCopies <= 9) {
            books << "0" << tCopies << std::endl;
        }
        else {
            books << tCopies << std::endl;
        }
        if (aCopies > 0 && aCopies <= 9) {
            books << "0" << aCopies << std::endl;
        }
        else {
            books << aCopies << std::endl;
        }
        books.clear();
        books.seekg(0, std::ios::beg);
        std::cout << "New Book Info:\n";
        searchPrintBookI(stoll(isbn));
        books.clear();
        books.seekg(0, std::ios::beg);
        return;
    }
}

// Takes in printed book isbn and finds book in books.txt then turns information to * to block it out
void Admin::deletePBook(long long isbn) {
    std::string type;
    std::string temp;
    std::string tempISBN;
    std::streampos beforeBook;
    
    beforeBook = books.tellg();
    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "Printed") {
            getline(books, tempISBN);
            if (isbn == stoll(tempISBN)) {
                books.clear();
                books.seekp(beforeBook);
                // turn everthing to *
                books << std::string(7, '*') << std::endl
                << std::string(13, '*') << std::endl
                << std::string(50, '*') << std::endl
                << std::string(50, '*') << std::endl
                << std::string(4, '*') << std::endl
                << std::string(2, '*') << std::endl
                << std::string(2, '*') << std::endl;
                books.clear();
                books.seekg(0, std::ios::beg);
                return;
            }
            else {
                getline(books, temp); // title
                getline(books, temp); // author
                getline(books, temp); // year
                getline(books, temp); // total copies
                getline(books, temp); // available copies
                getline(books, temp); // empty line
                beforeBook = books.tellg();
            }
        }
        else {
            getline(books, temp); // isbn
            getline(books, temp); // title
            getline(books, temp); // author
            getline(books, temp); // year
            getline(books, temp); // empty line
            beforeBook = books.tellg();
        }
    }
}

// Takes in title,author, isbn, and year published of new Ebook.  
// Makes sure book does not already exist before adding information to books.txt
void Admin::addEBook(std::string isbn, std::string title, std::string author, int year) {
    if (searchPrintBookI(stoll(isbn))) {
        std::cout << "Book already exits\n";
        return;
    }
    else {
        books.seekg(0, std::ios::end);
        books << "\nEBook\n" << isbn << std::endl;
        books << std::left << std::setw(50) << title << std::endl;
        books << std::left << std::setw(50) << author << std::endl;
        books << year << std::endl;
        books.clear();
        books.seekg(0, std::ios::beg);
        std::cout << "New Book Info:\n";
        searchEBookI(stoll(isbn));
        books.clear();
        books.seekg(0, std::ios::beg);
        return;
    }
}

// Takes in Ebook isbn and finds book in books.txt then turns information to * to block it out
void Admin::deleteEBook(long long isbn) {
    std::string type;
    std::string temp;
    std::string tempISBN;
    std::streampos beforeBook;
    
    beforeBook = books.tellg();
    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "EBook") {
            getline(books, tempISBN);
            if (isbn == stoll(tempISBN)) {
                books.clear();
                books.seekp(beforeBook);
                // turn everthing to *
                books << std::string(7, '*') << std::endl
                << std::string(13, '*') << std::endl
                << std::string(50, '*') << std::endl
                << std::string(50, '*') << std::endl
                << std::string(4, '*') << std::endl;
                books.clear();
                books.seekg(0, std::ios::beg);
                return;
            }
            else {
                getline(books, temp); // title
                getline(books, temp); // author
                getline(books, temp); // year
                getline(books, temp); // empty line
                beforeBook = books.tellg();
            }
        }
        else {
            getline(books, temp); // isbn
            getline(books, temp); // title
            getline(books, temp); // author
            getline(books, temp); // year
            getline(books, temp); // total copies
            getline(books, temp); // available copies
            getline(books, temp); // empty line
            beforeBook = books.tellg();
        }
    }
}

// Takes in name and id number of new user.  Makes sure user does not already exist before adding it to users.txt
void Admin::addUser(std::string name, int id) {
    if (searchUserI(id)) {
        std::cout << "User already exists\n";
        return;
    }
    else {
        users.seekg(0, std::ios::end);
        users << std::endl;
        users << std::left << std::setw(25) << name << std::endl;
        users << id << std::endl
        << "000.00\n" << "0000000000000 0000000000000 0000000000000 0000000000000 0000000000000\n"
        << "00-00-0000    00-00-0000    00-00-0000    00-00-0000    00-00-0000\n";
        users.clear();
        users.seekg(0, std::ios::beg);
        searchUserI(id);
        users.clear();
        users.seekg(0, std::ios::beg);
        return;
    }
}

// Takes in id and finds user in users.txt then turns information to * to block it out
void Admin::deleteUser(int id) {
    if (!searchUserI(id)) {
        return;
    }
    else {
        std::string temp;
        std::string tempID;
        std::streampos beforeUser;

        beforeUser = users.tellg();
        while (getline(users, temp)) {
            if (temp.empty()) continue;
            getline(users, tempID);
            if (tempID == std::to_string(id)) {
                users.seekg(beforeUser);
                // turn everthing to *
                users << std::string(25, '*') << std::endl
                << std::string(4, '*') << std::endl
                << std::string(6, '*') << std::endl
                << std::string(71, '*') << std::endl
                << std::string(67, '*') << std::endl;
                users.clear();
                users.seekg(0, std::ios::beg);
                return;
            }
            else {
                getline(users, temp);
                getline(users, temp);
                getline(users, temp);
                getline(users, temp);
                beforeUser = users.tellg();
            }
        }
    }
}