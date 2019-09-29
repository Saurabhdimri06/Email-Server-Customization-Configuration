#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
int main()
{
	FILE *fstr,*fmail; // File Pointer
	char line[128],ltime[26]; // 1st Line of the Mailer.txt
	char str[]="C:/Users/anitr/Desktop/"; //Path of Buffer Directory(Directory needed at the time of installation of postfix)
	char str1[]=".txt"; // To be added at the end of string
	
		time_t timer;
    	struct tm* tm_info;
    	time(&timer);
    	tm_info = localtime(&timer);
    	strftime(ltime, 26, "_%Y-%m-%d@%H;%M;%S", tm_info);
    	printf("%s\n",ltime);
    	//Print Local time and save it to name of file

	fstr=fopen("C:/Users/anitr/Desktop/Content/mailer.txt","r"); //Open File
	fgets (line, 100, fstr); //Get the first line in line[128] array
	fclose(fstr); //close file
	strtok(line,"\n"); //remove '\n'(line Break) from line using delimiter"
	strcat(str,line); //concatenate line[128] array to
	strcat(str,ltime); //concatenate time to the file name
	strcat(str,str1); //concatenate ".txt" at end
	printf("%s",str);
	rename("C:/Users/anitr/Desktop/Content/mailer.txt",str); //move file form temporary directory to buffer directory
	fmail=fopen("C:/Users/anitr/Desktop/Content/mailer.txt","w"); //write a new mailer.txt in place of the moved one
	fprintf(fmail,":"); // Add Colon ':' to new mailer.txt 
	fclose(fmail); //Close fmail
	return 0;
}
