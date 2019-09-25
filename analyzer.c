#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000
#define LSIZ 128 
#define RSIZ 20 
int tot;
>>>>>>> filtering
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
        l[i][strlen(l[i]) - 1] = '\0';  //storing word in 2D array
        i++;
    }
    tot = i;
    return 0;
}
int main()
{
	//Printing Contents of TestDictionary.txt   
    readDict();
    int i;
	char l[RSIZ][LSIZ];
    FILE *fptr;
    int line, col;
    int flag = 0;
    //Storing Words into an array
    WordArr(l);
    for(i = 0; i < tot; ++i)
    {
    	fptr = fopen("A:/Minor1/TestMailFile.txt", "r");
    	printf("\n%s\n",l[i]);
    	//Checking file against words stored in array
    	indexOf(fptr, l[i], &line, &col);
		//Flagging mail if word is found in file
    	if (line != -1)
		{
	    	flag = 1;
	    	printf("========================================================\n");
	    	printf("This mail is Flagged\n");
	    	printf("'%s' found at line: %d, col: %d\n", l[i], line + 1, col + 1);
			//break;		
		}
    	else
        	printf("'%s' does not exists.\n", l[i]);
    	// Close file
    	fclose(fptr);
	}
    return 0;
>>>>>>> filtering
}
