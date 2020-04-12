#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<time.h>
#include<conio.h>
#include<istream>

using namespace std;
// to time
struct tm time1() {
	time_t now;
	struct tm today; //tm include day and month and year and time (seconds , minutes , hours )
	now = time(NULL); //get the time from computer
	today = *localtime(&now);

	return today;
};

struct date {
	string day;
	string month;
	string year;
};

struct books {
	string id_of_book;
	string name_of_book;
	string author;
	string year;
	string status_book;
	string name_of_ismember;
	date start_of_time;
	date end_of_time;
	int numberword=0;
};

struct members {
	string id_of_member;
	string name_of_member;
	string pass_of_member;
	date date_of_member;
	string status_member;
	int number_isbooks=0;
};

struct isbooks {
	string id_of_book;
	string name_of_book;
	date start_of_time;
	date end_of_time;
};

int error;
string arr_of_words[1000][10000];
isbooks arr_of_isbooks[1000][5];

void Input(books arr_of_books[1000], int& book_id, members arr_of_members[1000], int& member_id, string calender1[370][2]);

string readpassword(string pass);

bool loginadmin();

int loginmember(members arr_of_members[1000], int member_id);

void display_books(books arr_of_books[1000], int i);

void display_members(members arr_of_members[1000], int i);

string search_idbook(string id, int book_id, books arr_of_books[1000]);

int addbook(int book_id, books arr_of_books[1000]);

string search_idmember(string id, int member_id, members arr_of_members[1000]);

int addmember(int member_id, members arr_of_members[1000]);

void search_of_book(books arr_of_books[1000], int book_id, string arr_of_words[1000][10000]);

void search_of_member(members arr_of_members[1000], int member_id);

void update_book(books arr_of_books[1000], int book_id, members arr_of_members[1000], int member_id);

void update_member(books arr_of_books[1000], int book_id, members arr_of_members[1000], int member_id);

void bowrring_book(books arr_of_books[1000], int book_id, string calender1[370][2], members arr_of_members[1000], int member_id, int rus_member);

void return_book(books arr_of_books[1000], int book_id, members arr_of_members[1000], int member_id, int rus_member);

