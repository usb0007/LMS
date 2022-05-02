#ifndef LIB_H     //defining header file
#define LIB_H

#include<iostream>   //including libraries
#include<sstream>
#include<fstream>
#include <set> 


using namespace std;

class book    //creating book class
{	
	string bid, name, author, publisher;
	
	public:
		book() {}  // Default Constructer
		book(string bid, string name,string author, string publisher,bool writeToFile) // Parameterized Constructor
		
		{
			this->bid=bid;
			this->name=name;
			this->author=author;
			this->publisher=publisher;
			
			if(writeToFile)
			{
				write();
			}
			}
			
			// write fucntion to write into the book.txt file.
			void write() 
			{
				ofstream out;
				out.open("Book.dat", std::fstream::app);
				out<<bid<<" "<<name<<" "<<author<<" "<<publisher<<endl;
				out.close();

				}
};

//creating user class and inheriting book class
class user:public book 
{
	protected:
		string eno,name,phone,email,pass,enroll,password;
	
	public:
		user(){} //default  Constructor
		user(string eno,string name, string phone, string email,string pass, bool writeToFile)   // Parameterized Constructor
		{
			this->eno = eno;
			this->pass = pass;
			this->name = name;
			this->phone = phone;
			this->email = email;
			
			if(writeToFile)
			{
				ofstream out;
				out.open("User.dat", std::fstream::app);
				out<<eno<<" "<<name<<" "<<phone<<" "<<email<<" "<<pass<<endl;
				out.close();
			}
		}
		
		
		//registration of user
		void signup() 
		{
			system("clear");
			//cout<<"Enter Enrollment :-> ";
			//cin>>eno;
			cout<<"Enter First Name :-> ";
			cin>>name;
			cout<<"Enter Password :-> ";
			cin>>pass;
			cout<<"Enter Contact no :-> ";
			cin>>phone;
			cout<<"Enter Email Id :-> ";
			cin>>email;
			
			int flag = 0;
			string key;
			key=eno;
			ifstream in;
			in.open("User.dat");
			
 			set<int> s1;      // declaring Set s1
 			 
			while(!in.eof())
			{
				 	string u1;
					getline(in,u1);
	
					if(u1.length() > 0)
					{
						
						stringstream ss(u1);
						string u1_eno, u1_name, u1_phone, u1_email, u1_pass;
						
						ss>>u1_eno>>u1_name>>u1_phone>>u1_email>>u1_pass;
				
						int num=stoi(u1_eno);
						s1.insert(num);
						   						
						cout<<endl;
						
					}
			}
			while(!in.eof())
			{
				string u2;
				getline(in,u2);
	
				if(u2.length() > 0)
				{
	   				stringstream ss(u2);
	   				string u2_eno, u2_name, u2_phone, u2_email, u2_pass;
	   				ss>>u2_eno>>u2_name>>u2_phone>>u2_email>>u2_pass;
			
	   				if(eno == key)
					{
						flag = 1;
						cout<<"User Already Exixts..";
						in.close();
						break;
					}			
				}
			}
			if(flag == 0)
				{
					int max_element=0;
					if (!s1.empty())
        				max_element = *(s1.rbegin());
        				
        				int id=max_element + 1;
        				
        				eno= to_string(id);
					user user1{eno,name, phone, email, pass, true};
			
					fstream out;
					out.open("user_sign.dat",std::fstream::app);
					out<<eno<<" "<<pass<<endl;
					out.close();
			
					cout<<endl<<"***** Successfully Created User account *****"<<endl;
					cout<<"Your eno is:  "<<eno<<"  your password : "<<pass<<endl;
					cout<<"\n\n";
					
				}	

		}
		
		
		void signin() //sign in for user
		{
			system("clear");
			cout<<endl<<"Enter Enrollment: ";
			cin>>eno;
			cout<<"Enter Password: ";
			cin>>pass;
			
			ifstream in;
			in.open("user_sign.dat");
			
			if(in.eof())
			{
				cout<<endl<<"!!! Wrong Enrollment Number or Password, Try again later "<<endl;	
			}
			else
			{
				int flag=0;
				while(!in.eof())
				{
					
					string user1;
					getline(in,user1);
	
					if(user1.length() > 0)
					{
						stringstream ss(user1);
						ss>>enroll>>password;
						
						if(enroll==eno && password==pass)
						{
							flag=1;
							int check=-1;
							cout<<endl<<"***** Successfully logged in as User *****"<<endl;
							while(check!=0)
							{
								cout<<endl<<"Available Choices :"<<endl<<endl;
								cout<<endl<<"1 - View All Books"<<endl;
								cout<<"2 - Issue Book"<<endl;
								cout<<"3 - Issued Books"<<endl;
								cout<<"4 - Return Book"<<endl;
								cout<<"0 - Logout"<<endl;
								
								cout<<endl<<"Enter your choice :-> ";
								cin>>check;
								
								switch(check)
								{
									case 1: viewAllBooks();
										break;
									case 2: issueBook();
										break;
									case 3: viewMyIssuedBooks();
										break;
									case 4: returnBook();
										break;
									default: cout<<endl<<"User logged Out Successfully..\n"<<endl;
								}
							}
						}
					}
				}
				if(flag==0)
				{
					cout<<endl;
					cout<<"!!!  User not found  !!!"<<endl<<endl;
				}
			}
			in.close();
		}
		
		
		
