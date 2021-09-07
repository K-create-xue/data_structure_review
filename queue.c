#include"queue.h"

//队列初始化
void QueueInit(Queue* q){
	if (q == NULL)
		return;
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
//创建队列节点
QNode* CreteNode(QDataType val){
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
// 队尾入队列
void QueuePush(Queue* q, QDataType val){
	struct QNode* node = CreteNode(val);
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++(q->_size);
}
// 队头出队列
void QueuePop(Queue* q){
	if (q->_front == NULL)
		return;
	struct QNode* node = q->_front;
	if (q->_front == q->_rear)
		q->_front = q->_rear = NULL;
	else
		q->_front = node->_next;
		free(node);
		--(q->_size);
}
// 获取队列头部元素
QDataType QueueFront(Queue* q){
	return q->_front->_data;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* q){
	return q->_rear->_data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q){
	return q->_size;
	/*int num = 0;
	QNode* cur = q->_front;
	while (cur){
		++num;
		cur = cur->_next;
	}
	return num;*/
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q){
	if (q->_front == NULL)
		return 1;
	return 0;
}
// 销毁队列
void QueueDestroy(Queue* q){
	QNode* cur = q->_front; 
	while (cur){
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

void test(){
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	while (!QueueEmpty(&q)){
		printf("%d", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}
int main(){
	test();
	return 0;
}
