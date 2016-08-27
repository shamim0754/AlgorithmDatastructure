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
void main() {
   struct node *ptr = head;
   int n,arr[50],i;
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

   getch();
}