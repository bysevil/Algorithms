#include"list.h"

int main(){
    ListNode* pHead = ListCreate();
    ListPrint(pHead);

    ListPushBack(pHead,1);
    ListPushBack(pHead,2);
    ListPushBack(pHead,3);
    ListPushBack(pHead,4);
    ListPrint(pHead);
    
    ListPushFront(pHead,10);
    ListPushFront(pHead,20);
    ListPushFront(pHead,30);
    ListPushFront(pHead,40);
    ListPrint(pHead);
    
    printf(" %d\n",ListFind(pHead,20)->_data);
    printf(" %p\n",ListFind(pHead,5));
    
    ListPopBack(pHead);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);
    ListPopBack(pHead);
    ListPrint(pHead);
    
    ListPopFront(pHead);
    ListPrint(pHead);
    ListPopFront(pHead);
    ListPrint(pHead);
    ListPopFront(pHead);
    ListPrint(pHead);
    ListPopFront(pHead);
    ListPrint(pHead);
    return 0;
}