void check_today(books arr_of_books[1000], int book_id);
//main function
void main()
{
	books arr_of_books[1000];
	members arr_of_members[1000];
	string calender1[370][2];
	bool rus_admin;
	int rus_member;
	int book_id = 0;            //to count the books
	int member_id = 0;
	int isbook = 0;
	tm today;
	int choice_section;            //Choice of section inside the library (admin/library)
	int choice_admin_section;     //Choice of database in the admin section(seeing lists, adding books etc)
	int choice_member_section;   //Choice of database in the member section
	int choice_visitor_section;
	int choice_search;
	int choise2_of_search;
	int check_id;

	Input(arr_of_books, book_id, arr_of_members, member_id , calender1);

	//start program
	do {

		cin.clear();
		cout << "" << setw(50) << "Welcome to The Library :" << setw(29) << "" << "\n\n";

		cout << "\t 1. Access the Admin Section \t\n\n";
		cout << "\t 2. Access The Member Section \t\n\n";
		cout << "\t 3. Access The Visitor Section \t\n\n";
		cout << "\t 4. Quit Program \t\t\n" << endl;

		do
		{
			error = 0;
			cout << "\n Please Enter Your Selection Between (1-4) : ";
			cin >> choice_section;
			if (cin.fail() && choice_section < 1 || choice_section > 4)
			{
				cout << "\n\tPlease Enter A Valid Input. " << endl;
				error = 1;
				cin.clear();
				cin.ignore(80, '\n');
			}
		} while (error == 1);
		system("cls");

		//if you are admin
		if (choice_section == 1)
		{
			rus_admin = loginadmin();
			if (rus_admin == true) 
			{
				// out time to file
				time1();
				do {
					system("cls");
					cout << "" << setw(40) << "Welcome Admin" << setw(29) << "" << endl << endl;
					cout << "\t 1. Add New Book in Book Database\t\n\n";
					cout << "\t 2. Add New Member in Member Database\t\n\n";
					cout << "\t 3. Display All Books\t\n\n";
					cout << "\t 4. Display All Members\t\n\n";
					cout << "\t 5. Search For A Book \t\n\n";
					cout << "\t 6. Search For A Member \t\n\n";
					cout << "\t 7. Update Book Data \t\n\n";
					cout << "\t 8. Update Member Data \t\n\n";
					cout << "\t 9. Check Today \t\n\n";
					cout << "\t 10. Help \t\n\n";
					cout << "\t 11. Return to previous list\t" << endl;

					do
					{
						error = 0;
						cout << "\n Please Enter Your Selsction Between (1-11) : ";
						cin >> choice_admin_section;
						if (cin.fail() && choice_admin_section < 1 || choice_admin_section > 11)
						{
							cout << "\n\tPlease Enter A Valid Input. " << endl;
							error = 1;
							cin.clear();
							cin.ignore(80, '\n');
						}
					} while (error == 1);

					system("cls");
					//CALLING FUNCTION ADD BOOK
					if (choice_admin_section == 1)
					{
						book_id=addbook(book_id, arr_of_books);
					}
					//CALLING FUNCTION ADD STUDENT
					if (choice_admin_section == 2)
					{
						member_id=addmember(member_id, arr_of_members);
					}
					//showing all the books
					if (choice_admin_section == 3)
					{
						for (int i = 0; i < book_id; i++)
						{
							display_books(arr_of_books, i);
							if (i == 9)
								system("pause");
						}
						system("pause");
					}
					//showing all the member
					if (choice_admin_section == 4)
					{
						for (int i = 0; i < member_id; i++)
						{
							display_members(arr_of_members ,i);
							if (i == 9)
								system("pause");
						}
						system("pause");
					}
					//search for a books
					if (choice_admin_section == 5)
					{
						search_of_book(arr_of_books, book_id, arr_of_words);
					}
					//search for a member
					if (choice_admin_section == 6)
					{
						search_of_member(arr_of_members ,member_id);
					}

					if (choice_admin_section == 7)
					{
						update_book(arr_of_books, book_id, arr_of_members, member_id);
					}
					if (choice_admin_section == 8)
					{
						update_member(arr_of_books, book_id, arr_of_members, member_id);
					}
					if (choice_admin_section == 9)
					{
						check_today(arr_of_books, book_id);
					}
					//to back
					if (choice_admin_section == 11)
					{
						break;
					}
				} while (true);

			}

		}
		//if you are member
		if (choice_section == 2)
		{
			rus_member = loginmember(arr_of_members, member_id);
			system("cls");
			if (rus_member >= 0)
			{
				do {
					system("cls");
					cout << "" << setw(40) << "Welcome Member" << setw(29) << "" << endl << endl;
					cout << "\t 1. Display All Books\t\n\n";
					cout << "\t 2. Search For A Book \t\n\n";
					cout << "\t 3. Borrowing A Book \t\n\n";
					cout << "\t 4. Return A Book \t\n\n";
					cout << "\t 5. Help \t\n\n";
					cout << "\t 6. Return to previous list\t" << endl;

					do
					{
						error = 0;
						cout << "\n Please Enter Your Selsction Between (1-6) : ";
						cin >> choice_member_section;
						if (cin.fail() && choice_member_section < 1 || choice_member_section > 6)
						{
							cout << "\n\tPlease Enter A Valid Input. " << endl;
							error = 1;
							cin.clear();
							cin.ignore(80, '\n');
						}
					} while (error == 1);

					system("cls");
					//showing all the books
					if (choice_member_section == 1)
					{
						for (int i = 0; i < book_id; i++)
						{
							display_books(arr_of_books, i);
							if (i == 9)
								system("pause");
						}
						system("pause");
					}
					//search for a books
					if (choice_member_section == 2)
					{
						search_of_book(arr_of_books, book_id, arr_of_words);
					}
					//to bowrring the book
					if (choice_member_section == 3)
					{
						bowrring_book(arr_of_books, book_id, calender1, arr_of_members , member_id, rus_member);
					}
					if (choice_member_section == 4)
					{
						return_book(arr_of_books, book_id, arr_of_members, member_id, rus_member);
					}
					//to back
					if (choice_member_section == 6)
					{
						break;
					}
				} while (true);
			}
		}
		//if you are visitor
		if (choice_section == 3)
		{
			do {
				system("cls");
				cout << "" << setw(40) << "Welcome Visitor" << setw(29) << "" << endl << endl;
				cout << "\t 1. Display All Books\t\n\n";
				cout << "\t 2. Search For A Book \t\n\n";
				cout << "\t 3. Help \t\n\n";
				cout << "\t 4. Return to previous list\t" << endl;

				do
				{
					error = 0;
					cout << "\n Please Enter Your Selsction Between (1-4) : ";
					cin >> choice_visitor_section;
					if (cin.fail() && choice_visitor_section < 1 || choice_visitor_section > 6)
					{
						cout << "\n\tPlease Enter A Valid Input. " << endl;
						error = 1;
						cin.clear();
						cin.ignore(80, '\n');
					}
				} while (error == 1);

				system("cls");
				//showing all the books
				if (choice_visitor_section == 1)
				{
					for (int i = 0; i < book_id; i++)
					{
						display_books(arr_of_books, i);
						if (i == 9)
							system("pause");
					}
					system("pause");
				}
				//search for a book
				if (choice_visitor_section == 2)
				{
					search_of_book(arr_of_books, book_id, arr_of_words);
				}
				//to back
				if (choice_visitor_section == 4)
				{
					break;
				}

			} while (true);

		}


	} while (choice_section != 4);
}

 void Input(books arr_of_books[1000], int& book_id, members arr_of_members[1000], int& member_id, string calender1[370][2])
{
	ifstream InBook;
	InBook.open("books.txt");   //include all books
	for (int i = 0; InBook.eof() == false; i++)
	{
		getline(InBook, arr_of_books[i].id_of_book, '%');
		//getting the date from the text file . Storing Book name
		getline(InBook, arr_of_books[i].name_of_book, '#');
		//storing author name
		getline(InBook, arr_of_books[i].author, '$');
		//storing year
		getline(InBook, arr_of_books[i].year, '@');
		//storing status
		getline(InBook, arr_of_books[i].status_book, '*');
		if (arr_of_books[i].status_book == "false")
		{
			getline(InBook, arr_of_books[i].name_of_ismember, '|');
			getline(InBook, arr_of_books[i].start_of_time.day, '/');
			getline(InBook, arr_of_books[i].start_of_time.month, '/');
			getline(InBook, arr_of_books[i].start_of_time.year, '|');
			getline(InBook, arr_of_books[i].end_of_time.day, '/');
			getline(InBook, arr_of_books[i].end_of_time.month, '/');
			getline(InBook, arr_of_books[i].end_of_time.year, '|');
		}
		book_id += 1;                           //getting the final value of book
	}
	book_id -= 1;
	InBook.close();
	for (int i = 0; i < book_id; i++)
	{
		fstream check1;
		check1.open(arr_of_books[i].name_of_book + ".txt");
		for (int j = 0; check1.eof() == false; j++)
		{
			getline(check1, arr_of_words[i][j], ' ');
			arr_of_books[i].numberword += 1;
		}
		arr_of_books[i].numberword -= 1;
		check1.close();
	}

	ifstream InMember;
	InMember.open("members.txt");    //include all member
	for (int i = 0; !InMember.eof(); i++)
	{
		getline(InMember, arr_of_members[i].id_of_member, '%');
		//getting the date from the text file . Storing member id
		getline(InMember, arr_of_members[i].name_of_member, '#');
		//storing member name
		getline(InMember, arr_of_members[i].pass_of_member, '$');
		//storing member pass
		getline(InMember, arr_of_members[i].date_of_member.day, '/');
		getline(InMember, arr_of_members[i].date_of_member.month, '/');
		getline(InMember, arr_of_members[i].date_of_member.year, '@');
		getline(InMember, arr_of_members[i].status_member, '*');
		//storing member date
		member_id += 1;                         //getting the final value of member
	}
	member_id -= 1;
	InMember.close();

	for (int i = 0; i < member_id; i++)
	{
		if (arr_of_members[i].status_member == "false")
		{
			fstream check2;
			check2.open(arr_of_members[i].name_of_member + ".txt");
			for (int j = 0; check2.eof() == false; j++)
			{
				getline(check2, arr_of_isbooks[i][j].id_of_book, '|');
				getline(check2, arr_of_isbooks[i][j].name_of_book, '|');
				getline(check2, arr_of_isbooks[i][j].start_of_time.day, '/');
				getline(check2, arr_of_isbooks[i][j].start_of_time.month, '/');
				getline(check2, arr_of_isbooks[i][j].start_of_time.year, '|');
				getline(check2, arr_of_isbooks[i][j].end_of_time.day, '/');
				getline(check2, arr_of_isbooks[i][j].end_of_time.month, '/');
				getline(check2, arr_of_isbooks[i][j].end_of_time.year, '|');
				arr_of_members[i].number_isbooks += 1;
			}
			arr_of_members[i].number_isbooks -= 1;
			check2.close();
		}
	}
	fstream calender;//for opening date text file
	calender.open("calender.txt");
	for (int i = 0; i < 365; i++)
	{
		getline(calender, calender1[i][0], '/');
		getline(calender, calender1[i][1], ';');
	}
}

