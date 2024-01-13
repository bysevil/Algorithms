#include"Heap.h"

void Swap(HPDataType* a, HPDataType* b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void ADJustDown(Heap* hp, int parent){
    assert(hp);
    int child = parent * 2 + 1;
    while(child < HeapSize(hp)){
        if(child + 1 < HeapSize(hp) && hp->_data[child] > hp->_data[child+1]){
            child++;
        }
        if(hp->_data[child] < hp->_data[parent]){
            Swap(hp->_data + child, hp->_data + parent);
            parent = child;
            child = parent * 2 + 1;
        }else{
            break;
        }
    }
}

void ADJustUp(Heap* hp, int child){
    assert(hp);
    int parent = (child - 1 ) / 2;
    while(parent >= 0){
        if(hp->_data[child] < hp->_data[parent]){
            Swap(hp->_data + child, hp->_data + parent);
            child = parent;
            parent = (child - 1 ) / 2;
        }else{
            break;
        }
    }
}

// 堆的构建
Heap* HeapCreate(HPDataType nums[], int Size){
    Heap* hp = malloc(sizeof(Heap));
    assert(hp);

    hp->_capacity = Size ? Size : 4;
    hp->_size = 0;

    hp->_data = malloc(sizeof(HPDataType) * HeapCapacity(hp));
    assert(hp->_data);

    for(int i = 0; i < Size; i++){
        HeapPush(hp,nums[i]);
    }

    return hp;
}

// 堆的销毁
void HeapDestory(Heap* hp){
    assert(hp);
    free(hp->_data);
    free(hp);
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x){
    assert(hp);
    
    if(HeapSize(hp) == HeapCapacity(hp)){
        hp->_capacity *= 2;
        hp->_data = realloc(hp->_data,HeapCapacity(hp));
        assert(hp->_data);
    }
    
    hp->_data[HeapSize(hp)] = x;
    hp->_size++;

    ADJustUp(hp,HeapSize(hp) - 1);
}
// 堆的删除
HPDataType HeapPop(Heap* hp){
    assert(hp);
    assert(!HeapEmpty(hp));
    Swap(hp->_data,hp->_data + HeapSize(hp) - 1);
    hp->_size--;
    ADJustDown(hp,0);
    return hp->_data[HeapSize(hp)];
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp){
    assert(hp);
    assert(!HeapEmpty(hp));
    return hp->_data[0];
}
// 堆的数据个数
int HeapSize(Heap* hp){
    assert(hp);
    return hp->_size;
}
//堆的大小
int HeapCapacity(Heap* hp){
    assert(hp);
    return hp->_capacity;
}
// 堆的判空
int HeapEmpty(Heap* hp){
    assert(hp);
    return hp->_size == 0;
}
