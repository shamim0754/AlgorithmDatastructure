#include <stdio.h>
#include <conio.h>

int binary_search(int arr[],int size,int searchitem);

void main() {

    int arr[20], n, i,item;
  	printf("Enter the size of the array\n");
  	scanf("%d", &n);

  	printf("Enter %d the elements\n",n);
  	for(i = 0; i < n; i++)
    	scanf("%d", &arr[i]);
    
    //display data
    printf("Data : [ ");
    for(i = 0; i < n; i++){
      printf("%d ",arr[i]);
    }
    printf("]\n");

    //input search item
    printf("enter search number:\n");
    scanf("%d", &item);
    if(binary_search(arr,n,item) == 1)
      printf("found");
    else
      printf("Not found");

    getch();

}

int binary_search(int arr[],int size,int searchitem){
	/*
	low,mid,high = store array index
	isFound = flag for search found or not
	*/
	int low,mid,high,isFound = 0;
	
	//high is less then 1 than size 
	high = size - 1;

	//otherwise search done
	while(low <= high){
		mid = (low + high) / 2;
		//if midlle index found
		if(arr[mid] == searchitem){
			isFound = 1;
         	break;
         }else if(searchitem < arr[mid])
        	high = mid - 1;
        else
        	low = mid + 1;
	}
  return isFound;  
}
