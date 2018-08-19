### Data Structure ###
Data Structure is a way to organized data in such a way that it can be used efficiently.Almost every enterprise application uses various types of data structures e.g array,linked list

### Data Structure Type ###
1. Built-in
    - Integers
    - Boolean (true, false)
    - Floating (Decimal numbers)
    - Character and Strings
2. Derived 
   - Array
   - Linked List
   - Stack
   - Queue
   - Tree
   - Graph
   - much more

### Stack ###
A stack is an abstract data type (ADT), commonly used in most programming languages. It is named stack as it behaves like a real-world stack, for example − deck of cards or pile of plates etc. <br>
Stack can only access the top element of a stack hence it is called LIFO(Last-in-first-out) like data structure
<h4>Operation</h4>
1. push() − pushing (storing) an element on the stack
2. pop() − removing (accessing) an element from the stack
4. peek() − get the top data element of the stack, without removing it.
5. isFull() − check if stack is full.
6. isEmpty() − check if stack is empty.


```C
#include <stdio.h>
#include <conio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1; 

//push into stack
void push(int value) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = value;
   }else {
      printf("Could not insert data, Stack is full.\n");
   }
}

//check stack full
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

//pick top element
int peek() {
   return stack[top];
}
//check stack empty 
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
int pop() {
   int value;
    
   if(!isempty()) {
      value = stack[top];
      top = top - 1;   
      return value;
   }else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void main() {
   // push items on to the stack 
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

   // print stack data 
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }
   getch();
}
```
### Queue ###
Queue is an abstract data structure, somewhat similar to Stack. In contrast to Queue, queue is opened at both end. One end is always used to insert data (enqueue) and the other is used to remove data (dequeue). Queue follows First-In-First-Out methodology, i.e., the data item stored first will be accessed first. <br>
In queue, we always dequeue (or access) data, pointed by front pointer and while enqueing (or storing) data in queue we take help of rear pointer.

<h4>Operation</h4>
1. enqueue() − add (store) an item to the queue.
2. dequeue() − remove (access) an item from the queue.
4. peek() − get the top data element of the stack, without removing it.
5. isFull() − check if stack is full.
6. isEmpty() − check if stack is empty.

```C
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
```
### linked-list ###
A linked-list is a sequence of data structures which are connected together via links. Linked List is a sequence of links which contains items. Each link contains a connection to another link. Linked list the second most used data structure after array.
<h4>Operation</h4>
1. Insertion − add an element at the beginning of the list.
2. Deletion − delete an element at the beginning of the list.
3. Display − displaying complete list.
4. Search − search an element using given key.
5. Delete − delete an element using given key.

```C
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
```

### Data Structure Operations ###
1. Traversing
2. Searching
3. Insertion
4. Deletion
5. Sorting
6. Merging

### Linear Searching ###

Linear search is a very simple search algorithm.Every items is checked and if a match founds then that particular item.it is slow since every element need to check.

```C
#include <stdio.h>
#include <conio.h>

int linear_search(int arr[],int size,int searchitem);

void main() {

    int arr[20], n, i,item;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter %d the elements\n",n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    //display data
    printf("Data : [ ");
    for(i = 0; i < n; i++){
      printf("%d ",arr[i]);
    }
    printf("]\n");

    //input search item
    printf("enter search number:\n");
    scanf("%d", &item);
    if(linear_search(arr,n,item) == 1)
      printf("found");
    else
      printf("Not found");

    getch();

}

int linear_search(int arr[],int size,int searchitem){
    int i;
    for(i = 0; i < size; i++) //number of iternation need for linear
         if(arr[i] == searchitem)
             return 1;
  
  return 0;  
}

```
### Binary Searching ###

