#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

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

int isBalanceBracket(char bracket[]){
   char x;
   for(int i = 0;i<strlen(bracket); i++){
     if (bracket[i] == '(' || bracket[i] == '[' || bracket[i] == '{'){
        push(bracket[i]);
        continue;
     }
     switch (bracket[i]){
        case ')':
            x = pop();
            if (x == '{' || x == '[')
                return 0;
            break;
        case '}':
            x = pop();
            if (x=='(' || x=='[')
                return 0;
            break;

        case ']':
            x = pop();
            if (x =='(' || x == '{')
                return 0;
            break;
        }
   }
   return isEmpty();
}
void main() {
   char bracket[80];

   printf("input a bracket (max 20 char)\n");
   scanf("%s",&bracket);

   if(isBalanceBracket(bracket) == 1)
    printf("is balanced of above bracket :true");
   else
    printf("is balanced of above bracket :false");
}