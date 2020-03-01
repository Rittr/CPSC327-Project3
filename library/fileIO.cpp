#include "../includes_usr/fileIO.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	books.clear();

	ifstream fileToBooks;
	fileToBooks.open(filename, ios::in);
	if (fileToBooks.is_open()) {
		book nextBook;
		int bookID;
		string title;
		string author;
		int stateInt;
		book_checkout_state state;
		int loanerID;

		//int numLine = 0;
		string line;
		string substr;
		while (!fileToBooks.eof()) {

			getline(fileToBooks, line);

			istringstream ss(line);

			getline(ss, substr, ',');
//			nextBook.book_id = substr;
			getline(ss, substr, ',');
			nextBook.title = substr;
			getline(ss, substr, ',');
			nextBook.author = substr;
			getline(ss, substr, ',');
			//stateInt = stoi(substr);
//			nextBook.state = book_checkout_state(stateInt);
			nextBook.state = IN;
			getline(ss, substr);
//			nextBook.loaned_to_patron_id = stoi(substr);

			//fileToBooks >> bookID >> title >> author >> state >> loanerID;

//			nextBook.book_id = bookID;
//			nextBook.title = title;
//			nextBook.author = author;
//			nextBook.state = state;
//			nextBook.loaned_to_patron_id = loanerID;

			books.push_back(nextBook);

//			ss >> bookID >> title >> author >> state >> loanerID;
		}
		if (books.size() < 1) {
			return NO_BOOKS_IN_LIBRARY;
		}
		return SUCCESS;
	}
		return COULD_NOT_OPEN_FILE;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	if (books.size() < 1){
		return NO_BOOKS_IN_LIBRARY;
	}
	fstream booksToFile;
	booksToFile.open(filename, ios::out | ios::binary | ios::trunc);
	if (booksToFile.is_open()) {
		for (int i = 0; i < books.size(); i++) {
//			patronsToFile << patrons[i].patron_id << ",";
			booksToFile << books[i].book_id << ","
					<< books[i].title << ","
					<< books[i].author << ","
					<< books[i].state << ","
					<< books[i].loaned_to_patron_id << endl;

		}

		booksToFile.close();
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	patrons.clear();

	ifstream fileToPatrons;
	fileToPatrons.open(filename, ios::in);
	if (fileToPatrons.is_open()) {
		string line;
		while (!fileToPatrons.eof()) {
			getline(fileToPatrons, line);
			//patrons << line;
			//I'll probably have to be more specific about where this line is going
		}
		if (patrons.size() < 1) {
			return NO_PATRONS_IN_LIBRARY;
		}
		return SUCCESS;
	}
		return COULD_NOT_OPEN_FILE;

}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	if (patrons.size() < 1) {
		return NO_PATRONS_IN_LIBRARY;
	}
	fstream patronsToFile;
	patronsToFile.open(filename, ios::out | ios::binary | ios::trunc);
	if (patronsToFile.is_open()) {
		for (int i = 0; i < patrons.size(); i++) {
			patronsToFile << patrons[i].patron_id << ",";
			patronsToFile << patrons[i].name << ",";
			patronsToFile << patrons[i].patron_id << endl;
		}

		patronsToFile.close();
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE;

}
