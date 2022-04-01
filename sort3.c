#include <stdio.h>
#define NUM 5

int main(void){
    int array[NUM] = {40, 22, 1, 0, 19};
    int i, j, min;

    //挿入ソート
    for(i=0; i<NUM; i++){
        min = array[i];
        for(j=i; j<NUM; j++){
            if(array[j] < min){
             min = array[j];
             array[j] = array[i];
             array[i] = min;
            }
        }
    }
    


    //選択ソート
    for(i=0; i<NUM; i++){
        min = array[i];
        for(j=i+1; j<NUM; j++){
            if(min > array[j]){
                min = array[j];
                array[j] = array[i];
                array[i] = min;
            }
        }
    }
    


    //バブルソート
    for(i=0; i<NUM; i++){
        for(j=i+1; j<NUM; j++){
            if(array[i] > array[j]){
                min = array[j];
                array[j] = array[i];
                array[i] = min;
            }
        }
    }
    


    //ソート結果出力
    for(i=0; i<NUM; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
