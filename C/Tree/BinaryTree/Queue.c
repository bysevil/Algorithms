#include"main.h"

//初始化队列
Queue* QueueCreate(QDataType data){
    Queue* Q = malloc(sizeof(Queue));
    assert(Q);

    QNode* NewNode = BuyQNode(data);

    Q->_QBack = NewNode;
    Q->_QFront = NewNode;
    Q->_size = 1;
    
    return Q;
}

// 获取队首元素
QNode* QueueFront(Queue* Q){
    return Q->_QFront;
}

// 出队
QDataType QueuePop(Queue* Q){
    assert(Q);
    assert(Q->_size);
    QNode* Head = QueueFront(Q);
    Q->_QFront = Head->_next;
    if(Q->_QFront == NULL){
        Q->_QBack = NULL; 
    }
    Q->_size--;
    return Head->_data;
}

//创建新节点
QNode* BuyQNode(QDataType data){
    QNode* NewNode = malloc(sizeof(QNode));
    assert(NewNode);

    NewNode->_data = data;
    NewNode->_next = NULL;

    return NewNode;
}

// 入队
QNode* QueuePush(Queue* Q,QDataType data){
    assert(Q);
    QNode* NewNode = BuyQNode(data);
    if(Q->_QBack){
        Q->_QBack->_next = NewNode;
        Q->_QBack = NewNode;
    }
    else{
        Q->_QFront = NewNode;
        Q->_QBack = NewNode;
    }
    Q->_size++;
    return NewNode;
}

bool QueueEmpty(Queue* Q){
    return Q->_size == 0;
}
