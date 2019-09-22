#include <stdio.h>
#include <stdlib.h>


#define SHELLSCRIPT "\
#/bin/bash \n\
echo \"hello\" \n\
echo \"how are you\" \n\
echo \"today\" \n\
"
/*Also you can write using char array without using MACRO*/
/*You can do split it with many strings finally concatenate 
  and send to the system(concatenated_string); */

int main()
{
    puts("Generating the filtered log for you :");
    puts("[---------------------------------------------------------]");
    puts("Starting now:");
    system(SHELLSCRIPT);    //it will run the script inside the c code. 
    return 0;
}
