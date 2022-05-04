#include <iostream>
using namespace std;

int main(){
    int area;
    cout << "面積 : ";   cin >> area;

    int i, j;
    int count = 0;

    for(i=0; i<=area; i++){
        for(j=0; j<=area; j++){
            if(i * j == area && i <= j){    //iとjの積がareaかつ、iがj以下なら実行
                if(j == 13){                //jが13の時は処理を中断し、tempラベルに遷移する
                    cout << "13で割り切れるため中断します。\n";
                    goto temp;
                }
                cout << i << " x " << j << "\n";
                count++;   //組み合わせの個数をカウントする
            }
        }
    }
    temp:
    cout << "全部で" << count << "個です。\n";
}
