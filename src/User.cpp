/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#include "User.h"

// Constructors
User::User() {
    name = "";
    ID = 0;
    feesOwed = 0.00;
}

User::User(std::string n, int id) {
    name = n;
    ID = id;
    feesOwed = 0.00;
}

User::User(std::string n, int id, float fees, std::string booksCheckedOut) {
    name = n;
    ID = id;
    feesOwed = fees;

    std::string tempBook = "";
    for (char c : booksCheckedOut) {
        if (c != ' ') {
            tempBook += c;
        }
        else {
            checkedBooks.push_back(tempBook);
            tempBook = "";
        }
    }
}

// Getter
std::string User::getName() const {
    return name;
}

std::string toLowerCase(std::string in) {
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
    return in;
}

// Display user information
void User::display() const {
    int counter;
    std::cout << "Showing info for " << name << std::endl;
    std::cout << "ID#: " << ID << std::endl;
    std::cout << "Fees Owed: $" << std::fixed << std::setprecision(2) << feesOwed << std::endl;
    std::cout << "Checked Out Books: " << std::endl;
    for (std::string book : checkedBooks) {
        if (book != "0000000000000") {
            std::cout << book << std::endl;
        }
    }
}

// searches books.txt for printed book isbn that matches passed isbn, returns true if found
bool User::searchPrintBookI(long long isbn) {
    std::string type;
    std::string ISBN;
    std::string title;
    std::string author;
    std::string year;
    std::string totCopies;
    std::string avaCopies;
    bool foundBook = false;

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "Printed") {
            getline(books, ISBN);
            if (isbn == stoll(ISBN)) {
                getline(books, title);
                getline(books, author);
                getline(books, year);
                getline(books, totCopies);
                getline(books, avaCopies);
                PrintBook book(title, author, stoll(ISBN), stoi(year), stoi(totCopies), stoi(avaCopies));
                books.clear();
                books.seekg(0, std::ios::beg);
                book.display();
                books.clear();
                books.seekg(0, std::ios::beg);
                foundBook = true;
                return true;
            }
            else {
                getline(books, title);
                getline(books, author);
                getline(books, year);
                getline(books, totCopies);
                getline(books, avaCopies);
            }
        }
    }
    if (!foundBook) {
        std::cout << "Book not found\n";
    }
    books.clear();
    books.seekg(0, std::ios::beg);
    return false;
}

// searches books.txt for printed book title that matches or contains passed string
void User::searchPrintBookT(std::string t) {
    std::string type;
    std::string ISBN;
    std::string title;
    std::string author;
    std::string year;
    std::string totCopies;
    std::string avaCopies;
    bool foundBook = false;

    t = toLowerCase(t);

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "Printed") {
            getline(books, ISBN);
            getline(books, title);
            if (toLowerCase(title).find(t) != std::string::npos) {
                getline(books, author);
                getline(books, year);
                getline(books, totCopies);
                getline(books, avaCopies);
                PrintBook book(title, author, stoll(ISBN), stoi(year), stoi(totCopies), stoi(avaCopies));
                book.display();
                foundBook = true;
            }
            else {
                getline(books, author);
                getline(books, year);
                getline(books, totCopies);
                getline(books, avaCopies);
            }
        }
    }
    if (!foundBook) {
        std::cout << "Book not found\n";
    }
    books.clear();
    books.seekg(0, std::ios::beg);
}

// searches books.txt for printed book author that matches or contains passed string
void User::searchPrintBookA(std::string a) {
    std::string type;
    std::string ISBN;
    std::string title;
    std::string author;
    std::string year;
    std::string totCopies;
    std::string avaCopies;
    bool foundBook = false;

    a = toLowerCase(a);

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "Printed") {
            getline(books, ISBN);
            getline(books, title);
            getline(books, author);
            if (toLowerCase(author).find(a) != std::string::npos) {
                getline(books, year);
                getline(books, totCopies);
                getline(books, avaCopies);
                PrintBook book(title, author, stoll(ISBN), stoi(year), stoi(totCopies), stoi(avaCopies));
                book.display();
                foundBook = true;
            }
            else {
                getline(books, year);
                getline(books, totCopies);
                getline(books, avaCopies);
            }
        }
    }
    if (!foundBook) {
        std::cout << "Book not found\n";
    }
    books.clear();
    books.seekg(0, std::ios::beg);
}

