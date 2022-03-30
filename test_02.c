#include <stdio.h>
#define NUM 128

int put_chnum(const char *s, int c){
    int count=0;

    while(*s) {
        if(*s++ == c)
         count++;
    }
     return count;
}


int main(void){
    char array[NUM];
    char temp[NUM/10];
    int count;

     printf("文字列を入力してください : ");
     scanf("%s", array);

     printf("%sからカウントするのは : ", array);
     scanf("%s", temp);

     count = put_chnum(array, temp[0]);

    if(count == -1){
        printf("その文字は0個含まれています");
    } else {
        printf("その文字は%d個含まれています", count);
    }

    return 0;
}
