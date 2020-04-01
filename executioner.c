#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#define BUFFER_SIZE 1000

#define SHELLSCRIPT "\
#/bin/bash \n\
cd /home/always2k/Desktop/Scimail/Admin/Logs/ \n\
touch s_log.txt \n\
cd /var/log \n\
grep -e 'uid' -e 'from' -e 'to' -e 'message-id'  mail.log | tail -n 4 >> /home/always2k/Desktop/Scimail/Admin/Logs/s_log.txt \n\
"

#define LSIZ 128 
#define RSIZ 20 
int tot;
int flag;
int WordArr(char l[][128])
{
    FILE *fptr1 ;
    int i = 0;
    //printf("\n\n Read the file and store the lines into an array :\n");
	//printf("------------------------------------------------------\n"); 	

    fptr1 = fopen("/home/always2k/Desktop/Scimail/dict.txt", "r");
    while(fgets(l[i], LSIZ, fptr1)) 
	{
        l[i][strlen(l[i]) - 1] = '\0';
        i++;
    }
    tot = i;
    return 0;
}
int search(char word[])
{
char line[200];
FILE *fptr = fopen("/home/always2k/Desktop/Scimail/mailer.txt", "r");
            while ( fgets ( line, 200, fptr ) != NULL ) /* read a line */
            {
                    if(strstr(line,word))
		    //fputs ( line, stdout );
                    flag=1;
            }
            fclose ( fptr );
            return 0;
}
/*
//To read the second File
void readDict()
{
     /Reading the contents of dic.txt/
     FILE *fp;
     char ch;
     
     /Open file in read mode/
     fp= fopen ("/home/always2k/Desktop/Scimail/dict.txt", "r");
     while( (ch = getc(fp)) != EOF) 
	{
	     /getc() function reads a character and its value is stored in variable 'ch' until EOF is encountered/
	     printf("%c", ch);
	}
}*/
void rename1()
{
FILE *fstr,*fmail;
	char line[128];
	char str[]="/home/always2k/Desktop/Scimail/Admin/Buffer/"; //Path of Buffer Directory(Directory needed at the time of installation of post fix)
	char str1[]=".txt"; // To be added at the end
		time_t timer;
    	char ltime[26];
    	struct tm* tm_info;
    	time(&timer);
    	tm_info = localtime(&timer);
    	strftime(ltime, 26, "_%Y-%m-%d@%H:%M:%S", tm_info);
    	//printf("%s\n",ltime);
	fstr=fopen("/home/always2k/Desktop/Scimail/mailer.txt","r"); //Open File
	fgets (line, 100, fstr); //Get the first line in line[128] array
	fclose(fstr);
	strtok(line,"\n"); //remove '\n'(line Break) from line using delimiter"
	strcat(str,line); //concatenate line[128] array to
	strcat(str,ltime); //concatenate time to the file name
	strcat(str,str1); //concatenate ".txt" at end
	//printf("%s",str); //Print FIle Name
	rename("/home/always2k/Desktop/Scimail/mailer.txt",str); //move file form temporary directory to buffer directory
	//fmail=fopen("/home/always2k/Desktop/Scimail/mailer.txt","w"); //write a new mailer.txt in place of the moved one
	//fprintf(fmail,":");
	//fclose(fmail);	
}
int main()
{   
    //readDict();
    int i;
	char l[RSIZ][LSIZ];
    FILE *fptr;
    int line, col;
    WordArr(l);
    for(i = 0; i < tot; ++i)
    {
    	search(l[i]);
	}
        //printf("%d\n",flag);
	if(flag==1)
	{
		rename1();
		system(SHELLSCRIPT);
	}
	else
		remove("/home/always2k/Desktop/Scimail/mailer.txt");
    return 0;
}