		void returnBook() //return a book that is issued by user 
		{
			system("clear");
			cout<<endl<<"Your Bookshelf : "<<endl<<endl;
			viewMyIssuedBooks();
			
			ofstream out;
			out.open("temp.dat", std::fstream::out);
			
			string key2;
			
			cout<<endl;
			cout<<"Enter Enrollment no :-> ";
			cout<<enroll<<endl;
			cout<<"Enter Book Id :-> ";
			cin>>key2;
			
			ifstream in;
			in.open("Issued_Books.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No data present in the record  !!!"<<endl;	
			} 
			else 
			{
				int flag = 0;
				while(!in.eof())
				{
					
					string issue;
					getline(in,issue);
	
					if(issue.length() > 0)
					{
						stringstream ss(issue);
						string rb_eno, bid;
						ss>>eno>>bid;
			
						if(rb_eno == enroll && bid == key2)
						{
							flag = 1;
						}
						else
						{
							out<<enroll<<" "<<bid<<endl;
						}
					}
				}
				
				if(flag == 0)
				{
					cout<<endl;
					cout<<"!!!  No Records found  !!!"<<endl;
				}
				else
				{
					cout<<endl;
					cout<<"***** Returned successfully *****"<<endl;
				}
			}
	
			
			in.close();
			out.close();
			
			remove("Issued_Books.dat");
			rename("temp.dat","Issued_Books.dat");
		}
		
		
		
		
		void viewAllBooks() //view all books 
		{
			system("clear");
			ifstream in;
			in.open("Book.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No book present in shelf  !!!"<<endl;	
			}
			else
			{
				while(!in.eof())
				{
					string book;
					getline(in,book);
	
					if(book.length() > 0)
					{
						stringstream ss(book);
						string vab_bid, vab_name, vab_author, vab_publisher;
						ss>>vab_bid>>vab_name>>vab_author>>vab_publisher;
				
						cout<<endl;
						cout<<"Book Id :-> "<<vab_bid<<endl;
						cout<<"Name :-> "<<vab_name<<endl;
						cout<<"Author :-> "<<vab_author<<endl;
						cout<<"Publisher :-> "<<vab_publisher<<endl;
					}
				}
			}
			in.close();
		}
		
		
		
		
		void issueBook() //issue a book
		{	
			system("clear");
			int flag=0;
			viewAllBooks();
		
			string enrollno, bid;
			
			cout<<endl;
			cout<<"Enter Enrollment no :-> ";
			cout<<enrollno<<endl;
			cout<<"Enter Book Id :-> ";
			cin>>bid;
			
			ifstream in;
			in.open("Book.dat");
			while(!in.eof())
			{
				string book;
					getline(in,book);
	
					if(book.length() > 0)
					{
						stringstream ss(book);
						string b_id;
						ss>>b_id;
						
						if(b_id==bid)
						{
							flag=1;
							cout<<endl<<"***** Book issued Successfully *****"<<endl;							
							ofstream out;
							out.open("Issued_Books.dat", std::fstream::app);
							out<<enrollno<<" "<<bid<<endl;
							out.close();
						}					
					}						
			}	
			if(flag==0)
						cout<<endl<<"!!!  Requested Book is not available  !!"<<endl;
			in.close();
		}
		
		
		
		
		void viewMyIssuedBooks() //view book that is issued by user 
		{
			system("clear");
			ifstream in;
			in.open("Issued_Books.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No Issue present in the record  !!!"<<endl;	
			}
			else
			{
				int flag=0;
				while(!in.eof())
				{
					string book;
					getline(in,book);
	
					if(book.length() > 0) 
					{
						stringstream ss(book);
						string vmi_eno,bid;
						ss>>vmi_eno>>bid;
						
						if(enroll==eno)
						{
							cout<<endl;
							flag=1;
							cout<<"Name :-> "<<vmi_eno<<endl;
							cout<<"Book Id :-> "<<bid<<endl;	
						}
					}
				}
				if(flag==0)
					cout<<endl<<"!!!  You have not issued any books  !!!"<<endl;
			}
		}
};

