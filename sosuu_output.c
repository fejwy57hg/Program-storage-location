#include <stdio.h>

int main(void){
    int x, y, flag;
    int count=0;

    for(x=2; x<=1000; x++){
       flag = 0;
       for(y=2; y<x; y++){
           if(x%y==0){
               flag = 1;
           }
       }
       if(flag == 0){
           printf("%3d ", x);
           count++;
           if(count%10==0){
               printf("\n");
           }
       } 
    }
  
    return 0;
}
