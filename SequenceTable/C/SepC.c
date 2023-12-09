#include"SepC.h"

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps){
	ps->a = malloc(4*sizeof(SLDateType));
	ps->size = 0;
	ps->capacity = 4; 
}
void SeqListDestroy(SeqList* ps){
	ps->size = ps->capacity = 0;
	free(ps->a);
	ps->a = NULL;
}

void SeqListPrint(SeqList* ps){
	for(int i = 0; i < ps->size; i++){
		printf("%d->",ps->a[i]);
	}
	printf("NULL\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x){
	SeqListInsert(ps,ps->size,x);
}
void SeqListPushFront(SeqList* ps, SLDateType x){
	SeqListInsert(ps,0,x);
}
void SeqListPopFront(SeqList* ps){
	SeqListErase(ps,0);
}
void SeqListPopBack(SeqList* ps){
	ps->size--;
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x){
	for(int i = 0; i < ps->size; i++){
		if(ps->a[i] == x){
			return i;
		}
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x){
	assert(ps);
	assert(pos <= ps->size && pos >= 0);
	if(ps->size == ps->capacity){
		ps->capacity *= 2;
		ps->a = realloc(ps->a,ps->capacity* sizeof(SLDateType));
		assert(ps->a);
	}
	for(int i = ps->size;i > pos; i--){
		ps->a[i] = ps->a[i-1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos){
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	ps->size--;
	for(int i = pos;i < ps->size; i++){
		ps->a[i] = ps->a[i+1];
	}
}