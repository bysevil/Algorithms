#include"SepC.h"

int main(){
    //初始化测试
    SeqList s;
    SeqListInit(&s);
    SeqListPrint(&s);

    //插入测试
    SeqListPushBack(&s,3);
    SeqListPrint(&s);
    SeqListPushBack(&s,4);
    SeqListPrint(&s);

    SeqListPushFront(&s,2);
    SeqListPrint(&s);
    SeqListPushFront(&s,1);
    SeqListPrint(&s);

    SeqListInsert(&s,1,10);
    SeqListPrint(&s);
    //查找测试
    printf("%d\n",SeqListFind(&s,4));
    printf("%d\n",SeqListFind(&s,20));
    //删除测试
    SeqListPopBack(&s);
    SeqListPrint(&s);
    SeqListPopFront(&s);
    SeqListPrint(&s);

    SeqListErase(&s,1);
    SeqListPrint(&s);

    SeqListDestroy(&s);
    SeqListPrint(&s);

    return 0;
}