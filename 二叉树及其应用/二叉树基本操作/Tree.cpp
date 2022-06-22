#include<iostream>
#include "Tree.h"
using namespace std;

void InitBiTree(BiList Tree) {
	//初始化二叉树
	Tree = NULL;
}

void DestroyBiTree(BiList Tree) {
	//销毁二叉树
	if (Tree == NULL) return;
	DestroyBiTree(Tree->LChild);
	DestroyBiTree(Tree->RChild);
	delete Tree;
}

void CreateBiTree(BiList &Tree) {
	//根据扩展先序遍历序列创建二叉链表
	DataType ch;
	
	cin >> ch;
	if (ch == ".") Tree = NULL;
	else {
		Tree = new BiTree;
		Tree->data = ch;
		CreateBiTree(Tree->LChild);
		CreateBiTree(Tree->RChild);
	}
}

int BiTreeLength(BiList Tree) {
	//求二叉树深度
	int hl, hr, max;
	if (Tree != NULL) {
		hl = BiTreeLength(Tree->LChild);
		hr = BiTreeLength(Tree->RChild);
		max = hl > hr ? hl : hr;
		return max + 1;
	}
	else return 0;
}

/*BiList PostOrder(BiList& Tree, DataType p)
{
	BiList pl = NULL;
	if (Tree != NULL) {
		if (Tree->data == p) return pl;
		{
		PostOrder(Tree->LChild, p);
		PostOrder(Tree->RChild, p);
		}
	}
}*/
BiList PostOrder(BiList& Tree,DataType p)
{//非递归中序遍历二叉树
	BiList S[m], l = Tree;
	int top = 0;//栈顶指针
	do {
		while (l != NULL) {
			S[++top] = l;
			l = l->LChild;
		}//遍历左子树
		if (top != 0) {
			l = S[top];
			top--;
			if (l->data == p) return l;
			l = l->RChild;//遍历右子树
		}
	} while (l != NULL || top != 0);
	return NULL;
}
void InsertChild(BiList& Tree, DataType p, int LR, DataType c) {
	//根据LR的不同取值，将c插做p的儿子结点
	BiList pl = NULL, cl = NULL;
	if (Tree != NULL) {
		pl = PostOrder(Tree, p);
	}
	if (pl == NULL) cout << "结点" << p << "不存在!" << endl;
	else if (pl->LChild != NULL && pl->RChild != NULL) cout << p << "结点已有左右孩子结点." << endl;
	else {
		if (LR % 2 == 0) {//LR为偶数时，插做左孩子结点
			if (pl->LChild != NULL) cout << p << "结点已存在左孩子结点." << endl;
			else {
				cl = new BiTree;
				cl->data = c;
				cl->LChild = NULL;
				cl->RChild = NULL;
				pl->LChild = cl;
			}
		}
		else {//LR为奇数时插做右孩子结点
			if (pl->RChild != NULL) cout << p << "结点已存在右孩子结点." << endl;
			else {
				cl = new BiTree;
				cl->data = c;
				cl->LChild = NULL;
				cl->RChild = NULL;
				pl->RChild = cl;
			}
		}
	}
}

void DisplayBiTree(BiList Tree)
{//非递归中序遍历二叉树
	BiList S[m], p=Tree;
	int top = 0;//栈顶指针
	do {
		while (p != NULL) {
			if (top > m) return;//栈满溢出
			S[++top] = p;
			p = p->LChild;
		}//遍历左子树
		if (top != 0) {
			p = S[top];
			top--;
			cout << p->data << ' ';
			p = p->RChild;//遍历右子树
		}
	} while (p != NULL || top != 0);
}

void DisplayLeaf(BiList Tree)
{//输出叶结点
	if (Tree != NULL) {
		if (Tree->LChild == NULL && Tree->RChild == NULL) cout << Tree->data << ' ';
		DisplayLeaf(Tree->LChild);
		DisplayLeaf(Tree->RChild);
	}
}

void DisplayDegree1(BiList Tree)
{//输出度为1的结点
	if (Tree != NULL) {
		if ((Tree->LChild != NULL && Tree->RChild == NULL) || (Tree->LChild == NULL && Tree->RChild != NULL))
			cout << Tree->data << ' ';
		DisplayDegree1(Tree->LChild);
		DisplayDegree1(Tree->RChild);
	}
}

void DisplayDegree2(BiList Tree)
{//输出度为2的结点
	if (Tree != NULL) {
		if (Tree->LChild != NULL && Tree->RChild != NULL) cout << Tree->data << ' ';
		DisplayDegree2(Tree->LChild);
		DisplayDegree2(Tree->RChild);
	}
}

void SwopChild(BiList Tree)
{//交换所有结点的左右孩子结点
	BiList temp = NULL;
	if (Tree != NULL) {
		if (Tree->LChild == NULL && Tree->RChild == NULL) return;
		else {
			temp = Tree->LChild;
			Tree->LChild = Tree->RChild;
			Tree->RChild = temp;
		}
		SwopChild(Tree->LChild);
		SwopChild(Tree->RChild);
	}
}

void PrintTree(BiList Tree, int Layer)
{//按树状打印二叉树
	if (Tree == NULL) return;
	PrintTree(Tree->RChild, Layer + 1);
	for (int i = 0; i < Layer; i++) cout << ' ';
	cout << Tree->data << endl;
	PrintTree(Tree->LChild, Layer + 1);
}


