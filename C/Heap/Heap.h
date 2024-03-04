#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _data;
	int _size;
	int _capacity; 
}Heap;

// 堆的构建
Heap* HeapCreate(HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
HPDataType HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
//堆的大小
int HeapCapacity(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
