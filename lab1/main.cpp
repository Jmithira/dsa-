#include <iostream>
#include "sorting.h"


int linearsearch(int arr[],int size,int n){
    for (int i=0;i<size;i++){
        if(arr[i]==n){
            return i;
            break;
        }
    }
    return -1;
}

int binarysearch(int arr[], int size, int n){
    int low=0;
    int high=size-1;
    while(low<=high){
        int mid=(high+low)/2;
        if (arr[mid]==n){
            return mid;
            break;
        }
        else if(arr[mid]<n){
            low=mid+1;
        }
        else if(arr[mid]>n){
            high=mid-1;
        }
    }
    return -1;
}
void InputArray(int arr[], int size){
    for (int i=0;i<size;i++){
        printf("Enter element number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}
int main(){
    int choice;
    int size;
    int element;
    int result;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int array[size];
    InputArray(array,size);
    do{
        printf("Menu\n");
        printf("1.Linear Search\n");
        printf("2.Binary Search\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            printf("Enter element to search: ");
            scanf("%d",&element);
            result=linearsearch(array,size,element);
            if (result==-1)
            printf("Element not found\n");
            else
            printf("Element found at index: %d \n\n",result);
            break;


            case 2:
            printf("Enter element to search: ");
            scanf("%d",&element);
            bubblesort(array,size);
            printf("Sorted Array>> ");
            display(array,size);
            result=binarysearch(array,size,element);
            if (result==-1)
            printf("Element not found");
            else
            printf("Element found at index: %d\n\n",result);
            break;


            case 3:
            printf("Exited");
            break;

            default:
            printf("Enter a valid choice between 1-4\n");        

        }
    }while (choice!=3);

}
