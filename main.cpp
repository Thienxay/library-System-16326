
#include <iostream>
#include "book.h"
using namespace std;

int main() {

    Book books[5];

    books[0].setBookDetails("C++ Basics", "John", "1003", "2026-01-10");
    books[1].setBookDetails("Python Guide", "Mary", "1001", "2026-02-12");
    books[2].setBookDetails("Data Structures", "David", "1005", "2026-03-15");
    books[3].setBookDetails("Web Development", "Anna", "1002", "2026-04-20");
    books[4].setBookDetails("Algorithms", "James", "1004", "2026-05-25");

    Book::sortBookData(books, 5);

    string choice;
    string isbn;

    while (true) {

        cout << "\n===== LIBRARY SYSTEM =====" << endl;
        cout << "1. Borrow Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            break;
        }

        if (choice == "3") {
            break;
        }

        if (choice != "1" && choice != "2") {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "Enter ISBN (0 to exit): ";

        if (!(cin >> isbn)) {
            break;
        }

        if (isbn == "0") {
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {

            if (books[i].getISBN() == isbn) {

                found = true;

                if (choice == "1") {
                    books[i].borrowBook();
                } else {
                    books[i].returnBook();
                }

                books[i].displayBookDetails();

                break;
            }
        }

        if (found == false) {
            cout << "Book not found!" << endl;
        }
    }

    cout << "Program ended." << endl;

    return 0;
}
