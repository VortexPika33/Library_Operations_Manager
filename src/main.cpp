/*
* Author: Brooke Picard
* Class: CSCI 2312
* Assignment: Project 1
* Created: 4/18/2025
* Due Date: 5/2/2025
*/

#include "Book.h"
#include "EBook.h"
#include "PrintBook.h"
#include "User.h"
#include "Admin.h"

int main() {
    std::string tempID;
    std::string tempName;
    User tempUser;
    User currentUser;
    Admin tempAdm;
    Admin currentAdm;
    std::string type;
    std::string searchBy;
    std::string check;
    std::string tempISBN;
    std::string tempTitle;
    std::string tempAuthor;
    std::string tempYear;
    std::string tempTCopies;
    std::string tempACopies;
    bool capNext = false;

    std::cout << "Please enter ID number to login: ";
    std::cin >> tempID;
    
    // Test for Admin Login
    if (tempID == "ADMIN") {
        std::cout << "Enter ID number: ";
        std::cin >> tempID;
        currentAdm = tempAdm.loginA(stoi(tempID));
        if (currentAdm.getName() == "") {
            std::cout << "ID was not found.  Quitting Program.";
            return 1;
        }
        std::cout << "Welcome " << currentAdm.getName() << "\n";

        int choice = 0;
        int lp = 0;
        while (lp == 0) {
            // Determine which function user would like to use
            std::cout << "What would you like to do:\n"
            << "1: Display current user info\n"
            << "2: Search for book\n"
            << "3: Search for user\n"
            << "4: Add book\n"
            << "5: Delete book\n"
            << "6: Add user\n"
            << "7: Delete user\n"
            << "8: Logout\n";
            std::cin >> choice;
            switch (choice) {
                // Display current user info
                case 1:
                    currentAdm.displayA();
                    break;
                // Search for book
                case 2:
                    // Figure out type of book for search
                    std::cout << "Which type of book would you like to search for?\n"
                    << "Enter 'E' for EBook\n"
                    << "Enter 'P' for Printed Book\n";
                    std::cin >> type;
                    //Figure out how they would like to search
                    std::cout << "How would you like to search for book?\n"
                    << "Enter 'T' for Title\n"
                    << "Enter 'A' for Author\n"
                    << "Enter 'I' for ISBN\n";
                    std::cin >> searchBy;
                    // Search EBooks
                    if (type == "E" || type == "e") {
                        // Search by title
                        if (searchBy == "T" || searchBy == "t") {
                            std::cout << "Please enter title of book: ";
                            std::cin >> tempTitle;
                            currentAdm.searchEBookT(tempTitle);
                        }
                        // Search by author
                        else if (searchBy == "A" || searchBy == "a") {
                            std::cout << "Please enter author's name: ";
                            std::cin >> tempAuthor;
                            currentAdm.searchEBookA(tempAuthor);
                        }
                        // Search by ISBN
                        else if (searchBy == "I" || searchBy == "i") {
                            std::cout << "Please enter ISBN (No dashes): ";
                            std::cin >> tempISBN;
                            currentAdm.searchEBookI(stoll(tempISBN));
                        }
                        // Error handler
                        else {
                            std::cout << "Please enter T, A, or I\n";
                        }
                    }
                    // Search PrintedBooks
                    else if (type == "P" || type == "p") {
                        // Search by title
                        if (searchBy == "T" || searchBy == "t") {
                            std::cout << "Please enter title of book: ";
                            std::cin >> tempTitle;
                            currentAdm.searchPrintBookT(tempTitle);
                        }
                        // Search by author
                        else if (searchBy == "A" || searchBy == "a") {
                            std::cout << "Please enter author's name: ";
                            std::cin >> tempAuthor;
                            currentAdm.searchPrintBookA(tempAuthor);
                        }
                        // Search by ISBN
                        else if (searchBy == "I" || searchBy == "i") {
                            std::cout << "Please enter ISBN (No dashes): ";
                            std::cin >> tempISBN;
                            currentAdm.searchPrintBookI(stoll(tempISBN));
                        }
                        // Error handler
                        else {
                            std::cout << "Please enter T, A, or I\n";
                        }
                    }
                    // Error handler
                    else {
                        std::cout << "Please enter E or P\n";
                        break;
                    }
                    break;
                // Search for user
                case 3:
                    //Figure out how they would like to search
                    std::cout << "How would you like to search for user?\n"
                    << "Enter 'N' for Name\n"
                    << "Enter 'I' for ID\n";
                    std::cin >> searchBy;
                    // Search by name
                    if (searchBy == "N" || searchBy == "n") {
                        std::cout << "Please enter name: ";
                        std::cin >> tempName;
                        currentAdm.searchUserN(tempName);
                    }
                    else if (searchBy == "I" || searchBy == "i") {
                        std::cout << "Please enter ID: ";
                        std::cin >> tempID;
                        currentAdm.searchUserI(stoi(tempID));
                    }
                    else {
                        std::cout << "Please enter N or I\n";
                    }
                    break;
                // Add book
                case 4:
                    // Figure out type of book their adding
                    std::cout << "Which type of book would you like to add?\n"
                    << "Enter 'E' for EBook\n"
                    << "Enter 'P' for Printed Book\n";
                    std::cin >> type;
                    // Add EBook
                    if (type == "E" || type == "e") {
                        std::cout << "Please enter ISBN (no dashes): ";
                        std::cin >> tempISBN;
                        std::cin.ignore();
                        std::cout << "Please enter title (with proper capitalization): ";
                        std::getline(std::cin, tempTitle);
                        std::cout << "Please enter author (with proper capitalization): ";
                        std::getline(std::cin, tempAuthor);
                        std::cout << "Please enter year published: ";
                        std::cin >> tempYear;
                        currentAdm.addEBook(tempISBN, tempTitle, tempAuthor, stoi(tempYear));
                    }
                    // Add Printed Book
                    else if (type == "P" || type == "p") {
                        std::cout << "Please enter ISBN (no dashes): ";
                        std::cin >> tempISBN;
                        std::cin.ignore();
                        std::cout << "Please enter title (with proper capitalization): ";
                        std::getline(std::cin, tempTitle);
                        std::cout << "Please enter author (with proper capitalization): ";
                        std::getline(std::cin, tempAuthor);
                        std::cout << "Please enter year published: ";
                        std::cin >> tempYear;
                        std::cout << "Please enter total copies: ";
                        std::cin >> tempTCopies;
                        std::cout << "Please enter available copies: ";
                        std::cin >> tempACopies;
                        currentAdm.addPBook(tempISBN, tempTitle, tempAuthor, stoi(tempYear), stoi(tempTCopies), stoi(tempACopies));
                    }
                    // Error handler
                    else {
                        std::cout << "Please enter E or P\n";
                        break;
                    }
                    break;
                // Delete book
                case 5:
                    // Figure out type of book
                    std::cout << "What type of book do you want to delete?\n"
                    << "Enter 'P' for Printed Book\n"
                    << "Enter 'E' for EBook\n";
                    std::cin >> searchBy;
                    // Printed Book
                    if (searchBy == "P" || searchBy == "p") {
                        std::cout << "Please enter ISBN: ";
                        std::cin >> tempISBN;
                        currentAdm.searchPrintBookI(stoll(tempISBN));
                        std::cout << "Is this the correct book? (y/n): ";
                        std::cin >> check;
                        if (check == "Y" || check == "y") {
                            currentAdm.deletePBook(stoll(tempISBN));
                            break;
                        }
                        else if (check == "N" || check == "n") {
                        }
                        // Error Handling
                        else {
                            std::cout << "Please enter y or n\n";
                            break;
                        }
                    }
                    // EBook
                    else if (searchBy == "E" || searchBy == "e") {
                        std::cout << "Please enter ISBN: ";
                        std::cin >> tempISBN;
                        currentAdm.searchEBookI(stoll(tempISBN));
                        std::cout << "Is this the correct book? (y/n): ";
                        std::cin >> check;
                        if (check == "Y" || check == "y") {
                            currentAdm.deleteEBook(stoll(tempISBN));
                            break;
                        }
                        else if (check == "N" || check == "n") {
                        }
                        // Error Handling
                        else {
                            std::cout << "Please enter y or n\n";
                            break;
                        }
                    }
                    else {
                        std::cout << "Please enter P or E\n";
                    }
                    break;
                // Add user
                case 6:
                    std::cin.ignore();
                    std::cout << "Please enter name: ";
                    std::getline(std::cin, tempName);
                    std::cout << "Please enter ID: ";
                    std::cin >> tempID;
                    currentAdm.addUser(tempName, stoi(tempID));
                    break;
                // Delete user
                case 7:
                    std::cout << "Enter ID of user you would like to delete: ";
                    std::cin >> tempID;
                    currentAdm.searchUserI(stoi(tempID));
                    std::cout << "Is this the correct user? (y/n): ";
                    std::cin >> check;
                    if (check == "Y" || check == "y") {
                        currentAdm.deleteUser(stoi(tempID));
                        break;
                    }
                    else if (check == "N" || check == "n") {
                    }
                    // Error Handling
                    else {
                        std::cout << "Please enter y or n\n";
                        break;
                    }
                    break;
                // Logout
                case 8:
                    std::cout << "Logging out";
                    currentAdm.books.close();
                    currentAdm.logout();
                    return 0;
                    break;
                // Default case
                default:
                    std::cout << "Please enter number 1-8\n";
                    break;
            }
        }
    }

    // Login for User
    else {
        currentUser = tempUser.login(stoi(tempID));
        if (currentUser.getName() == "") {
            std::cout << "ID was not found.  Quitting Program.";
            return 1;
        }
        std::cout << "Welcome " << currentUser.getName() << "\n";

        int choice = 0;
        int lp = 0;
        while (lp == 0) {
            // Determine which function user would like to use
            std::cout << "What would you like to do:\n"
            << "1: Display current user info\n"
            << "2: Search for book\n"
            << "3: Checkout book\n"
            << "4: Return book\n"
            << "5: Logout\n";
            std::cin >> choice;
            switch (choice) {
                // Display current user info
                case 1:
                    currentUser.display();
                    break;
                // Search for book
                case 2:
                    // Figure out type of book for search
                    std::cout << "Which type of book would you like to search for?\n"
                    << "Enter 'E' for EBook\n"
                    << "Enter 'P' for Printed Book\n";
                    std::cin >> type;
                    //Figure out how they would like to search
                    std::cout << "How would you like to search for book?\n"
                    << "Enter 'T' for Title\n"
                    << "Enter 'A' for Author\n"
                    << "Enter 'I' for ISBN\n";
                    std::cin >> searchBy;
                    // Search EBooks
                    if (type == "E" || type == "e") {
                        // Search by title
                        if (searchBy == "T" || searchBy == "t") {
                            std::cout << "Please enter title of book: ";
                            std::cin >> tempTitle;
                            currentUser.searchEBookT(tempTitle);
                        }
                        // Search by author
                        else if (searchBy == "A" || searchBy == "a") {
                            std::cout << "Please enter author's name: ";
                            std::cin >> tempAuthor;
                            currentUser.searchEBookA(tempAuthor);
                        }
                        // Search by ISBN
                        else if (searchBy == "I" || searchBy == "i") {
                            std::cout << "Please enter ISBN (No dashes): ";
                            std::cin >> tempISBN;
                            currentUser.searchEBookI(stoll(tempISBN));
                        }
                        // Error handler
                        else {
                            std::cout << "Please enter T, A, or I\n";
                        }
                    }
                    // Search PrintedBooks
                    else if (type == "P" || type == "p") {
                        // Search by title
                        if (searchBy == "T" || searchBy == "t") {
                            std::cout << "Please enter title of book: ";
                            std::cin >> tempTitle;
                            currentUser.searchPrintBookT(tempTitle);
                        }
                        // Search by author
                        else if (searchBy == "A" || searchBy == "a") {
                            std::cout << "Please enter author's name: ";
                            std::cin >> tempAuthor;
                            currentUser.searchPrintBookA(tempAuthor);
                        }
                        // Search by ISBN
                        else if (searchBy == "I" || searchBy == "i") {
                            std::cout << "Please enter ISBN (No dashes): ";
                            std::cin >> tempISBN;
                            currentUser.searchPrintBookI(stoll(tempISBN));
                        }
                        // Error handler
                        else {
                            std::cout << "Please enter T, A, or I\n";
                        }
                    }
                    // Error handler
                    else {
                        std::cout << "Please enter E or P\n";
                    }
                    break;
                // Checkout book
                case 3:
                    // Determine type of book
                    std::cout << "Please enter type of book you would like to checkout\n"
                    << "Enter 'E' for EBook\n"
                    << "Enter 'P' for Printed Book\n";
                    std::cin >> type;
                    while (lp == 0) {
                        // Ebook Checkout
                        if (type == "E" || type == "e") {
                            std::cout << "Please enter ISBN of book you would like to check out: ";
                            std::cin >> tempISBN;
                            currentUser.searchEBookI(stoll(tempISBN));
                            std::cout << "Is book above correct? (y/n): ";
                            std::cin >> check;
                            // Checkout Book
                            if (check == "Y" || check == "y") {
                                currentUser.checkoutEBook(stoll(tempISBN));
                                break;
                            }
                            // Ask for ISBN again
                            else if (check == "N" || check == "n") {
                            }
                            // Error Handling
                            else {
                                std::cout << "Please enter y or n\n";
                                break;
                            }
                        }
                        // Printed book checkout
                        else if (type == "P" || type == "p") {
                            std::cout << "Please enter ISBN of book you would like to check out: ";
                            std::cin >> tempISBN;
                            currentUser.searchPrintBookI(stoll(tempISBN));
                            std::cout << "Is book above correct? (y/n): ";
                            std::cin >> check;
                            // Checkout Book
                            if (check == "Y" || check == "y") {
                                currentUser.checkoutPBook(stoll(tempISBN));
                                break;
                            }
                            // Ask for ISBN again
                            else if (check == "N" || check == "n") {
                            }
                            // Error Handling
                            else {
                                std::cout << "Please enter y or n\n";
                                break;
                            }
                        }
                        // Error Handling
                        else {
                            std::cout << "Please enter E or P\n";
                        }
                    }
                    break;
                // Return book
                case 4:
                    // Determine type of book
                    std::cout << "Please enter type of book you would like to return\n"
                    << "Enter 'E' for EBook\n"
                    << "Enter 'P' for Printed Book\n";
                    std::cin >> type;
                    // Ebook Checkout
                    if (type == "E" || type == "e") {
                        std::cout << "Please enter ISBN of book you would like to return: ";
                        std::cin >> tempISBN;
                        currentUser.searchEBookI(stoll(tempISBN));
                        std::cout << "Is book above correct? (y/n): ";
                        std::cin >> check;
                        // Checkout Book
                        if (check == "Y" || check == "y") {
                            currentUser.returnEBook(stoll(tempISBN));
                            break;
                        }
                        // Ask for ISBN again
                        else if (check == "N" || check == "n") {
                        }
                        // Error Handling
                        else {
                            std::cout << "Please enter y or n\n";
                            break;
                        }
                        break;
                    }
                    // Printed Book Checkout
                    else if (type == "P" || type == "p") {
                        std::cout << "Please enter ISBN of book you would like to return: ";
                        std::cin >> tempISBN;
                        currentUser.searchPrintBookI(stoll(tempISBN));
                        std::cout << "Is book above correct? (y/n): ";
                        std::cin >> check;
                        // Checkout Book
                        if (check == "Y" || check == "y") {
                            currentUser.returnPBook(stoll(tempISBN));
                            break;
                        }
                        // Ask for ISBN again
                        else if (check == "N" || check == "n") {
                        }
                        // Error Handling
                        else {
                            std::cout << "Please enter y or n\n";
                            break;
                        }
                        break;
                    }
                    else {
                        std::cout << "Please enter E or P\n";
                        break;
                    }
                    break;
                // Logout
                case 5:
                    std::cout << "Logging out";
                    currentUser.books.close();
                    currentUser.users.close();
                    return 0;  // dynamic memory delete?
                    break;
                // Default case
                default:
                    std::cout << "Please enter number 1-6\n";
                    break;
            }
        }
    }
}