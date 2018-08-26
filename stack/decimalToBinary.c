#include <stdio.h>
#include <conio.h>

int MAXSIZE = 1000;
int stack[1000];
int top = -1;

void push(int value) {
   if(!isFull()) {
      stack[++top] = value;
   }
}

int isFull() {
   return top == MAXSIZE ? 1 : 0;
}

int isEmpty() {
   return top == -1 ? 1 : 0;
}
int pop() {
   if(!isEmpty())
      return stack[top--];
}

void main() {
   int n,dividend;
   printf("Enter a number to convert binary ? \n");
   scanf("%d",&n);

   dividend = n;
   while(dividend > 0)  {
        push(dividend % 2);
        dividend /= 2;
    }

    printf("%d binary = ",n);
    while(!isEmpty()) {
      printf("%d",pop());
    }
    getch();
}