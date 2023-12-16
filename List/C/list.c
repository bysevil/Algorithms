#include"list.h"
// 创建返回链表的头结点.
ListNode* ListCreate(){
    ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
    if(!NewNode){
        perror("NewNode malloc fail");
        exit(EXIT_FAILURE);
    }

    NewNode->_next = NewNode->_prev = NewNode;
    return NewNode;
}
// 双向链表销毁
void ListDestory(ListNode* pHead){
    assert(pHead);
    while(pHead->_next != pHead){
        ListErase(pHead->_next);
    }
    free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead){
    assert(pHead);
    ListNode* cur = pHead->_next;
    while(cur != pHead){
        printf(" %d ->", cur->_data);
        cur = cur->_next;
    }
    printf(" NULL\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x){
    assert(pHead);
    ListInsert(pHead,x);
}
// 双向链表尾删
void ListPopBack(ListNode* pHead){
    assert(pHead);
    assert(pHead->_next != pHead);
    ListErase(pHead->_prev);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x){
    assert(pHead);
    ListInsert(pHead->_next,x);
}
// 双向链表头删
void ListPopFront(ListNode* pHead){
    assert(pHead);
    assert(pHead->_next != pHead);
    ListErase(pHead->_next);
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x){
    ListNode* cur = pHead->_next;
    while(cur != pHead){
        if(cur->_data == x){
            return cur;
        }
        cur = cur->_next;
    }
    return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x){
    assert(pos);
    ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
    if(!NewNode){
        perror("Insert NewNode malloc fail");
        exit(EXIT_FAILURE);
    }
    NewNode->_data = x;
    NewNode->_next = pos;
    NewNode->_prev = pos->_prev;

    pos->_prev->_next = NewNode;
    pos->_prev = NewNode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos){
    assert(pos);
    pos->_prev->_next = pos->_next;
    pos->_next->_prev = pos->_prev;
    free(pos);
}
