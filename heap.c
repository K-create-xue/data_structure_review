#include<stdlib.h>
#include<stdbool.h>
//假设小堆
typedef int HDataType;
void shiftDown(int* arr, int n, int cur);
void shiftUp(int* arr, int n, int cur);
typedef struct heap{
	HDataType* _data;
	int _size;
	int _capacity;
}heap;

//初始化
void heapInit(heap* hp){
	if (hp == NULL)
		return;
	//空堆
	hp->_data = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
}
//检查空间
void checkCapacity(heap* hp){
	if (hp->_size == hp->_capacity){
		int newC = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
		hp->_data = (HDataType*)realloc(hp->_data, sizeof(HDataType)*newC);
		hp->_capacity = newC;
	}
}
//小堆顶点
HDataType heapTop(heap* hp)
{
	return hp->_data[0];
}
//尾插
void heapPush(heap* hp, HDataType val){
	//检查空间
	checkCapacity(hp);
	//尾插
	hp->_data[hp->_size++] = val;
	//向上调整
	shiftUp(hp->_data, hp->_size, hp->_size - 1);
}
//删除
void heapPop(heap* hp){
	if (hp->_data == NULL)
		return;
	//交换
	int tmp = hp->_data[0];
	hp->_data[0]=hp->_data[hp->_size - 1];
	hp->_data[hp->_size - 1] = tmp;
	//尾删
	--hp->_size;
	//向下调整
	shiftDown(hp->_data, hp->_size,0);
}
//判断为空
bool heapEmpty(heap* hp){
	if (hp == NULL || hp->_data == NULL)
		return true;
	return false;
}
//向下调整
void shiftDown(int* arr, int n, int cur){
	//找到孩子的位置
	//左孩子
	int child = 2 * cur + 1;
	while (child < n){
		//从左孩子中找一个最小的
		if (child + 1 < n && arr[child] > arr[child + 1])
			++child;
		//和当前数据比较
		//1.调整
		if (arr[child] < arr[cur]){
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;

			//更新
			cur = child;
			child = cur * 2 + 1;
		}
else//不调整，孩子》=当前
		break;
	}
 }
//向上更新(小堆)
void shiftUp(int* arr, int n, int cur){
	//父节点下标
	int parent = (cur - 1) / 2;
	while (cur > 0){
		//交换
		if (arr[cur]<arr[parent]){
			int tmp = arr[cur];
			arr[cur] = arr[parent];
			arr[parent] = tmp;

		//更新
			cur = parent;
			parent = (cur - 1) / 2;
		}
		//不交换
		else{
			break;
		}
	}
}

void test(){
	int arr[] = { 1, 5, 10, 7, 8, 6,3,9,4,2 };
	int n=sizeof(arr) / sizeof(arr[0]);
	heap hp;
	heapInit(&hp);
	for (int i = 0; i < n; ++i){
		heapPush(&hp, arr[i]);
	}
	for (int i = 0; i < n - 1; ++i){
		heapPop(&hp);
	}
}
//void test(){
//	int arr[] = {10,5,8,3,2,1};
//	int n=sizeof(arr) / sizeof(arr[0]);
//构建一个小堆
//	for (int i = ((n - 2) / 2); i >= 0; --i)
//		shiftDown(arr,n, i);
//	}
	

int main(){
	test();
	return 0;
}
