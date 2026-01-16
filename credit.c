#include <stdio.h>

int main(void)
{
    // Prompting the user for input
    long long n;
    do
    {
        printf("Number: ");
        scanf("%lld", &n);
    }
    while (n < 0);

    // Counting the number of digits
    int digits = 0;
    long long p = n;
    while (p > 0)
    {
        p = p / 10;
        digits++;
    }
    if ((digits != 15) && (digits != 13) && (digits != 16))
    {
        printf("INVALID\n");
        return 0;
    }

    // Finding starting digits of the number
    long long sd = n;
    do
    {
        sd = sd / 10;
    }
    while (sd >= 100);

    // Checksum and Luhn's algorithm
    int sum = 0;
    long long temp = n;
    for(int i = 0;i < digits; i++){
        int digit = temp % 10;
        if(i % 2 == 1){
            int mult = digit * 2;
            sum += (mult/10) + (mult%10);
        }
        else{
            sum += digit;
        }
        temp = temp/10;
    }
    if(sum % 10 != 0){
        printf("INVALID\n");
        return 0;
    }

    // Identifying the type of credit card
    if ((digits == 15) && (sd == 37 || sd == 34))
    {
        printf("AMEX\n");
    }
    else if ((digits == 13) && (sd / 10 == 4))
    {
        printf("VISA\n");
    }
    else if ((digits == 16) && (sd / 10 == 4))
    {
        printf("VISA\n");
    }
    else if ((digits == 16) && (sd / 10 == 5) && (0 < sd % 10 && sd % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}