/*
    Filename: main.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 05/16/2015    
    Class: CS 163 - Program #3
    Description: This file tests the ADT's and shows how the program could 
	be used by the user.
*/

#include "class.h"

void clear();   // Clear function
int menu();     // Menu function

int main()
{
	// Variables to create a new app in the system
	char name[SIZE];
	char ** keywords;
	char * keyword = new char[SIZE];
	int key_len;
	char desc[SIZE];
	int rating;
	
	app an_app;				// ADT app
	table a_table(11, 100);	// ADT Table - Hash table (Size of the hash table, Probable amount of apps)
	app * list_of_apps;		// Pointer to an app - Auxiliar an array of apps
	int list_len;			// Length of the array of apps

	int option;				// Option of the menu
	
	clear();				// Clear the system screen
		
	do					    // Loop for the menu
	{					
		option = menu();	// Shows the menu and receive the option
		
        switch(option)
        {
            case 1:
				// If the option is 1
				// Receive data to create an new app 
				cout << "Please, enter the application name: ";
				cin.get(name, SIZE, '\n');
				cin.ignore(SIZE, '\n');
	
				do
				{
					cout << "Please, enter the number of keywords(0-5) for this application: ";
					cin  >> key_len; 
					cin.ignore(SIZE, '\n');
		
					if(key_len > 5 || key_len <= 0)
						cout << "ERROR! Please enter a number smaller than 6 and greater than 0!" << endl;
					
				}while(key_len > 5 || key_len <= 0);
				
				keywords = new char*[key_len];
				
	
				cout << "Please, enter the keywords for this application." << endl;
				for(int i = 0; i < key_len; i++)
				{
					keywords[i] = new char[SIZE];
					cout << "#" << i+1 << " - Keyword: ";
					cin.get(keywords[i], SIZE, '\n');
					cin.ignore(SIZE, '\n');
				}
				
				cout << "Enter a description for this application: ";
				cin.get(desc, SIZE, '\n');
				cin.ignore(SIZE, '\n');
	
				cout << "Enter a rating(0-5) for this application: ";
				cin >> rating;
				cin.ignore(SIZE, '\n');
				
				// Try to create a new app and add the new app in the system
				if(an_app.create_app(name,keywords,key_len,desc,rating))
				{
					cout << "\n";
					if(a_table.insert(keywords, key_len, an_app))
						cout << "The app was successfully inserted!\n" << endl;
				}
			
				break;
			case 2:
				// If the option is 2
				// Try to find an app with the provided keyword
				cout << "Enter the app keyword to find: ";
				cin.get(keyword, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
					if(!a_table.display(keyword, list_of_apps, list_len))
					cout << "Sorry, we couldn't find any app which has that keyword!" << endl;
				
				break;
			case 3:
				// If the option is 3
				// Display all apps
				if(!a_table.display_all())
					cout << "Sorry, none app was inserted in the system yet!" << endl;
				break;
			default:
				clear();
		}
	}while(option != 0);
	
	return 0;
}

void clear(void)
{
    cout << "\033[H\033[J";
}

int menu()
{
    int option;
    
    cout << "----------------- SMART FIND APP ----------------" << endl;
    cout << "1 - Add an app to easily find in the future." << endl;
    cout << "2 - Find an app or a group of apps by a keyword." << endl;
    cout << "3 - Display all apps in the system." << endl;
    cout << "0 - Exit." << endl;
    
    do
    {
        cout << "Enter an option: ";
        cin >> option;
        cin.ignore(100,'\n');
    }
    while(option < 0 && option > 4);
    
    clear();
    
    return option;
}