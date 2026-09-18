#include <iostream>
#include <string>

using namespace std;

struct Book
{
    int id;
    string name;
    string author;

    void inputInfo()
    {
        cin >> id;
        cin >> name;
        cin >> author;
    }

    void outputInfo()
    {
        cout << id << " ";
        cout << name << " ";
        cout << author << endl;
    }
};

struct Library
{
    int idLibrary;
    string nameLibrary;
    int numBooks;

    Book books[100];

    void inputLibrary()
    {
        cin >> idLibrary;
        cin >> nameLibrary;
        cin >> numBooks;

        for (int i = 0; i < numBooks; i++)
        {
            cin >> books[i].id;
            cin >> books[i].name;
            cin >> books[i].author;
        }
    }

    void outputLibrary()
    {
        cout << idLibrary << " ";
        cout << nameLibrary << endl;

        for (int i = 0; i < numBooks; i++)
        {
            books[i].outputInfo();
        }
    }

    // Thêm một quyển sách
    void addBook(Book a)
    {
        books[numBooks] = a;
        numBooks++;
    }

    // Tìm và trả về thông tin sách theo ID
    Book getBookInfo(int idBook)
    {
        for (int i = 0; i < numBooks; i++)
        {
            if (books[i].id == idBook)
            {
                return books[i];
            }
        }

        // Không tìm thấy
        Book emptyBook;
        emptyBook.id = -1;
        return emptyBook;
    }

    // Trả về danh sách các sách
    Book* getBooks()
    {
        return books;
    }
};


int main()
{
    Library library;

    library.inputLibrary();
    library.outputLibrary();

    return 0;
}
