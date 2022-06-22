#pragma once
#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef int ElemType;

struct Poly {
	float coef;
	int exp;
};

template <class T>
struct Node {
	T data;
	Node* next;
};

template <class T>
class Linklist {
public:
	Linklist();//构造函数，构建一个新链表
	~Linklist();//析构函数，删除表空间
	void IninList(int n);//初始化链表，创建含有n个元素的链表
	//void DestroyList();//销毁链表
	int ListLength();//求链表长度
	int GetElem(int i, T& e);//获得链表第i个元素值
	void LocatcElem(T e);//输出链表中与e满足compare关系的元素位置
	int compare(T a, T b);//若a==b，返回1，否则返回0
	T PriorElem(T cur_e, T& pre_e);//求链表中元素cur_e的前驱
	void ListTraverse();//遍历链表
	void ListInsert(int i, T e);//在第i个位置插入e
	int ListDelete(int i, T& e);//删除第i个元素，用e返回
	int Empty();//判表空，表空返回1，表非空返回0；
private:
	Node<T>* Head;
};
#endif//_LINKLIST_H