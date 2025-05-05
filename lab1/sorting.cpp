#include <stdio.h>
using namespace std;

void bubblesort(int arr[], int size){
    for (int i=0; i<size-1;i++){
        for (int j=0; j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;   
            }
        }

    }
}

void insertionsort(int arr[],int n){
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void selectionsort(int arr[],int n){
    for (int i=0; i<n-1; i++){
        int minidx=i;
        for (int j=i+1; j<n; j++){
            if (arr[j]<arr[minidx]){
                minidx=j;
            }
        }
        int temp=arr[minidx];
        arr[minidx]=arr[i];
        arr[i]=temp;
    }
}

void display(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/*  int main(){
    int choice;
    int n;
    int arr[]={12,45,23,13,76};
    printf("Enter the size of array: ");
    scanf("%d",&n);
    if (n<=0){
        printf("Enter a valid size, size cannot be negative or zero");
    }
    
    do{
        printf("Menu\n");
        printf("1.Bubble sort\n");
        printf("2.Insertion sort\n");
        printf("3.Selection sort\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            bubblesort(arr,n);
            printf("Array sorted using bubblesort: ");
            display(arr,n);
            break;
            case 2:
            insertionsort(arr,n);
            printf("Array sorted using insertion sort: ");
            display(arr,n);
            break;
            case 3:
            selectionsort(arr,n);
            printf("Array sorted using selection sort: ");
            display(arr,n);
            break;
            case 4:
            printf("Exiting");
            break;
            default:
            printf("Invalid choice, enter a choice between 1 - 4");
            
        }

    }while(choice!=4);
    return 0;

} */