Binary search is a fast search algorithm.
 [Alogrithm](http://www.tutorialspoint.com/data_structures_algorithms/binary_search_algorithm.htm).

 ```C
#include <stdio.h>
#include <conio.h>

int binary_search(int arr[],int size,int searchitem);

void main() {

    int arr[20], n, i,item;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter %d the elements\n",n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    //display data
    printf("Data : [ ");
    for(i = 0; i < n; i++){
      printf("%d ",arr[i]);
    }
    printf("]\n");

    //input search item
    printf("enter search number:\n");
    scanf("%d", &item);
    if(binary_search(arr,n,item) == 1)
      printf("found");
    else
      printf("Not found");

    getch();

}

int binary_search(int arr[],int size,int searchitem){
    /*
    low,mid,high = store array index
    isFound = flag for search found or not
    */
    int low,mid,high,isFound = 0;
    
    //high is less then 1 than size 
    high = size - 1;

    //otherwise search done
    while(low <= high){
        mid = (low + high) / 2;
        //if midlle index found
        if(arr[mid] == searchitem){
            isFound = 1;
            break;
         }else if(searchitem < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
  return isFound;  
}

 ```

### Sorting ###

Sorting refers to arranging data in a particular format in accending or decending.Importance of sorting lies in the fact that data searching can be optimized to a very high level if data is stored in a sorted manner.

### Bubble Sort ###

```C
#include <stdio.h>
#include <conio.h>
#include <string.h>

void main(){
	int n,a[20],i,j,temp;

    printf("Enter total numbers of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    // take value from user
    for(i = 0; i < n; i++){
      scanf("%d",&a[i]);
    }
    printf("Before sort : [ ");
    // input array value
    for(i = 0; i < n; i++){
      printf("%d ",a[i]);
    }
    printf("]");
    // input array value
    for(i = 0; i < n; i++){ //number of iternation need for bubble up
    	 for(j = 0; j < n-i; j++){ //n-i for performance you can use n
    	 	/*
    	 	for decending order : pickup greater value for bubble up
    	 	for accending order : pickup smaller value for bubble up then use <
    	 	*/
    	 	if(a[j] > a[j+1]){
    	 		temp = a[j]; // for swaping purpose
    	 		a[j] = a[j+1]; // bubble up
    	 		a[j+1] = temp; // swap
    	 	}
    	 }
    }
    printf("After sort : [ ");
    for(i = 0; i < n; i++){
      printf("%d ",a[i]);
    }
    printf("]");
}
```



### Quick Sort ###
 [Alogrithm](http://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm).

 ```C
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(){
    /*
    arr = store elements that needs to sort using quick
    n = store no of elements
    i = store index value
    */
    int arr[20], n, i;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter the elements to be sorted\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, n-1);

    printf("sorted : ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
quicksort(int *arr, int low, int high){
    /*
    pivot = store pivot element
    temp = for swaping
    i,j = store index value
    */
    int pivot, i, j, temp;

    //if equal or more quick sort done
    if(low < high) {
        pivot = low; // select a pivot element,you can choose any one
        i = low;
        j = high;

        // increment i till you get a number 
        //greater from left side than the pivot element
        while(arr[i] <= arr[pivot] && i <= high)
            i++;
        // decrement j till you get a number 
        //from right side less than the pivot element
        while(arr[j] > arr[pivot] && j >= low)
            j--;
        //if equal or more quick sort done
        if(i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        // when i >= j it means the j-th position is the correct position
        // of the pivot element, hence swap the pivot element with the
        // element in the j-th position
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;

        // Repeat quicksort for the two sub-arrays, one to the left of j
        // and one to the right of j
        quicksort(arr, low, j-1);
        quicksort(arr, j+1, high);
    }   
}
```

### Merge Sort ###
 [Alogrithm](http://www.tutorialspoint.com/data_structures_algorithms/merge_sort_algorithm.htm).
 
```C
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 50

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

void main(){
  /*
  arr = store elements that needs to sort using quick
  n = store no of elements
  i = store index value
  */
  int arr[MAX], n, i;
    printf("Enter the size of the array\n");
    scanf("%d", &n);

    printf("Enter the elements to be sorted\n");
    for(i = 0; i < n; i++)
      scanf("%d", &arr[i]);

    partition(arr, 0, n-1);
    
    printf("sorted : ");
    for(i = 0; i < n; i++)
      printf("%d ", arr[i]);
}
void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;

         partition(arr,low,mid);
         partition(arr,mid+1,high);

         mergeSort(arr,low,mid,high);
    }
}
void mergeSort(int arr[],int low,int mid,int high){
    int i,m,k,l,temp[MAX];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high)){
      if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }

}
```
