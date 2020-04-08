Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@cdeo7347 
me50
/
cdeo7347
Private
6
00
 Code Pull requests 0 Actions Projects 0 Security Insights
cdeo7347/mario.c
@cdeo7347 cdeo7347 automated commit by submit50 [lang=C.UTF-8]
81b1f4b 14 days ago
49 lines (46 sloc)  1.38 KB
  
#include <cs50.h>
#include <stdio.h>

int main(void)
{
// height of pyramid, number of 
//columns and the rows are initialized below
   int height= get_int("Enter the height: \n");
//height is entered through user input
   int columns = 0;
   int row = 0; 
   
   while (height < 1 || height > 8)
   {
//if the height is less than 1 and greather than 8 
// the user is prompted to pick a different height
        printf("Enter the height: ");
        get_int("%i", height);
    }
    printf("\n");
//implement for loop for the lines in the pyramid
     for( row = 1; row <= height; row++) 
   {
//if the column is less than the height given 
//by the user then the pyramid will keep 
//adding new columns 
            for( columns = 1; columns <= height; columns++) 
       {
             if( columns >= height + 1 - row)
           { 
// I think the best way to explain the if statement 
//is with an example. So if the column is 1 
//the height would be 2 and the row would be 1. 
// 2-1= 1. The equation will print out the right number of 
//hashes in that column, for this example it will print 
// one hash 
               printf("#");
            }
            else 
// the else statement basically says anything that isn't a hash from the 
 // previous statement should be filled with a blank space 
            {
                printf(" ");
            }
        } 
        printf("\n");  
    }
}