string readpassword(string pass)
{
	const char BACKSPACE = 8;
	const char RETURN = 13;
	unsigned char ch = 0;
	while ((ch = getch()) != RETURN)
	{
		if (ch == BACKSPACE)
		{
			if (pass.length() != 0)
			{
				cout << "\b \b";
				pass.resize(pass.length() - 1);
			}
		}
		else if (ch == 0 || ch == 224) // handle escape sequences
		{
			getch(); // ignore non printabxle chars
			continue;
		}
		else
		{
			pass += ch;
			cout << '*';
		}
	}
	return pass;
}
// to check is admin
bool loginadmin()
{
	// to read user name && password form text file
	string user1;
	string pass1;
	//to check is admin
	bool isadmin = false;
	// file  
	fstream check;
	// open file
	check.open("admin.txt");
	// read user name amd password from file
	check >> user1 >> pass1;
	check.close();
	//check is admin
	for (int i = 0; i < 3; i++)
	{
		string user;
		string  pass;
		cout << "Enter The Username: ";
		cin >> user;
		cout << "Enter The Password: ";
		pass = readpassword(pass);
		if (user == user1 && pass == pass1)
		{
			isadmin = true;
			break;
		}
		/// if wrong password or username
		else
		{
			// to clear the program
			system("cls");
			cout << "Wrong Username or Password." << endl;
		}

	}
	if (isadmin == true)
	{
		//time form function (data type:"struct tm",day as a valible)
		struct tm day = time1();
		//file to add new deta to login
		fstream file("admin.txt", ios_base::app | ios_base::out);
		file << "time : " << day.tm_hour << ':' << day.tm_min << ':' << day.tm_sec << " | ";
		file << "date: " << day.tm_mday << '/' << day.tm_mon + 1 << '/' << day.tm_year + 1900 << endl;
	}
	system("cls");
	return isadmin;
}

int loginmember(members arr_of_members[1000], int member_id)
{
	int j;
	for (int i = 0; i < 3; i++)
	{
		string name;
		string pass;
		cout << "Enter Name : ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Password : ";
		pass = readpassword(pass);
		bool ismember = false;
		for (j = 0; j < member_id; j++)
		{
			if (name == arr_of_members[j].name_of_member&&pass == arr_of_members[j].pass_of_member)
			{
				ismember = true;
				break;
			}
		}
		system("cls");
		if (ismember == true)
		{
			return j;
		}
		else
		{
			cout << "Wrong Name Or Password." << endl;
		}
	}
	return -1;
}

void display_books(books arr_of_books[1000], int i)
{
	cout << "Id : " << arr_of_books[i].id_of_book << endl;
	cout << "Name : " << arr_of_books[i].name_of_book << endl;
	cout << "Author : " << arr_of_books[i].author << endl;
	cout << "Year : " << arr_of_books[i].year << endl;
	if (arr_of_books[i].status_book == "false")
	{
		cout << "Name of Member : " << arr_of_books[i].name_of_ismember << endl;
		cout << "Date of Issue Book : " << arr_of_books[i].start_of_time.day << '/' << arr_of_books[i].start_of_time.month << '/' << arr_of_books[i].start_of_time.year << endl;
		cout << "Date of Return Book : " << arr_of_books[i].end_of_time.day << '/' << arr_of_books[i].end_of_time.month << '/' << arr_of_books[i].end_of_time.year << endl;
	}
	cout << "\n\n";
}

void display_members(members arr_of_members[1000], int i)
{
	cout << "Id : " << arr_of_members[i].id_of_member << endl;
	cout << "Name : " << arr_of_members[i].name_of_member << endl;
	cout << "Password : " << arr_of_members[i].pass_of_member << endl;
	cout << "Date Of Registration : " << arr_of_members[i].date_of_member.day << '/' << arr_of_members[i].date_of_member.month << '/' << arr_of_members[i].date_of_member.year << endl;

	if (arr_of_members[i].status_member == "false")
	{
		for (int j = 0; j <arr_of_members[i].number_isbooks; j++)
		{
			cout << "ID of Issue Book : " << arr_of_isbooks[i][j].id_of_book << endl;
			cout << "Name of Issue Book : " << arr_of_isbooks[i][j].name_of_book << endl;
			cout << "Date of Issue Book : " << arr_of_isbooks[i][j].start_of_time.day << '/' << arr_of_isbooks[i][j].start_of_time.month << '/' << arr_of_isbooks[i][j].start_of_time.year << endl;
			cout << "Date of Return Book : " << arr_of_isbooks[i][j].end_of_time.day << '/' << arr_of_isbooks[i][j].end_of_time.month << '/' << arr_of_isbooks[i][j].end_of_time.year << endl;
		}
	}
	cout << "\n\n";
}

string search_idbook(string id, int book_id, books arr_of_books[1000])
{
	getline(cin, id);
	while (true) 
	{
		bool isfound = false;
		for (int i = 0; i <book_id; i++)
		{
			if (arr_of_books[i].id_of_book == id)
			{
				isfound = true;
				break;
			}
		}
		if (isfound == false)
			break;
		else {
			cout << "\n\tThe ID is Already Used\nEnter Another ID : (Suggest " << (book_id + 1) << " )";
			getline(cin, id);
		}
	}
	return id;
}

int addbook(int book_id, books arr_of_books[1000])
{
	system("cls");
	books add;
	cout << "\n\tEnter ID : ";
	getline(cin, add.id_of_book);
	add.id_of_book = search_idbook(add.id_of_book, book_id, arr_of_books);
	string name;
	cout << "\n\tEnter Name : ";
	getline(cin, add.name_of_book);
	cout << "\n\tEnter Author : ";
	getline(cin, add.author);
	cout << "\n\tEnter Year : ";
	getline(cin, add.year);
	string text;
	cout << "\n\tEnter Text : ";
	getline(cin, text);
	int x = 1;
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == ' ')
		{
			x++;
		}
	}
	fstream InBook("books.txt", ios_base::app);
	InBook << add.id_of_book << '%' << add.name_of_book << '#' << add.author << '$' << add.year << '@' << "true" << '*';
	arr_of_books[book_id].id_of_book = add.id_of_book;
	arr_of_books[book_id].name_of_book = add.name_of_book;
	arr_of_books[book_id].author = add.author;
	arr_of_books[book_id].year = add.year;
	arr_of_books[book_id].status_book = "true";
	ofstream newfile;
	newfile.open(add.name_of_book + ".txt");
	newfile.close();
	ofstream thefile(add.name_of_book + ".txt", ios_base::app);
	thefile << text;
	thefile.close();
	fstream check1;
	check1.open(add.name_of_book + ".txt");
	for (int j = 0; j<x; j++)
	{
		getline(check1, arr_of_words[book_id][j], ' ');
	}
	check1.close();
	book_id += 1;
	return book_id;
}

