#include <stdio.h>
struct node
{
   int data;
   struct node *next;
};
struct node *head = NULL;

void travers(struct node *node){

   while(node != NULL){
      printf("%d ",node->data);
      node = node->next; // loop while last node( we know last node link is NULL)
   }
}

void insert(int data)
{
   //create a node
   struct node *myNode = (struct node*) malloc(sizeof(struct node));
   myNode->data = data;
   myNode->next = head;

   //head now 
   head = myNode;
}

struct node *current = NULL;
void update(int oldData, int newData) {
   current = head;
   while(current->next != NULL) {
      if(current->data == oldData) {
         current->data = newData;
         return;
      }
      current = current->next;
   }
   printf("%d does not exist in the list\n", oldData);
}

void delete(int deleteData){
   struct node* previous = NULL;

   current = head;
   while(current != NULL) {
      if(current->data == deleteData) {
         previous->next = current->next;
         break;
      }
      previous = current;
      current = current->next;
   }
}

void search(int searchValue){
   current = head;
   while(current != NULL) {
      if(current->data == searchValue) {
         printf("found %d", searchValue);
         break;
      }
     current = current->next;
   }
}

main() {
   insert(3);
   insert(10);
   printf("The linked list elements after insertion :\n");
   travers(head);

   update(10, 12);
   printf("\nThe linked list elements after update :\n");
   travers(head);

   search(3);

   delete(3);
   printf("\nThe linked list elements after deletion :\n");
   travers(head);
}
