#include <stdio.h>
#include <conio.h>

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