string search_idmember(string id, int member_id, members arr_of_members[1000])
{
	getline(cin, id);
	while (true) {
		bool isfound = false;
		for (int i = 0; i < member_id; i++)
		{
			if (arr_of_members[i].id_of_member == id)
			{
				isfound = true;
				break;
			}
		}
		if (isfound == false)
			break;
		else
		{
			cout << "\n\tThe ID is Already Used\nEnter Another ID : (Suggest " << (member_id + 1) << " )";
			getline(cin, id);
		}
	}
	return id;
}

int addmember(int member_id, members arr_of_members[1000])
{
	system("cls");
	string id;
	cout << "\n\tenter id : ";
	getline(cin, id);
	id = search_idmember(id, member_id, arr_of_members);
	cout << "\n\tenter name : ";
	string name;
	getline(cin, name);
	cout << "\n\tenter password : ";
	string password;
	getline(cin, password);
	struct tm addday = time1();
	fstream InMember("members.txt", ios_base::app);
	InMember << id << '%' << name << '#' << password << '$';
	InMember << addday.tm_mday << '/' << addday.tm_mon + 1 << '/' << addday.tm_year + 1900 << '@' << "true*";
	ofstream newfile;
	arr_of_members[member_id].id_of_member = id;
	arr_of_members[member_id].name_of_member = name;
	arr_of_members[member_id].pass_of_member = password;
	tm today = time1();
	int Year = today.tm_year + 1900;
	int Month = today.tm_mon + 1;
	int Day = today.tm_mday;
	stringstream year;
	year << Year;
	string Y_O_C = year.str();
	stringstream month;
	month << Month;
	string M_O_C = month.str();
	stringstream day;
	day << Day;
	string D_O_C = day.str();
	arr_of_members[member_id].date_of_member.day = D_O_C;
	arr_of_members[member_id].date_of_member.month = M_O_C;
	arr_of_members[member_id].date_of_member.year = Y_O_C;
	member_id += 1;
	newfile.open(name +".txt");
	return member_id;
}

void search_of_book(books arr_of_books[1000], int book_id, string arr_of_words[1000][10000])
{
	string search_book;
	char answer;
	int choise_of_search;
	do {
		bool isfound = false;


		cout << "\n\tSelect One Of The Following Options : \n" << endl;
		cout << "\n\t1. Search By Id : \n" << endl;
		cout << "\n\t2. Search By Name : \n" << endl;
		cout << "\n\t3. Search By Author : \n" << endl;
		cout << "\n\t4. Search By Year : \n" << endl;
		cout << "\n\t5. Search By Words : \n" << endl;
		
			cin >> choise_of_search;
			while (cin.fail())
			{
				cout << "\n\tPlease Enter Your Selection Between (1:5) : ";
				cin.clear();
				cin.ignore(80, '\n');
				cin >> choise_of_search;
			}

			if (choise_of_search == 1)
			{
				cout << "\n\tEnter The Book's Id : ";
				cin >> search_book;
				system("cls");
				for (int i = 0; i < book_id; i++)
				{
					if (arr_of_books[i].id_of_book == search_book)
					{
						display_books(arr_of_books, i);
						isfound = true;
					}
				}
			}
			else if (choise_of_search == 2)
			{
				cout << "\n\tEnter The Book's Name : ";
				cin >> search_book;
				system("cls");
				for (int i = 0; i < book_id; i++)
				{
					if (arr_of_books[i].name_of_book.find(search_book) != string::npos)
					{
						display_books(arr_of_books, i);
						isfound = true;
					}
				}
			}
			else if (choise_of_search == 3)
			{
				cout << "\n\tEnter The Book's Author : ";
				cin >> search_book;
				system("cls");
				for (int i = 0; i < book_id; i++)
				{
					if (arr_of_books[i].author.find(search_book) != string::npos)
					{
						display_books(arr_of_books, i);
						isfound = true;
					}
				}
			}
			else if (choise_of_search == 4)
			{
				cout << "\n\tEnter The Book's Year : ";
				cin >> search_book;
				system("cls");
				for (int i = 0; i < book_id; i++)
				{
					if (arr_of_books[i].year == search_book)
					{
						display_books(arr_of_books, i);
						isfound = true;
					}
				}
			}
			else if (choise_of_search == 5)
			{
				int m = 0;
				bool swapped;
				bool isword = false;
				int sortad_book[1000][2] = { { 0 } };
				int sum;
				int sort = 0;
				string search_word[2];
				cout << "\n\tEnter The Word of Book : ";
				cin.ignore();
				getline(cin, search_book);
				system("cls");
				for (int i = 0; i < search_book.size(); i++)
				{
					if (search_book[i] == ' ')
					{
						m++;
						isword = true;
						continue;
					}
					search_word[m] += search_book[i];
				}
				for (int i = 0; i < book_id; i++)
				{
					sum = 0;
					bool found = false;

					for (int j = 1; j < arr_of_books[i].numberword; j++)
					{
						if (isword == false)
						{
							if (search_book == arr_of_words[i][j - 1])
							{
								sum++;
								isfound = true;
								found = true;
							}
						}
						if (isword == true)
						{
							if (search_word[0] == arr_of_words[i][j - 1] && search_word[1] == arr_of_words[i][j])
							{
								sum++;
								isfound = true;
								found = true;
							}
						}
					}
					if (found == true)
					{
						sortad_book[sort][0] = i;
						sortad_book[sort][1] = sum;
						sort++;
					}
				}
				do
				{
					swapped = false;
					for (int i = 1; i <sort; i++)
					{

						if (sortad_book[i - 1][1]<sortad_book[i][1])
						{
							swap(sortad_book[i - 1], sortad_book[i]);
							swapped = true;
						}
					}
				} while (swapped);
				/*for (int i = 0; i < sort; i++)
				{
				cout << sortad_book[i][0]<<" " << sortad_book[i][1] <<"sjgjs"<< endl;
				}
				system("pause");*/
				for (int i = 0; i <sort; i++)
				{
					int n;
					n = sortad_book[i][0];
					display_books(arr_of_books, n);
				}
				break;
			}
			else if (choise_of_search>5 || choise_of_search<1)
			{
				cout << "\tPlease Enter Your Selection Between (1:5) : ";
			}
		

		if (isfound == false)
		{
			cout << "\n\t Not Found This Book" << endl;
		}
		cout << "\n\tDo You Want To Search Again? (Y/N) : ";
		cin >> answer;
		system("cls");
		if (answer == 'N' || answer == 'n')
		{
			break;
		}
		else if (answer == 'y' || answer == 'Y')
		{
			continue;
		}

	} while (true);
	system("cls");
}

