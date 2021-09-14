#include<iostream>
#include<time.h>
#include <algorithm>
using namespace std;

//插入排序
void insertSort(int* arr, int n){
	for (int i = 1; i < n; i++){
		int end = i - 1;
		int data = arr[i];
		while (end>=0 && data<arr[end]){
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end+1] = data;
	}
}
//希尔排序
void shellSort(int* arr, int n){
	int gap = n;
	while (gap > 1){
		gap = gap / 3 + 1;
		//最后
		//
		for (int i = gap; i < n; ++i){
			//同一组
			int end = i - gap;
			//待插入
			int data = arr[i];
			while (end >= 0 && arr[end]>data){
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}
//选择排序
void selectSort(int* arr, int n){
	int start = 0;//记录起始位置
	int end = n - 1;//记录结束位置
	while ( start < end){
		int minIndex = start;//最小值下标
		for (int i = start+1; i <= end; ++i){//找最小值位置
			if (arr[i] < arr[minIndex])
				minIndex = i;
		}
		//把最小值放开始位置
		swap(arr[minIndex], arr[start]);
		++start;
	}
}
//选择排序2
void selectSort2(int* arr, int n){
	int start = 0;
	int end = n - 1;
	while (start < end){
		int minIdx = start;
		int maxIdx = end;
		for (int i = start+1; i <= end; ++i){
			if (arr[i] < arr[minIdx])
				minIdx = i;
			if (arr[i]>arr[maxIdx])
				maxIdx = i;
		}
		swap(arr[start], arr[minIdx]);
		if (maxIdx == start)
			maxIdx = minIdx;
		swap(arr[maxIdx],arr[end]);
		++start;
		--end;
	}
}
//向下调整
void shiftDown(int* arr, int n, int cur){
	int child = cur * 2 + 1;
	while (child < n){
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		if (arr[cur]<arr[child]){
			swap(arr[child], arr[cur]);
			cur = child;
			child = cur * 2 + 1;
		}
		else
			break;
	}
}
//堆排序
void heapSort(int* arr, int n){
	for (int i = (n - 2) / 2; i >= 0; --i){
		shiftDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0){
		swap(arr[end], arr[0]);
		shiftDown(arr, end, 0);
		--end;
	}
}
void printArr(int *arr, int n){
	for (int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void testShellSort(){
	int arr[] = {10,1,3,2,0,7,5,4,6,8,12};
	printArr(arr, 11);
	insertSort(arr, 11);
	printArr(arr, 11);
}
//选择排序测试
void testSelectSort(){
	int arr[] = { 10, 1, 3, 2, 0, 7, 5, 4, 6, 8, 12 };
	printArr(arr, 11);
	selectSort(arr, 11);
	printArr(arr, 11);
}
//堆排序测试
void testHeapSort(){
	int arr[] = { 10, 1, 3, 2, 0, 7, 5, 4, 6, 8, 12 };
	printArr(arr, 11);
	heapSort(arr, 11);
	printArr(arr, 11);
}
void test1(){
	int n;
	cout << "数据量:>";
	cin >> n;
	srand(time(NULL));
	int *arr = new int[sizeof(int)*n];
	int * copy1 = new int[sizeof(int)*n];
	int * copy2 = new int[sizeof(int)*n];
	int * copy3 = new int[sizeof(int)*n];
	for (int i = 0; i < n; ++i){
		arr[i] = rand();
	}
	memcpy(copy1, arr, sizeof(int)*n);
	memcpy(copy2, arr, sizeof(int)*n);
	memcpy(copy3, arr, sizeof(int)*n);
	time_t begin1 = clock();
	//insertSort(copy1, n);
	time_t end1 = clock();
	cout << end1 - begin1 << endl;
	time_t begin2 = clock();
	shellSort(copy2, n);
	time_t end2 = clock();
	cout << end2 - begin2 << endl;

	time_t begin3 = clock();
	std::sort(copy3, copy3 + n);
	time_t end3 = clock();
	cout << end3 - begin3 << endl;

}
int main(){
	testHeapSort();
	return 0;
}
