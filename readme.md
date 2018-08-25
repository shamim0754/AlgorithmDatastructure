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

### Algorithm ###
An algorithm is a procedure having well defined steps for solving a particular problem

The major categories of algorithms are given below:
1. Sort Algorithm: Sorting the items inside a data structure either acending or decending.
2. Search Algorithm : Searching the items inside a data structure.
3. Delete Algorithm : Delere the items from a data structure.
4. Insert Algorithm :  Inserting an item inside a data structure.
4. Update Algorithm :  Updating an item inside a data structure.

### Characteristics of an Algorithm ###

1. Input: An algorithm must have 0 or well defined inputs.
2. Output: An algorithm must have 1 or well defined outputs, and should match with the desired output.
3. Feasibility: An algorithm must be terminated after the finite number of steps.
4. Independent: An algorithm must have step-by-step directions which is independent of any programming code.
5. Unambiguous: An algorithm must be unambiguous and clear. Each of their steps and input/outputs must be clear and lead to only one meaning.

### Algorithm Complexity ###
The complexity of an algorithm gives the running time and/or the storage space required by the algorithm in terms of the size of input data.

1. Space Complexity
Space complexity of an algorithm represents the amount of memory space required by the algorithm in its life cycle. The space required by an algorithm is equal to the sum of the following two components −

1. Fixed part:  it is a space required to store certain data and variables, that are independent of the size of the problem. For example, simple variables and constants used, program size, etc.

2. variable part : it is a space required by variables, whose size depends on the size of the problem. For example, dynamic memory allocation, recursion stack space, etc.

2. Time Complexity
Time complexity of an algorithm represents the amount of time required by the algorithm to run to completion
For example, addition of two n-bit integers takes n instuction. Consequently, the total computational time is T(n) = c ∗ n, where c is the time taken for the addition of two bits.

<b>Asymptotic analysis</b> of an algorithm refers to defining the mathematical boundation/framing of its run-time performance.The time required by an algorithm falls under three types −

1. Best Case − Minimum time required for program execution. it express by nota
tion called Ω Notation
2. Average Case − Average time required for program execution.

3. Worst Case − Maximum time required for program execution.
it express by nota
tion called Ο(Big O) Notation

The other one asymptotic notations  is <br/>
θ Notation : it express both best case and worst case.

Consider flowing function

```C
int myFunction(int n)
{
   int x=n+10;
   x=x/2;
   return x;
}
```

Since any value of n it execute constant number of instruction . as a result it will always need same time. it express by O(1);

Consider floowing function
```C
int myFunction2(int n)
{
  int sum=0;
  for(int i=1;i<=n;i++)
  {
    sum+=i;
    if(sum>=1000) break;
  }
  return sum;
}
```

Since based on value of n number of instruction increased . although it can break but we always concider worse case . it is expressed by O(n);

```C
int myFunction3(int n)
{
int sum=0;
for(int i=1;i<=n;i++)
{
for(int j=i;j<=n;j++)
{
sum+=(i+j);
}
}
return sum;
}
```
Since first loop is running n times, 2nd loop is running n-1 times,3rd loop running n-2 times <br />
so algorithm complexitity = n + n-2 + n-3+.....+1
                           = n * (n + 1)/2
                           = (n<sup>2</sup> + n)/2 
                           = n<sup>2</sup> (n<sup>2</sup> + n and n<sup>2</sup> is very little)
                           = O(n<sup>2</sup>)

