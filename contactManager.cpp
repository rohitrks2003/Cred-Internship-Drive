#include<bits/stdc++.h>
#include "Services.cpp"
using namespace std;


// Struct to support Trie datatype
struct Trie
{
	vector<Contact> containsWord;
	Trie* children[26];
	
	Trie()
	{
		for(int i=0;i<26;i++)
		{
			children[i]=NULL;
		}
		containsWord.clear();
	}
};

// Inheritence

class contactManager:public Services
{
	Trie* root;
	vector<Contact> result;
	
	public:
	
	contactManager()
	{
		root=new Trie();
	}
	
	// this function is used to add a new contact in contact list
	void addContact(string firstName,string lastName,string contactNumber)
	{
		if(!checkValidContactNumber(contactNumber) or !checkValidName(firstName) or !checkValidName(lastName))
		{
			return;
		}
		if(firstName.length()==0)
		{
			return;
		}
		
		Contact person=Contact(firstName,lastName,contactNumber);
		
		int firstNameLength=firstName.length();
		Trie* node=root;
		
		
		for(int i=0;i<firstNameLength;i++)
		{
			char currentCharacter=firstName[i];
			currentCharacter=convertToLowerCase(currentCharacter);
			int indexOfCurrentCharacter=currentCharacter-'a';
			
			if(node->children[indexOfCurrentCharacter]==NULL)
			{
				node->children[indexOfCurrentCharacter]=new Trie();
			}
			node=node->children[indexOfCurrentCharacter];
		}
		node->containsWord.push_back(person);
		cout<<"INFO: Contact Successfully Added\n";
	}
	
	// This is a helper function that will help in the searching process
	void searchInSubtree(Trie* node,Contact prefixContact)
	{
		for(auto contactDetails:node->containsWord)
		{
			if(isTheContactMatching(contactDetails,prefixContact))
			{
				result.push_back(contactDetails);
			}
		}
		for(int i=0;i<26;i++)
		{
			if(node->children[i]!=NULL)
			{
				searchInSubtree(node->children[i],prefixContact);
			}
		}
	}
	
	
	// first we will locate the first name up to prefix 
	// and then we will find all the name under that subtree
	vector<Contact> searchContact(string firstNamePrefix,string lastNamePrefix,string contactNumberPrefix)
	{
		result.clear();
		Trie* node=root;
		int firstNamePrefixLength=firstNamePrefix.length();
		for(int i=0;i<firstNamePrefixLength;i++)
		{
			char currentCharacter=firstNamePrefix[i];
			currentCharacter=convertToLowerCase(currentCharacter);
			int indexOfCurrentCharacter=currentCharacter-'a';
			
			
			if(node->children[indexOfCurrentCharacter]==NULL)
			{
				return result;
			}
			node=node->children[indexOfCurrentCharacter];
		}
		
		// now we have got the node from which we can apply dfs to find
		// all the person satisifying the condition
		
		Contact prefixContact=Contact(firstNamePrefix,lastNamePrefix,contactNumberPrefix);
		searchInSubtree(node,prefixContact);
		return result;
	}
};
