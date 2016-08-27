#include <stdio.h>
#include <conio.h>

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

void enqueue(int value){

   if(!isFull()){
   
      if(rear == MAX-1){
         rear = -1;            
      }       

      intArray[++rear] = value;
      itemCount++;
   }
}
bool isFull(){
   return itemCount == MAX;
}
int dequeue(){
   int value = intArray[front++];
   
   if(front == MAX){
      front = 0;
   }
   
   itemCount--;
   return value;  
}

int peek(){
   return intArray[front];
}

bool isEmpty(){
   return itemCount == 0;
}

void main() {
   /* enqueue 5 items */
   enqueue(3);
   enqueue(5);
   enqueue(9);
   enqueue(1);
   enqueue(12);
   
   // dequeue one item 
   int num = dequeue();
   printf("Element dequeue: %d\n",num);

   // pick one item
   printf("Element at front: %d\n",peek());
   getch();
}