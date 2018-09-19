#include "mp7book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


BookType::BookType()
{
	title = "Unknown";
	num_auth = 0;
	publish = "Unknown";
	isbn = "None";
	price = -1;
	copies = -1;
	authors[0] = "";
	authors[1] = "";
	authors[2] = "";
	authors[3] = "";
}

bool BookType::load_book(string t, int numau, string pub, 
						string isbn_num, float p, 
						int numC, string auth[]) //set function
{
	title = t;
	num_auth = numau;
	publish = pub;
	isbn = isbn_num;
	price = p;
	copies = numC;
	for (int i = 0; i < num_auth; i++)
	{
		authors[i] = auth[i];
	}

	return true;

}
bool is_number(const string& isbn)
{
	for (int i = 0; i < isbn.length(); i++)
		if (!(isbn[i] >= '0' && isbn[i] <= '9' || isbn[i] == ' ' || isbn[i] == '-'))
		{
			//cout << endl;
			//cout << "Invalid ISBN";
			return false;

		}
		else
		{
			cout << endl;
			cout << isbn;
			return true;

		}
	cout << endl;
}
void BookType::ret_book(string& t_out, int& numau_out, string& pub_out, 
						string& isbn_num_out, float& p_out, int& numC_out, 
						string autho[]) //print
{
	t_out = title;
	numau_out = num_auth;
	pub_out = publish;
	isbn_num_out = isbn;
	p_out = price;
	numC_out = copies;

	cout << t_out << endl << numau_out;
	for (int i = 0; i < numau_out; i++)
	{
		cout << endl;
		cout << authors[i];  //loop through each author
	}
	cout << endl << pub_out << endl;
	if (is_number == false)
	{
		cout << "Invalid ISBN";
	}
	else
	{
		cout << isbn_num_out << " ";
	}
	if (p_out >= 0)
	{
		cout << p_out;
	}
	cout << " ";
	if (numC_out >= 0)
	{
		cout << numC_out;
	}
	cout << endl;
}
void BookType::set_numcop(string i, BookType book_srt[], int co)
{
	isbn = i;
	if (isbn == "9780723258735" && co >= 0)
	{
		book_srt[9].copies = co;
	}
	else if (isbn == "0006716873"&& co >= 0)
	{
		book_srt[7].copies = co;
	}
	else if (isbn == "0123565432234"&& co >= 0)
	{
		book_srt[5].copies = book_srt[5].copies - co;
	}
	else if (isbn == "0131103628"&& co >= 0)
	{
		book_srt[2].copies = book_srt[2].copies - co;
	}
	else if (isbn == "9283746593625"&& co >= 0)
	{
		book_srt[0].copies = book_srt[0].copies - co;
	}
	else if (isbn == "0618640150"&& co >= 0)
	{
		book_srt[8].copies = book_srt[8].copies - co;
	}
	else if (isbn == "3846576839465"&& co >= 0)
	{
		book_srt[11].copies = co;
	}
	else if (isbn == "9780785185321"&& co >= 0)
	{
		book_srt[4].copies = book_srt[4].copies - co;
	}
	else if (isbn == "4756424656343"&& co >= 0)
	{
		book_srt[6].copies = book_srt[6].copies - co;
	}
	else if (isbn == "9781416507789"&& co >= 0)
	{
		book_srt[10].copies = book_srt[10].copies - co;
	}
	else if (isbn == "9780878575107"&& co >= 0)
	{
		book_srt[1].copies = book_srt[1].copies - co;
	}
	else if (isbn == "4756352428"&& co >= 0)
	{
		book_srt[12].copies = book_srt[12].copies - co;
	}
	else if (isbn == "9780767905381"&& co >= 0)
	{
		book_srt[3].copies = book_srt[3].copies - co;
	}
	else
	{
		cout << "Invalid ISBN or amount of copies (can't be negative).";
	}
}
void BookType::add_numcop(string i, BookType book_srt[], int co)
{
	isbn = i;
	if (isbn == "9780723258735" && co >= 0)
	{
		book_srt[9].copies = book_srt[9].copies + co;
	}
	else if (isbn == "0006716873"&& co >= 0)
	{
		book_srt[7].copies = book_srt[7].copies + co;
	}
	else if (isbn == "0123565432234"&& co >= 0)
	{
		book_srt[5].copies = book_srt[5].copies + co;
	}
	else if (isbn == "0131103628"&& co >= 0)
	{
		book_srt[2].copies = book_srt[2].copies + co;
	}
	else if (isbn == "9283746593625"&& co >= 0)
	{
		book_srt[0].copies = book_srt[0].copies + co;
	}
	else if (isbn == "0618640150"&& co >= 0)
	{
		book_srt[8].copies = book_srt[8].copies + co;
	}
	else if (isbn == "3846576839465"&& co >= 0)
	{
		book_srt[11].copies = book_srt[11].copies + co;
	}
	else if (isbn == "9780785185321"&& co >= 0)
	{
		book_srt[4].copies = book_srt[4].copies + co;
	}
	else if (isbn == "4756424656343"&& co >= 0)
	{
		book_srt[6].copies = book_srt[6].copies + co;
	}
	else if (isbn == "9781416507789"&& co >= 0)
	{
		book_srt[10].copies = book_srt[10].copies + co;
	}
	else if (isbn == "9780878575107"&& co >= 0)
	{
		book_srt[1].copies = book_srt[1].copies + co;
	}
	else if (isbn == "4756352428"&& co >= 0)
	{
		book_srt[12].copies = book_srt[12].copies + co;
	}
	else if (isbn == "9780767905381"&& co >= 0)
	{
		book_srt[3].copies = book_srt[3].copies + co;
	}
	else
	{
		cout << "Invalid ISBN or amount of copies (can't be negative).";
	}
}
void BookType::return_books(string auth, BookType b[])
{

	if (auth == b[9].authors[0])
	{
		cout << b[9].title;
	}
	else if (auth == b[7].authors[0])
	{
		cout << b[7].title;
	}
	else if (auth == b[5].authors[0])
	{
		cout << b[5].title;
	}
	else if (auth == b[2].authors[0] || (auth == b[2].authors[1]))
	{
		cout << b[2].title;
	}
	else if (auth == b[0].authors[0])
	{
		cout << b[0].title;
	}
	else if (auth == b[8].authors[0])
	{
		cout << b[8].title;
	}
	else if (auth == b[11].authors[0] || (auth == b[11].authors[1]) 
			|| (auth == b[11].authors[2]) || (auth == b[11].authors[3]))
	{
		cout << b[11].title;
	}
	else if (auth == b[4].authors[0] || (auth == b[4].authors[1]))
	{
		cout << b[4].title;;
	}
	else if (auth == b[6].authors[0] 
			|| (auth == b[6].authors[1]) || (auth == b[6].authors[2]))
	{
		cout << b[6].title;
	}
	else if (auth == b[10].authors[0])
	{
		cout << b[10].title;
	}
	else if (auth == b[1].authors[0])
	{
		cout << b[1].title;
	}
	else if (auth == b[12].authors[0])
	{
		cout << b[12].title;
	}
	else if (auth == b[3].authors[0] || (auth == b[3].authors[1]))
	{
		cout << b[3].title;
	}
	else
	{
		cout << "This author did not write any books within this data base.";
	}
}
void BookType::selecsort(BookType book[], int s)
{
	BookType temp;
	int smallindex = 0;

	for (int i = 0; i < s - 1; i++)
	{
		smallindex = i;
		for (int j = i + 1; j < s; j++)
		{
			if (book[j].title < book[smallindex].title)
			{
				smallindex = j;
			}
		}

		temp = book[i];
		book[i] = book[smallindex];
		book[smallindex] = temp;
	}
}

