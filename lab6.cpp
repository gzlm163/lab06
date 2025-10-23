
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct sBook {
  string surnameAuthor; 
  string nameBook;
  int yearOfRelease;
  int countBooks;
  double price; 
};

int main() {
  int booksCount;
  string authorSurname;  
  double theTotalCostOfBooksByThisAuthor;
  int minYearOfRelease;
  string oldestBook;
  sBook bookList[99];

  cout << " Books Count = ";
  cin >> booksCount;
  cout << " Enter the author's last name: ";
  cin >> authorSurname;
  
  theTotalCostOfBooksByThisAuthor = 0.0;
  minYearOfRelease = 3000;
  
  ifstream fin("file.txt");
  ofstream fout("fileOut.txt");
  
  cout << " Books by this author: " << endl;
  fout << " Books by this author: " << endl;

  if (fin.is_open() == 0) {
    cout << " Error of Open " << endl;
  } else {
    for (int bookIndex = 0; bookIndex < booksCount; ++bookIndex) {
      fin >> bookList[bookIndex].surnameAuthor
          >> bookList[bookIndex].nameBook
          >> bookList[bookIndex].yearOfRelease
          >> bookList[bookIndex].countBooks
          >> bookList[bookIndex].price;
       
      if (bookList[bookIndex].surnameAuthor == authorSurname) {
        cout << " " << bookList[bookIndex].nameBook << endl;
        fout << " " << bookList[bookIndex].nameBook << endl;
        
        theTotalCostOfBooksByThisAuthor += bookList[bookIndex].price;
        
	  }
	  
      if (bookList[bookIndex].yearOfRelease < minYearOfRelease) {
	    minYearOfRelease = bookList[bookIndex].yearOfRelease;
        oldestBook = bookList[bookIndex].nameBook;
        
	  }   
    }
    
    cout << " The total cost of books by this author = " << theTotalCostOfBooksByThisAuthor << "  " << " The oldest book: " << oldestBook;
    fout << " The total cost of books by this author = " << theTotalCostOfBooksByThisAuthor << "  " << " The oldest book: " << oldestBook;

    fin.close();
    fout.close();
    
  }

  return 0;
}