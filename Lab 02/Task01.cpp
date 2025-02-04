//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

struct Book{
    string title;
    string author;
    int year;
};

int main (){

    int numofBooks;
    cout << "Enter the number of books: ";
    cin >> numofBooks;

    Book *books = new Book[numofBooks];

    for (int i = 0; i < numofBooks; i++)
    {
        cout << "Enter details for book "<< i+1 << endl;
        cout << "Title: ";
        cin >> books[i].title;
        cout << "Author: ";
        cin >> books[i].author;
        cout << "Year: ";
        cin >> books[i].year;
    }    

        int findYear;
        cout << "Enter the year to find published books after it: ";
        cin >> findYear;
        
        cout << "Books published after " << findYear << endl;
        bool found = false;
        for (int i = 0; i < numofBooks; i++)
        {
            if(books[i].year > findYear)
            {
              cout << "Title: " << books[i].title<< endl;
              cout << "Author: " << books[i].author << endl;
              cout << "Year: " << books[i].year << endl;
              found=true;
            }
        }

        if (!found)
        {
            cout << "No books published after "<< findYear<<endl;
        }

        delete[] books;
        return 0;
}

