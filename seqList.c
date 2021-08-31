#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"seqList.h"

//初始化顺序表
void initSeqList(seqList* sl){
	assert(sl);
	sl->_data = NULL;
	sl->_size = sl->_capacity = 0;
}

//尾插数据
void push_back(seqList* sl,SLDataType val){
	assert(sl);
	//检查容量
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;
}

//检查容量
void checkCapacity(seqList* sl){
	//assert(sl);//检查指针   debug有效，release无效
	if (sl == NULL)
		return;
	if (sl->_size == sl->_capacity){
		int newCapacity = sl->_capacity == 0 ? \
			1:2 * sl->_capacity;
		sl->_data = (SLDataType*)realloc(sl->_data, sizeof(SLDataType)*newCapacity);
		
		/*
		//开空间，拷贝数据，释放原有空间
		SLDataType* tmp = (SLDataType*)\
			malloc(sizeof(SLDataType)*newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType)*sl->_size);
		//释放
		free(sl->_data);
		//更新
		sl->_data = tmp;
		*/
		//更新
		sl->_capacity = newCapacity;
	}
}

//打印顺序表
void printSeqList(seqList* sl){
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->_size; ++i){
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}

//尾删
void pop_back(seqList* sl){
	if (sl == NULL)
		return;
	if (sl->_size>0)
	--(sl->_size);
}

//头插
void push_front(seqList* sl,SLDataType val){
	if (sl == NULL)
		return;
	checkCapacity(sl);//1.
	int end = sl->_size;//2.移动元素
	while (end>0){
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	sl->_data[0] = val;//3.头插
	++sl->_size;//4.更新
}

//头删
void pop_front(seqList* sl){
	if (sl == NULL)
		return;
	//0.判断
	if (sl->_size == 0)
		return;
	//1.移动
	int start = 1;
	while (start < sl->_size){
		sl->_data[start - 1] = sl->_data[start];
		++start;
	}
	//2.更新
	--(sl->_size);
}

void insert(seqList* sl, size_t pos, SLDataType val){
	if (sl == NULL) return;
	//1.检查容量
	if (pos >= 0 && pos <= sl->_size){
		checkCapacity(sl);
		//2.移动数据[pos,sl->_size)
		int end = sl->_size;
		while (end > pos){
			sl->_data[end] = sl->_data[end - 1];
			end--;
		}
		//3.插入数据
		sl->_data[pos] = val;
		//4.更新
		++(sl->_size);
	}
}

//任意位置删除元素
void erase(seqList* sl, int pos){
	if (sl == NULL || sl->_size == 0)
		return;
	//1.检查位置[0,sl->_size)
	if (pos >= 0 && pos < sl->_size){
		//2.移动元素
		int start = pos;
		while (start<(sl->_size-1)){
			sl->_data[start] = sl->_data[start + 1];
			start++;
		}
		//3.更新
		--(sl->_size);
	}
}

//判断是否为空
bool empty(seqList* sl){
	if (sl == NULL || sl->_size == 0)
		return true;
	else
		return false;
}

//有效元素的大小
int size(seqList* sl){
	if (sl == NULL)
		return 0	;
	return sl->_size;
}

//查找值返回位置
int find(seqList* sl, SLDataType val){
	if (sl == NULL)
		return 0;
	int i = 0;
	for (; i < sl->_size; ++i){
		if (sl->_data[i] == val)
			return i;
	}
	return -1;
}

//销毁顺序表
void destroySeqList(seqList* sl){
	if (sl == NULL)
		return;
	if (sl->_data){
		free(sl->_data);
		sl->_data = NULL;
	}
}

//测试
void test(){
	seqList sl;
	initSeqList(&sl);

}
/*
void test(){
	seqList sl;
	initSeqList(&sl);
	push_back(&sl, 1);
	push_back(&sl, 2);
	push_back(&sl, 3);
	push_back(&sl, 4);
	push_back(&sl, 5);
	printSeqList(&sl);//1 2 3 4 5

	erase(&sl, 0); printSeqList(&sl);//2 3 4 5
	erase(&sl, 7); printSeqList(&sl);//2 3 4 5 
	erase(&sl, 3); printSeqList(&sl);//2 3 4 
	erase(&sl, 0); printSeqList(&sl);//3 4
	erase(&sl, 2); printSeqList(&sl);//3 4
	erase(&sl, 1); printSeqList(&sl);//3


}

void test(){
	seqList sl;
	initSeqList(&sl);
	insert(&sl, 0, 1);
	printSeqList(&sl);
	insert(&sl, 1, 2);
	printSeqList(&sl);
	insert(&sl, 0, 0);
	printSeqList(&sl);
	//insert(&sl, 2, 0.5);
	printSeqList(&sl);
	insert(&sl, 3, 9);
	//insert(&sl, 7, 9);
	printSeqList(&sl);

}

void test(){
	seqList sl;
	initSeqList(&sl);
	push_back(&sl, 1);
	push_back(&sl, 2);
	push_back(&sl, 3);
	push_back(&sl, 4);
	push_back(&sl, 5);

	printSeqList(&sl);

	pop_front(&sl);
	pop_front(&sl);
	pop_front(&sl);
	pop_front(&sl);
	printSeqList(&sl);
	pop_front(&sl);
	pop_front(&sl);
	printSeqList(&sl);

}

void test(){
	seqList sl;
	initSeqList(&sl);
	push_front(&sl, 9);
	printSeqList(&sl);
	push_front(&sl, 8);
	printSeqList(&sl);
	push_front(&sl, 7);
	printSeqList(&sl);
	push_front(&sl, 6);
	printSeqList(&sl);
	push_front(&sl, 5);
	printSeqList(&sl);

}

void test(){
	seqList sl;
	initSeqList(&sl);
	push_back(&sl, 1);
	push_back(&sl, 2);
	push_back(&sl, 1);
	push_back(&sl, 3);
	push_back(&sl, 4);
	printSeqList(&sl);
	pop_back(&sl);
	printSeqList(&sl);
	
}
*/
int main(){
	test();
	system("pause");
	return 0;
}
