#include <cs50.h>
#include <math.h> 
#include <stdio.h>

int main()
{
    int cents; 

    do
    {
        //user input for change owed
        float dollars = get_float("Change owed:");
        cents = round(dollars * 100); 
//rounds the dollar input into cents
    }
    while (cents <= 0); 
//the do while statement is prompting for the user input of change 
//owed until the user inputs a valid (non negative) number 

//the following four lines of code work by checking the cents owed 
//and dividing it by the largest coin value being 25 to see how many quarters are needed 
//then it jumps to the next coin, being the dime and divides by 10 and will continue to
//check how many coins are needed. This was based off of the example in the first lecture 
//where the guy ripped the telephone book in  half several times to find what he was looking for. 
// we are essentially dividing the amount due by the coins to determine how many of each coin is needed 
// Sorry if that does not make sense. It's the best way I could explain it. 
    int quarters = cents / 25;
    int dimes = (cents % 25) / 10;
    int nickels = ((cents % 25) % 10) / 5;
    int pennies = ((cents % 25) % 10) % 5;

    printf("%d\n", quarters + dimes + nickels + pennies);
}
