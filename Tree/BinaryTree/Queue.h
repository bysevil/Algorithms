typedef struct BinaryTreeNode* QDataType;

typedef struct QNode{
    QDataType _data;
    struct QNode* _next;
}QNode;

typedef struct Queue{
    QNode* _QFront;
    QNode* _QBack;
    size_t _size;
}Queue;

// 初始化队列
Queue* QueueCreate();
// 出队
QDataType QueuePop(Queue* Q);

// 获取队首元素
QNode* QueueFront(Queue* Q);

//创建新节点
QNode* BuyQNode(QDataType data);

// 入队
QNode* QueuePush(Queue* Q,QDataType data);

//判空
bool QueueEmpty(Queue* Q);