// searches books.txt for ebook isbn that matches passed isbn, returns true if found
bool User::searchEBookI(long long isbn) {
    std::string type;
    std::string ISBN;
    std::string title;
    std::string author;
    std::string year;
    bool foundBook = false;

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "EBook") {
            getline(books, ISBN);
            if (isbn == stoll(ISBN)) {
                getline(books, title);
                getline(books, author);
                getline(books, year);
                EBook book(title, author, stoll(ISBN), stoi(year));
                books.clear();
                books.seekg(0, std::ios::beg);
                book.display();
                foundBook = true;
                books.clear();
                books.seekg(0, std::ios::beg);
                return true;
            }
            else {
                getline(books, title);
                getline(books, author);
                getline(books, year);
            }
        }
    }
    if (!foundBook) {
        std::cout << "Book not found\n";
    }
    books.clear();
    books.seekg(0, std::ios::beg);
    return false;
}

// searches books.txt for ebook title that matches or contains passed string
void User::searchEBookT(std::string t) {
    std::string type;
    std::string ISBN;
    std::string title;
    std::string author;
    std::string year;
    bool foundBook = false;

    t = toLowerCase(t);

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "EBook") {
            getline(books, ISBN);
            getline(books, title);
            if (toLowerCase(title).find(t) != std::string::npos) {
                getline(books, author);
                getline(books, year);
                EBook book(title, author, stoll(ISBN), stoi(year));
                book.display();
                foundBook = true;
            }
            else {
                getline(books, author);
                getline(books, year);
            }
        }
    }
    if (!foundBook) {
        std::cout << "Book not found\n";
    }
    books.clear();
    books.seekg(0, std::ios::beg);
}

// searches books.txt for ebook author that matches or contains passed string
void User::searchEBookA(std::string a) {
    std::string type;
    std::string ISBN;
    std::string title;
    std::string author;
    std::string year;

    bool foundBook = false;

    a = toLowerCase(a);

    while (getline(books, type)) {
        if (type.empty()) continue;
        type.erase(std::remove(type.begin(), type.end(), '\r'), type.end());
        if (type == "EBook") {
            getline(books, ISBN);
            getline(books, title);
            getline(books, author);
            if (toLowerCase(author).find(a) != std::string::npos) {
                getline(books, year);
                EBook book(title, author, stoll(ISBN), stoi(year));
                book.display();
                foundBook = true;
            }
            else {
                getline(books, year);
            }
        }
    }
    if (!foundBook) {
        std::cout << "Book not found\n";
    }
    books.clear();
    books.seekg(0, std::ios::beg);
}

