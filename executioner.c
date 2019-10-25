#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#define BUFFER_SIZE 1000

#define LSIZ 128 
#define RSIZ 20 
int tot;
int WordArr(char l[][128])
{
    FILE *fptr1 ;
    int i = 0;
    //printf("\n\n Read the file and store the lines into an array :\n");
	//printf("------------------------------------------------------\n"); 	

    fptr1 = fopen("/home/always2k/Desktop/Temp/dict.txt", "r");
    while(fgets(l[i], LSIZ, fptr1)) 
	{
        l[i][strlen(l[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    return 0;
}
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

//To read the second File
void readDict()
{
     /*Reading the contents of dic.txt*/
     FILE *fp;
     char ch;
     
     /*Open file in read mode*/
     fp= fopen ("/home/always2k/Desktop/Temp/dict.txt", "r");
     while( (ch = getc(fp)) != EOF) 
	{
	     /*getc() function reads a character and its value is stored in variable 'ch' until EOF is encountered*/
	     printf("%c", ch);
	}
}
void rename1()
{
FILE *fstr,*fmail;
	char line[128];
	char str[]="/home/always2k/Desktop/Buffer/"; //Path of Buffer Directory(Directory needed at the time of installation of post fix)
	char str1[]=".txt"; // To be added at the end
		time_t timer;
    	char ltime[26];
    	struct tm* tm_info;
    	time(&timer);
    	tm_info = localtime(&timer);
    	strftime(ltime, 26, "_%Y-%m-%d@%H:%M:%S", tm_info);
    	//printf("%s\n",ltime);
	fstr=fopen("/home/always2k/Desktop/Temp/mailer.txt","r"); //Open File
	fgets (line, 100, fstr); //Get the first line in line[128] array
	fclose(fstr);
	strtok(line,"\n"); //remove '\n'(line Break) from line using delimiter"
	strcat(str,line); //concatenate line[128] array to
	strcat(str,ltime); //concatenate time to the file name
	strcat(str,str1); //concatenate ".txt" at end
	printf("%s",str); //Print FIle Name
	rename("/home/always2k/Desktop/Temp/mailer.txt",str); //move file form temporary directory to buffer directory
	fmail=fopen("/home/always2k/Desktop/Temp/mailer.txt","w"); //write a new mailer.txt in place of the moved one
	fprintf(fmail,":");
	fclose(fmail);	
}
int main()
{   
    //readDict();
    int i;
	char l[RSIZ][LSIZ];
    FILE *fptr;
    int line, col;
    int flag = 0;
    WordArr(l);
    for(i = 0; i < tot; ++i)
    {
    	fptr = fopen("/home/always2k/Desktop/Temp/mailer.txt", "r");
    	//printf("\n%s\n",l[i]);
    	indexOf(fptr, l[i], &line, &col);

    	if (line != -1)
		{
	    	flag = 1;
	    	//printf("========================================================\n");
	    	//printf("This mail is Flagged\n");
	    	//printf("'%s' found at line: %d, col: %d\n", l[i], line + 1, col + 1);
	    	//printf("DONE\n");
	    	fclose(fptr);
		//break;		
		}
    	else
        	{
        	//printf("CLEAN MAIL");
			//printf("'%s' does not exists.\n", l[i]);
			fclose(fptr);
			//break;	
		    }
    	// Close file
    	fclose(fptr);
	}
	if(flag==1)
	{
		rename1();
	}
    return 0;
}


