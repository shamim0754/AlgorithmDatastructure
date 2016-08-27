#include <stdio.h>
#include <conio.h>
#include <math.h>
//#define MAX 20

void quicksort(int arr[], int low, int high);
void main(){
	/*
	arr = store elements that needs to sort using quick
	n = store no of elements
	i = store index value
	*/
	int arr[20], n, i;
  	printf("Enter the size of the array\n");
  	scanf("%d", &n);

  	printf("Enter the elements to be sorted\n");
  	for(i = 0; i < n; i++)
    	scanf("%d", &arr[i]);

    quicksort(arr, 0, n-1);

    printf("sorted : ");
  	for(i = 0; i < n; i++)
    	printf("%d ", arr[i]);
}
void quicksort(int arr[], int low, int high){
	/*
	pivot = store pivot element
	temp = for swaping
	i,j = store index value
	*/
	int pivot, i, j, temp;

	//if equal or more quick sort done
    if(low < high) {
    	pivot = low; // select a pivot element,you can choose any one
	    i = low;
	    j = high;

	    // increment i till you get a number 
	    //greater from left side than the pivot element
      	while(arr[i] <= arr[pivot] && i <= high)
        	i++;
        // decrement j till you get a number 
        //from right side less than the pivot element
        while(arr[j] > arr[pivot] && j >= low)
        	j--;
        //if equal or more quick sort done
	    if(i < j) {
	        temp = arr[i];
	        arr[i] = arr[j];
	        arr[j] = temp;
	    }
	    // when i >= j it means the j-th position is the correct position
	    // of the pivot element, hence swap the pivot element with the
	    // element in the j-th position
	    temp = arr[j];
	    arr[j] = arr[pivot];
	    arr[pivot] = temp;

	    // Repeat quicksort for the two sub-arrays, one to the left of j
	    // and one to the right of j
	    quicksort(arr, low, j-1);
	    quicksort(arr, j+1, high);
	}	
}
