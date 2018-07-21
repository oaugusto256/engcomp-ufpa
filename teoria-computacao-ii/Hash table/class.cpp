/*
    Filename: class.cpp
    Created by Alves Silva, Otavio Augusto
    Date: 05/16/2015    
    Class: CS 163 - Program #3
    Description: This file contains the functions of the class.h  
*/

#include "class.h"

// Constructor
app::app()
{
	name = NULL;
	keywords = NULL;
	key_len = 0;
	desc = NULL;
	rating = 0;
}

// Destructor
app::~app()
{
	delete [] name;
	name = NULL;
	
	for(int i = 0; i < key_len; ++i)
	{
		delete [] keywords[i];
		keywords[i] = NULL;
	}
	
	delete keywords;
	keywords = NULL;
	
	delete [] desc;
	desc = NULL;
}

// Create an app with the provided arguments
int app::create_app(char * new_name, char ** new_keywords, int new_key_len, char * new_desc, int new_rating)
{
	if(!new_name)
		return 0;
	
    name = new char[strlen(new_name)+1];
    strcpy(name, new_name);
	
	key_len = new_key_len;
	
	keywords = new char*[key_len];
	for(int i = 0; i < key_len; ++i)
	{
		keywords[i] = new char[strlen(new_keywords[i])+1];
		strcpy(keywords[i], new_keywords[i]);
	}
	
    desc = new char[strlen(new_desc)+1];
    strcpy(desc, new_desc);
	
	rating = new_rating;
	
	return 1;
}

// This function retrieve the information to the ADT provided,
// but the key_value must have in at least one of the keywords
int app::retrieve(char * key_value, app & to_retrieve)
{
	bool match = false;
	
	// Checking with the ADT has the provided key_value
	for(int i = 0; i < key_len; i++)
	{
		if(!strcmp(key_value, keywords[i]))
			match = true;
	}
	
	// If there is the keyword, the retrieve occurs
	if(match)
	{
	
		if(to_retrieve.name)
		{
			delete [] to_retrieve.name;
			to_retrieve.name = NULL;
		}
	
		if(to_retrieve.keywords)
		{
			for(int i = 0; i < to_retrieve.key_len; ++i)
				delete [] to_retrieve.keywords[i];
		}
	
		if(to_retrieve.desc)
		{
			delete [] to_retrieve.desc;
			to_retrieve.desc = NULL;
		}
	
		to_retrieve.name = new char[strlen(name)+1];
		strcpy(to_retrieve.name, name);
	
		to_retrieve.key_len = key_len;
	
		to_retrieve.keywords = new char*[key_len];
	
		for(int i = 0; i < to_retrieve.key_len; ++i)
		{
			to_retrieve.keywords[i] = new char[strlen(keywords[i])+1];
			strcpy(to_retrieve.keywords[i], keywords[i]);
		}
	
		to_retrieve.desc = new char[strlen(desc)+1];
		strcpy(to_retrieve.desc, desc);
	
		to_retrieve.rating = rating;
	}
	
	if(match)
		return 1;	// Success
	else
		return 0;	// Failed
}

// This function takes the argument and copies it into the app's data members
int app::copy_info(const app & copy_from) 
{
	// If the argument doesn't have data
	if(!copy_from.name)
		return 0;	// Return failed 

    // If the data members already have some thing, 
    // we have to deallocate any memory
    if(name)
        delete [] name;
	
	if(keywords)
	{
		for(int i = 0; i < key_len; ++i)
			delete [] keywords[i];
	}
	
	if(desc)
		delete [] desc;
	
	// Setting pointers to NULL for safety
	name = NULL;
	keywords = NULL;
	desc = NULL;
	
	// Starting perform a deep copy
    name = new char[strlen(copy_from.name)+1];
    strcpy(name, copy_from.name);
	
	key_len = copy_from.key_len;
	
	keywords = new char*[key_len];
	
	for(int i = 0; i < key_len; ++i)
	{
		keywords[i] = new char[strlen(copy_from.keywords[i])+1];
		strcpy(keywords[i], copy_from.keywords[i]);
	}
	
    desc = new char[strlen(copy_from.desc)+1];
    strcpy(desc, copy_from.desc);
	
	rating = copy_from.rating;
	
	return 1;	// Return success
}

