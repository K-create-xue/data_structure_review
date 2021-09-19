#include<iostream>
#include<time.h>
#include <algorithm>
#include<stack>
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
//冒泡排序
void bubbleSort(int* arr, int n){
	//相邻元素比较
	int end = n; //[0,end]
	while (end > 1){
		int flag = 0;//标记排序中是否发生交换
		for (int i = 1; i < end; ++i){
			if (arr[i] < arr[i - 1]){
				swap(arr[i], arr[i - 1]);
				flag = 1;
			}
		}
		if (flag == 0)//无交换，
			break;
		--end;
	}
}
//快速排序基准点  数据有序且过多时，会导致递归溢出
//用三数取中可以避免
int position(int* arr, int begin,int end){
	//选基准点
	int key = arr[begin];
	int start = begin;//记录起点位置
	while (begin < end){
		//从后往前，找小于
		while (begin < end && arr[end] >= key)
			--end;
		//从前往后，找大于基准值
		while (begin < end && arr[begin] <= key)
			++begin;
		swap(arr[begin], arr[end]);
	}
	swap(arr[start], arr[begin]);
	return begin;
}
//快排
void quickSort(int* arr, int begin, int end){
	if (begin >= end)
		return;
	int divide = position(arr, begin, end);
	//左，[begin,divide)
	quickSort(arr, begin, divide - 1);
	//右，[divede+1,end]
	quickSort(arr, divide + 1, end);
}
//找基准值   挖坑法
int partion2(int* arr, int begin, int end){
	int key = arr[begin];
	while (begin < end){
		while (begin<end && arr[end] < key)
			--end;
		arr[begin] = arr[end];
		while (begin<end && arr[begin]>key)
			++begin;
		arr[end]=arr[begin];
	}
	arr[begin] = key;
	return begin;
}
//找基准值  前后指针版本
int partion3(int* arr, int begin, int end){
	//上一个小于基准值位置
	int prev = begin;
	//下一个小于基准值位置
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end){
		//当cur走到下一个小于基准值位置
		if (arr[cur] < key && ++prev != cur){
			swap(arr[cur], arr[prev]);
		}
		++cur;
	}
	swap(arr[begin], arr[prev]);
	return prev;
}
//非递归快排，不会有栈溢出风险
void quickSortNoR(int* arr,int n){
	stack<int> st;
	int begin = 0, end = n - 1;
	st.push(begin);
	st.push(end);
	while (!st.empty()){
		int end2 = st.top();
		st.pop();
		int begin2 = st.top();
		st.pop();
		int div = partion3(arr, begin, end);
		//[begin,div-1]
		if (div - 1 > begin2){
			st.push(begin2);
			st.push(div-1);
		}
		//[div+1,end]
		if (end > div + 1){
			st.push(div + 1);
			st.push(end2);
		}
	}
}
//归并排序
void merge(int* arr, int begin, int mid, int end, int* tmp){
	//递增
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = begin;
	while (begin1 < end1 && begin2 < end2){
		if (arr[begin1] < arr[begin2]){
			tmp[index++] = arr[begin1];
			begin1++;
		}
		else{
			tmp[index++] = arr[begin2];
			begin2++;
		}
	}
	if (begin1 >= end1)
		memcpy(tmp + index, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 < end2)
		memcpy(tmp + index, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	//合并之后的零时空间拷贝过去
	memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
//
void _mergeSort(int* arr,int begin,int end,int* tmp){
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1,end, tmp);
	merge(arr, begin, mid,end,tmp);
}
//
void mergeSort(int* arr, int n){
	//申请辅助空间
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}
//归并排序不递归
void mergeSortNoR(int* arr, int n){
	int* tmp = (int*)malloc(sizeof(int)*n);
	//子序列长度
	int step = 1;
	while (step < n){
		for (int idx = 0; idx < n; idx += 2 * step){
			//找两个待合并子序列区间
			//[begin,mid]  [min+1,end]
			int begin = idx;
			int mid = idx + step - 1;
			if (mid >= n - 1)
				//不存在第二个子序列
				continue;
			int end = idx + 2 * step - 1;
			//判断第二个子序列是否越界
			if (end>n)
				end = n - 1;
			merge(arr, begin, mid, end, tmp);
		}
		step *= 2;
	}
}

//计数排序
void countSort(int* arr, int n){
	int max=arr[0], min=arr[0];
	for (int i = 1; i < n; ++i){
		if (arr[i]>max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	//申请范围
	int range = max - min + 1;
	int* countArr = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < n; ++i){
		countArr[arr[i] - min]++;
	}
	//遍历数组。排序
	int idx = 0;
	for (int i = 0; i < range; ++i){
		idx = countArr[i];
		while (idx--){
			arr[idx++] = i+min;
		}
	}
}
//打印
void printArr(int *arr, int n){
	for (int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}
//快排测试
void testQuickSort(){
	int arr[] = { 10, 1, 3, 2, 0, 7, 5, 4, 6, 8, 12 };
	printArr(arr, 11);
	quickSort(arr, 0,10);
	printArr(arr, 11);
}
//冒泡排序测试
void testBubbleSort(){
	int arr[] = { 10, 1, 3, 2, 0, 7, 5, 4, 6, 8, 12 };
	printArr(arr, 11);
	bubbleSort(arr, 11);
	printArr(arr, 11);
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
	testBubbleSort();
	return 0;
}
