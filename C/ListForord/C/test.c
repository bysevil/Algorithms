#include"forward_list.h"

int main() {
	//创建节点测试
	SListNode* head = BuySListNode(1);
	SListPrint(head);
	
	//尾插测试
	free(head); head = NULL;

	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPrint(head);

	//后插测试
	SListInsertAfter(head->next, 10);
	SListPrint(head);

	//查找测试
	SListNode* pos = SListFind(head, 10);
	printf(" %d\n", pos->data);
	pos = SListFind(head, 5);
	if (pos == NULL) printf(" NULL\n");

	//后删测试
	//SListEraseAfter(head->next->next->next);//断言测试
	SListEraseAfter(head->next->next);
	SListPrint(head);

	//前插测试
	SLTInsert(&head,head->next->next,20);
	SListPrint(head);

	//头插测试
	SListPushFront(&head, 30);
	SListPrint(head);

	//删除测试
	SLTErase(&head,head->next->next->next);
	SListPrint(head);

	//头删测试
	SListPopFront(&head);
	SListPrint(head);

	//尾删测试
	SListPopBack(&head);
	SListPrint(head);

	//销毁测试
	SLTDestroy(&head);
	SListPrint(head);
	SLTDestroy(&head);
	return 0;
}