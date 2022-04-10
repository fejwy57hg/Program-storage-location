#include <stdio.h>
#include <stdlib.h>

// 構造体の定義
typedef struct node{
    char c;
    int code;
    struct node *next;
} node_t;


// 新しい node を作成する関数
node_t *node_new(char c, int code){
    node_t *new;
    new = (node_t*)malloc(sizeof(node_t));
   
    // 文字を代入
    new->c = c;
    // 文字コードを代入
    new->code = code;
    // 終端のアドレスを代入
    new->next = NULL;

    // 作成した node のアドレスを返す
    return new;
}


//表示関数
void node_list(node_t *pos){
printf("\ntop address: %p\n\n", pos);     
    while (pos != NULL){
        printf("address: %p, ", pos);
        printf("data: %c, ", pos->c);
        printf("code: %d, ", pos->code);
        printf("next_address: %p\n", pos->next);        
        pos = pos->next;
    }
  }



// i 番目のノードを削除する関数   **********
node_t *node_del(node_t *top, int i){
    int count;
    node_t *pos, *pre, *tmp;

    if (i==1){   //先頭ノードなら
        pos = top->next;
    } else {
        pre = top;  
        pos = top->next;

        for (count=2; count<i && (pos->next != NULL); count++){
            pre = pos;       //その時点でのノードアドレス
            pos = pos->next; //次のノードアドレス
        }


            if (count = i){
                tmp = pos;
            }
            pre->next = pos->next;

    }
    return tmp;
}


//挿入関数
// i+1 番目にノード(new)を挿入する
node_t *node_ins(node_t *top, int i, node_t *new){
    int count;
    node_t *pos;

    // 先頭への挿入
    if (i==0){
        new->next = top;
        pos = new;
    } else {
        // 先頭以外への挿入
        pos = top;
        for (count=1; count<i && (pos->next != NULL); count++){
            pos = pos->next;
        }
       
         new->next = pos->next;
        pos->next = new;

    }

    pos = top;

    return pos;
}


int main(int argc, char **argv){
    // 変数定義
    node_t  *top=NULL, *new, *pos, *tmp1, *tmp2; 
    int i, j;

  
    if (argc<2){
        puts("please input two numbers");
    }



    // 'A' を代入する node を作成
    new = node_new('A', 'A');
    top = new;
    pos = new;    

    // 'B' - 'Z' を代入する node を作成
    for (i='B'; i<='Z'; i++){
        new = node_new(i, i);
        pos->next = new; //現在位置がポインタnextを指した時、新しく確保したメモリ領域のアドレスを代入する
        pos = new;       //現在位置を新しく確保したメモリ領域のアドレスとする
    }


 // 指定された場所
    i = atoi(argv[1]);
    printf("\n- Delete %dth node.\n", i);

    // 指定された場所のノードを削除する (関数を呼び出す)
   tmp1 = node_del(top, i); //tmp1に削除したアドレスを記憶させておく
   printf("%p\n", tmp1);

  //指定された場所
    j = atoi(argv[2]);
    printf("\n- Delete %dth node.\n", j);


    // 指定された場所のノードを削除する (関数を呼び出す)
   tmp2 = node_del(top, j-1); //tmp2に削除したアドレスを記憶させておく
       printf("%p\n", tmp2);


 // 指定された場所にノードを挿入する (関数を使う)
    top = node_ins(top, i-1, tmp2); //コマンドラインの第二引数をi-1番目に挿入


 // 指定された場所にノードを挿入する (関数を使う)
    top = node_ins(top, j-1, tmp1); //コマンドラインの第二引数をj-1番目に挿入


    // 先頭から node のデータを表示
    node_list(top);
    

    return 0;
}
