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
//To Search the contents of Email file for Specific Word/Phrase
int indexOf(FILE *fptr, const char *word, int *line, int *col)
{
    char str[BUFFER_SIZE];
    char *pos;

    *line = -1;
    *col  = -1;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        *line += 1;

        // Find first occurrence of word in str
        pos = strstr(str, word);

        if (pos != NULL)
        {
            // First index of word in str is 
            // Memory address of pos - memory
            // address of str.
            *col = (pos - str);
            break;
        }
    }


    // If word is not found then set line to -1
    if (*col == -1)
        *line = -1;

    return *col;
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