void search_of_member(members arr_of_members[1000], int member_id)
{
	string search_member;
	string search_of_day;
	string search_of_month;
	string search_of_year;
	char answer;
	int choise_of_search;
	int choise2_of_search;
	do {
		bool isfound = false;

		cout << "\n\tSelect One Of The Following Options : \n" << endl;
		cout << "\n\t1. Search By Id : \n" << endl;
		cout << "\n\t2. Search By Name : \n" << endl;
		cout << "\n\t3. Search By date : \n" << endl;
		cout << "\n\tEnter Your Selection (1:3) : ";

		
			cin >> choise_of_search;
			while (cin.fail())
			{
				cout << "\n\tPlease Enter Your Selection Between (1:3) : ";
				cin.clear();
				cin.ignore(80, '\n');
				cin >> choise_of_search;
			}
			if (choise_of_search == 1)
			{
				cout << "\n\tEnter Your Member's Id : ";
				cin >> search_member;
				system("cls");

				for (int i = 0; i < member_id; i++)
				{
					if (arr_of_members[i].id_of_member == search_member)
					{
						display_members(arr_of_members, i);
						isfound = true;
					}
				}
				break;
			}
			else if (choise_of_search == 2)
			{
				cout << "\n\tEnter Your Member's Name : ";
				cin >> choise_of_search;
				system("cls");
				for (int i = 0; i < member_id; i++)
				{
					if (arr_of_members[i].name_of_member.find(search_member) != string::npos)
					{
						display_members(arr_of_members, i);
						isfound = true;
					}
				}
				break;
			}
			else if (choise_of_search == 3)
			{
				system("cls");
				cout << "\n\tSelect One Of The Following Options : \n" << endl;
				cout << "\n\t1. Search By Day Only : \n" << endl;
				cout << "\n\t2. Search By Month Only : \n" << endl;
				cout << "\n\t3. Search BY Year Only : \n" << endl;
				cout << "\n\t4. Search By All Date : \n" << endl;
				cout << "\n\tEnter Your Selection (1:4) : ";
				while (true)
				{

					cin >> choise2_of_search;
					while (cin.fail())
					{
						cout << "\n\tPlease Enter Your Selection Between (1:4) : ";
						cin.clear();
						cin.ignore(80, '\n');
						cin >> choise2_of_search;
					}
					if (choise2_of_search == 1)
					{
						cout << "\n\tEnter Your Member's Date (Day) : ";
						cin >> search_member;
						system("cls");

						for (int i = 0; i < member_id; i++)
						{
							if (arr_of_members[i].date_of_member.day == search_member)
							{
								display_members(arr_of_members, i);
								isfound = true;
							}
						}
						break;
					}
					else if (choise2_of_search == 2)
					{
						cout << "\n\tEnter Your Member's Date (Month) : ";
						cin >> search_member;
						system("cls");

						for (int i = 0; i < member_id; i++)
						{
							if (arr_of_members[i].date_of_member.month == search_member)
							{
								display_members(arr_of_members, i);
								isfound = true;
							}
						}
						break;
					}
					else if (choise2_of_search == 3)
					{
						cout << "\n\tEnter Your Member's Date (Years) : ";
						cin >> search_member;
						system("cls");

						for (int i = 0; i < member_id; i++)
						{
							if (arr_of_members[i].date_of_member.year == search_member)
							{
								display_members(arr_of_members, i);
								isfound = true;
							}
						}
						break;
					}
					else if (choise2_of_search == 4)
					{
						cout << "\n\tEnter Your Member's All Date : " << endl;
						cout << "\n\tEnter The Member's Day : ";
						cin >> search_of_day;
						cout << "\n\tEnter The Member's Month : ";
						cin >> search_of_month;
						cout << "\n\tEnter The Member's Year : ";
						cin >> search_of_year;
						system("cls");

						for (int i = 0; i < member_id; i++)
						{
							if (arr_of_members[i].date_of_member.day == search_of_day && arr_of_members[i].date_of_member.month == search_of_month && arr_of_members[i].date_of_member.year == search_of_year)
							{
								display_members(arr_of_members, i);
								isfound = true;
							}
						}
						break;
					}
					else if (choise2_of_search<1 || choise2_of_search>4)
					{
						cout << "\n\tPlease Enter Your Selection Between (1:4) : ";
					}
				}
				break;
			}
			else if (choise_of_search<1 || choise_of_search>3)
			{
				cout << "\n\tPlease Enter Your Selection Between (1:3) : ";
			}
		

		if (!isfound)
		{
			cout << "\n\t Not Found This Member " << endl;
		}
		cout << "\n\tDo You Want To Search Again? (Y/N) : ";
		cin >> answer;
		system("cls");
		if (answer == 'N' || answer == 'n')
		{
			break;
		}
		else if (answer == 'y' || answer == 'Y')
		{
			continue;
		}

	} while (true);
}

