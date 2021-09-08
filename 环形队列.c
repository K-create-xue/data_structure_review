//环形空间k个大小
//申请k+1个防止rear越出
//用(rear+1)%(k+1)是否等于front判断是否，慢了，，
//循环的时候碰到数组下标大于k时，需要移动到0下标
typedef struct {
    int* _data;
    int _front;
    int _rear;
    int _k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->_rear==obj->_front)
    return true;
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if((obj->_rear+1)%(obj->_k+1)==obj->_front)
    return true;
    return false;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* mq=(MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    mq->_data=(int*)malloc(sizeof(int)*(k+1));
    mq->_front=mq->_rear=0;
    mq->_k=k;
    return mq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)) return false;
    obj->_data[obj->_rear++]=value;
    if(obj->_rear>obj->_k)
    obj->_rear=0;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    return false;
    obj->_front++;
    if(obj->_front>obj->_k)
    obj->_front=0;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    return -1;
    return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    return -1;
    if(obj->_rear!=0)
    return obj->_data[obj->_rear-1];
    return obj->_data[obj->_k];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
