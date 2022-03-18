#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long count = 0;
    long a,v,card_number,digit_last;
    long s = 0;
    int p = 2;
    int u = 0;
    int x = 0;
    int t = 0;
    int b = 0;
    int o = 0;
    double l,k;
    int s1,s2,x1;

//Insert the card number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 1);

    a = card_number;

// Count the length of the card number;
    while (a > 0)
    {
        a = a / 10;
        count++;
    }

    v = card_number;

//Luhn's Algorithm;
    for (int i = 0; i < count; i++)
    {
        digit_last = v % 10;
        v = (v - digit_last) / 10;
        p++;
        if (p % 2 == 0)
        {
            b = 2 * digit_last;
            if (b > 9)
            {
                u = u + b % 10 + (b - b % 10)/10;
            }
            else
            {
                t = t + b;
            }
        }
        else
        {
        o = o + digit_last;
        }
    }

    x = u + t + o;

//Find first 2 numbers;
    l = card_number;
    k = pow(10, count - 2);
    s2 = (l - fmod(l,k)) / k;

//Find first number of the card;
    s1 = (s2 - fmod(s2,10)) / 10;

//Check the card;

    x1 =  x % 10;
    if ((s1 == 4) && (count == 13 || count == 16) && (x1 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        if ((s2 > 50 && s2 < 56) && (count == 16) && (x1 == 0))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            if ((s2 == 34 || s2 == 37) && (count == 15) && (x1 == 0))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

    }