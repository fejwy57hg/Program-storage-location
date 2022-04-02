#include <stdio.h>
#include <stdlib.h>

//構造体定義
typedef struct node{
    char c;             // 文字データ(文字)
    int code;           // 文字コード(整数)
    struct node *next; // 次の node のアドレス(ポインタ)
} node_t;   //node_t == struct node


// ノード作成関数
// 引数: メンバ値
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
        printf("  %p\n", pos->next);
    }

    return;
}



// --- main ---
int main(int argc, char **argv){
    node_t *top=NULL, *temp, *pos, *new;
    int input_num, i;
    
     if(argc < 2){   //コマンドラインで指定がなかった時の処理
        printf("Please enter the characters you wish to delete");
        return 1;
    }


    // リスト作成
     new = node_new('A', 'A');
    top = new;
    pos = top;

    for(i='B'; i<='Z'; i++){
        new = node_new(i, i);
        pos->next = new;
        pos = new;
    }


     // 指定された場所
    input_num = atoi(argv[1]); //文字列を整数値に変換
    printf("\n- Delete %dth node.\n", input_num);

   if(input_num < 1 || input_num > 26){  //1~26が指定された場合の処理
       printf("Specify the nodes to be deleted by number from 1 to 26");
       return 1;
   }


   //リスト表示
     printf("\n");
     node_list(top);


    //先頭要素を削除する場合
    if(input_num == 1){
     temp = top;      //先頭アドレスを退避
     top = top->next;  //先頭アドレスの次のアドレスを先頭アドレスとする
     free(temp);      //tempのメモリ解放
    }

    //終端要素を削除する場合
    else if(input_num == 26){
        for(pos=top; pos->next->next != NULL; pos=pos->next);  //終端ノードの1つ前のノードに移動
        temp = pos->next;
        pos->next = NULL;
        free(temp);
    }
  

    //それ以外を削除する場合
    else if(input_num != 1 || input_num != 26){
        for (i=1, pos=top; i<(input_num-1); i++, pos = pos->next);  // pos に削除するノードの 1つ前のノードのアドレスを代入
    temp = pos->next;        // tmp に削除するノードのアドレスを代入
    pos->next = temp->next;  // pos のアドレスのノードのメンバ next に削除するノードの次のノードのアドレスを代入
    free(temp);              // tmp (削除するノード)のアドレスを解放する  
    }

    //リスト表示
     printf("\n");
     node_list(top);

  
    return 0;
}
