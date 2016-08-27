#include <stdio.h>
#include <conio.h>
struct node  
{
   int value;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList()
{
   struct node *ptr = head;
   printf("\n[ ");
   
   //start from the beginning
   while(ptr != NULL)
   {        
      printf("%d ",ptr->value);
      ptr = ptr->next;
   }
   
   printf(" ]");
}

//insert link at the first location
void insert(int value)
{
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   
   link->value = value;
   
   //point it to old first node
   link->next = head;
   
   //point first to new first node
   head = link;
}
int length(){
   int length = 0;
   struct node *current;
   
   for(current = head; current != NULL; current = current->next)
      length++;
   
   return length;
}
//find a link with given value
struct node* search(int searchItem){
   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL)
      return NULL;

   while(current->value != searchItem){
      
      if(current->next == NULL) //if it is last node
         return NULL;
      else
         current = current->next; //go to next link
   }
   //if data found, return the current Link
   return current;
}
//delete a link with given value
struct node* delete(int value){
   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
   //if list is empty
   if(head == NULL)
      return NULL;

   while(current->value != value){

      if(current->next == NULL) //if it is last node
         return NULL;
      else{
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }    
   }
   //found a match, update the link
   if(current == head) 
      //change first to point to next link
      head = head->next;
   else 
      //bypass the current link
      previous->next = current->next;
      
   
   return current;
}
void main() {
   struct node *ptr = head;
   int n,arr[50],i,item,ditem;
   printf("How many data you want to store ? \n");
   scanf("%d", &n);

   printf("Enter %d elements\n",n);
   for(i = 0; i < n; i++)
      scanf("%d", &arr[i]);
   
   for(i = 0; i < n; i++)
      insert(arr[i]);
   
   printf("Original List: "); 
   //print list
   printList();
   
   printf("\nEnter a searchItem \n");
   scanf("%d", &item);
   struct node *foundLink = search(item);
   if(foundLink == NULL)
      printf("Not found");
   else
      printf("found");

   printf("\nEnter a delete item \n");
   scanf("%d", &ditem);
   delete(ditem);

   //print list
   printList();

   getch();
}