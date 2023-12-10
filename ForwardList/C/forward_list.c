#include"forward_list.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x) {
	SListNode* ret = malloc(sizeof(SListNode));
	if (ret == NULL) {
		printf("空间申请失败");
		exit(-1);
	}
	ret->data = x;
	ret->next = NULL;
	return ret;
}
// 单链表打印
void SListPrint(SListNode* plist) {
	while (plist) {
		printf(" %d ->", plist->data);
		plist = plist->next;
	}
	printf(" NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x) {
	assert(pplist);
	SListNode* plist = *pplist;
	if (plist) {
		while (plist->next) {
			plist = plist->next;
		}
		plist->next = BuySListNode(x);
	}
	else {
		*pplist = BuySListNode(x);
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x) {
	SLTInsert(pplist,*pplist,x);
}
// 单链表的尾删
void SListPopBack(SListNode** pplist) {
	assert(pplist);
	SListNode* plist = *pplist;
	assert(plist);

	if (plist->next == NULL) {
		SLTErase(pplist, plist);
	}

	while (plist->next->next) {
		plist = plist->next;
	}

	SLTErase(&plist, plist->next);
}
// 单链表头删
void SListPopFront(SListNode** pplist) {
	SLTErase(pplist, *pplist);
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	while (plist) {
		if (plist->data == x) {
			return plist;
		}
		plist = plist->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x) {
	assert(pos);
	SListNode* NewNode= BuySListNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos) {
	SListNode* del = pos->next;
	assert(del);
	pos->next = del->next;
	free(del);
}

// 在pos的前面插入
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x) {
	assert(pphead);
	assert(pos);
	SListNode* plist = *pphead;
	if (plist == pos) {
		*pphead = BuySListNode(x);
		(*pphead)->next = plist;
		return;
	}
	while (plist) {
		if (plist->next == pos) {
			SListNode* NewNode = BuySListNode(x);
			NewNode->next = plist->next;
			plist->next = NewNode;
			return;
		}
		plist = plist->next;
	}
		printf("pos未找到，插入失败\n");
}
// 删除pos位置
void SLTErase(SListNode** pphead, SListNode* pos) {
	assert(pphead);
	assert(pos);
	SListNode* plist = *pphead;
	assert(plist);

	if (plist == pos) {
		*pphead = plist->next;
		free(plist);
		return;
	}

	while (plist) {
		if (plist->next == pos) {
			plist->next = pos->next;
			free(pos);
			return;
		}
		plist = plist->next;
	}

	printf("未找到pos，删除失败");

}
void SLTDestroy(SListNode** pphead) {
	assert(pphead);
	while (*pphead) {
		SListPopFront(pphead);
	}
}
