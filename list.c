#include<stdio.h>

typedef int LDataType;
//单链表节点
typedef struct listNode{
	LDataType _data;
	struct listNode* _next;
}listNode;
//头指针
typedef struct list{
	listNode* _head;
}list;
//初始化链表
void listInit(list* lst){
	if (lst == NULL)
		return;
	lst->_head = NULL;
}
//创建节点
listNode* createNode(LDataType val){
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_next = NULL;
	node->_data = val;
	return node;
}
//尾插
void push_back(list* lst,LDataType val){
	if (lst == NULL)
		return;
	if (lst->_head == NULL){
		lst->_head = createNode(val);
	}
	else{
		listNode* tail = lst->_head;
		while (tail->_next){
			tail = tail->_next;
		}
		tail->_next = createNode(val);
	}
}
//尾删
void pop_back(list* lst){
	if (lst == NULL || lst->_head==NULL)
		return;
	struct listNode* tail = lst->_head;
	struct listNode* prev = NULL;
	while (tail->_next){
		prev = tail;
		tail = tail->_next;
	}
	free(tail);
	if (prev == NULL)
		lst->_head = NULL;
	else
	prev->_next = NULL;
}
//头插
void push_front(list* lst, LDataType val){
	if (lst == NULL)
		return;
	struct listNode* node = createNode(val);
	node->_next = lst->_head;
	lst->_head = node;	
	
}
//头删
void pop_front(list* lst){
	if(lst == NULL || lst->_head==NULL)
		return;
	struct listNode* node = lst->_head->_next;
	free(lst->_head);
	lst->_head = node;
}
//某个位置后面插入
void insert(listNode* cur, LDataType val){
	if (cur == NULL)
		return;
	listNode* node = createNode(val);
	node->_next = cur->_next;
	cur->_next = node;
}
//删除某个节点下一个节点
void erase(listNode* cur){
	if (cur == NULL)
		return;
	listNode* node = cur->_next;
	if (cur->_next){
		cur->_next = cur->_next->_next;
		free(node);
	}
}
//查找
listNode* find(list* lst,LDataType val){
	if (lst == NULL || lst->_head == NULL)
		ruturn NULL;
	listNode* cur = lst->_head;
	while (cur){
		if (cur->_data == val)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
//链表数据个数
int listSize(list* lst){

}
//销毁链表
void listDestroy(list* lst){
	if (lst == NULL || lst->_head==NULL)
		return;
	listNode* cur = lst->_head;
	while (cur){
		listNode* node = cur->_next;
		free(cur);
		cur = node;
	}
	lst->_head = NULL;
}

void test(){
	list lst;
	listInit(&lst);
	push_back(&lst, 1);
	push_back(&lst, 2);
	push_back(&lst, 3);
	push_back(&lst, 4);

	pop_back(&lst);
	pop_back(&lst);
	pop_back(&lst);
	pop_back(&lst);
	pop_back(&lst);
	pop_back(&lst);

	push_front(&lst, 6);
	push_front(&lst, 2);
	push_front(&lst, 1);

	pop_front(&lst);
	pop_front(&lst);
	pop_front(&lst);
	pop_front(&lst);


}

int main(){
	test();
	return 0;
}
