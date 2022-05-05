#include <stdio.h>
#include <stdarg.h>

//第一引数に応じてそれ以降の引数の和を求める
//第二引数以降の引数の和を求めてdouble型で返す
double vsum(int sw, ...){
    double sum = 0.0;
    va_list ap;  //関数呼び出し時に積まれた引数をアクセスするための特殊な型

    va_start(ap, sw);   //可変部引数アクセス開始

    switch (sw) {    //int型の第二引数とint型の第三引数を加算
        case 0: sum += va_arg(ap, int);  //引数を次々と取り出す
                sum += va_arg(ap, int);
                break;
            
            //int型の第二引数とlong型の第三引数を加算
         case 1: sum += va_arg(ap, int);
                sum += va_arg(ap, long);
                break;
                 
               //int型の第二引数とlong型の第三引数とdouble型の第四引数を加算  
           case 2: sum += va_arg(ap, int);
                sum += va_arg(ap, long);
                 sum += va_arg(ap, double);
                break;
    }

    va_end(ap);  //可変部引数アクセス終了

    return sum;
}


//-------main
int main(void){
    printf("10 + 2 = %.2f\n", vsum(0, 10, 2));

    printf("57 + 300000L = %.2f\n", vsum(1, 57, 30000L));

    printf("98 + 2L  + 3.14 = %.2f\n", vsum(2, 98, 2L, 3.14));

    return 0;
}
