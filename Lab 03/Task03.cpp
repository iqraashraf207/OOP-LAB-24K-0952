//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;

class Library{
private:
    string bookList[MAX_BOOKS];
    string borrowedBooks[MAX_BOOKS];
    bool availableBooks[MAX_BOOKS];
    int totalBooks;
    int totalBorrowed;

public:
    Library(){
        totalBooks = 0;
        totalBorrowed = 0;
    }

    void addBook(string bookName){
        if (totalBooks < MAX_BOOKS){
            bookList[totalBooks] = bookName;
            availableBooks[totalBooks] = true;
            totalBooks++;
            cout << bookName << " book added succesfully." << endl;
        } else{
            cout << "Cannot add more books." << endl;
        }
    }

    void displayBooks(){
        cout << "Available Books:" << endl;
        for (int i = 0; i < totalBooks; i++)
        {
            if (availableBooks[i]){
                cout << i + 1 << ". " << bookList[i] << endl;
            }
        }
    }

    void lendBook(string bookName){
        for (int i = 0; i < totalBooks; i++)
        {
            if (bookList[i] == bookName && availableBooks[i]){
                availableBooks[i] = false;
                borrowedBooks[totalBorrowed] = bookName;
                totalBorrowed++;
                cout << bookName << " book has been borrowed." << endl;
                return;
            }
        }
        cout << bookName << " book is not available." << endl;
    }

    void returnBook(string bookName){
        for (int i = 0; i < totalBorrowed; i++)
        {
            if (borrowedBooks[i] == bookName){
                borrowedBooks[i] = borrowedBooks[totalBorrowed - 1];
                totalBorrowed--;
                for (int j = 0; j < totalBooks; j++)
                {
                    if (bookList[j] == bookName){
                        availableBooks[j] = true;
                        break;
                    }
                }
                cout << bookName << " book has been returned." << endl;
                return;
            }
        }
        cout << bookName << " book was not borrowed." << endl;
    }
};

int main(){
    Library lib;

    lib.addBook("Introduction to C Language");
    lib.addBook("Calculus 11th Edition");
    lib.addBook("DaVinci Code");
    lib.displayBooks();

    lib.lendBook("Calculus 11th Edition");
    lib.lendBook("DaVinci Code");
    lib.displayBooks();

    lib.returnBook("Calculus 11th Edition");
    lib.displayBooks();

    return 0;
}