// checks printed book with matching isbn has availavle copies with  checkAvailability(long long).  
// Inputs book's isbn under current logged in user in next available book slot.  
// Asks for current date and saves it in corresponding date slot.  
// If all slots are filled outputs "Cannot checkout more than 5 books"
void User::checkoutPBook(long long isbn) {
    PrintBook tempBook;
    std::string tempID;
    std::string temp;
    std::streampos pos;
    std::streampos backUpPos;
    std::string date;
    std::streampos datePos;

    if (tempBook.checkAvailability(isbn)) {
        while (getline(users, tempID)) {
            if (tempID.empty()) continue;
            getline(users, tempID);
            if (stoi(tempID) == ID) {
                getline(users, temp); // skip fees
                pos = users.tellg();
                for (int i = 1; i <= 5; i++) {
                    backUpPos = users.tellg();
                    users >> temp;
                    if (temp == "0000000000000" && i == 1) {
                        users.clear();
                        users.seekp(backUpPos);
                        users << std::to_string(isbn) << " ";
                        users.clear();
                        users.seekg(0, std::ios::beg);
                        std::cout << "Please enter current date with form MM-DD-YYYY (include 0): ";
                        std::cin >> date;
                        getline(users, temp); // name
                        getline(users, temp); // id
                        getline(users, temp); // fees
                        getline(users, temp); // books
                        users << date;
                        users.clear();
                        users.seekg(0, std::ios::beg);
                        checkedBooks.push_back(std::to_string(isbn));
                        tempBook.checkout(isbn);
                        return;
                    }
                    if (temp == "0000000000000") {
                        users.clear();
                        users.seekp(backUpPos);
                        users << std::to_string(isbn) << " ";
                        users.clear();
                        users.seekg(0, std::ios::beg);
                        std::cout << "Please enter current date with form MM-DD-YYYY (include 0): ";
                        std::cin >> date;
                        getline(users, temp); // name
                        getline(users, temp); // id
                        getline(users, temp); // fees
                        getline(users, temp); // books
                        datePos = users.tellg();
                        users.seekp(datePos + static_cast<std::streampos>((i-1)*14));
                        users << date;
                        users.clear();
                        users.seekg(0, std::ios::beg);
                        checkedBooks.push_back(std::to_string(isbn));
                        tempBook.checkout(isbn);
                        return;
                    }
                    if (i == 5 && temp != "0000000000000") {
                        std::cout << "Cannot checkout more than 5 books\n";
                        return;
                    }
                }
            }
            else {
                getline(users, temp); // fees
                getline(users, temp); // books
            }
        }
    }
}

// Inputs book's isbn under current logged in user in next available book slot.  
// Asks for current date and saves it in corresponding date slot.  
// If all slots are filled outputs "Cannot checkout more than 5 books"
void User::checkoutEBook(long long isbn) {
    std::string tempID;
    std::streampos pos;
    std::streampos backUpPos;
    std::string temp;
    std::string date;
    std::streampos datePos;

    while (getline(users, tempID)) {
        if (tempID.empty()) continue;
        getline(users, tempID);
        if (stoi(tempID) == ID) {
            getline(users, temp); // fees
            pos = users.tellg();
            for (int i = 1; i <= 5; i++) {
                backUpPos = users.tellg();
                getline(users, temp, ' ');
                if (temp == "0000000000000" && i == 1) {
                    users.clear();
                    users.seekp(pos);
                    users << std::to_string(isbn) << " ";
                    users.clear();
                    users.seekg(0, std::ios::beg);
                    std::cout << "Please enter current date with form MM-DD-YYYY (include 0): ";
                    std::cin >> date;
                    getline(users, temp); // name
                    getline(users, temp); // id
                    getline(users, temp); // fees
                    getline(users, temp); // books
                    users << date;
                    users.clear();
                    users.seekg(0, std::ios::beg);
                    checkedBooks.push_back(std::to_string(isbn));
                    return;
                }
                if (temp == "0000000000000") {
                    users.clear();
                    users.seekp(backUpPos);
                    users << std::to_string(isbn) << " ";
                    users.clear();
                    users.seekg(0, std::ios::beg);
                    std::cout << "Please enter current date with form MM-DD-YYYY: ";
                    std::cin >> date;
                    getline(users, temp); // name
                    getline(users, temp); // id
                    getline(users, temp); // fees
                    getline(users, temp); // books
                    datePos = users.tellg();
                    users.seekp(datePos + static_cast<std::streampos>((i-1)*14));
                    users << date;
                    users.clear();
                    users.seekg(0, std::ios::beg);
                    checkedBooks.push_back(std::to_string(isbn));
                    return;
                }
                if (i == 5 && temp != "0000000000000") {
                    std::cout << "Cannot checkout more than 5 books\n";
                    return;
                }
            }
        }
        else {
            getline(users, temp); // fees
            getline(users, temp); // books
        }
    }
}

