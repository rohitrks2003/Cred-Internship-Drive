#include<bits/stdc++.h>
#include "contact.cpp"
using namespace std;


// This class provides Services used at various places in code
class Services
{
	public:
	
	
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
				cout<<"ERROR: Contact number can only have digits\n";
				return false;
			}
		}
		if(contactNumber.length()!=10)
		{
			cout<<"ERROR: Contact number should be of length 10\n";
			return false;
		}
		return true;
	}
	
	// Valid name only contains lowercase and uppercase character
	bool checkValidName(string Name)
	{
		for(char character:Name)
		{
			if(character>='A' and character<='Z')
			{
				
			}
			else if(character>='a' and character<='z')
			{
				
			}
			else 
			{
				cout<<"ERROR: The Name should only contain Alphabets\n";
				return false;
			}
		}
		return true;
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
	
	bool isTheContactMatching(Contact contact,Contact prefixContact)
	{
		string firstName=contact.getfirstName();
		string lastName=contact.getlastName();
		string contactNumber=contact.getcontactNumber();
		
		string firstNamePrefix=prefixContact.getfirstName();
		string lastNamePrefix=prefixContact.getlastName();
		string contactNumberPrefix=prefixContact.getcontactNumber();

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
};
