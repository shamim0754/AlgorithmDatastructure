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
    int fibonacci[n+1];
    int i;
    fibonacci[0] = 0;   fibonacci[1] = 1;
    for (i = 2; i <= n; i++)
      fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

  return fibonacci[n];
}
