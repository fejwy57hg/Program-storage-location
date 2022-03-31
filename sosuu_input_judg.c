#include <stdio.h>

int main(void){
    int x, y, flag;

  
  printf("整数を入力してください : ");
  scanf("%d", &x);
    
       if(x==2){
           printf("%dは素数です", x);
          }

       for(y=2; y<x; y++){
            flag = 0;
           if(x%y==0){
               flag = 1;
                printf("%dは素数ではないです", x);
               break;
           }
       }
       if(flag == 0){
           printf("%dは素数です", x);
       }
    
  
    return 0;
}
