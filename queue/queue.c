#include <stdio.h>
#include <conio.h>

#define MAX 10

int intArray[MAX];
int front = 0;
int rear = 0;

int total =0;
void enqueue(int value){
   if(!isFull()){
      intArray[rear++] = value;
      total++;
   }else{
        printf("overflow ");
        exit(0);
   }
}
void travers(int array[]){
    for(int i = front; i < MAX; i++)
        printf("queue[%d] = %d \n", i, array[i]);
}

int dequeue(){
   int value = intArray[front++];
   total--;
   return value;
}

//utility function
int isFull(){
   return total == MAX ? 1 : 0;
}

int peek(){
   return intArray[front];
}

int isEmpty(){
   return total == 0 ? 1 : 0;
}

void main() {

   /* enqueue 5 items */
   enqueue(3);
   enqueue(5);
   enqueue(9);
   enqueue(1);
   enqueue(12);
   travers(intArray) ;

   int num = dequeue();
   printf("Element dequeue: %d\n",num);
   travers(intArray) ;

   getch();
}
