#include"QueueList.h"

int main() {
	Queue* q = malloc(sizeof(Queue));
	QueueInit(q);
	printf("%d %d %d\n", QueueSize(q), QueueFront(q), QueueBack(q));

	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	printf("%d %d %d\n",QueueSize(q), QueueFront(q), QueueBack(q));


	QueuePop(q);
	printf("%d %d %d\n", QueueSize(q), QueueFront(q), QueueBack(q));
	QueuePop(q);
	printf("%d %d %d\n", QueueSize(q), QueueFront(q), QueueBack(q));
	
	QueueDestroy(q);
	printf("%d %d %d\n", QueueSize(q), QueueFront(q), QueueBack(q));

	free(q);
	return 0;
}