/* 
	Algorithm
	Start program
		Creates variables to keep information from a app order
			App name
			Array of keywords
			Number of keywords
			App description
			Rating
		Create ADT app and table
			An app	
			Tabla with the hash table size and the probable amount of apps that will be used
		
		Loop - While the option isn't 0 - EXIT
			Display the menu for the user
				If the option is 1 - Add an app
					Take the app information
					Create an app
					Insert the app in the table with the key position
					Increase the number of apps inserted
				If the option is 2 - Display an app or apps with the keyword 
					Find the key position with the keyword
					Try to match the keyword with app which the node is point
					If match
						Retrieve the information
						Insert in the list of apps 
					Else
						Traversal to the next node

					Display the list of apps found
				If the option is 3
					Display all apps inserted until now
				If the option is 0
					Close the application
				Else
					Clear the terminal
					Display the menu for the user
		End loop
		
	End program
*/

/*
    Filename: class.h
    Created by Alves Silva, Otavio Augusto
    Date: 05/16/2015    
    Class: CS 163 - Program #3
    Description: The purpose of this program is to simulate an away to storage some information
	about smartphone applications to easily find in the future. We are goind to use a hash table
	to organize these informations. The program will take care of some informations, which are the 
	app name, keywords, description and a rating of the app. Therefore, in this file we have the ADT
	(Application and Table) to bring life to this program, as well as the prototypes, constructors 
	and destructors of each class.  
*/


#include <ctime>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

int const SIZE = 100;

// ADT of an app
class app
{
	public:
		app();		// Constructor
		~app();		// Destructor
		
		int create_app(char * name, char ** key_words, int key_len, char * desc, int rating);	// Create an app
		int retrieve(char * key_value, app & to_retrieve);	// Retrieve information from the ADT
		int copy_info(const app & copy_from);				// Copy information from the ADT
		int display_info();									//  Display the app information
		
	private:
		char * name;		// App name
		char ** keywords;	// List of keywords of this app
		int key_len;		// Size of the list
		char * desc;		// App description 
		int rating;			// App rating
};

// Struct of the node
struct node
{
	app * an_app;	// Point for an app
	node * next;	// Point for the next node
};

// ADT of the table
class table
{
	public:
		table(int table_size, int amount_of_apps);	// Constructor
		~table();									// Destructor
		
		int hash_function(char * key_word) const;		// Hash function
		int insert(char ** key_words, int key_len, const app & to_add);  // Insert an app in the table
		int retrieve(char * key_word, app * & found, int & list_len);	 // Retrieve information from an app in the table
		int display(char * key_word, app * & found, int & list_len);	 // Display all apps with a specific keyword	
		int display_all() const;					// Display all apps which have already been added		
	
	private:
		node ** hash_table;		// Array of pointers of nodes
		int hash_table_size;	// Hash table size
		app * list_of_apps;		// List of apps which the hash table will have
		int number_of_apps;		// Number of apps which have already been added
};