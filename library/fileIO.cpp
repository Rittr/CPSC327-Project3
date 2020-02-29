#include "../includes_usr/fileIO.h"
#include <fstream>
#include <sstream>
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
		int bookID;
		string title;
		string author;
		book_checkout_state state;
		int loanerID;

		//int numLine = 0;
		string line;
		while (!fileToBooks.eof()) {
			getline(fileToBooks, line);
			istringstream ss(line);
			ss >> bookID >> title >> author >> state >> loanerID;
			//books[numLine] << line;
			books.emplace_back(bookID, title, author, state, loanerID);


			//numLine++;
			//I'll probably have to be more specific about where this line is going
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
	return SUCCESS;
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
	return SUCCESS;
}
