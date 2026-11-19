
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability = true;
    string dateAdd;

public:
    void setBookDetails(string t, string a,
                        string id, string date);

    void displayBookDetails() const;
    void borrowBook();
    void returnBook();
    string getISBN() const;

    static void sortBookData(Book books[], int size);
};

#endif
