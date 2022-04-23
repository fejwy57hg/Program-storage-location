#include <stdio.h>
#include <math.h>  //sqrtを使用する場合は、コンパイルオプションとして、-lmを追加する

//内分点・外分点の構造体定義
//線分ABは、入力値とする
typedef struct math{
    double pal; //パラメータ
} math;


//2点間の距離の構造体定義
typedef struct math_2{
    double pal;
} math2;


//内分点・外分点の座標における構造体定義
typedef struct math_3{
    double pal;
} math3;


//プロトタイプ宣言
//内分点・外分点を求める関数
void Inner_outer(math x, math y, math a, math b, math *c, math *d);

//二点間の距離を求める公式
float two_points_Distance_between(math2 x1, math2 y1, math2 x2, math2 y2);


//内分点・外分点の座標を求める関数
//x1,y1は点Aのxy座標、x2,y2は点Bのxy座標、m,nはm:nに内分・外分するパラメータ、*p,*Qは座標を格納するポインタ
void coordinates_of_inner_outer(math3 X1, math3 Y1, math3 X2, math3 Y2, math3 m, math3 n, 
                                 math3 *P, math3 *Q, math3 *R, math3 *S);


int main(void){
    
    int i;  //何を求めるのかを決める
    printf("何を求めますか？\n");
    printf("[1]...内分点・外分点\n");
    printf("[2]...2点間の距離\n");
    printf("[3]...内分点・外分点の座標\n");
    scanf("%d", &i);  //何を求めるのかを決める

//C言語の場合、switch文が『一つのブロック・スコープ』であるため、スコープの途中で変数宣言を行うことができない
//switchブロックより前に、使用する変数を定義する必要がある


//内分点・外分点の変数定義
    math x, y;  //距離の2点A,Bのパラメータ入力用変数
    math a, b;  //内分パラメータ
    double c=0;  //結果格納変数
    double d=0;  //結果格納変数


//2点間の距離の変数定義
math2 x1, y1, x2, y2; //各座標のパラメータ
math2 result;  //結果格納変数



//内分点・外分点の座標の変数定義
math3 X1, Y1, X2, Y2, m, n; //各座標のパラメータ
double p, q, r, s;  //結果格納変数

 
    switch(i){
        case 1:   //内分点・外分点
    
    //データ入力
    printf("2点 A, Bを入力してください\n");
    printf("A : "); scanf("%lf", &x.pal);  //a = x
    printf("B : "); scanf("%lf", &y.pal);  //b = y
    
    printf("X : Y の内分・外分パラメータを入力してください\n");
    printf("X : "); scanf("%lf", &a.pal); //m = a
    printf("Y : "); scanf("%lf", &b.pal); //n = b


    //2点間の距離を求める関数にわたす
    Inner_outer(x, y, a, b, &c, &d); 

    //結果出力
    printf("2点 A B を結ぶ線分 %.0f , %.0f を %.0f : %.0f に内分・外分する点は\n", x.pal, y.pal, a.pal, b.pal);
    printf("内分点 : %.2f\n", c);
    printf("内分点 : %.2f\n", d);
    break;


    case 2:  //2点間の距離
    
    //データ入力
    printf("2点 A, B の座標を入力してください\n");
    printf("Aのx座標 : "); scanf("%lf", &x1.pal);
    printf("Aのy座標 : "); scanf("%lf", &y1.pal);
    printf("Bのx座標 : "); scanf("%lf", &x2.pal);
    printf("Bのy座標 : "); scanf("%lf", &y2.pal);

    //関数に入力したパラメータを渡すし、メンバresultが演算結果を取得
    result.pal = two_points_Distance_between(x1, y1, x2, y2);

     //結果出力
     printf("2点 A, B 間の距離は%.2fです\n", result);

     break;

     
     case 3:  //内分点・外分点の座標

   //データ入力
    printf("2点 A, B の座標を入力してください\n");
    printf("Aのx座標 : "); scanf("%lf", &X1.pal);
    printf("Aのy座標 : "); scanf("%lf", &Y1.pal);
    printf("Bのx座標 : "); scanf("%lf", &X2.pal);
    printf("Bのy座標 : "); scanf("%lf", &Y2.pal);

    putchar('\n');

    printf("内分・外分するm : n のパラメータを入力してください\n");
    printf("m : ");  scanf("%lf", &m.pal);
    printf("n : ");   scanf("%lf", &n.pal);


   //関数に渡す
   coordinates_of_inner_outer(X1, Y1, X2, Y2, m, n, &p, &q, &r, &s);

   //結果出力
   printf("2点 A(%.0lf, %.0lf), B(%.0lf, %.0lf)　を結ぶ線分 AB　を, %.0lf : %.0lf に内分する点P, 外分する点Qの座標は\n", X1, Y1, X2, Y2, m, n);
   printf("P : (%.2lf, %.2lf), Q : (%.2lf, %.2lf)", p, q, r, s);

     break;

    }

    return 0;
}


//内分点、外分点を求める関数
void Inner_outer(math x, math y, math a, math b, math *c, math *d){
    
    //内分点
    c -> pal = ((b.pal * x.pal)+(a.pal * y.pal)) / (a.pal + b.pal);   

    //外分点
    d -> pal = ((-b.pal * x.pal)+(a.pal * y.pal)) / (a.pal - b.pal);  
}


//2点間の距離を求める関数
float two_points_Distance_between(math2 x1, math2 y1, math2 x2, math2 y2){
     float result;  //演算結果格納変数

    result = sqrt ( ((x2.pal - x1.pal) * (x2.pal - x1.pal)) + ((y2.pal - y1.pal) * (y2.pal - y1.pal)) );

     return result;
 }


 //内分点・外分点の座標を求める関数
void coordinates_of_inner_outer(math3 X1, math3 Y1, math3 X2, math3 Y2, math3 m, math3 n, 
                                math3 *P, math3 *Q, math3 *R, math3 *S)
{
    //座標P
    P -> pal = ((n.pal * X1.pal) + (m.pal * X2.pal)) / (m.pal + n.pal); 
 
    //座標Q
    Q -> pal = ((n.pal * Y1.pal) + (m.pal * Y2.pal)) / (m.pal + n.pal); 

    //座標R
    R -> pal = ((-n.pal * X1.pal) + (m.pal * X2.pal)) / (m.pal - n.pal); 
 
     //座標S
    S -> pal = ((-n.pal * Y1.pal) + (m.pal * Y2.pal)) / (m.pal - n.pal); 
}
