typedef int SLDataType;

typedef struct seqList{
	SLDataType* _data;//需要动态开辟的数组
	size_t _size;//有效元素个数
	size_t _capacity;//元素容量大小
}seqList;

void initSeqList(seqList* sl);//初始化顺序表
void push_back(seqList* sl, SLDataType val);//尾插
void checkCapacity(seqList* sl);//检查容量
void printSeqList(seqList* sl);//打印顺序表
void pop_back(seqList* sl);//尾删
void push_front(seqList* sl);//头插
void pop_front(seqList* sl);//头删
void insert(seqList* sl, size_t pos, SLDataType val);//任意位置插入
void erase(seqList* sl, int pos);//任意位置删除元素
bool empty(seqList* sl);//判断是否为空
int size(seqList* sl);//有效元素的大小
int find(seqList* sl, SLDataType val);//查找值返回位置
void destroySeqList(seqList* sl);//销毁顺序表
