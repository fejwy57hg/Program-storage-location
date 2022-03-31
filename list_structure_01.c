#include <stdio.h>
#include <stdlib.h> //malloc(動的メモリ確保)使用

//構造体定義
typedef struct node{
    char c;             // 文字データ(文字)
    int code;           // 文字コード(整数)
    struct node *next; // 次の node のアドレス(ポインタ)
} node_t;   //node_t == struct node


// ノード作成関数
node_t *node_new(char c, int code){
    node_t *new;

    new = (node_t *)malloc(sizeof(node_t)); // 領域確保
    new->c = c;
    new->code = code;
    new->next = NULL;

    return new; // 確保した領域のアドレスを返す
}


// リスト表示関数
// 引数: 表示を開始する先頭ノードのアドレス
void node_list(node_t *pos){
    printf("*** list data\n");

    // 指定されたノードから next が NULL のノードまでノードのメンバを表示
    for (; pos!=NULL; pos = pos->next){
        printf("pos: %p ->", pos);
        printf("  %c,", pos->c);
        printf("  %d, ", pos->code);
        printf("next_address: %p\n", pos->next);
    }

    return;
}


// --- main ---
int main(void){
    node_t *top=NULL, *new, *pos;
    int c, i;

    for (i='A'; i<='Z'; i++){    
        c = i;  
        new = node_new(c, c); // 新規ノード作成

        if (top == NULL){
            top = new;
        } else {
            pos->next = new;
        }

        pos = new; // 現在のノードを作成したノードにする
    } 


   //リスト表示
    printf("\n");
    node_list(top);

    return 0;
}
