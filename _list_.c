#include<stdlib.h>
//双向带头循环链表
typedef int LDataType;//数据类型

typedef struct listNode{
	LDataType _data;
	struct listNode* _prev;//指向上一个节点
	struct listNode* _next;//指向下一个节点
}listNode;//结构体定义 

//双向带头循环链表
typedef struct List{
	listNode* _head;
}List;
//创建空节点
listNode* createListNode(LDataType val){
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}
//初始化节点
void listInit(List* lst){
	if (lst == NULL)
		return;
	//空链表
	lst->_head = createListNode(0);
	lst->_head->_next = lst->_head->_prev = lst->_head;
}
//尾插O(1)
void push_back(List* lst, LDataType val){
	if (lst == NULL)
		return;
	struct listNode* newNode = createListNode(val);
	newNode->_next = lst->_head;
	newNode->_prev = lst->_head->_prev;

	lst->_head->_prev->_next= newNode;
	lst->_head->_prev = newNode;
}
//尾删O(1)
void pop_back(List* lst){
	if (lst == NULL)
		return;
	if (lst->_head == lst->_head->_next)
		return;
	struct listNode* node = lst->_head->_prev;
	node->_prev->_next = lst->_head;
	lst->_head->_prev = node->_prev;
	free(node);
}
//打印链表
void printList(List* lst){
	if (lst == NULL)
		return;
	struct listNode* cur = lst->_head->_next;
	while (cur!=lst->_head){
		printf("%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// 双向链表头插O(1)
void push_front(List* lst, LDataType val){
	if (lst == NULL)
		return;
	struct listNode* node = createListNode(val);
	node->_next = lst->_head->_next;
	node->_prev = lst->_head;
	lst->_head->_next->_prev = node;
	lst->_head->_next = node;
}
// 双向链表头删
void pop_front(List* lst){
	if (lst == NULL)
		return;
	if (lst->_head == lst->_head->_next)
		return;
	struct listNode* node = lst->_head->_next;
	node->_next->_prev= lst->_head;
	lst->_head->_next = node->_next;
	free(node);
}
// 双向链表删除pos位置的节点
void ListErase(List* lst,listNode* pos){
	if (!lst || lst->_head == NULL)
		return;
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
// 双向链表在pos的前面进行插入
void insert(List* lst,listNode* pos, LDataType val){
	if (lst == NULL)
		return;
	struct listNode* node = createListNode(val);
	node->_next = pos;
	node->_prev = pos->_prev;
	
	pos->_prev->_next = node;
	pos->_prev = node;
}

// 双向链表查找
listNode* find(List* lst, LDataType val){
	if (lst == NULL || lst->_head == NULL)
		return NULL;
	if (lst->_head->_next == lst->_head)
		return NULL;
	listNode* node = lst->_head->_next;
	while (node != lst->_head){
		if (node->_data == val)
			return node;
		node = node->_next;
	}
	return NULL;
}
//销毁链表
void listDestroy(List* lst){
	if (lst == NULL)
		return;
	struct listNode* node = lst->_head->_next;
	while (node != lst->_head){
		struct listNode* next = node->_next;
		free(node);
		node = next;
	}
	free(lst->_head);
}
//测试
void test(){
	List lst;
	listInit(&lst);
	push_back(&lst, 1);
	printList(&lst);
	push_back(&lst, 2);
	printList(&lst);
	push_back(&lst, 3);
	printList(&lst);
	push_back(&lst, 4);
	printList(&lst);
	push_back(&lst, 5);
	printList(&lst);

	pop_back(&lst);
	printList(&lst);
	pop_back(&lst);
	printList(&lst);
	pop_back(&lst);
	printList(&lst);
	pop_back(&lst);
	printList(&lst);

	push_front(&lst, 4);
	printList(&lst);
	push_front(&lst, 3);
	printList(&lst);
	push_front(&lst, 2);
	printList(&lst);
	push_front(&lst, 1);
	printList(&lst);

	pop_front(&lst);
	printList(&lst);
	pop_front(&lst);
	printList(&lst);
	pop_front(&lst);
	printList(&lst);
	pop_front(&lst);
	printList(&lst);

	
}
//主进程
int main(){
	test();
	return 0;
}
