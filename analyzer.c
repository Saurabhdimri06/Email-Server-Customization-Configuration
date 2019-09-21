#include<stdio.h>
//To read the Contents of Dictionary File
void readDict()
{
     /*Reading the contents of TestDictionary.txt*/
     FILE *fp;
     char ch;
     
     /*Open file in read mode*/
     fp= fopen ("A:/Minor1/TestDictionary.txt", "r");
     while( (ch = getc(fp)) != EOF) 
	{
	     /*getc() function reads a character and its value is stored in variable 'ch' until EOF is encountered*/
	     printf("%c", ch);
	}
}
int main()
{
	//Printing Contents of TestDictionary.txt
	readDict();
	//Add Filtering module
	
	//Add File handling for filter and dictionary

	//Searching the contents form the file
	
	
	return 0;
}
