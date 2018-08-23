#include <stdio.h>
#include <conio.h>
int main(){
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
 return 0;
}