void renamefile(string oldname, string newname) {
	char old[100] = {};
	oldname += ".txt";

	for (int i = 0; i < oldname.size(); i++) {
		old[i] = oldname[i];
	}
	char newn[100] = {};
	newname += ".txt";
	for (int i = 0; i < newname.size(); i++) {
		newn[i] = newname[i];
	}
	int res;
	res = rename(old, newn);

}
void update_book(books arr_of_books[1000], int book_id, members arr_of_members[1000], int member_id)
{
	int choice, ismember, isbook;
	bool isfound = false;
	string search, old_name, new_name;
	cout << "\t1.Enter Book's ID\t\n\n";
	cout << "\t2.Search for A Book\t\n\n";
	do
	{
		error = 0;
		cout << "\n Please Enter Your Selsction Between (1-2) : ";
		cin >> choice;
		if (cin.fail() && choice < 1 || choice > 2)
		{
			cout << "\n\tPlease Enter A Valid Input. " << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	system("cls");
	if (choice == 1)
	{
		cout << "\tEnter The Book's ID : ";
		cin >> search;
		while (true)
		{
			bool isavailable = false;
			system("cls");
			for (int i = 0; i < book_id; i++)
			{
				if (arr_of_books[i].id_of_book == search)
				{
					display_books(arr_of_books, i);
					system("pause");
					cout << "\n\tEnter ID : ";
					getline(cin, arr_of_books[i].id_of_book);
					arr_of_books[i].id_of_book = search_idbook(arr_of_books[i].id_of_book, book_id, arr_of_books);
					old_name = arr_of_books[i].name_of_book;
					cout << "\n\tEnter Name : ";
					getline(cin, arr_of_books[i].name_of_book);
					new_name = arr_of_books[i].name_of_book;
					cout << "\n\tEnter Author : ";
					getline(cin, arr_of_books[i].author);
					cout << "\n\tEnter Year : ";
					getline(cin, arr_of_books[i].year);
					isbook = i;
					isavailable = true;
					if (arr_of_books[i].status_book == "false")
					{
						for (int k = 0; k < member_id; k++)
						{
							if (arr_of_members[k].status_member == "false")
							{
								for (int j = 0; j < arr_of_members[k].number_isbooks; j++)
								{
									if (arr_of_isbooks[k][j].id_of_book == search)
									{
										arr_of_isbooks[k][j].id_of_book = arr_of_books[i].id_of_book;
										arr_of_isbooks[k][j].name_of_book = arr_of_books[i].name_of_book;
										ismember = k;
										isfound = true;
										break;
									}
								}
								if (isfound)
								{
									break;
								}
							}
						}
					}
					if (isfound)
					{
						break;
					}
				}
			}
			if (isavailable == true)
			{
				break;
			}
			else
			{
				cout << "\tThe ID is not Valid\t\n\n";
				cout << "\tEnter The Book's ID : ";
				cin >> search;
			}
		}
		fstream file1("books.txt", std::fstream::out | std::fstream::trunc);
		ofstream file2("books.txt", ios_base::app);
		for (int i = 0; i < book_id; i++)
		{
			file2 << arr_of_books[i].id_of_book << "%" << arr_of_books[i].name_of_book << "#" << arr_of_books[i].author << "$" << arr_of_books[i].year << "@" << arr_of_books[i].status_book << "*";
			if (arr_of_books[i].status_book == "false")
			{
				file2 << arr_of_books[i].name_of_ismember << '|';
				file2 << arr_of_books[i].start_of_time.day << '/' << arr_of_books[i].start_of_time.month << '/' << arr_of_books[i].start_of_time.year << '|';
				file2 << arr_of_books[i].end_of_time.day << '/' << arr_of_books[i].end_of_time.month << '/' << arr_of_books[i].end_of_time.year << '|';
			}
		}
		file2.close();
		if (isfound)
		{
			fstream file5(arr_of_members[ismember].name_of_member + ".txt", std::fstream::out | std::fstream::trunc);
			ofstream file6(arr_of_members[ismember].name_of_member + ".txt", ios_base::app);
			for (int i = 0; i < arr_of_members[ismember].number_isbooks; i++)
			{
				file6 << arr_of_isbooks[ismember][i].id_of_book << '|' << arr_of_isbooks[ismember][i].name_of_book << '|';
				file6 << arr_of_isbooks[ismember][i].start_of_time.day << '/' << arr_of_isbooks[ismember][i].start_of_time.month << '/' << arr_of_isbooks[ismember][i].start_of_time.year << '|';
				file6 << arr_of_isbooks[ismember][i].end_of_time.day << '/' << arr_of_isbooks[ismember][i].end_of_time.month << '/' << arr_of_isbooks[ismember][i].end_of_time.year << '|';
			}
			file6.close();
		}
		if (new_name != old_name)
		{
			renamefile(old_name, new_name);
/*			ofstream newfile;
			newfile.open(new_name + ".txt");
			newfile.close();
			ofstream thefile(new_name + ".txt", ios_base::app);
			for (int i = 0; i < arr_of_books[isbook].numberword; i++)
			{
				thefile << arr_of_words[isbook][i] << " ";
			}
			thefile.close();*/
		}
	}
	else if (choice == 2)
	{
		search_of_book(arr_of_books, book_id, arr_of_words);
	}
}

void update_member(books arr_of_books[1000], int book_id, members arr_of_members[1000], int member_id)
{
	int choice, ismember;
	bool isfound = false;
	string search, old_name, new_name;
	cout << "\t1.Enter Member's ID\t\n\n";
	cout << "\t2.Search for A Member\t\n\n";
	do
	{
		error = 0;
		cout << "\n Please Enter Your Selsction Between (1-2) : ";
		cin >> choice;
		if (cin.fail() && choice < 1 || choice > 2)
		{
			cout << "\n\tPlease Enter A Valid Input. " << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	system("cls");
	if (choice == 1)
	{
		cout << "\tEnter The Member's ID : ";
		cin >> search;
		while (true)
		{
			bool isavailable = false;
			system("cls");
			for (int i = 0; i < member_id; i++)
			{
				if (arr_of_members[i].id_of_member == search)
				{
					display_members(arr_of_members, i);
					system("pause");
					cout << "\n\tEnter ID : ";
					getline(cin, arr_of_members[i].id_of_member);
					arr_of_members[i].id_of_member = search_idmember(arr_of_members[i].id_of_member, member_id, arr_of_members);
					old_name = arr_of_members[i].name_of_member;
					cout << "\n\tEnter Name : ";
					getline(cin, arr_of_members[i].name_of_member);
					new_name = arr_of_members[i].name_of_member;
					cout << "\n\tEnter Password : ";
					getline(cin, arr_of_members[i].pass_of_member);
					ismember = i;
					isavailable = true;
					if (arr_of_members[i].status_member == "false")
					{
						for (int k = 0; k < book_id; k++)
						{
							if (arr_of_books[k].status_book == "false")
							{
								if (arr_of_books[k].name_of_ismember == old_name)
								{
									arr_of_books[k].name_of_ismember = new_name;
									isfound = true;
									break;
								}
							}
						}
					}
					if (isfound)
					{
						break;
					}
				}
			}
			if (isavailable == true)
			{
				break;
			}
			else
			{
				cout << "\tThe ID is not Valid\t\n\n";
				cout << "\tEnter The Member's ID : ";
				cin >> search;
			}
		}
		if (isfound)
		{
			fstream file1("books.txt", std::fstream::out | std::fstream::trunc);
			ofstream file2("books.txt", ios_base::app);
			for (int i = 0; i < book_id; i++)
			{
				file2 << arr_of_books[i].id_of_book << "%" << arr_of_books[i].name_of_book << "#" << arr_of_books[i].author << "$" << arr_of_books[i].year << "@" << arr_of_books[i].status_book << "*";
				if (arr_of_books[i].status_book == "false")
				{
					file2 << arr_of_books[i].name_of_ismember << '|';
					file2 << arr_of_books[i].start_of_time.day << '/' << arr_of_books[i].start_of_time.month << '/' << arr_of_books[i].start_of_time.year << '|';
					file2 << arr_of_books[i].end_of_time.day << '/' << arr_of_books[i].end_of_time.month << '/' << arr_of_books[i].end_of_time.year << '|';
				}
			}
			file2.close();
		}
		fstream file5("members.txt", std::fstream::out | std::fstream::trunc);
		ofstream file6("members.txt", ios_base::app);
		for (int i = 0; i <member_id; i++)
		{
			file6 << arr_of_members[i].id_of_member << '%' << arr_of_members[i].name_of_member << '#';
			file6 << arr_of_members[i].pass_of_member << '$' << arr_of_members[i].date_of_member.day << '/' << arr_of_members[i].date_of_member.month << '/';
			file6 << arr_of_members[i].date_of_member.year << '@' << arr_of_members[i].status_member << '*';
		}
		file6.close();
		if (new_name != old_name)
		{
			renamefile(old_name, new_name);
	/*		ofstream newfile;
			newfile.open(new_name + ".txt");
			newfile.close();
			ofstream thefile(new_name + ".txt", ios_base::app);
			for (int i = 0; i < arr_of_members[ismember].number_isbooks; i++)
			{
				thefile << arr_of_isbooks[ismember][i].id_of_book << '|' << arr_of_isbooks[ismember][i].name_of_book << '|';
				thefile << arr_of_isbooks[ismember][i].start_of_time.day << '/' << arr_of_isbooks[ismember][i].start_of_time.month << '/' << arr_of_isbooks[ismember][i].start_of_time.year << '|';
				thefile << arr_of_isbooks[ismember][i].end_of_time.day << '/' << arr_of_isbooks[ismember][i].end_of_time.month << '/' << arr_of_isbooks[ismember][i].end_of_time.year << '|';
				renamefile(old_name, new_name);
			}
			thefile.close();*/
		}
	}
	else if (choice == 2)
	{
		search_of_member(arr_of_members, member_id);
	}
}

void bowrring_book(books arr_of_books[1000], int book_id, string calender1[370][2], members arr_of_members[1000], int member_id, int rus_member)
{
	char answer;
	int choice;
	int position;
	int bboock;
	bool isfound = false;
	string search, date, DY, MTH;
	tm today = time1();
	cout << "\t1.Enter Book's ID\t\n\n";
	cout << "\t2.Search for A Book\t\n\n";
	cin >> choice;
	do
	{
		error = 0;
		cout << "\n Please Enter Your Selsction Between (1-2) : ";
		cin >> choice;
		if (cin.fail() && choice < 1 || choice > 2)
		{
			cout << "\n\tPlease Enter A Valid Input. " << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	system("cls");
	if (choice == 1)
	{
		cout << "\tEnter The Book's Id : ";
		cin >> search;
		while (true)
		{
			bool isavailable = false;
			system("cls");
			for (int i = 0; i < book_id; i++)
			{
				if (arr_of_books[i].id_of_book == search)
				{
					if (arr_of_books[i].status_book == "true")
					{
						int Year = today.tm_year + 1900;
						int Month = today.tm_mon + 1;
						int Day = today.tm_mday;
						stringstream year;
						year << Year;
						string Y_O_C = year.str();
						stringstream month;
						month << Month;
						string M_O_C = month.str();
						stringstream day;
						day << Day;
						string D_O_C = day.str();
						string NY_O_C = Y_O_C;
						position = 0;
						for (position = 0; position < 365; position++)
						{
							if (calender1[position][0] == D_O_C&& calender1[position][1] == M_O_C)
							{
								break;
							}
						}
						if (position >= 335)
						{
							stringstream year;
							Year += 1;
							year << Year;
							NY_O_C = year.str();
						}
						bboock = i;
						display_books(arr_of_books, i);
						cout << "The Book is booked for you from : " << today.tm_mday << " / " << today.tm_mon + 1 << " / " << today.tm_year + 1900 << " ";
						cout << "till : " << calender1[(position + 30) % 365][0] << '/' << calender1[(position + 30) % 365][1] << '/' << NY_O_C << '\n' << endl;
						system("pause");
						arr_of_books[i].status_book = "false";
						arr_of_books[i].name_of_ismember = arr_of_members[rus_member].name_of_member;
						arr_of_books[i].start_of_time.day = D_O_C;
						arr_of_books[i].start_of_time.month = M_O_C;
						arr_of_books[i].start_of_time.year = Y_O_C;
						arr_of_books[i].end_of_time.day = calender1[(position + 30) % 365][0];
						arr_of_books[i].end_of_time.month = calender1[(position + 30) % 365][1];
						arr_of_books[i].end_of_time.year = NY_O_C;
						arr_of_members[rus_member].status_member = "false";
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].id_of_book = arr_of_books[bboock].id_of_book;
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].name_of_book = arr_of_books[bboock].name_of_book;
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].start_of_time.day = arr_of_books[i].start_of_time.day;
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].start_of_time.month = arr_of_books[i].start_of_time.month;
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].start_of_time.year = arr_of_books[i].start_of_time.year;
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].end_of_time.day = arr_of_books[i].end_of_time.day;
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].end_of_time.month = arr_of_books[i].end_of_time.month;
						arr_of_isbooks[rus_member][arr_of_members[rus_member].number_isbooks].end_of_time.year = arr_of_books[i].end_of_time.year;
						arr_of_members[rus_member].number_isbooks++;
						isavailable = true;
						break;
					}
					else if (arr_of_books[i].status_book == "false")
					{
						cout << "\tThe Book is not Available" << endl;
						isavailable = true;
						break;
					}
				}
			}
			if (isavailable == true)
			{
				break;
			}
			else
			{
				cout << "\tThe ID is not Valid\t\n\n";
				cout << "\tEnter The Book's ID : ";
				cin >> search;
			}
		}
		fstream file1("books.txt", std::fstream::out | std::fstream::trunc);
		ofstream file2("books.txt", ios_base::app);
		for (int i = 0; i < book_id; i++)
		{
			file2 << arr_of_books[i].id_of_book << "%" << arr_of_books[i].name_of_book << "#" << arr_of_books[i].author << "$" << arr_of_books[i].year << "@" << arr_of_books[i].status_book << "*";
			if (arr_of_books[i].status_book == "false")
			{
				file2 << arr_of_books[i].name_of_ismember << '|';
				file2 << arr_of_books[i].start_of_time.day << '/' << arr_of_books[i].start_of_time.month << '/' << arr_of_books[i].start_of_time.year << '|';
				file2 << arr_of_books[i].end_of_time.day << '/' << arr_of_books[i].end_of_time.month << '/' << arr_of_books[i].end_of_time.year << '|';
			}
		}
		file2.close();
		fstream file3("members.txt", std::fstream::out | std::fstream::trunc);
		ofstream file4("members.txt", ios_base::app);
		for (int i = 0; i < member_id; i++)
		{
			file4 << arr_of_members[i].id_of_member << "%" << arr_of_members[i].name_of_member << "#" << arr_of_members[i].pass_of_member << "$";
			file4 << arr_of_members[i].date_of_member.day << '/' << arr_of_members[i].date_of_member.month << '/' << arr_of_members[i].date_of_member.year << '@' << arr_of_members[i].status_member << "*";
		}
		file4.close();
		fstream file(arr_of_members[rus_member].name_of_member + ".txt", ios_base::app | ios_base::out);
		file << arr_of_books[bboock].id_of_book << '|' << arr_of_books[bboock].name_of_book << '|';
		file << arr_of_books[bboock].start_of_time.day << '/' << arr_of_books[bboock].start_of_time.month << '/' << arr_of_books[bboock].start_of_time.year << '|';
		file << arr_of_books[bboock].end_of_time.day << '/' << arr_of_books[bboock].end_of_time.month << '/' << arr_of_books[bboock].end_of_time.year << '|';
		file.close();
	}
	else if (choice == 2)
	{
		search_of_book(arr_of_books, book_id, arr_of_words);
	}
}