```

int binary_search(int arr[],int size,int searchitem){
   int low,mid,high,isFound = 0;
   high = size - 1;
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

Since here every time n is divided 2 times. <br />
How many times a number can divided by two? <br />
Ans : log<sub>2</sub>n (n = a number)<br />
it is expressed by O(log<sub>2</sub>n)

if an algorithm have (n<sup>4</sup>) , (n<sup>2</sup>) and log<sub>2</sub>n<br />
then = (n<sup>4</sup>) + (n<sup>2</sup>) + log<sub>2</sub>n<br />
= (n<sup>4</sup>) (Since (n<sup>2</sup>) + log<sub>2</sub>n is very small)


### Algorithm Technique ###

1. Greedy approach : In greedy algorithm approach, decisions are made from the given solution domain. As being greedy, the closest solution that seems to provide an optimum solution is chosen  at that moment. But it may fail where global optimization

  Example : Counting Coins, we have coins of 1, 7, 10 value, How many coins are required to get 18 ?

  Ans : 3 coins.Greedy approach forces the algorithm to pick the largest to lowest possible coin.
  1. 10, the remaining count is 7
  2. 7, the remaining count is 1
  3. 1


  if we slightly change the problem(Count 15) then the same approach may not be able to produce the same optimum result, then greedy approach may use more coins than necessary<br/>
  10 + 1 + 1+1+1+1+1+1(6 coins)
  <br />
  Whereas the same problem could be solved by using only 3 coins (7 + 7 + 1) . (it may fail where global optimization)

  ```
  int coin[3] = { 10, 5, 2,1 } ;
   int totalChange = 16, coinRequired = 0;
   // for i = 1 to total coin decensing  order
   for(int i = 0; i <= 3; i++){
      if(totalChange >= coin[i]){
          coinRequired ++;
          totalChange -= coin[i];
      }
   }
   printf("The required coins %d", coinRequired);
  ```

Most networking algorithms use the greedy approach. Here is a list of few of them −

1. Travelling Salesman Problem
2. Prim's Minimal Spanning Tree Algorithm
3. Kruskal's Minimal Spanning Tree Algorithm
4. Dijkstra's Minimal Spanning Tree Algorithm
5. Graph - Map Coloring
6. Graph - Vertex Cover
7. Knapsack Problem
8. Job Scheduling Problem :
  Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.

  In greedy approach,
  1) Sort all jobs in decreasing order of profit.
  2) Initialize the result sequence as first job in sorted jobs( place at Scheduling List).
  3) Do following for remaining n-1 jobs
  .......a) If the current job can fit in the current result sequence 
            without missing the deadline, add current job to the result.
            Else ignore the current job.

  For Example : <br />
  ![alt text](images/job_schduling.png)

  1) Sort all jobs in decreasing order of profit.

  ![alt text](images/job_schduling1.png)

  2) Initialize the result sequence as first job in sorted jobs( place at Scheduling List).

  Since job A has deadline 2 unit so it could be place at 0-1 or 1-2 seconds. we choose always latest dealine  so we choose 1-2

  ![alt text](images/job_schduling2.png)

  Next job C we start looking empty backward from unit 2. 0-1 is empty slot so c is there

  ![alt text](images/job_schduling3.png)

  Next job D we start looking empty backward from unit 1. 0-1 is not empty slot so skip it

  Next job B we start looking empty backward from unit 1. 0-1 is not empty slot so skip it

  Next job E we start looking empty backward from unit 3. 2-3 is  empty slot so E is there

  ![alt text](images/job_schduling4.png)

  ```
  //implement using C++
  #include<iostream>
  #include<algorithm>
  using namespace std;

  struct Job{
      char id;
      int deadline;
      int profit;
  };

  bool comparison(Job a, Job b)
  {
       return a.profit > b.profit;
  }

  void printJobScheduling(Job arr[], int n){
      sort(arr, arr+n, comparison);

       int result[n]; // To store result (Sequence of jobs)
       bool slot[n];

       // Initialize all slots to be free
      for (int i=0; i<n; i++)
          slot[i] = false;
      // Iterate through all given jobs
      for (int i=0; i<n; i++){
              //min(n, arr[i].deadline)-1; slot before or after based on deadline
          for (int j=min(n, arr[i].deadline)-1; j>=0; j--){
            // Free slot found
            if (slot[j]==false)
            {
               result[j] = i;  // Add this job to result
               slot[j] = true; // Make this slot occupied
               break;
            }
          }
      }

      // Print the result
      for (int i=0; i<n; i++)
         if (slot[i])
           cout << arr[result[i]].id << " ";
  }
  // Driver program to test methods
  int main()
  {
      Job arr[] = {
                      {'a', 2, 100},
                      {'b', 1, 19},
                      {'c', 2, 27},
                      {'d', 1, 25},
                      {'e', 3, 15}
                 };
      int n = sizeof(arr)/sizeof(arr[0]);
      cout << "Following is maximum profit sequence of job :" ;
      printJobScheduling(arr, n);
      return 0;
  }

  ```

2. Divide and Conquer :

  In divide and conquer approach, the problem in hand, is divided into smaller sub-problems and then each problem is solved independently. When we keep on dividing the subproblems into even smaller sub-problems, we may eventually reach a stage where no more division is possible. Those "atomic" smallest possible sub-problem (fractions) are solved. The solution of all sub-problems is finally merged in order to obtain the solution of an original problem.

  Example : Convert following small alphabet to capital alphabet

  ![alt text](images/divide_and_conquer.jpg)

  The following computer algorithms are based on divide-and-conquer programming approach −

  1. Merge Sort
  2. Quick Sort
  3. Binary Search
  4. Strassen's Matrix Multiplication
  5. Closest pair (points)

2. Dynamic programming :

  Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again.

  Mostly, these algorithms are used for optimization.

  The following computer problems can be solved using dynamic programming approach −

  1. Fibonacci number series
  ```C
  void main(){
      int n;
      printf("Enter number of elements :\n");
      scanf("%d", &n);
      for(int i=0; i< n; i++)
          printf("%d ", fibonacci(i));

  }
  int fibonacci( int n ) {
      if( n == 0 ) return 0;
      if( n == 1 ) return 1;
      return fibonacci( n-1 ) + fibonacci( n-2 );
  }
  ```
  Execution time : 3.266s <br />

  Recursion tree for execution of fib(5)

  ![alt text](images/fibbo.png)

  We can see that the function fib(3) is being called 2 times. If we would have stored the value of fib(3), then instead of computing it again, we could have reused the old stored value.

  There are following two different ways to store the values so that these values can be reused:
  a) Memoization (Top Down)

  ```C
  #include <stdio.h>
  #include <conio.h>
  int dp[20];

  void main(){
      int n;
      printf("Enter number of elements :\n");
      scanf("%d", &n);
      for(int i=0;i<20;i++)
          dp[i] = -1;
      for(int i=0; i< n; i++)
          printf("%d ", fibonacci(i));

  }
  int fibonacci( int n ) {
      if( n == 0 ) return 0;
      if( n == 1 ) return 1;
      if( dp[n] != -1 ) return dp[n];
      else{
          dp[n] = fibonacci( n-1 ) + fibonacci( n-2 );
          return dp[n];
      }
  }

  ```

  Execution time : 2.265s <br />

  b) Tabulation (Bottom Up)


  2. Knapsack problem
  3. Tower of Hanoi
  4. All pair shortest path by Floyd-Warshall
  5. Shortest path by Dijkstra
  6. Project scheduling

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
