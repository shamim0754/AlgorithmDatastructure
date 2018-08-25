#include <stdio.h>
#include <conio.h>
#include<string.h>


int MAXSIZE = 80;
int stack[80];
int top = -1;

//push into stack
void push(int value) {
   stack[++top] = value;
}

//check stack empty
int isEmpty() {
    return top == -1 ? 1 : 0;
}
int pop() {
   return stack[top--];
}
//check whether the symbol is operator?
int isOperand(char symbol) {

   switch(symbol) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '(':
      case ')':
         return 1;
         break;
      default:
         return 0;
   }
}
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int precedence(char ch)
{
    switch (ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

//converts infix expression to postfix
void convert(char infix[],char postfix[]) {
   int i,symbol,j = 0;

   for(i = 0;i<strlen(infix);i++) {
      symbol = infix[i];
      if(isOperand(symbol) == 0) {
         postfix[j] = symbol;
         j++;
      } else if(symbol == '(') {
        push(symbol);
      } else if(symbol == ')') {
        while(stack[top] != '(') {
            postfix[j] = pop();
            j++;
        }
        pop();
      } else {
        if(precedence(symbol) > precedence(stack[top])) {
            push(symbol);
        } else {
            while(precedence(symbol) <= precedence(stack[top])) {
                postfix[j] = pop();
                 j++;
            }
            push(symbol);
        }
      }
   }

   while(!isEmpty()) {
      postfix[j] = pop();
      j++;
   }

   postfix[j]='\0';  //null terminate string.
}
//int stack
int stack_int[25];
int top_int = -1;

void push_int(int item) {
   stack_int[++top_int] = item;
}

char pop_int() {
   return stack_int[top_int--];
}

//evaluates postfix expression
int evaluate(char *postfix){
    char ch;
    int i = 0,value1,value2;

    while( (ch = postfix[i++]) != '\0') {
        if(isdigit(ch)) {
       push_int(ch - '0');  // Push the operand
      } else {
         //Operator,pop two  operands
         value1 = pop_int();
         value2 = pop_int();

         switch(ch) {
            case '+':
               push_int(value1+value2);
               break;
            case '-':
               push_int(value1-value2);
               break;
            case '*':
               push_int(value1*value2);
               break;
            case '/':
               push_int(value1/value2);
               break;
         }
      }
    }
    return stack_int[top_int];
}
void main(){
    //= "1*(2+3)"
    char infix[80] ,postfix[80];
    printf("Enter a infix to convert postfix ? \n");
    scanf("%s",&infix);
    convert(infix,postfix);

    printf("Infix expression is: %s\n" , infix);
    printf("Postfix expression is: %s\n" , postfix);
    printf("Evaluated expression is: %d\n" , evaluate(postfix));
}
