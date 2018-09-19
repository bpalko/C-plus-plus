/*Brendan Palkowski / CPS 171 / November 6th, 2017
This program will take 2 dates for input, either from a file or user. It will change the month 
into the English written version, it will calculate it's julian date, and it will calculate the 
time elapsed between dates (in days). Output is either sent to a file or printed within console 
based upon user's choice of input. It will tell the user the time elapsed with the two dates taken 
in echoed, as well as written in a sentence. It will also tell if invalid. Assumptions within this 
program is that input with be in the  month/date/year form. It also assumes that leap years start 
after 1582. Most variables within this  program are obivious, like month1, month2, etc. The three 
I will touch are 'telapsed' which stands  for time elapsed, 'choice' which stands for user's choice 
of input, and 'engmonth' which stands for englishmonth, meaning translation into english from int. 
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Get_Date(int& month, int& date, int& year, bool& invalid);
void Get_Date2(int& month, int& date, int&year, ifstream& inFile, bool& invalid);
string Print_Month(int month);
int Convert_to_Julian(int month, int date, int year);
int Time_Elapsed(int juliandate1, int year1, int juliandate2, int year2);
int main()
{
	int month1 = 0, date1 = 0, year1 = 0, year2 = 0, 
		date2 = 0, month2 = 0, juliandate1 = 0, juliandate2 = 0, 
		telapsed = 0, choice = 0;
	string strmonth1, strmonth2;
	bool invalid;
	ifstream inFile;
	ofstream outFile;

	inFile.open("infile.txt");
	outFile.open("outfile.txt");

	cout << "Please choose whether to use an input file or interactive input." 
		 << "(1 for input file, 0 for interactive)" << endl;
	cin >> choice;

	if (choice == 1)
	{
		while (inFile) //Infile input
		{
			Get_Date2(month1, date1, year1, inFile, invalid);
			if (month1 == 0 && date1 == 0 && year1 == 0)
				break;
			Get_Date2(month2, date2, year2, inFile, invalid);
			if (month1 == 0 && date1 == 0 && year1 == 0)
				break;

			//String versions of the months given
			strmonth1 = Print_Month(month1);
			strmonth2 = Print_Month(month2);

			//Calculation of Julian dates (1-365/366)
			juliandate1 = Convert_to_Julian(month1, date1, year1);
			juliandate2 = Convert_to_Julian(month2, date2, year2);

			//Difference of time between 2 dates to find time elapsed
			telapsed = Time_Elapsed(juliandate1, year1, juliandate2, year2);

			if (invalid == false)
				outFile << "Invalid input." << endl;
			else if (year2 > year1)
			{
				outFile << month1 << " " << date1 << " " << year1 << endl;
				outFile << month2 << " " << date2 << " " << year2 << endl;
				outFile << "There is " << telapsed << " day(s) between " << strmonth1 << " " 
						<< date1 << " " << year1 << " and " << strmonth2 << " " << date2 << " " << year2 << endl;
			}
			else if (year1 > year2)
			{
				outFile << month1 << " " << date1 << " " << year1 << endl;
				outFile << month2 << " " << date2 << " " << year2 << endl;
				outFile << "There is " << telapsed << " day(s) between " << strmonth2 << " " 
					    << date2 << " " << year2 << " and " << strmonth1 << " " << date1 << " " << year1 << endl;
			}
			else if (year1 == year2)
			{
				if (date1 > date2)
				{
					outFile << month1 << " " << date1 << " " << year1 << endl;
					outFile << month2 << " " << date2 << " " << year2 << endl;
					outFile << "There is " << telapsed << " day(s) between " << strmonth2 << " " 
						    << date2 << " " << year2 << " and " << strmonth1 << " " << date1 << " " << year1 << endl;
				}
				else if (date1 < date2)
				{
					outFile << month1 <<" " << date1 <<" " << year1 << endl;
					outFile << month2 <<" "<< date2 <<" " << year2 << endl;
					outFile << "There is " << telapsed << " day(s) between " << strmonth1 << " " 
						    << date1 << " " << year1 << " and " << strmonth2 << " " << date2 << " " << year2 << endl;
				}
			}
			invalid = true;
			
		}
	}
	else if (choice == 0) //Interactive
	{
		//Initial retrieval of dates
		Get_Date(month1, date1, year1, invalid);
		Get_Date(month2, date2, year2, invalid);

		//String versions of the months given
		strmonth1 = Print_Month(month1);
		strmonth2 = Print_Month(month2);

		//Calculation of Julian dates (1-365/366)
		juliandate1 = Convert_to_Julian(month1, date1, year1);
		juliandate2 = Convert_to_Julian(month2, date2, year2);

		//Difference of time between 2 dates to find time elapsed
		telapsed = Time_Elapsed(juliandate1, year1, juliandate2, year2);

		if (invalid == false)
			cout << "Invalid input." << endl;
		else if (year2 > year1)
		{
			cout << month1 << " " << date1 << " " << year1 << endl;
			cout << month2 << " " << date2 << " " << year2 << endl;
			cout << "There is " << telapsed << " day(s) between " << strmonth1 << " " 
				 << date1 << " " << year1 << " and " << strmonth2 << " " << date2 << " " << year2 << endl;
		}
		else if (year1 > year2)
		{
			cout << month1 << " " << date1 << " " << year1 << endl;
			cout << month2 << " " << date2 << " " << year2 << endl;
			cout << "There is " << telapsed << " day(s) between " << strmonth2 << " " 
				 << date2 << " " << year2 << " and " << strmonth1 << " " << date1 << " " << year1 << endl;
		}
		else if (year1 == year2)
		{
			if (date1 > date2)
			{
				cout << month1 << " " << date1 << " " << year1 << endl;
				cout << month2 << " " << date2 << " " << year2 << endl;
				cout << "There is " << telapsed << " day(s) between " << strmonth2 << " " 
					 << date2 << " " << year2 << " and " << strmonth1 << " " << date1 << " " << year1 << endl;
			}
			else if (date1 < date2)
			{
				cout << month1 << " " << date1 << " " << year1 << endl;
				cout << month2 << " " << date2 << " " << year2 << endl;
				cout << "There is " << telapsed << " day(s) between " << strmonth1 << " " 
					 << date1 << " " << year1 << " and " << strmonth2 << " " << date2 << " " << year2 << endl;
			}
		}
	}
	
	return 0;
}
void Get_Date(int& month, int& date, int&year, bool& invalid)
{
	cout << "Please enter a date. (Format month/date/year)" << endl;
	cin >> month >> date >> year;

	if (month > 12 || month < 0)
	{
		invalid = false;
	}
	if ((date == 29) && (month == 2) && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)));

	else if ((date > 28) && (month == 2))
	{
		invalid = false;
	}

	if ((date > 30) && ((month == 4) || (month == 6) || (month == 9) || (month == 11)))
	{
		invalid = false;
	}
	if ((date > 31) && ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) 
		|| (month == 10) || (month == 12)))
	{
		invalid = false;
	}
	if (date < 0)
		invalid = false;
}
void Get_Date2(int& month, int& date, int&year, ifstream& inFile, bool& invalid)
{
	
	inFile >> month >> date >> year;		

	if (month > 12 || month < 0)
	{
		invalid = false;
		
	}
	if ((date == 29) && (month == 2) && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)));

	else if ((date > 28) && (month == 2))
	{
		invalid = false;
		
	}

	if ((date > 30) && ((month == 4) || (month == 6) || (month == 9) || (month == 11)))
	{
		invalid = false;
		
	}
	if ((date > 31) && ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) 
		|| (month == 10) || (month == 12)))
	{
		invalid = false;
	}
	if (date < 0)
		invalid = false;
}
string Print_Month(int month)
{
		string engmonth;
		switch (month) 
		{
		case 1:
		{
			engmonth = "January";
			break;
		}
		case 2:
		{
			engmonth = "February";
			break;
		}
		case 3:
		{
			engmonth = "March";
			break;
		}
		case 4:
		{
			engmonth = "April";
			break;
		}
		case 5:
		{
			engmonth = "May";
			break;
		}
		case 6:
		{
			engmonth = "June";
			break;
		}
		case 7:
		{
			engmonth = "July";
			break;
		}
		case 8:
		{
			engmonth = "August";
			break;
		}
		case 9:
		{
			engmonth = "September";
			break;
		}
		case 10:
		{
			engmonth = "October";
			break;
		}
		case 11:
		{
			engmonth = "November";
			break;
		}
		case 12:
		{
			engmonth = "December";
			break;
		}

		}
		return engmonth;
}
int Convert_to_Julian(int month, int date, int year)
{
	int i = 0;

	if ((month < 3) && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)));
	else if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) date++;

	switch (month)
	{
	case 1:
	{
		i = date;
		break;
	}
	case 2:
	{
		i = date + 31;
		break;
	}
	case 3:
	{
		i = date + 59;
		break;
	}
	case 4:
	{
		i = date + 90;
		break;
	}
	case 5:
	{
		i = date + 120;
		break;
	}
	case 6:
	{
		i = date + 151;
		break;
	}
	case 7:
	{
		i = date + 181;
		break;
	}
	case 8:
	{
		i = date + 212;
		break;
	}
	case 9:
	{
		i = date + 243;
		break;
	}
	case 10:
	{
		i = date + 273;
		break;
	}
	case 11:
	{
		i = date + 304;
		break;
	}
	case 12:
	{
		i = date + 334;
		break;
	}
	}
	return i;

}
int Time_Elapsed(int juliandate1, int year1, int juliandate2, int year2)
{
	int days = 0, telapsed = 0;

	juliandate1 = (juliandate1 + (year1 * 365));
	juliandate2 = (juliandate2 + (year2 * 365));

	if (juliandate1 >= juliandate2)
		telapsed = juliandate1 - juliandate2;

	else telapsed = juliandate2 - juliandate1;


	if (year1 < year2) {
		for (int i = year1; i < year2; i++)
			if ((i % 400 == 0 || i % 100 != 0) && (i % 4 == 0))
				days++;
	}

	else for (int i = year2; i < year1; i++)
		if ((i % 400 == 0 || i % 100 != 0) && (i % 4 == 0))
			days++;

	telapsed = telapsed + days;

	return telapsed;
}

/* Output

INTERACTIVE:

Please choose whether to use an input file or interactive input.(1 for input file, 0 for interactive)
0
Please enter a date. (Format month/date/year)
5 24 1995
Please enter a date. (Format month/date/year)
5 24 2017
5 24 1995
5 24 2017
There is 8036 day(s) between May 24 1995 and May 24 2017
Press any key to continue . . .


INFILE:

*/