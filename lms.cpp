#include <iostream>     //including libraries
#include "lms.h"       //including header file

using namespace std;


//main method
int main() 
{
	int choice = -1;
	
	system("clear");
	
    	
    	cout<<"\n\t\t\t      **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**"<<endl;
    	cout<<"\n\t\t\t      **                                                             **"<<endl;
    	cout<<"\n\t\t\t      **    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=    **"<<endl;
    	cout<<"\n\t\t\t      **    =                    WELCOME TO                     =    **"<<endl;
    	cout<<"\n\t\t\t      **    =             LIBRARY MANAGEMENT SYSTEM             =    **"<<endl;
    	cout<<"\n\t\t\t      **    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=    **"<<endl;
    	cout<<"\n\t\t\t      **                                                             **"<<endl;
    	cout<<"\n\t\t\t      **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n"<<endl;
    	
    	cout<<"\n\t\t\t      **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**"<<endl;	
    	cout<<"\n\t\t\t      **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**"<<endl;
    	cout<<"\n\t\t\t      **                                                             **"<<endl;
    	cout<<"\n\t\t\t      **    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-                                                 -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-               TEAM MEMBERS                      -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-              _______________                    -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-                                                 -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-              1.  Arjit Dubey                    -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-              2.  Dinesh Jagtap                  -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-              3.  Krishna Vishwakarma            -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-              4.  Rahul Malik                    -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-              5.  Ummed Singh                    -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-                                                 -=    **"<<endl;
    	cout<<"\n\t\t\t      **    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=    **"<<endl;
    	cout<<"\n\t\t\t      **                                                             **"<<endl;
    	cout<<"\n\t\t\t      **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**"<<endl;
    	cout<<"\n\t\t\t      **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n"<<endl;
	
	
	while(choice!=0)
	{
		cout<<endl<<"Available Choices :"<<endl<<endl;
		cout<<"1 - User Signup"<<endl;
		cout<<"2 - Librarian Signup"<<endl;
		cout<<"3 - User Login"<<endl;
		cout<<"4 - Librarian Login"<<endl;
		cout<<"0 - Exit"<<endl;
		
		cout<<endl<<"Enter your choice : -> ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				user user;
				user.signup();
			}
				break;
			case 2:
			{
				librarian lib;
				lib.signup();
			}
				break;
			case 3:
				{
					user user;
					user.signin();
				}
				break;
			case 4:
				{
					librarian lib;
					lib.signin();
				}
				break;
			default:
				cout<<endl<<"Warning :-> System Closing..."<<endl;
				cout<<endl<<".."<<endl;
				cout<<endl<<"."<<endl;
				//system("clear");
				
		}
	}
	cout<<endl<<endl<<"--------------------------------------------------------------";
	cout<<endl<<"|********** Thank You for Using Library Management **********|"<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
	return 0;
}//End of main
