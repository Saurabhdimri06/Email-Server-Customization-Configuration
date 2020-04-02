#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<dirent.h>

void all_logs(char filename[]);
void edit_dict(char filename[]);
void show_buffer();
void alter_services();

#define SHELLSCRIPT "\
#/bin/bash \n\
sudo postfix reload \n\
"
#define SHELLSCRIPT1 "\
#/bin/bash \n\
sudo postfix start \n\
"

#define SHELLSCRIPT2 "\
#/bin/bash \n\
sudo postfix stop \n\
"
#define SHELLSCRIPT3 "\
#/bin/bash \n\
cd .. \n\
gedit dict.txt \n\
"
#define SHELLSCRIPT4 "\
#/bin/bash \n\
sudo postfix status \n\
"
#define SHELLSCRIPT5 "\
#/bin/bash \n\
openssl req -new -newkey rsa:2048 -nodes -out certreq.txt -keyout private.key \n\
sudo postconf -e 'smtpd_use_tls = yes' \n\
sudo postconf -e 'smtpd_tls_key_file = /etc/ssl/private.key' \n\
sudo postconf -e 'smtpd_tls_cert_file = /etc/ssl/server.crt' \n\
sudo postfix reload \n\
"
int main()
{
	int ch;
	printf("\n       Welcome to the Admin Panel\n");
	printf("========================================\n");
	printf("1-All Mail Logs \n2-Sensitive Mail Logs \n3-Edit Dictionary \n4-View Buffer \n5-Add/Modify SSL" 
			"\n6-Stop/Reload Postfix services \n7-Logout\n");
	
	printf("Enter your choice: ");
	scanf("%d",&ch);
	while(ch!=7)
	{
		switch(ch)
		{	
			case 1:  printf("\nSearching for server mail logs\n");
					 sleep(1);
					 printf("Generating contents...\n");
					 printf("--------------------------------------------------------------------------------\n");
					 sleep(1);
					 all_logs("/home/always2k/Desktop/Scimail/Admin/Logs/log.txt");
			break;
			case 2:  printf("Opening sensitive mail logs \n");
					 sleep(1);
					 printf("Generating contents...\n");
					 printf("--------------------------------------------------------------------------------\n");
					 sleep(1);
					 all_logs("/home/always2k/Desktop/Scimail/Admin/Logs/s_log.txt");
			break;
			case 3:  printf("Accessing the dictionary\n");
					 sleep(1);
					 system(SHELLSCRIPT3);
			break;
			case 4:  printf("Accessing the buffer directory");
					 sleep(1);
					 show_buffer();	 
			break;
			case 5:  printf("Creating SSL Certificate");
					 sleep(1);
                                         system(SHELLSCRIPT5);
			break;
			case 6:  printf("Select the choice to alter postfix service \n");
					 alter_services();
			break;
		}
		printf("\n=========================================\n");
		printf("1-All Mail Logs \n2-Sensitive Mail Logs \n3-Edit Dictionary \n4-View Buffer \n5-Add SSL" 
			"\n6-Stop/Reload Postfix services \n7-Logout\n");
		printf("\n=====================================\n");
		printf("\nWhat more do you want to do: ");
		scanf("%d",&ch);	
	}
	if(ch == 7)
	{
		printf("\n====================================\n");
		printf("Saving system configurations......\n");
		sleep(2);
		printf("Logging out the panel.....\n");
		sleep(2);
		printf("Logged out sucessfully !!!\n");
	}
	
	return 0;

}

void all_logs( char filename[] )
{
    /*Reading the contents of file entered*/
     FILE *fp;
     char ch;
     /*Open file in read mode*/
     fp= fopen (filename, "r");
     while( (ch = getc(fp)) != EOF) 
	{
	     /*getc() function reads a character and its value is stored in variable 'ch' until EOF is encountered*/
	     printf("%c", ch);
	}

}


void show_buffer()
{
	DIR *d;
    struct dirent *dir;
    d = opendir("/home/always2k/Desktop/Scimail/Admin/Buffer/");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

void alter_services()
{
	int ch;
	printf("1-Reload \n2-Start \n3-Stop\n4-Status\n");
	scanf("%d",&ch);
	if(ch == 1)
	{
		printf("\nReloading the services of Postfix server \n");
		system(SHELLSCRIPT);
	}
	else if(ch == 2)
	{
		printf("\nStarting the services of Postfix server \n");
		system(SHELLSCRIPT1);
	}
	else if (ch == 3)
	{
		printf("\nStopping the services of Postfix server \n");
		system(SHELLSCRIPT2);
	}
	else if (ch == 4)
	{
		printf("\nPostfix server status \n");
		system(SHELLSCRIPT4);
	}
}