class librarian:public user //creating librarian class and inheriting the user class 
{
	public:
		librarian(){} // Default Constructor

		void signup()
		{
			system("clear");
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Password: ";
			cin>>pass;
			
			fstream out;
			out.open("Librarian_sign.dat",std::fstream::app);
			out<<name<<" "<<pass<<endl;
			out.close();
			
			cout<<endl<<"***** Successfully created Librarian account *****"<<endl;
			cout<<"Your name is:  "<<name<<"  your password : "<<pass<<endl;
		}
		
		
		
		void signin() //sign in for librarian
		{
			system("clear");
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Password: ";
			cin>>pass;
			
			ifstream in;
			in.open("Librarian_sign.dat");
			
			if(in.eof())
			{
				cout<<endl<<"Wrong Username or Password, Try again later "<<endl;	
			}
			else
			{
				int flag=0;
				while(!in.eof())
				{
					string user;
					getline(in,user);
	
					if(user.length() > 0)
					{
						stringstream ss(user);
						string lname,password;
						ss>>lname>>password;
						
						if(lname==name && password==pass)
						{
							flag=1;
							int check=-1;
							cout<<endl<<"***** Successfully logged in as Librarian. *****"<<endl;
							while(check!=0)
							{
								cout<<endl<<"Available Choices :"<<endl<<endl;
								cout<<endl<<"1 - Create New User"<<endl;
								cout<<"2 - Search User"<<endl;
								cout<<"3 - View All Users"<<endl;
								cout<<"4 - Insert Book"<<endl;
								cout<<"5 - View All Books"<<endl;
								cout<<"6 - Issue Book"<<endl;
								cout<<"7 - Search Books"<<endl;
								cout<<"8 - Issued Books"<<endl;
								cout<<"9 - Return Book"<<endl;
								cout<<"10 - Delete User"<<endl;
								cout<<"0 - Logout"<<endl;
								
								cout<<endl<<"Enter your choice :-> ";
								cin>>check;
								
								switch(check)
								{
									case 1: signup();
										break;
									case 2: searchUser();
										break;
									case 3: viewAllUsers();
										break;
									case 4: insertBook();
										break;
									case 5: viewAllBooks();
										break;
									case 6: issueBook();
										break;
									case 7: searchBook();
										break;	
									case 8: viewIssuedBooks();
										break;
									case 9: returnBook();
										break;
									case 10: deleteUser();
										break;
									default: cout<<endl<<"Librarian logged Out Successfully..\n"<<endl;
								}
							}
						}
					}	
				}
				if(flag==0)
				{
					cout<<endl;
					cout<<"!!!  Librarian not found  !!!"<<endl<<endl;
				}
			}
			in.close();
		}
		
		
		
		
		void viewAllUsers() //view all users
		{
			system("clear");
			ifstream in;
			in.open("User.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No user present in the record  !!!"<<endl;	
			}
			else 
			{
				while(!in.eof())
				{
					string user;
					getline(in,user);
	
					if(user.length() > 0)
					{
						stringstream ss(user);
						string eno, name, phone, email;
						ss>>eno>>name>>phone>>email;
						cout<<endl;
						cout<<"Enrollment No :-> "<<eno<<endl;
						cout<<"Name :-> "<<name<<endl;
						cout<<"Phone No :-> "<<phone<<endl;
						cout<<"Email :-> "<<email<<endl;	
					}
				}	
			}
	
			in.close();
		}
		
		
		
		
		void searchUser() //search a user
		{
			system("clear");
			string key;
			cout<<endl;
			cout<<"Enter Enrollment no :-> ";
			cin>>key;
			
			ifstream in;
			in.open("User.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No user present in the record  !!!"<<endl;	
			}
			else
			{
				int flag = 0;
				while(!in.eof())
				{
					string user;
					getline(in,user);
	
					if(user.length() > 0)
					{
						stringstream ss(user);
						string eno, name, phone, email;
						ss>>eno>>name>>phone>>email;
			
						if(eno == key)
						{
							flag = 1;
							cout<<endl;
							cout<<"Enrollment No :-> "<<eno<<endl;
							cout<<"Name :-> "<<name<<endl;
							cout<<"Phone No :-> "<<phone<<endl;
							cout<<"Email :-> "<<email<<endl;
							break;
						}			
					}
				}
				
				if(flag == 0)
				{
					cout<<endl;
					cout<<"!!!  User not found  !!!"<<endl<<endl;
				}	
			}
			in.close();
		}
	
	
	
	
		void deleteUser() //delete the user
		{
			system("clear");
			ofstream out;
			out.open("temp.dat", std::fstream::out);
			
			string key;
			cout<<endl;
			cout<<"Enter Enrollment no :-> ";
			cin>>key;
			
			ifstream in;
			in.open("User.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No user present in the record  !!!"<<endl;	
			}
			else
			{
				int flag = 0;
				while(!in.eof())
				{
					string user;
					getline(in,user);
	
					if(user.length() > 0)
					{
						stringstream ss(user);
						string eno, name, phone, email;
						ss>>eno>>name>>phone>>email;
			
						if(eno == key)
						{
							flag = 1;
						}
						else
						{
							out<<eno<<" "<<name<<" "<<phone<<" "<<email<<endl;
						}
					}
				}
				
				if(flag == 0)
				{
					cout<<endl;
					cout<<"!!!  No user found  !!!"<<endl;
				}
				else
				{
					cout<<endl;
					cout<<"***** User Deleted Successfully *****"<<endl;
				}
			}
	
			
			in.close();
			out.close();
			
			remove("User.dat");
			rename("temp.dat","User.dat");
		}
			
		
		
