#include <iostream>
#include "book.h"
using namespace std;

// Set book information
void Book::setBookDetails(string t, string a, string id, string date) {
    title = t;
    author = a;
    ISBN = id;
    dateAdd = date;
    availability = true;
}

// Get book ISBN
string Book::getISBN() const {
    return ISBN;
}

// Display book information
void Book::displayBookDetails() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Date Added: " << dateAdd << endl;

    if (availability == true) {
        cout << "Status: Available" << endl;
    } else {
        cout << "Status: Borrowed" << endl;
    }
}

// Borrow a book
void Book::borrowBook() {
    if (availability == true) {
        availability = false;
        cout << "Book borrowed successfully!" << endl;
    } else {
        cout << "Book is already borrowed!" << endl;
    }
}

// Return a book
void Book::returnBook() {
    if (availability == false) {
        availability = true;
        cout << "Book returned successfully!" << endl;
    } else {
        cout << "Book is already available!" << endl;
    }
}


// Sort books using Insertion Sort
void Book::sortBookData(Book books[], int size) {

    for (int i = 1; i < size; i++) {

        Book key = books[i];
        int j = i - 1;

        while (j >= 0 && books[j].ISBN > key.ISBN) {
            books[j + 1] = books[j];
            j--;
        }

        books[j + 1] = key;
    }
}
