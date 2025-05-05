#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int is_palindrome(int *num); //function to check if a number is palindrome
int is_armstrong(int *num); //function to check if a number is armstrong


int is_palindrome(int* num){
    int og=*num;
    int dig;
    int *rev=(int*) malloc(sizeof(int));
    *rev=0;
    while(*num>0){
        dig=*num%10;
        *rev=*rev*10+dig;
        *num=*num/10;
    }
    if (og==*rev){
        printf("Palindrome\n");
    }
    else{
        printf("Not a palindrome\n");
    }
    return 0;
}

int is_armstrong(int *num){
    int og=*num, dig,num_digits=0,sum=0;
    while(*num>0){
        num_digits++;
        *num/=10;

    }
    *num=og;
    while(*num>0){
        dig=*num%10;
        sum=sum+pow(dig,num_digits);
        *num/=10;
    }
    if (sum==og){
        printf("Armstrong\n");
    }
    else{
        printf("Not an armstrong number\n");
    }
   
   return 0;
}

int is_perfectnum(int *num){
    int sum = 0;
    for (int i = 1; i <= *num / 2; i++) {
        if (*num % i == 0) {
            sum += i;
        }
    }
    if (sum==*num){
        printf("Perfect number");
    }
    else{
        printf("Not a perfect number");
    }

    return 0;
}


int main(){
    int *choice=(int*) malloc(sizeof(int));
    do{
        int *num=(int*) malloc(sizeof(int));
        printf("Enter a number:");
        scanf("%d",num);
        printf("\nMenu\n");
        printf("1. Palindrome\n");
        printf("2. Armstrong number\n");
        printf("3. Perfect number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",choice);
        switch(*choice){
            case 1:
            printf("checking if it is a palindrome\n");
            is_palindrome(num);
            break;

            case 2:
            printf("checking if it is armstrong\n");
            is_armstrong(num);
            break;

            case 3:
            printf("checking if it is a perfect number\n");
            is_perfectnum(num);
            break;

            case 4:
            printf("Exiting\n");
            break;

            default:
            printf("Enter a valid option\n");
            break;


        }
    }while (*choice!=4);
}