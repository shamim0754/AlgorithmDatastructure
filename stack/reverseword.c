#include <stdio.h>
#include <conio.h>
#include <string.h>

int MAXSIZE = 80;
char stack[80];
int top = -1;

//push into stack
void push(char value) {

   if(!isFull()) {
      stack[++top] = value;
   }else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int isFull() {
   return top == MAXSIZE ? 1 :0;
}

//pick top element
char peek() {
   return stack[top];
}
//check stack empty
int isEmpty() {
   return top == -1 ? 1 :0;
}

char pop() {
   if(!isEmpty()) {
      return stack[top--];
   }else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void main() {
   char name[80];
   printf("input a word (max 20 char)\n");
   scanf("%s",&name);
   for(int i = 0;i<strlen(name); i++)
     push(name[i]);

   printf("Reverse of above word\n");
   while(!isEmpty()) {
      printf("%c",pop());
   }
}