		void viewIssuedBooks() //view a book that is issued
		{
			system("clear");
			ifstream in;
			in.open("Issued_Books.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No book present in the record  !!!"<<endl;	
			}
			else
			{
				while(!in.eof())
				{
					string issue;
					getline(in,issue);
	
					if(issue.length() > 0)
					{
						stringstream ss(issue);
						string eno, bid;
						ss>>eno>>bid;
			
						cout<<endl;
						cout<<"Enrollment No :-> "<<eno<<endl;
						cout<<"Book Id :-> "<<bid<<endl;	
					}
				}	
			}
	
			in.close();
		}
		
		
		
		
		void insertBook() //inserting book details
		{
			system("clear");
			string bid, name, author, publisher;
	
			cout<<endl;
			//cout<<"Enter Book Id :-> ";
			//cin>>bid;
			cout<<"Enter Book Name :-> ";
			cin>>name;
			cout<<"Enter Author Name :-> ";
			cin>>author;
			cout<<"Enter Publisher :-> ";
			cin>>publisher;
			
			int flag = 0;
			string key;
			key=bid;
			ifstream in;
			in.open("Book.dat");
			set<int> s1; // declaring Set s1
			
 			while(!in.eof())
			{
				 	string text;
					getline(in,text);
	
					if(text.length() > 0)
					{
						
						stringstream ss(text);
						string ib_bid, ib_name, ib_author, ib_publisher;
						
						ss>>ib_bid>>ib_name>>ib_author>>ib_publisher;
				
						int num=stoi(ib_bid);
						s1.insert(num);
						   						
						cout<<endl;
						
					}
			}
			
			while(!in.eof())
				{
					string book;
					getline(in,book);
	
					if(book.length() > 0)
					{
						stringstream ss(book);
						string ib1_bid, ib1_name, ib1_author, ib1_publisher;
						ss>>ib1_bid>>ib1_name>>ib1_author>>ib1_publisher;
			
						if(bid == key )
						{
							flag = 1;
							cout<<"Book Already Exists";
							in.close();
							break;
						}			
					}
				}
				
				if(flag == 0)
				{
					int max_element=0;
					if (!s1.empty())
        				max_element = *(s1.rbegin());
        				//cout<<"sadsadasdsadasd  "<<max_element;
        				int id=max_element + 1;
        				
        				bid= to_string(id);
					
					book book{bid, name, author, publisher, true};
					cout<<"Book Added Successtully..";
					
				}		
		}
		
		
		
		void searchBook() //search a book
		{
			system("clear");
			string key;
			
			
			cout<<endl;
			cout<<"Enter Book Id :-> ";
			cin>>key;
			
			ifstream in;
			in.open("Book.dat");
	
			if(in.eof())
			{
				cout<<endl<<"!!!  No Book present in the record  !!!"<<endl;	
			}
			else
			{
				int flag = 0;
				while(!in.eof())
				{
					string book;
					getline(in,book);
	
					if(book.length() > 0)
					{
						stringstream ss(book);
						string bid, name, author, publisher;
						ss>>bid>>name>>author>>publisher;
			
						if(bid == key)
						{
							flag = 1;
							cout<<endl;
							cout<<"Book Id :-> "<<bid<<endl;
							cout<<"Name :-> "<<name<<endl;
							cout<<"Author :-> "<<author<<endl;
							cout<<"Publisher :-> "<<publisher<<endl;
							break;
						}			
					}
				}
				
				if(flag == 0)
				{
					cout<<endl;
					cout<<"!!!  Book not found  !!!"<<endl<<endl;
				}	
			}
			in.close();
		}
		
};

#endif
