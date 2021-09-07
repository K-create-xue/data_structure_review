#pragma once
#include<stdlib.h>
typedef int QDataType;
//节点
typedef struct QNode{
	struct QNode* _next;
	QDataType _data;
}QNode;
//队列
typedef struct Queue{
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;

//初始化
void QueueInit(Queue* q);
//创建队列节点
QNode* CreteNode(QDataType val);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
