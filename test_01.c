#include <stdio.h>

void swap(int *px, int *py){
    int temp = *px;
    *px = *py;
    *py = temp;
}

void sort2(int *n1, int *n2){
    if(*n1 > *n2)
       swap(n1, n2);
}

void sort3(int *n1, int *n2, int *n3){
    if(*n1 > *n2)  swap(n1, n2);
    if(*n2 > *n3)  swap(n2, n3);
    if(*n1 > *n2)  swap(n1, n2);
}


int main(void){
    int x, y, z;
    x = 3;
    y = 2, 
    z = 1;

    sort2(&x, &y);
    sort3(&x, &y, &z);

    printf("x value : %d\n", x);
    printf("y value : %d\n", y);
    printf("z value : %d\n", z);

    return 0;
}
