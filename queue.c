#include <stdio.h>
#include <stdlib.h>
#define N 10

void createq(int[], int*, int*);
void add(int[], int*, int*, int);
void del(int[], int*, int*);
void showqueue(int[], int, int);

int main(void) {
    int queue[N];
    int front, rear;
    int input, select;
    
    createq(queue, &front, &rear);
    
    while(1) {
        printf("\n\n請輸入選項(-1結束)：");
        printf("\n(1)插入值至佇列");
        printf("\n(2)刪除前端值");
        printf("\n(3)顯示所有內容");
        printf("\n$c>");
        scanf("%d", &select);
        if(select == -1)
            break;
        switch(select) {
            case 1:
                printf("\n輸入值：");
                scanf("%d", &input);
                add(queue, &front, &rear, input);
                break;
                
            case 2:
                del(queue, &front, &rear);
                break;
            case 3:
                showqueue(queue, front, rear);
                break;
            default:
                printf("\n選項錯誤！");
        }
    }
    
    printf("\n");
    
    return 0;
}

void createq(int queue[], int* front, int* rear) {
    int i;
    
    for(i = 0; i < N; i++)
        queue[i] = 0;
    
    *front = *rear = 0;
}
void add(int queue[], int* front, int* rear, int data) {
    int f, r;
    f = *front;
    r = *rear;
    r = (r+1) % N;
    
    if(f == r) {
        printf("\n佇列已滿！");
        return;
    }
    
    queue[r] = data;//存值
    *rear = r;//指標移動
}

void del(int queue[], int* front, int* rear) {
    int f, r;
    f = *front;
    r = *rear;
    
    if(f == r) {
        printf("\n佇列為空！");
        return;
    }
    
    f = (f + 1) % N;//取值
    * front = f;//指標移動
}

void showqueue(int queue[], int front, int rear) {
    int i;
    
    printf("\n佇列內容：");
    for(i = (front+1) % N; i <= rear; i++)
        printf("%d ", queue[i]); 
} 
