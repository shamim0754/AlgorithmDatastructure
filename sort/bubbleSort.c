#include <stdio.h>
#include <conio.h>
#include <string.h>
void bubble_sort(int[], int);
void main(){
	int n,a[20],i;

    printf("Enter total numbers of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    // take value from user
    for(i = 0; i < n; i++){
      scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    
}
void bubble_sort(int iarr[], int num) {
    int i,j,temp;

    printf("Before sort : [ ");
    // input array value
    for(i = 0; i < num; i++){
      printf("%d ",iarr[i]);
    }
    printf("]");
    
    for(i = 0; i < num; i++){ //number of iternation need for bubble up
         for(j = 0; j < num-1; j++){ //n-i for performance you can use n
            //pickup greater value
            if(iarr[j] > iarr[j+1]){
                temp = iarr[j]; // for swaping purpose
                iarr[j] = iarr[j+1]; // bubble up
                iarr[j+1] = temp; // swap
            }
         }
    }

    printf("After sort : [ ");
    for(i = 0; i < num; i++){
      printf("%d ",iarr[i]);
    }
    printf("]");
}
