#include<bits/stdc++.h>
#include "contact.cpp"
using namespace std;

class contactManager
{
	vector<Contact> listOfContacts;
	
	public:
	
	contactManager()
	{
		listOfContacts.clear();
	}
	
	vector<Contact> getlistOfContacts()
	{
		return listOfContacts;
	}
	
	bool checkValidContactNumber(string contactNumber)
	{
		for(auto x:contactNumber)
		{
			if(x>='0' and x<='9')
			{
				// this is a valid character for a phone number
			}
			else 
			{
				return false;
			}
		}
		if(contactNumber.length()!=10)
		{
			return false;
		}
		return true;
	}
	
	// this function is used to add a new contact in contact list
	void addContact(string firstName,string lastName,string contactNumber)
	{
		if(!checkValidContactNumber(contactNumber))
		{
			return;
		}
		if(firstName.length()==0)
		{
			return;
		}
		Contact person=Contact(firstName,lastName,contactNumber);
		listOfContacts.push_back(person);
	}
	
	// this function is used to convert a uppercase character in lowercase
	char convertToLowerCase(char character)
	{
		if(character>='A' and character<='Z')
		{
			character+=32;
		}
		return character;
	}
	
	bool CheckIfCharactersAreSameInCaseInsensitive(char firstCharacter,char secondCharacter)
	{
		// convert both the characters in lowercase
		firstCharacter=convertToLowerCase(firstCharacter);
		secondCharacter=convertToLowerCase(secondCharacter);
		return firstCharacter==secondCharacter;
	}
	
	bool checkIfTheStringsHaveSamePrefix(string firstString,string secondString)
	{
		if(firstString.length()==0 or secondString.length()==0)
		{
			return true;
		}
		if(firstString.length()>secondString.length())
		{
			return false;
		}
		
		int lengthToCheck=min(firstString.length(),secondString.length());
		bool stringsHaveSamePrefix=true;
		for(int i=0;i<lengthToCheck;i++)
		{
			if(!CheckIfCharactersAreSameInCaseInsensitive(firstString[i],secondString[i]))
			{
				stringsHaveSamePrefix=false;
				break;
			}
		}
		return stringsHaveSamePrefix;
	}
	
	bool isTheContactMatching(Contact contact,string firstNamePrefix,string lastNamePrefix,string contactNumberPrefix)
	{
		string firstName=contact.getfirstName();
		string lastName=contact.getlastName();
		string contactNumber=contact.getcontactNumber();

		if(checkIfTheStringsHaveSamePrefix(firstNamePrefix,firstName) and checkIfTheStringsHaveSamePrefix(lastNamePrefix,lastName)
		and checkIfTheStringsHaveSamePrefix(contactNumberPrefix,contactNumber))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	vector<Contact> searchContact(string firstNamePrefix,string lastNamePrefix,string contactNumberPrefix)
	{
		vector<Contact> result;
		for(auto contactDetails:listOfContacts)
		{
			string firstName=contactDetails.getfirstName();
			if(isTheContactMatching(contactDetails,firstNamePrefix,lastNamePrefix,contactNumberPrefix))
			{
				result.push_back(contactDetails);
			}
		}
		return result;
	}
};
