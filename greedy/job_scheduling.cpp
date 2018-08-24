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
