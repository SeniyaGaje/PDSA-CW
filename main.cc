#include "include/System.h"
#include <iostream>
#include <limits>
#include <string> 
void clearCin() {
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

void printHeader() {
    // ANSI escape codes for color
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";

    std::cout << RED << R"(
  _     _ _                                _   _                                      
 | |   (_) |                              | | (_)                                     
 | |    _| |__  _ __ __ _ _ __ _   _    __| |  _ _ __   __ _                          
 | |   | | '_ \| '__/ _` | '__| | | |  / _` | | | '_ \ / _` |                         
 | |___| | |_) | | | (_| | |  | |_| | | (_| | | | | | | (_| |                         
 |______|_|_.__/|_|  \__,_|_|   \__, |  \__,_| |_|_| |_|\__, |                         
                                __/ |                    __/ |                         
                               |___/                    |___/                          
)" << RESET << '\n';
    std::cout << GREEN << "Welcome to the Library Management System\n" << RESET;
    std::cout << YELLOW << "--------------------------------\n" << RESET;
    std::cout << CYAN << "This system allows you to manage books and students.\n"
              << "You can create, view, issue, and return books.\n"
              << "Students can be registered and managed easily.\n" << RESET;
    std::cout << YELLOW << "--------------------------------\n" << RESET;
}

int main() {
    System librarySystem;
    int choice;
    std::string author, publication;

    do {
        printHeader();
        std::cout << "Library Management System\n";
        std::cout << "--------------------------------\n";
        std::cout << "1. Create Book\n";
        std::cout << "2. Show Book\n";
        std::cout << "3. Create Student\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Search Books by Author\n";
        std::cout << "7. Search Books by Publication\n";
        std::cout << "8. Check Book Availability\n";
        std::cout << "9. Exit\n";
        std::cout << "--------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearCin(); 

        int bno, admno, quant;
        std::string bname, aname, pname, sname;

        switch (choice) {
            case 1: {
                std::cout << "\n-- Create New Book --\n";
                std::cout << "Enter book number: ";
                std::cin >> bno;
                std::cout << "Enter quantity: ";
                std::cin >> quant;
                clearCin(); 
                std::cout << "Enter book name: ";
                getline(std::cin, bname);
                std::cout << "Enter author name: ";
                getline(std::cin, aname);
                std::cout << "Enter publication name: ";
                getline(std::cin, pname);
                librarySystem.createBook(bno, quant, bname, aname, pname);
                break;
            }
            case 2:
                std::cout << "\n-- Show Book Details --\n";
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                librarySystem.showBook(bno);
                break;
            case 3: {
                std::cout << "\n-- Register New Student --\n";
                std::cout << "Enter student name: ";
                getline(std::cin, sname);
                std::cout << "Enter student admission number: ";
                std::cin >> admno;
                clearCin();
                librarySystem.createStudent(sname, admno);
                break;
            }
            case 4:
                std::cout << "\n-- Issue Book to Student --\n";
                std::cout << "Enter student admission number: ";
                std::cin >> admno;
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                librarySystem.issueBook(admno, bno);
                break;
            case 5:
                std::cout << "\n-- Return Book --\n";
                std::cout << "Enter student admission number: ";
                std::cin >> admno;
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                librarySystem.returnBook(admno, bno);
                break;

            case 6:
                std::cout << "\n-- Search Books by Author --\n";
                std::cout << "Enter author name: ";
                getline(std::cin, author);
                librarySystem.searchBooksByAuthor(author);
                break;


            case 7:
                std::cout << "\n-- Search Books by Publication --\n";
                std::cout << "Enter publication name: ";
                getline(std::cin, publication);
                librarySystem.searchBooksByPublication(publication);
                break;

            case 8:
                std::cout << "\n-- Check Book Availability --\n";
                std::cout << "Enter book number: ";
                std::cin >> bno;
                clearCin();
                if (librarySystem.checkBookAvailability(bno)) {
                    std::cout << "Book is available.\n";
                } else {
                    std::cout << "Book is not available.\n";
                }
                break;

            case 9:
                std::cout << "\nExiting...\n";
                break;
            default:
                std::cout << "\nInvalid choice, please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
