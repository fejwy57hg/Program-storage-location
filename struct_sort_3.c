#include <stdio.h>
#include <string.h>
#define NUM 5 //人数
#define NAME 64 //名前の長さ

//構造体定義
typedef struct student{
    char name[NAME];  //名前
    int height;  //身長
    float weight;  //体重
} student;


//プロトタイプ宣言
void sort_name(student a[]);  //名前ソート関数
void sort_height(student a[]); //身長ソート関数
void sort_weight(student a[]); //体重ソート関数
void swap_data(student *x, student *y);  //交換関数
void input_data(student *result);  //出力関数


int main(void){
    int i;  //カウンタ    
    int check;  //ソートする対象を決める変数
    student std[NUM];  //入力値格納構造体

    //データ入力
    for(i=0; i<NUM; i++){
        printf("-------------------\n");
        printf("%dth student\n", i+1);
        printf("name  : ");  scanf("%s", std[i].name); //nameにアクセス
        printf("height : ");  scanf("%d", &std[i].height);
        printf("weight : ");  scanf("%f", &std[i].weight);
         printf("-------------------\n");
         printf("\n");
    }

    
   //何順にソートするのかを決める
    printf("何順に並べますか？\n");
    printf("[1]...名簿順,  [2]...身長順,  [3]...体重順 : ");
    scanf("%d", &check);

    
    switch(check){
        case 1: sort_name(std);  break;
        case 2: sort_height(std); break;
        case 3: sort_weight(std); break;
    }

    printf("\n");

    //データ出力
    input_data(&std[0]);

    return 0;
}


//名前ソート関数
void sort_name(student a[]){
    int i, j;
     for(i=0; i<NUM; i++){
        for(j=i+1; j<NUM; j++){
            if(strcmp(a[i].name, a[j].name) > 0){  //昇順に並べ替える
              swap_data(&a[i], &a[j]); //二値のアドレス交換関数に渡す
            }
        }
     }
  }


//身長ソート関数
void sort_height(student a[]){
    int i, j;
     for(i=0; i<NUM; i++){
        for(j=i+1; j<NUM; j++){
            if(a[i].height < a[j].height){  //昇順に並べ替える
              swap_data(&a[i], &a[j]); //二値のアドレス交換関数に渡す
            }
        }
     }
}


//体重ソート関数
void sort_weight(student a[]){
    int i, j;
     for(i=0; i<NUM; i++){
        for(j=i+1; j<NUM; j++){
            if(a[i].weight < a[j].weight){  //昇順に並べ替える
              swap_data(&a[i], &a[j]); //二値のアドレス交換関数に渡す
            }
        }
     }
}


//交換関数
void swap_data(student *x, student *y){
    student temp = *x;
    *x = *y;
    *y = temp;
}


//出力関数
void input_data(student *result){
    int i;
    
    for(i=0; i<NUM; i++){
         printf("---------------------------------------------------------\n");
        printf("%dth student\n", i+1);
        printf("name  : %s  ", result[i].name);  
        printf("height : %d  ", result[i].height);  
        printf("weight : %.1f\n", result[i].weight);  
        printf("---------------------------------------------------------\n\n");
    }
}
