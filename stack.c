#include<stdio.h>
#include<stdio.h>
typedef int STDataType;
//顺序表结构实现
typedef struct stack
{
	STDataType* _data;
	int _size;
	int _capacity;
}stack;
void stackInit(stack* st)
{
	if (!st)return;
	st->_data = NULL;
	st->_size = 0;
	st->_capacity = 0;
}
void checkCapacity(stack* st)
{
	if (st->_size == st->_capacity)
	{
		int newCapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
			st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)*newCapacity);
			st->_capacity = newCapacity;

	}
}
void stackPush(stack* st, STDataType val)
{
	if (st == NULL)return;
	checkCapacity(st);
	//尾插
	st->_data[st->_size++] = val;
}
//出栈
void stackPop(stack* st)
{
	if (!st)return;
	//尾删
	if (st->_size>0)
	st->_size--;

}
STDataType stackTop(stack* st)
{
	return st->_data[st->_size - 1];
}
void test()
{
	stack s;
	stackInit(&s);
	stackPush(&s, 1);
	stackPush(&s, 2);
	stackPush(&s, 3);
	stackPush(&s, 4);
	for(int o = 0; o < 4; ++o)
	{
		printf("%d	", stackTop(&s));
		stackPop(&s);
	}
	printf("\n");
}
int main()
{
	test();
	return 0;
}