// Asks for current date (return date) and checkoutDate is passed as parameter then both dates are converted to days.  
// daysPassed is calculated by subtracting checkoutDateInDays from returnDateInDays.  
// 14 is subtracted from days passed for grace period.  
// If daysPass is less than or equal to 0 no fees are added, otherwise $10 is added to fees 
// as well as $5 for each week after - including partial weeks.  Returns fees calculated
float User::calculateFees(std::string checkoutDate) {
    float fees = 0.00;
    int checkoutMonth;
    int checkoutDay;
    int checkoutYear;
    int checkoutDateInDays;
    std::string returnDate;
    int returnMonth;
    int returnDay;
    int returnYear;
    int daysPassed;
    int returnDateInDays;

    // assume every month has 30 days

    std::cout << "Please enter current date with form MM-DD-YYYY: ";
    std::cin >> returnDate;
    
    // Split dates
    checkoutMonth = stoi(checkoutDate.substr(0, 2));
    checkoutDay = stoi(checkoutDate.substr(3, 2));
    checkoutYear = stoi(checkoutDate.substr(6, 4));
    returnMonth = stoi(returnDate.substr(0, 2));
    returnDay = stoi(returnDate.substr(3, 2));
    returnYear = stoi(returnDate.substr(6, 4));

    checkoutDateInDays = checkoutYear * 360 + checkoutMonth * 30 + checkoutDay; // Convert checkout date to days
    returnDateInDays = returnYear * 360 + returnMonth * 30 + returnDay; // Convert return date into days
    daysPassed = returnDateInDays - checkoutDateInDays;
    daysPassed -= 14; // Grace period
    if (daysPassed <= 0) {
        std::cout << "No fees added\n";
        return fees;
    }
    fees += 10;
    fees += 5  * (static_cast<float>(daysPassed) / 7); // Adds $5 per week not returned - includes partial weeks
    std::cout << "Fees added $" << std::fixed << std::setprecision(2) << fees << std::endl;
    return fees;
}

// Finds printed book with matching isbn (passed as parameter), if found resets book slot to 0s and date to 0s.  
// Calls calculateFees(string) and adds to current user's feesOwed.  
// Outputs "Book could not be returned/found" if book could not be found
void User::returnPBook(long long isbn) {
    PrintBook tempBook;
    std::string tempID;
    std::string temp;
    std::string date;
    std::streampos pos;
    std::streampos feesPos;
    std::streampos datePos;
    bool returnBook = false;

    while (getline(users, tempID)) {
        if (tempID.empty()) continue;
        getline(users, tempID);
        if (stoi(tempID) == ID) {
            getline(users, temp); // fees
            for (int i = 1; i <= 5; i++) {
                pos = users.tellg();
                getline(users, temp, ' ');
                if (temp == std::to_string(isbn)) {
                    users.clear();
                    users.seekp(pos);
                    users << "0000000000000 ";
                    users.clear();
                    users.seekg(0, std::ios::beg);
                    getline(users, temp); // name
                    getline(users, temp); // id
                    feesPos = users.tellg();
                    getline(users, temp); // fees
                    getline(users, temp); // books
                    datePos = users.tellg();
                    users.seekp(datePos + static_cast<std::streampos>((i-1)*14));
                    getline(users, date, ' ');
                    users.seekp(datePos + static_cast<std::streampos>((i-1)*14));
                    users << "00-00-0000";
                    feesOwed += calculateFees(date);
                    users.seekp(feesPos);
                    // add buffer
                    if (feesOwed <= 9.99) {
                        users << "00" << std::fixed << std::setprecision(2) << feesOwed;
                    }
                    else if (feesOwed <= 99.99 && feesOwed >= 10.00) {
                        users << "0" << std::fixed << std::setprecision(2) << feesOwed;
                    }
                    else if (feesOwed <= 999.99 && feesOwed >= 100.00) {
                        users << std::fixed << std::setprecision(2) << feesOwed;
                    }
                    users.clear();
                    users.seekg(0, std::ios::beg);
                    checkedBooks.erase(std::remove(checkedBooks.begin(), checkedBooks.end(), std::to_string(isbn)), checkedBooks.end());
                    tempBook.returnBook(isbn);
                    returnBook = true;
                    return;
                }
            }
        }
        else {
            getline(users, temp); // fees
            getline(users, temp); // books
        }
    }
    if (!returnBook) {
        std::cout << "Book could not be returned/found\n";
        return;
    }
}

