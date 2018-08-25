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
