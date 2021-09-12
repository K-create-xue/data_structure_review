#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
typedef char BTDataType; 

typedef struct BTNode{
	BTDataType _data;
	struct BTNode* _left;
	struct BTNode* _right;
}BTNode;
//通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* arr, int* index){
	if (arr[*index] == '#'){
		++(*index);
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = arr[*index];  
	++(*index);
	root->_left = BinaryTreeCreate(arr, index);
	root->_right = BinaryTreeCreate(arr, index);
	return root;
}
//前序遍历
void preOrder(BTNode* root){
	if (root){
		//根   左  右
		printf("%c", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);
	}
}
//中序遍历
void inOrder(BTNode* root){
	if (!root)
		return;
	//左    根    右
	inOrder(root->_left);
	printf("%c", root->_data);
	inOrder(root->_right);
}
//后序遍历
void postOrder(BTNode* root){
	if (!root)
		return;
	//左    右    根
	postOrder(root->_left);
	postOrder(root->_right);
	printf("%c", root->_data);
}
//节点个数
int BTSize(BTNode* root){
	if (!root)
		return 0;
	int left = BTSize(root->_left);
	int right = BTSize(root->_right);
	return left + right + 1;
}
//叶子节点
int BTLeafSize(BTNode* root){
	if (!root)
		return 0;
	if ((root->_left == NULL) && (root->_right == NULL))
		return 1;
	return BTLeafSize(root->_left) + BTLeafSize(root->_right);
}
//第k层节点个数
int BTLayerSize(BTNode* root,int K){
	if (!root)
		return 0;
	if (K == 1)
		return 1;
	return BTLayerSize(root->_left, K - 1)
		+ BTLayerSize(root->_right, K - 1);
}
//查找
BTNode* BTFind(BTNode* root, BTDataType ch){
	BTNode* node;
	if (root == NULL)
		return NULL;
	if (root->_data == ch)
		return root;
	node = BTFind(root->_left, ch);
	if (node)
		return node;
	return BTFind(root->_right, ch);
}
//销毁  不会有野指针
void BTDestroy(BTNode** root){
	if (*root){
		BTDestroy(&((*root)->_left));
		BTDestroy(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}
//销毁 会有野指针
void BTDestroy2(BTNode* root){
	if (root){
		BTDestroy2(root->_left);
		BTDestroy2(root->_right);
		free(root);//root为拷贝指针，赋值为NULL真的指针指向不变，二级指针赋值NULL才可以，
		//不赋值为空，就会出现野指针
	}
}
//层序遍历
void BTLevelOrder(BTNode* root){
	queue<BTNode*> q;
	if (root)
	q.push(root);
	while (!q.empty()){
		BTNode* node = q.front();
		cout << node->_data;
		if (node->_left)
		q.push(node->_left);
		if (node->_right)
		q.push(node->_right);
		q.pop();
	}
}

void test(){
	char arr[] = "ABD##E#H##CF##G##";
	int index = 0;
	BTNode* root = BinaryTreeCreate(arr, &index);
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	BTLevelOrder(root);
	cout << endl;
}
int main(){
	test();
	
	return 0;
}
//34
