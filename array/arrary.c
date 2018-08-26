#include <stdio.h>
int array[] = {1,3,5,7,8};
int  n = 4;
void travers(int array[]){
    for(int i = 0; i < n; i++)
        printf("array[%d] = %d \n", i, array[i]);
}
void insert(int value){
    array[n++] = value;
}
void update(int value, int updateIndex){
    array[updateIndex] = value;
}
void delete(int indexDelete){
   int j = indexDelete;
   while( j < n) {
      array[j-1] = array[j];
      j++;
   }
   n--;
}
void search(int searchValue){
    for(int i = 0; i < n; i++){
        if(array[i] == searchValue)
            printf("Found element %d at position %d\n", searchValue, i);
    }
}
main() {
   printf("The original array elements are :\n");

   travers(array);
   insert(10);
   printf("The array elements after insertion :\n");
   travers(array);

   update(12, 0);
   printf("The array elements after update :\n");
   travers(array);

   delete(3); // delete 3th position(value 5)
   printf("The array elements after deletion :\n");
   travers(array);

   search(3);
}