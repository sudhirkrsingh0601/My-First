#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    bool available;

public:
    Book(string title, string author) : title(title), author(author), available(true) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailability(bool avail) {
        available = avail;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        cout << "Books available in the library:" << endl;
        for (const Book& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor();
            if (book.isAvailable()) {
                cout << " (Available)" << endl;
            } else {
                cout << " (Not Available)" << endl;
            }
        }
    }

    void borrowBook(const string& title) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) {
            return b.getTitle() == title && b.isAvailable();
        });

        if (it != books.end()) {
            it->setAvailability(false);
            cout << "You have borrowed the book: " << title << endl;
        } else {
            cout << "Book \"" << title << "\" is not available for borrowing." << endl;
        }
    }

    void returnBook(const string& title) {
        auto it = find_if(books.begin(), books.end(), [&](const Book& b) {
            return b.getTitle() == title && !b.isAvailable();
        });

        if (it != books.end()) {
            it->setAvailability(true);
            cout << "You have returned the book: " << title << endl;
        } else {
            cout << "Book \"" << title << "\" cannot be returned." << endl;
        }
    }
};

int main() {
    Library library;

    // Add some initial books to the library
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    library.addBook(Book("1984", "George Orwell"));

    int choice;
    string title;

    cout << "Welcome to the Library Management System!" << endl;
    do {
        cout << "\nMenu:\n1. Display Books\n2. Borrow Book\n3. Return Book\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2:
                cout << "Enter the title of the book you want to borrow: ";
                cin.ignore();
                getline(cin, title);
                library.borrowBook(title);
                break;
            case 3:
                cout << "Enter the title of the book you want to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;
            case 4:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
