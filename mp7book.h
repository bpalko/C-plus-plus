#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class BookType
{
public:

	BookType::BookType();  //construc
	bool load_book(string t, int numau, string pub, 
				   string isbn_num, float p, int numC, string auth[]);
	void ret_book(string& t_out, int& numau_out, string& pub_out,
				  string& isbn_num_out, float& p_out, int& numC_out, string autho[]);
	void BookType::set_numcop(string i, BookType b[], int c);
	void BookType::add_numcop(string i, BookType book_srt[], int co);
	string Removechar(string isb, char c);
	void selecsort(BookType book[], int s);
	void BookType::display_t_onsorted(string t, BookType book_srt[]);
	void if_p(BookType book_sort[]);
	void BookType::sorted_array(BookType book[], BookType book_s[]);
	void BookType::display_i_onsorted(string i, BookType book_srt[]);
	void BookType::sorted_trans(BookType book[], BookType book_t[]);
	string num_to(string userinput, int num_a);
	void BookType::display_r_onsorted(string i, BookType book_srt[], int co);
	void BookType::return_books(string auth, BookType b[]);
private:
	string title;
	int num_auth;
	string publish;
	string isbn;
	float price;
	int copies;
	string authors[4];

};