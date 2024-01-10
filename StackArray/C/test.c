#include"StackArray.h"

int main() {
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	printf("%d %d \n", StackTop(&s),StackSize(&s));
	StackPush(&s, 2);
	printf("%d %d \n", StackTop(&s), StackSize(&s));
	StackPush(&s, 3);
	printf("%d %d \n", StackTop(&s), StackSize(&s));
	StackPush(&s, 4);
	printf("%d %d \n", StackTop(&s), StackSize(&s));
	StackPush(&s, 5);
	printf("%d %d \n", StackTop(&s), StackSize(&s));

	StackPop(&s);
	printf("%d %d \n", StackTop(&s), StackSize(&s));
	StackPop(&s);
	printf("%d %d \n", StackTop(&s), StackSize(&s));
	StackPop(&s);
	printf("%d %d \n", StackTop(&s), StackSize(&s));
	StackPop(&s);
	printf("%d %d \n", StackTop(&s), StackSize(&s));
	
	StackDestroy(&s);
	printf("%d\n", StackSize(&s));

	return 0;
}