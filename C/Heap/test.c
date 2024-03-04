#include"Heap.h"

void print(Heap* hp){
    for(int i = 0; i < hp->_size; i++){
        printf("%d ",hp->_data[i]);
    }
    printf("\n");
}

int main(){
    int nums[] = {9,8,7,6,5,4,3,2,1};
    Heap* hp = HeapCreate(nums,9);
    print(hp);

    printf("%d ",HeapPop(hp));
    printf("%d ",HeapPop(hp));
    printf("%d ",HeapPop(hp));
    printf("%d ",HeapPop(hp));
    printf("%d ",HeapPop(hp));
    printf("%d ",HeapPop(hp));
    printf("%d ",HeapPop(hp));
    printf("%d ",HeapPop(hp));
    printf("\n");

    HeapPush(hp,1);
    HeapPush(hp,2);
    HeapPush(hp,3);
    HeapPush(hp,4);
    HeapPush(hp,5);
    print(hp);

    printf("%d\n",HeapTop(hp));
    
    HeapDestory(hp);
    return 0;
}