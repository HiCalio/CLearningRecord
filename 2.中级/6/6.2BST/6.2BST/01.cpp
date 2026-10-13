#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct BSTNode {
	ElemType data;
	struct BSTNode* rchild;
	struct BSTNode* lchild;
}*BSTree,BSTNode;

bool BST_insert(BSTree &T, ElemType x) {
	BSTNode* New = (BSTree)calloc(1, sizeof(BSTNode));
	New->data = x;
	if (T == NULL) {
		T = New;
	}
	else {
		BSTNode* p=T,*parent=p;
		while (p) {
			parent = p;
			if (p->data > x) {
				p = p->lchild;
			}
			else if(p->data<x){
				p = p->rchild;
			}
			else {
				return false;
			}
		}
		if (parent->data > x) {
			parent->lchild = New;
		}
		else {
			parent->rchild = New;
		}
	}
	return true;
}
//二叉排序树插入节点

void Delete_BST(BSTree& root, ElemType x) {
	if (root == NULL) return;
	if (root->data > x) {
		Delete_BST(root->lchild, x);
	}
	else if(root->data<x){
		Delete_BST(root->rchild, x);
	}
	else {
		BSTNode* temp = root;
		if (root->lchild == NULL) {
			root = root->rchild;
			free(temp);
		}
		else if (root->rchild == NULL) {
			root = root->lchild;
			free(temp);
		}
		else {//两个子树都不为空，找到待删除节点的中序前驱（即左子树最右节点）来代替该节点位置
			temp = root->lchild;
			while (temp->rchild != NULL) {
				temp = temp->rchild;
			}
			root->data = temp->data;
			Delete_BST(root->lchild, temp->data);//在root的左子树中删除，不能直接传temp，否则无法找到temp指向的父节点
		}
	}
}

void InOrder(BSTree T) {
	if (T) {
		InOrder(T->lchild);
		printf("%-3d", T->data);
		InOrder(T->rchild);
	}
}

void Creat_BST(BSTree &T, ElemType* str, int k) {
	int i;
	for (i = 0;i < k;i++) {
		BST_insert(T, str[i]);
	}
}

int main() {
	BSTree T = NULL;
	ElemType str[7] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str, 7);
	InOrder(T);
	printf("\n");
	Delete_BST(T, 20);
	InOrder(T);
	return 0;
}