// This function displays the app information
int app::display_info()
{
	if(!name)
		return 0;
	
	cout <<"App name: " << name << endl;
	cout <<"Key words: ";
	
	for(int i = 0; i < key_len; i++)
	{
		if(i == key_len-1)
			cout << "#" << i+1 << "- "<<  keywords[i] << "." << endl;
		else
			cout << "#" << i+1 << "- "<<  keywords[i] << ", ";		
	}
	
	cout <<"Description: " << desc << endl;
	cout <<"Rating: " << rating << endl;
	cout << "-------------------------------------------------" << endl;
	
	return 1;
}

// Constructor
table::table(int table_size, int amount_of_apps)
{
	hash_table_size = table_size;	// Hash table size
		
	number_of_apps = 0;				// Number of apps which have already been added
	
	list_of_apps = new app[amount_of_apps];		// List of apps which will be added in the hash table
	
	hash_table = new node*[hash_table_size]; 	// Hash table

    for(int i = 0; i < hash_table_size; ++i)    // Point each pointer to NULL
		hash_table[i] = NULL;
}

// Destructor
table::~table()
{
	// For each element in the hash table
	for(int i = 0; i < hash_table_size; ++i)
	{
		if(!hash_table[i])			// If there has nothing
			delete hash_table[i];	// Delete the pointer
		else
		{
			while(hash_table[i])					// While isn't NULL
			{
	   			node * temp = hash_table[i]->next;	// Take the next pointer
	    		delete hash_table[i];				// Delete the node
	    		hash_table[i] = temp; 				// Retrieve the node
			}	
		}
	}
}

// Hash function
int table::hash_function(char * keyword) const
{
	int key, len, value = 0;	// Variables to store the key
								// The len of the keyword
								// The keyword value
	                                                                                                                                                 
	len = strlen(keyword);   	// Take the len                                       
	for(int i = 0; i < len; i ++)                                                     
		value += keyword[i]; 	// Sum all ASCII values of this keyword
	
	key = value % hash_table_size;	// Modulize the value and receive the key
		  
	return key;					// Return the key
}

// This function insert the provided app
// into a specific location in the table
// which is provided by the key
int table::insert(char ** keywords, int key_len, const app & to_add)
{
	int key;						// Variable to hold key of the keywords
	int len = key_len;				// Lenght of the keywords
	
	app * new_app = new app;		// Create a new app
	new_app->copy_info(to_add);		// Copy informations of the 
									// argument to this new app
	
	for(int i = 0; i < key_len; ++i)// For each keyword
	{
		node * temp = new node;		// Create a new node
		
		temp->an_app = new_app;		// Point the node pointer to the new app
		
		key = hash_function(keywords[i]); // Take the key position
		
		temp->next = hash_table[key];		// Insert the node in the table
		hash_table[key] = temp;				// Update the first node
	}
	
	list_of_apps[number_of_apps].copy_info(to_add); // Insert this new app in the list
	number_of_apps += 1;							// Increase the numbers of apps
	
	return 1;
}

// This function tries to retrieve an app information, but
// the keyword must have to match

int table::retrieve(char * keyword, app * & found, int & list_len)
{
	int key, success = 0;
	int i = 0;
	int len = 0;
	
	key = hash_function(keyword);	// Take the key position of the retrieve
	
	node * temp = hash_table[key];	// Create a pointer for this position
	
	while(temp)						// Count the number of nodes of this chaining
	{
		len += 1;
		temp = temp->next;
	}
	
	list_len = len;				//	Update the value of the list_len	
	found = new app[len];		//  Allocate memory for the argument provided
								//  with the exactly amount of memory necessary 
	temp = hash_table[key];		//  Point the pointer for the beginner
	
	while(temp)					// While the chaining has nodes
	{
		success = temp->an_app->retrieve(keyword, found[i]);	// Try to retrieve the app which has the key_value
		temp = temp->next;										// Point the next
		if(success)												// If success increase the pointer of the list of apps
			i += 1;
	}
	
	return success;
}

int table::display(char * keyword, app * & apps_found, int & list_len)
{	
	if(!number_of_apps)			// If the number of apps is zero
		return 0;				// Return failed
			
	if(retrieve(keyword, apps_found, list_len))		// Try to retrieve the apps with the provided keyword
	{	
		for(int i = 0; i < list_len; ++i)			
		{
			apps_found[i].display_info();			// Display all apps with the provided keyword
		}
		return 1;
	}
	
	return 0;
}

int table::display_all() const
{
	if(!number_of_apps)			// If the number of apps is zero
		return 0;				// Return failed
	
	for(int i =0; i < number_of_apps; i++)		// For each app in the app list
		list_of_apps[i].display_info();			// Display info
	
	return 1;
}


