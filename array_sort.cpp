#include <iostream>
#include <typeinfo>

using namespace std;

void reverce(int a[], int n){
    cout << typeid(a).name() << "のポインタaが先頭要素を指す配列の並びを反転します。\n";

    for(int i=0; i < (n / 2); i++ )
    {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 -i] = temp;
    }
}


int main(){
    int array[5];

    for(int i=0; i<5; i++){
        cout << "array[" << i << "] : ";
        cin >> array[i];
    }
    reverce(array, (sizeof(array) / sizeof(array[0])));


    for(int i=0; i<5; i++){
        cout << "array[" << i << "] = " << array[i] << '\n';
    }
}
