#pragma once
#ifndef TREE_H
#define TREE_H
#include<string>
typedef std::string DataType;
#define m 100

//创建一个二叉树链表结点
struct BiTree {
	DataType data;
	BiTree* LChild = NULL;
	BiTree* RChild = NULL;
};
typedef BiTree* BiList;

void InitBiTree(BiList Tree);//初始化一棵二叉树
void DestroyBiTree(BiList Tree);//销毁二叉树
void CreateBiTree(BiList& Tree);//创建一棵二叉树
int BiTreeLength(BiList Tree);//求二叉树深度
BiList PostOrder(BiList& Tree, DataType p);//中序遍历二叉树,在二叉树中寻找结点元素为p的结点
void InsertChild(BiList& Tree, DataType p, int LR, DataType c);//根据LR的奇偶，将c插作p的右孩子或者左孩子
void DisplayBiTree(BiList Tree);//输出所有结点,非递归中序遍历
void DisplayLeaf(BiList Tree);//输出叶结点
void DisplayDegree1(BiList Tree);//输出度为1的结点
void DisplayDegree2(BiList Tree);//输出度为2的结点
void SwopChild(BiList Tree);//交换所有结点的左右孩子结点
void PrintTree(BiList Tree, int Layer);//按树状打印二叉树


#endif //TREE_H