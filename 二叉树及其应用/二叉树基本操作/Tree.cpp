#include<iostream>
#include "Tree.h"
using namespace std;

void InitBiTree(BiList Tree) {
	//��ʼ��������
	Tree = NULL;
}

void DestroyBiTree(BiList Tree) {
	//���ٶ�����
	if (Tree == NULL) return;
	DestroyBiTree(Tree->LChild);
	DestroyBiTree(Tree->RChild);
	delete Tree;
}

void CreateBiTree(BiList &Tree) {
	//������չ����������д�����������
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
	//����������
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
{//�ǵݹ��������������
	BiList S[m], l = Tree;
	int top = 0;//ջ��ָ��
	do {
		while (l != NULL) {
			S[++top] = l;
			l = l->LChild;
		}//����������
		if (top != 0) {
			l = S[top];
			top--;
			if (l->data == p) return l;
			l = l->RChild;//����������
		}
	} while (l != NULL || top != 0);
	return NULL;
}
void InsertChild(BiList& Tree, DataType p, int LR, DataType c) {
	//����LR�Ĳ�ͬȡֵ����c����p�Ķ��ӽ��
	BiList pl = NULL, cl = NULL;
	if (Tree != NULL) {
		pl = PostOrder(Tree, p);
	}
	if (pl == NULL) cout << "���" << p << "������!" << endl;
	else if (pl->LChild != NULL && pl->RChild != NULL) cout << p << "����������Һ��ӽ��." << endl;
	else {
		if (LR % 2 == 0) {//LRΪż��ʱ���������ӽ��
			if (pl->LChild != NULL) cout << p << "����Ѵ������ӽ��." << endl;
			else {
				cl = new BiTree;
				cl->data = c;
				cl->LChild = NULL;
				cl->RChild = NULL;
				pl->LChild = cl;
			}
		}
		else {//LRΪ����ʱ�����Һ��ӽ��
			if (pl->RChild != NULL) cout << p << "����Ѵ����Һ��ӽ��." << endl;
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
{//�ǵݹ��������������
	BiList S[m], p=Tree;
	int top = 0;//ջ��ָ��
	do {
		while (p != NULL) {
			if (top > m) return;//ջ�����
			S[++top] = p;
			p = p->LChild;
		}//����������
		if (top != 0) {
			p = S[top];
			top--;
			cout << p->data << ' ';
			p = p->RChild;//����������
		}
	} while (p != NULL || top != 0);
}

void DisplayLeaf(BiList Tree)
{//���Ҷ���
	if (Tree != NULL) {
		if (Tree->LChild == NULL && Tree->RChild == NULL) cout << Tree->data << ' ';
		DisplayLeaf(Tree->LChild);
		DisplayLeaf(Tree->RChild);
	}
}

void DisplayDegree1(BiList Tree)
{//�����Ϊ1�Ľ��
	if (Tree != NULL) {
		if ((Tree->LChild != NULL && Tree->RChild == NULL) || (Tree->LChild == NULL && Tree->RChild != NULL))
			cout << Tree->data << ' ';
		DisplayDegree1(Tree->LChild);
		DisplayDegree1(Tree->RChild);
	}
}

void DisplayDegree2(BiList Tree)
{//�����Ϊ2�Ľ��
	if (Tree != NULL) {
		if (Tree->LChild != NULL && Tree->RChild != NULL) cout << Tree->data << ' ';
		DisplayDegree2(Tree->LChild);
		DisplayDegree2(Tree->RChild);
	}
}

void SwopChild(BiList Tree)
{//�������н������Һ��ӽ��
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
{//����״��ӡ������
	if (Tree == NULL) return;
	PrintTree(Tree->RChild, Layer + 1);
	for (int i = 0; i < Layer; i++) cout << ' ';
	cout << Tree->data << endl;
	PrintTree(Tree->LChild, Layer + 1);
}


