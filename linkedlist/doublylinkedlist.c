#include <stdio.h>
struct node
{
   struct node *prev;
   int data;
   struct node *next;
};
struct node *head = NULL;
struct node *current = NULL; //travers purpose
void traversForword(){
   current = head;
   while(current != NULL){
      printf("%d ",current->data);
      current = current->next;
   }
}

void traversBackword(){
   current = head;
   while(current != NULL){
      printf("%d ",current->data);
      current = current->prev;
   }
}

void insertBegining(int data)
{
   //create a node
   struct node *myNode = (struct node*) malloc(sizeof(struct node));
   myNode->data = data;
   myNode->next = head;
   myNode->prev = NULL;

   if (head != NULL)
        head->prev = myNode;

   //myNode is head now
   head = myNode;
}


main() {
   insertBegining(3);
   insertBegining(10);
   printf("The Double linked list elements after insertion :\n");
   traversForword(head);
}