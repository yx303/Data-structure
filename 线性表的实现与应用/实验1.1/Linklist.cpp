#include<iostream>
#include "Linklist.h"
using namespace std;

template <class T>
Linklist<T>::Linklist() {
	//构造函数，构建一个新表
	Head = new Node<T>;
	Head->next = NULL;
}

template <class T >
Linklist<T>::~Linklist() {
	//析构函数，删除表空间
	Node<T>* p;
	while (Head) {
		p = Head;
		Head = Head->next;
		delete p;
	}
	Head = NULL;
}

template <class T>
void Linklist<T>::IninList(int n) {
	//使用尾插法，创建n个元素的链表
	cout << "请依次输入" << n << "个元素值:";
	Node<T>* p, * s;
	p = Head;//p指向表尾
	for (int i = 0; i < n; i++) {
		s = new Node<T>;
		cin >> s->data;
		s->next = p->next;
		p->next = s;
		p = s;
	}
}

template <class T>
int Linklist<T>::ListLength() {
	//遍历整个链表，获得链表长度
	int len = 0;
	Node<T>* p;
	for (p = Head->next; p != NULL; p = p->next) {
		len++;
	}
	return len;
}

template <class T>
int Linklist<T>::GetElem(int i, T& e) {
	//获得第i个元素值，用e传回
	Node<T>* p;
	int k=0;
	p = Head;
	while (p->next != NULL && k < i - 1) {//找到第i个元素的前驱，即第i-1个
		p = p->next;
		k++;
	}
	if (!p->next || k > i - 1) {cout << "输入位置不合理." << endl;//空表或者 i<0或者i大于表长
	return 0;}
	else {
		e = p->next->data;
		return 1;
	}
}

template <class T>
int Linklist<T>::compare(T a, T b) {
	//判断a是否等于b
	return a == b;
}

template <class T>
void Linklist<T>::LocatcElem(T e) {
	//返回与e相等的元素位置
	Node<T>* p;
	int i = 1, cnt = 0;
	for (p = Head; p->next != NULL; p = p->next)
		if (compare(e, p->next->data)) cnt++;//先找是否有与e相等的元素
	if (cnt != 0) {//如果有则依次输出位置
		cout << "与" << e << "相等的元素位置为:";
		p = Head;
		while (p->next) {
			if (compare(e, p->next->data))
				cout << i << " ";
			p = p->next;
			i++;
		}
		cout << endl;
	}
	else cout << "没有与" << e << "相等的元素." << endl;//如果没有则输出没有
}

template <class T>
T Linklist<T>::PriorElem(T cur_e, T& pre_e) {
	//求cur_e的前驱元素，用pre_e返回
	Node<T>* p;
	for (p = Head; p->next != NULL; p = p->next) {
		if (p->next->data == cur_e) {
			pre_e = p->data;
			return pre_e;
		}
	}
}

template <class T>
void Linklist<T>::ListTraverse() {
	{//遍历显示链表
		Node<T>* p;//设置工作指针
		p = Head->next;//从首元结点开始遍历
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

template <class T>
void Linklist<T>::ListInsert(int i, T e) {
	//在第i个位置插入e
	Node<T>* p = Head, * q;
	int k = 0;
	while (p->next && k < i - 1) {//寻找第i个位置的前驱i-1
		p = p->next;
		k++;
	}
	if (!p->next || k > i - 1) cout << "位置异常" << endl;//空表、i<0、i大于表长
	else {
		q = new Node<T>;
		q->data = e;
		q->next = p->next;
		p->next = q;
	}
}

template <class T>
int Linklist<T>::ListDelete(int i, T& e) {
	//删除第i个位置的元素 用e返回
	Node<T>* p = Head, * q;
	int k = 0;
	while (p->next && k < i - 1) {//找到第i个位置的前驱，即i-1
		p = p->next;
		k++;
	}
	if (!p->next || k > i - 1) {
		cout << "位置异常." << endl;
		return 0;
	}
	else {
		q = p->next;
		e = q->data;
		p -> next = q->next;
		delete q;
		return 1;
	}
}

template <typename T>
int Linklist<T>::Empty() {
	if (Head->next == NULL) return 1;
	else return 0;
}