#include"QueueList.h"

// 初始化队列 
void QueueInit(Queue* q) {
	q->_front = NULL;
	q->_rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data) {
	QNode* NewNode = malloc(sizeof(QNode));
	if (NewNode == NULL) {
		perror("Funtion QueuePush : malloc failed");
		return;
	}
	NewNode->_data = data;
	NewNode->_next = NULL;
	if (QueueEmpty(q)) {
		q->_front = q->_rear = NewNode;
	}
	else {
		q->_rear->_next = NewNode;
		q->_rear = NewNode;
	}
}
// 队头出队列 
void QueuePop(Queue* q) {
	if (QueueEmpty(q)) {
		printf("Funtion QueuePop : Pop Node Failed : Empty Queue\n");
	}
	else {
		QNode* PopNode = q->_front;
		q->_front = q->_front->_next;
		free(PopNode);
		if (q->_front == NULL)
			q->_rear = NULL;
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	if (QueueEmpty(q)) {
		printf("Funtion QueueFront : Get Node Failed: Empty Queue\n");
		return 0;
	}
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q) {
	if (QueueEmpty(q)) {
		printf("Funtion QueueBack : Get Node Failed : Empty Queue\n");
		return 0;
	}
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q) {
	QNode* cur = q->_front;
	int size = 0;
	while (cur) {
		size++;
		cur = cur->_next;
	}
	return size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	return q->_rear == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q) {
	while (!QueueEmpty(q)) {
		QueuePop(q);
	}
}