#include <stdio.h>
#include <conio.h>
void bubble_sort(int[], int);
void main(){
    //Declaring variables
    int array[100],n,i;

    //Number of elements in array form user input
    printf("Enter the number of element you want to Sort : ");
    scanf("%d",&n);

    //code to ask to enter elements from user equal to n
    printf("Enter Elements in the list : ");
    for(i = 0; i < n; i++)
        scanf("%d",&array[i]);

    //calling quickSort function defined above
    quicksort(array,0,n-1);
    
}
