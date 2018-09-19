/* Brendan Palkowski / CPS 171 / December 17th, 2017
This program uses classes for an ADT on book information. The book information is stored into an 
array. The information is taken from an infile. Each index holds a title, number of authors, 
authors (up to 4), publisher, ISBN, price, and number of copies. This program will 
print an unsorted array, and after a sorted array in alphabetical order by selection 
sort. Then there is a transaction section with it's own infile. This transaction file
feeds the program a leading Token and content following it. This program identifies 
what the leading token needs to do for operations and then operates based on the
trailing content. These tokens will ask to print a sorted array, title with no. copies
, ISBN with no. copies, set copies to int based on ISBN passed, reduce copies by int
based on ISBN, add copies by int based on ISBN, and new title with trailing book info,
and lastly print any book written by the author. Output can be found in the console window.
Assumptions are that the information given will not exceed the 50 indexes of the array. The use
of functions is quite heavy here; I tried to keep their names relative to their use. 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "mp7book.h"

using namespace std;
string Removechar(string isb, char c)  //Rid of hyphen
{
	string result;
	for (size_t i = 0; i < isb.size(); i++)
	{
		char currentChar = isb[i];
		if (currentChar != c)
			result += currentChar;
	}
	return result;
}

const int SIZE = 50;
int main()
{
	BookType book[SIZE] = {}, book_sort[SIZE] = {}, book_t[SIZE] = {};
	ifstream inFile, inFile_T;
	inFile.open("mp7data.txt");

	string title;
	int num_auth;
	string publish;
	string isbn, isbn_clean;
	float price;
	int copies;
	string authors[4];

	int i = 0;
	while (!inFile.eof())
	{
		getline(inFile, title);
		inFile >> num_auth;
		for (int j = 0; j < num_auth; j++)
		{
			if (j == 0) {
				inFile.ignore(); 
			}
			getline(inFile, authors[j]);
		}
		getline(inFile, publish);
		getline(inFile, isbn);
		isbn_clean = Removechar(isbn, '-');
		inFile >> price;
		inFile.ignore();
		inFile >> copies;
		inFile.ignore();
		book[i].load_book(title, num_auth, publish, isbn_clean, price, copies, authors);
		// this will iterate on each pass and update the new book array index to populate a new book
		i++;
	}
	cout << "**************************** UNSORTED ***************************" << endl;
	for (int i = 0; i < 12; i++)
	{
		book[i].ret_book(title, num_auth, publish, isbn, price, copies, authors);
		cout << endl;
	}
	cout << "******************* SORTED ****************" << endl;
	book[12].sorted_array(book, book_sort);
	book[12].selecsort(book_sort, SIZE);
	for (int i = 0; i < 12; i++)
	{
		book_sort[i].ret_book(title, num_auth, publish, isbn, price, copies, authors);
		cout << endl;
	}

	cout << "****************** MOVING TO TRANSACTION SECTION*********************" << endl;
	inFile_T.open("mp7trans.txt");  
	char userinput_c;
	int token_9, token_15, token_16int, token_17int, token_18int;
	float token_14;
	string userinput[SIZE] = {},
		t_sub, userinput_s,
		token_7, title_t,
		token_1, token_2, token_3,
		token_4, token_5, token_6, token_8, token_10, token_11, token_12, token_13, token_16,
		token_17, token_18, token_19, token_20, token_21, token_22;
	book[13].sorted_trans(book, book_t);
	book[13].selecsort(book_t, SIZE);
	while (!inFile_T.eof())
	{
		inFile_T >> token_1;
		inFile_T.ignore();
		getline(inFile_T, token_2);
		getline(inFile_T, token_3);
		getline(inFile_T, token_4);
		getline(inFile_T, token_5);
		getline(inFile_T, token_6);
		inFile_T >> token_7;
		inFile_T.ignore();
		getline(inFile_T, token_8); 
		inFile_T >> token_9; 
		inFile_T.ignore();
		getline(inFile_T, token_10);
		getline(inFile_T, token_11);
		getline(inFile_T, token_12);
		getline(inFile_T, token_13);
		inFile_T >> token_14; 
		inFile_T.ignore();
		inFile_T >> token_15; 
		inFile_T.ignore();
		getline(inFile_T, token_16); 
		getline(inFile_T, token_17); 
		getline(inFile_T, token_18); 
		getline(inFile_T, token_19); 
		getline(inFile_T, token_20); 
		getline(inFile_T, token_21); 
		inFile_T >> token_22;
	}
	title = token_8; 
	num_auth = token_9; 
	authors[0] = token_10; 
	authors[1] = token_11; 
	publish = token_12; 
	isbn = token_13; 
	price = token_14;
	copies = token_15; 

	// Implements new book
	book_t[13].load_book(title, num_auth, publish, isbn_clean, price, copies, authors);
	book_t[13].selecsort(book_t, SIZE);                                               
	cout << "****************FIRST P READ**********************" << endl;
	for (int i = 0; i < 12; i++)
	{
		book_sort[i].ret_book(title, num_auth, publish, isbn, price, copies, authors);
		cout << endl;
	}
	
	string token_2c = token_2.substr(0, 1);
	string token_2s = token_2.substr(2, token_2.length());  //Token "T"
	book_t[8].display_t_onsorted(token_2s, book_t);
	cout << endl;

	string token_3c = token_3.substr(0, 1);
	string token_3s = token_3.substr(2, token_3.length());  
	book_t[3].display_t_onsorted(token_3s, book_t);          //Token "T"
	cout << endl;

	string token_4c = token_4.substr(0, 1);
	string token_4s = token_4.substr(2, token_4.length());  
	book_t[11].display_i_onsorted(token_4s, book_t);         //Token "I"
	cout << endl;

	string token_5c = token_5.substr(0, 1);
	string token_5s = token_5.substr(2, token_5.length());  
	book_t[11].display_i_onsorted(token_5s, book_t);       //Token "I"
	cout << endl;

	string token_6c = token_6.substr(0, 1);
	string token_6s = token_6.substr(2, token_6.length());  
	token_6s = Removechar(token_6s, '-');                    //Token "I"
	book_t[8].display_i_onsorted(token_6s, book_t);
	cout << endl;

	cout << endl;
	cout << "***************** N READ ****************" << endl;
	for (int i = 0; i < 13; i++)  //"N" Read
	{
		book_t[i].ret_book(title, num_auth, publish, isbn, price, copies, authors);  
		cout << endl;
	}
	// "************* ADD, SUB, SET FOR COPIES *************" ;
	string token_16c = token_16.substr(0, 1);
	string token_16s = token_16.substr(2, 15);
	token_16s = Removechar(token_16s, '-');
	string token_16i = token_16.substr(18, token_16.length());
	istringstream(token_16i) >> token_16int;
	book[6].display_r_onsorted(token_16s, book_t, token_16int);

	string token_17c = token_17.substr(0, 1);
	string token_17s = token_17.substr(2, 13);
	string token_17i = token_17.substr(15, token_17.length());
	istringstream(token_17i) >> token_17int;
	book[11].set_numcop(token_17s, book_t, token_17int);

	string token_18c = token_18.substr(0, 1);
	string token_18s = token_18.substr(2, 13);
	string token_18i = token_18.substr(15, token_18.length());
	istringstream(token_18i) >> token_18int;
	book[5].add_numcop(token_18s, book_t, token_18int);
	
	cout << "******************RETURNING W'S *******************" << endl;
	string token_19c = token_19.substr(0, 1);
	string token_19s = token_19.substr(2, token_19.length());  
	book_t[3].return_books(token_19s, book_t);
	cout << endl;
	string token_20c = token_20.substr(0, 1);
	string token_20s = token_20.substr(2, token_20.length());
	book_t[12].return_books(token_20s, book_t);
	cout << endl;
	string token_21c = token_21.substr(0, 1);
	string token_21s = token_21.substr(2, token_21.length());
	book_t[1].return_books(token_21s, book_t);
	cout << endl;
	cout << endl;
	
	cout << "******************* LAST P READ *****************" << endl;
	if (token_22 == "P")
	{
		for (int i = 0; i < 13; i++)
		{
			book_t[i].ret_book(title, num_auth, publish, isbn, price, copies, authors);
			cout << endl;
		}
	}

	return 0;
}