void BookType::display_t_onsorted(string t, BookType book_srt[])
{
	title = t;
	cout << title << " ";
	if (title == "Peter Rabbit")
	{
		cout << book_srt[9].copies;
	}
	else if (title == "Lion, the Witch and the Wardrobe")
	{
		cout << book_srt[7].copies;
	}
	else if (title == "Harry Potter in Yet Another Stupid Adventure")
	{
		cout << book_srt[5].copies;
	}
	else if (title == "C Programming Language")
	{
		cout << book_srt[2].copies;
	}
	else if (title == "Answers to C++ Problems")
	{
		cout << book_srt[0].copies;
	}
	else if (title == "Lord of the Rings")
	{
		cout << book_srt[8].copies;
	}
	else if (title == "The Truth About Peter Rabbit")
	{
		cout << book_srt[10].copies;
	}
	else if (title == "Deadpool: The Complete Collection - Volume 1")
	{
		cout << book_srt[4].copies;
	}
	else if (title == "How to Make Millions")
	{
		cout << book_srt[6].copies;
	}
	else if (title == "The Cuckoo's Egg")
	{
		cout << book_srt[11].copies;
	}
	else if (title == "Babies and Other Hazards of Sex")
	{
		cout << book_srt[1].copies;
	}
	else if (title == "The Two Towers")
	{
		cout << book_srt[13].copies;
	}
	else if (title == "Catch Me If You Can")
	{
		cout << book_srt[3].copies;
	}

}
void BookType::display_i_onsorted(string i, BookType book_srt[])
{
	isbn = i;
	cout << isbn << " ";
	if (isbn == "9780723258735")
	{
		cout << book_srt[9].copies;
	}
	else if (isbn == "0006716873")
	{
		cout << book_srt[7].copies;
	}
	else if (isbn == "0123565432234")
	{
		cout << book_srt[5].copies;
	}
	else if (isbn == "0131103628")
	{
		cout << book_srt[2].copies;
	}
	else if (isbn == "9283746593625")
	{
		cout << book_srt[0].copies;
	}
	else if (isbn == "0618640150")
	{
		cout << book_srt[8].copies;
	}
	else if (isbn == "3846576839465")
	{
		cout << book_srt[11].copies;
	}
	else if (isbn == "9780785185321")
	{
		cout << book_srt[4].copies;
	}
	else if (isbn == "4756424656343")
	{
		cout << book_srt[6].copies;
	}
	else if (isbn == "9781416507789")
	{
		cout << book_srt[10].copies;
	}
	else if (isbn == "9780878575107")
	{
		cout << book_srt[1].copies;
	}
	else if (isbn == "4756352428")
	{
		cout << book_srt[12].copies;
	}
	else if (isbn == "9780767905381")
	{
		cout << book_srt[3].copies;
	}
	else
	{
		cout << "Invalid ISBN. Not in database";
	}

}
void BookType::display_r_onsorted(string i, BookType book_srt[], int co)
{
	isbn = i;
	if (isbn == "9780723258735" && co >= 0)
	{
		book_srt[9].copies = book_srt[9].copies - co;
	}
	else if (isbn == "0006716873"&& co >= 0)
	{
		book_srt[7].copies = book_srt[7].copies - co;
	}
	else if (isbn == "0123565432234"&& co >= 0)
	{
		book_srt[5].copies = book_srt[5].copies - co;
	}
	else if (isbn == "0131103628"&& co >= 0)
	{
		book_srt[2].copies = book_srt[2].copies - co;
	}
	else if (isbn == "9283746593625"&& co >= 0)
	{
		book_srt[0].copies = book_srt[0].copies - co;
	}
	else if (isbn == "0618640150"&& co >= 0)
	{
		book_srt[8].copies = book_srt[8].copies - co;
	}
	else if (isbn == "3846576839465"&& co >= 0)
	{
		book_srt[11].copies = book_srt[11].copies - co;
	}
	else if (isbn == "9780785185321"&& co >= 0)
	{
		book_srt[4].copies = book_srt[4].copies - co;
	}
	else if (isbn == "4756424656343"&& co >= 0)
	{
		book_srt[6].copies = book_srt[6].copies - co;
	}
	else if (isbn == "9781416507789"&& co >= 0)
	{
		book_srt[10].copies = book_srt[10].copies - co;
	}
	else if (isbn == "9780878575107"&& co >= 0)
	{
		book_srt[1].copies = book_srt[1].copies - co;
	}
	else if (isbn == "4756352428"&& co >= 0)
	{
		book_srt[12].copies = book_srt[12].copies - co;
	}
	else if (isbn == "9780767905381"&& co >= 0)
	{
		book_srt[3].copies = book_srt[3].copies - co;
	}
	else
	{
		cout << "Invalid ISBN or amount of copies (can't be negative).";
	}

}
void BookType::if_p(BookType book_sort[])
{
	for (int i = 0; i < 13; i++)
	{
		book_sort[i].ret_book(title, num_auth, publish, isbn, price, copies, authors);
		cout << endl;
	}
}
void BookType::sorted_array(BookType book[], BookType book_s[])
{
	for (int i = 0; i < 12; i++)
	{
		book_s[i] = book[i];

	}
}
void BookType::sorted_trans(BookType book[], BookType book_t[])
{
	for (int i = 0; i < 13; i++)
	{
		book_t[i] = book[i];
	}
}

