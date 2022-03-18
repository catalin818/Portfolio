#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int y = get_int("Height: ");
    while (y<1 || y>8)
    {
        y = get_int("Height: ");    //checking if input number is from 1 to 8.
    }
    int n=1;
    int a=y;
        do
        {
            for (int i=0; i<y-1;i++)   //prints first spaces
            {
                printf(" ");
            }
            for (int j=0;j<n;j++)   //prints # equally to the row number
            {
                printf("#");
            }
                printf("  ");   //prints the spaces between the #
            for (int j=0;j<n;j++)
            {
                printf("#");    //prints the second part of # equally to the row
            }
        printf("\n");
        y--;
        n++;
        }
        while(n<=a);
    }