
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

short get_short(char text[], short MIN, short MAX); // function to get safe user input and check for validity

int main()
{   
    system("clear");

    // Christmas tree printing
    printf("-------------------------------------------------------------------------\n");
    int height = get_short("Liebe Lucie, wie groß soll dein Weihnachtsbaum werden? (10-50)", 10, 50); 

    for (int i = 1; i < height; i++)
    {
        int starCount = (i * 2) - 1;
        int spaceCount = height - i +1;

        for (int j = 0; j < spaceCount; j++)
            printf(" ");
        for (int j = 0; j < starCount; j++)
            printf("*");
        
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < height; j++) 
            printf(" ");
        
        printf("*\n");
      
      return 0;
    }
  
  