// Finds ebook with matching isbn (passed as parameter), if found resets book slot to 0s and date to 0s.  
// Calls calculateFees(string) and adds to current user's feesOwed.  
// Outputs "Book could not be returned/found" if book could not be found
void User::returnEBook(long long isbn) {
    EBook tempBook;
    std::string tempID;
    std::string temp;
    std::string date;
    std::streampos pos;
    std::streampos feesPos;
    std::streampos datePos;
    bool returnBook = false;
    
        while (getline(users, tempID)) {
            if (tempID.empty()) continue;
            getline(users, tempID);
            if (stoi(tempID) == ID) {
                getline(users, temp); // fees
                for (int i = 1; i <= 5; i++) {
                    pos = users.tellg();
                    getline(users, temp, ' ');
                    if (temp == std::to_string(isbn)) {
                        users.clear();
                        users.seekp(pos);
                        users << "0000000000000 ";
                        users.clear();
                        users.seekg(0, std::ios::beg);
                        getline(users, temp); // name
                        getline(users, temp); // id
                        feesPos = users.tellg();
                        getline(users, temp); // fees
                        getline(users, temp); // books
                        datePos = users.tellg();
                        users.seekp(datePos + static_cast<std::streampos>((i-1)*14));
                        getline(users, date, ' ');
                        users.seekp(datePos + static_cast<std::streampos>((i-1)*14));
                        users << "00-00-0000";
                        feesOwed += calculateFees(date);
                        users.seekp(feesPos);
                        // add buffer 
                        if (feesOwed <= 9.99) {
                            users << "00" << std::fixed << std::setprecision(2) << feesOwed;
                        }
                        else if (feesOwed <= 99.99 && feesOwed >= 10.00) {
                            users << "0" << std::fixed << std::setprecision(2) << feesOwed;
                        }
                        else if (feesOwed <= 999.99 && feesOwed >= 100.00) {
                            users << std::fixed << std::setprecision(2) << feesOwed;
                        }
                        users.clear();
                        users.seekg(0, std::ios::beg);
                        checkedBooks.erase(std::remove(checkedBooks.begin(), checkedBooks.end(), std::to_string(isbn)), checkedBooks.end());
                        tempBook.returnBook(isbn);
                        returnBook = true;
                        return;
                    }
                }
            }
            else {
                getline(users, temp); // fees
                getline(users, temp); // books
            }
        }
        if (!returnBook) {
            std::cout << "Book could not be returned/found\n";
            return;
        }
}

// finds user with matching id passed as parameter then reads data from users.txt and 
// creates a new User object and returns.  If user is not found nullUser is created with no variables
User User::login(int id) {
    std::string tempName;
    std::string tempID;
    std::string tempFees;
    std::string tempBooks;
    std::string tempDates;
    
    users.clear();
    users.seekg(0, std::ios::beg);

    while (getline(users, tempName)) {
        if (tempName.empty()) continue;
        getline(users, tempID); // Id
        if (stoi(tempID) == id) {
            getline(users, tempFees); // Fees
            getline(users, tempBooks); // Books
            User newUser(tempName, std::stoi(tempID), std::stof(tempFees), tempBooks);
            users.clear();
            users.seekg(0, std::ios::beg);
            return newUser;
        }
        else {
            getline(users, tempFees); // Fees
            getline(users, tempBooks); // Books
            getline(users, tempDates); // Dates
        }
    }
    users.clear();
    users.seekg(0, std::ios::beg);
    User nullUser;
    return nullUser;
}