void return_book(books arr_of_books[1000], int book_id, members arr_of_members[1000], int member_id, int rus_member)
{
	int choice;
	string search, date, DY, MTH;
	tm today = time1();
	cout << "\t1.Enter Book's ID\t\n\n";
	cout << "\t2.Search for A Book\t\n\n";
	do
	{
		error = 0;
		cout << "\n Please Enter Your Selsction Between (1-2) : ";
		cin >> choice;
		if (cin.fail() && choice < 1 || choice > 2)
		{
			cout << "\n\tPlease Enter A Valid Input. " << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	system("cls");
	if (choice == 1)
	{
		cout << "\tEnter The Book's ID : ";
		cin >> search;
		while (true)
		{
			bool isavailable = false;
			system("cls");
			for (int i = 0; i < arr_of_members[rus_member].number_isbooks; i++)
			{
				if (arr_of_isbooks[rus_member][i].id_of_book == search)
				{
					for (int j = i + 1; j < arr_of_members[rus_member].number_isbooks; j++)
					{
						arr_of_isbooks[rus_member][j - 1].id_of_book == arr_of_isbooks[rus_member][j].id_of_book;
						arr_of_isbooks[rus_member][j - 1].name_of_book == arr_of_isbooks[rus_member][j].name_of_book;
						arr_of_isbooks[rus_member][j - 1].start_of_time.day == arr_of_isbooks[rus_member][j].start_of_time.day;
						arr_of_isbooks[rus_member][j - 1].start_of_time.month == arr_of_isbooks[rus_member][j].start_of_time.month;
						arr_of_isbooks[rus_member][j - 1].start_of_time.year == arr_of_isbooks[rus_member][j].start_of_time.year;
						arr_of_isbooks[rus_member][j - 1].end_of_time.day == arr_of_isbooks[rus_member][j].end_of_time.day;
						arr_of_isbooks[rus_member][j - 1].end_of_time.month == arr_of_isbooks[rus_member][j].end_of_time.month;
						arr_of_isbooks[rus_member][j - 1].end_of_time.year == arr_of_isbooks[rus_member][j].end_of_time.year;
					}
					for (int i = 0; i < book_id; i++)
					{
						if (arr_of_books[i].id_of_book == search)
						{
							display_books(arr_of_books, i);
							cout << "The Book is returned successfully " << endl;
							system("pause");
						}
					}
					arr_of_books[i].status_book = "true";
					if (arr_of_members[rus_member].number_isbooks > 1)
					{
						arr_of_members[rus_member].status_member = "false";
					}
					else if (arr_of_members[rus_member].number_isbooks == 1)
					{
						arr_of_members[rus_member].status_member = "true";
					}
					arr_of_members[rus_member].number_isbooks--;
					isavailable = true;
					break;
				}
			}
			if (isavailable)
			{
				break;
			}
			else if (isavailable == false)
			{
				cout << "\tYou Do Not Have The Book\t\n";
				cout << "\tEnter The Book's ID : ";
				cin >> search;
			}
		}
		fstream file1("books.txt", std::fstream::out | std::fstream::trunc);
		ofstream file2("books.txt", ios_base::app);
		for (int i = 0; i < book_id; i++)
		{
			file2 << arr_of_books[i].id_of_book << "%" << arr_of_books[i].name_of_book << "#" << arr_of_books[i].author << "$" << arr_of_books[i].year << "@" << arr_of_books[i].status_book << "*";
			if (arr_of_books[i].status_book == "false")
			{
				file2 << arr_of_books[i].name_of_ismember << '|';
				file2 << arr_of_books[i].start_of_time.day << '/' << arr_of_books[i].start_of_time.month << '/' << arr_of_books[i].start_of_time.year << '|';
				file2 << arr_of_books[i].end_of_time.day << '/' << arr_of_books[i].end_of_time.month << '/' << arr_of_books[i].end_of_time.year << '|';
			}
		}
		file2.close();
		fstream file3("members.txt", std::fstream::out | std::fstream::trunc);
		ofstream file4("members.txt", ios_base::app);
		for (int i = 0; i < member_id; i++)
		{
			file4 << arr_of_members[i].id_of_member << "%" << arr_of_members[i].name_of_member << "#" << arr_of_members[i].pass_of_member << "$";
			file4 << arr_of_members[i].date_of_member.day << '/' << arr_of_members[i].date_of_member.month << '/' << arr_of_members[i].date_of_member.year << '@' << arr_of_members[i].status_member << "*";
		}
		file4.close();
		fstream file5(arr_of_members[rus_member].name_of_member + ".txt", std::fstream::out | std::fstream::trunc);
		ofstream file6(arr_of_members[rus_member].name_of_member + ".txt", ios_base::app);
		for (int i = 0; i < arr_of_members[rus_member].number_isbooks; i++)
		{
			file6 << arr_of_isbooks[rus_member][i].id_of_book << '|' << arr_of_isbooks[rus_member][i].name_of_book << '|';
			file6 << arr_of_isbooks[rus_member][i].start_of_time.day << '/' << arr_of_isbooks[rus_member][i].start_of_time.month << '/' << arr_of_isbooks[rus_member][i].start_of_time.year << '|';
			file6 << arr_of_isbooks[rus_member][i].end_of_time.day << '/' << arr_of_isbooks[rus_member][i].end_of_time.month << '/' << arr_of_isbooks[rus_member][i].end_of_time.year << '|';
		}
		file6.close();
	}
	else if (choice == 2)
	{
		search_of_book(arr_of_books, book_id, arr_of_words);
	}
}

void check_today(books arr_of_books[1000], int book_id)
{
	bool isfound = false;
	tm today = time1();
	int Year = today.tm_year + 1900;
	int Month = today.tm_mon + 1;
	int Day = today.tm_mday;
	stringstream year;
	year << Year;
	string Y_O_C = year.str();
	stringstream month;
	month << Month;
	string M_O_C = month.str();
	stringstream day;
	day << Day;
	string D_O_C = day.str();
	for (int i = 0; i < book_id; i++)
	{
		if (D_O_C == arr_of_books[i].end_of_time.day && M_O_C == arr_of_books[i].end_of_time.month && Y_O_C == arr_of_books[i].end_of_time.year)
		{
			display_books(arr_of_books, i);
			isfound = true;
		}
	}
	if (!isfound)
	{
		cout << "\n\n\t No book return today\n";
	}
	system("pause");
}

////////////////////////////////////////////////////////////////////