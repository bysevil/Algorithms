#include"StackArray.h"
// 初始化栈 
void StackInit(Stack* ps) {
	ps->_a = malloc(sizeof(STDataType) * 4);
	if (ps->_a == NULL) {
		perror("Init malloc fail");
		exit(EXIT_FAILURE);
	}
	ps->_capacity = 4;
	ps->_top = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	assert(ps->_a);
	if (ps->_top == ps->_capacity) {
		ps->_capacity *= 2;
		STDataType* tmp = realloc(ps->_a, sizeof(STDataType) * ps->_capacity);
		if (tmp == NULL) {
			perror("Push realloc fail");
			exit(EXIT_FAILURE);
		}
		ps->_a = tmp;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// 出栈 
void StackPop(Stack* ps) {
	assert(ps);
	assert(ps->_a);
	assert(!StackEmpty(ps));
	ps->_top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(ps->_a);
	assert(ps->_top);
	return ps->_a[ps->_top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps) {
	assert(ps);
	assert(ps->_a);
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps) {
	assert(ps);
	assert(ps->_a);
	if (ps->_top == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
// 销毁栈 
void StackDestroy(Stack* ps) {
	assert(ps);
	assert(ps->_a);
	free(ps->_a);
	ps->_top = 0;
	ps->_capacity = 0;
}