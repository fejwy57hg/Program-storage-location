#include <stdio.h>
#define NUM 128

int main(void){
    int i;
    int array[NUM];

    array[0] = 0;
    printf("%d\n", array[0]);
    array[1] = 1;
    printf("%d\n", array[1]);

    for(i=2; i<NUM; i++){
        array[i] = array[i-2] + array[i-1];
         if(array[i] >= 1000){
            break;
        }
        printf("%d\n", array[i]);
    }
  
    return 0;
}
