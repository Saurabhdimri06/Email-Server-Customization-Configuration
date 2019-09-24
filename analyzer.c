#include<stdio.h>
int tot;
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
//To Store the Words in the Dictionary in 2D array
int WordArr(char l[][128])
{
    FILE *fptr1 ; 
    int i = 0;
    printf("\n\n Read the file and store the lines into an array :\n");
	printf("------------------------------------------------------\n"); 	

    fptr1 = fopen("A:/Minor1/TestDictionary.txt", "r"); //open file
    while(fgets(l[i], LSIZ, fptr1)) 
	{
        l[i][strlen(l[i]) - 1] = '\0';  //stroing word in 2D array
        i++;
    }
    tot = i;
    return 0;
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
