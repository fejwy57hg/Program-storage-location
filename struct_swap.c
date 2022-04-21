#include <stdio.h>
#define NUM 5 //学生の人数
#define NAME 64 //名前の文字列

//構造体定義
typedef struct student{
    char name[NAME]; //名前
    int score; //得点
} student_s;


//出力関数
void input_data(student_s *data){
    int i;
      for(i=0; i<NUM; i++){
        printf("%dth student\n", i+1);
        printf("name : ");
        printf("%s  ", data[i].name);
        printf("score : ");
        printf("%d\n", data[i].score);
    }
 }

//ソート処理----------------------------------------------------------------------------------------
//交換関数
void swap(student_s *x, student_s *y){
    student_s temp = *x;
    *x = *y;
    *y = temp;
}

//交換判定関数
void sort(student_s a[]){   //a = std になるから、stdの構造体として振る舞うことができる
    int i, j;  //カウンタ
     //バブルソート
     for(i=0; i<NUM; i++){
        for(j=i+1; j<NUM; j++){
            if(a[i].score < a[j].score){  //昇順に並べ替える
              swap(&a[i], &a[j]); //二値のアドレス交換関数に渡す
            }
        }
    }
}
//----------------------------------------------------------------------------------------------------


int main(void){
    int i;
    student_s std[NUM]; //入力値格納用配列
 
   //データ入力
    for(i=0; i<NUM; i++){
        printf("%dth student\n", i+1);
        printf("name : ");
        scanf("%s", std[i].name);
        printf("score : ");
        scanf("%d", &std[i].score);
    }


   //ソート関数に渡す
    sort(std);  //構造体を丸ごと渡す

    //出力
     input_data(&std[0]);


    return 0;
}
