#include<iostream>
#include "Linklist.h"
using namespace std;

template <class T>
Linklist<T>::Linklist() {
	//���캯��������һ���±�
	Head = new Node<T>;
	Head->next = NULL;
}

template <class T >
Linklist<T>::~Linklist() {
	//����������ɾ����ռ�
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
	//ʹ��β�巨������n��Ԫ�ص�����
	cout << "����������" << n << "��Ԫ��ֵ:";
	Node<T>* p, * s;
	p = Head;//pָ���β
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
	//���������������������
	int len = 0;
	Node<T>* p;
	for (p = Head->next; p != NULL; p = p->next) {
		len++;
	}
	return len;
}

template <class T>
int Linklist<T>::GetElem(int i, T& e) {
	//��õ�i��Ԫ��ֵ����e����
	Node<T>* p;
	int k=0;
	p = Head;
	while (p->next != NULL && k < i - 1) {//�ҵ���i��Ԫ�ص�ǰ��������i-1��
		p = p->next;
		k++;
	}
	if (!p->next || k > i - 1) {cout << "����λ�ò�����." << endl;//�ձ���� i<0����i���ڱ�
	return 0;}
	else {
		e = p->next->data;
		return 1;
	}
}

template <class T>
int Linklist<T>::compare(T a, T b) {
	//�ж�a�Ƿ����b
	return a == b;
}

template <class T>
void Linklist<T>::LocatcElem(T e) {
	//������e��ȵ�Ԫ��λ��
	Node<T>* p;
	int i = 1, cnt = 0;
	for (p = Head; p->next != NULL; p = p->next)
		if (compare(e, p->next->data)) cnt++;//�����Ƿ�����e��ȵ�Ԫ��
	if (cnt != 0) {//��������������λ��
		cout << "��" << e << "��ȵ�Ԫ��λ��Ϊ:";
		p = Head;
		while (p->next) {
			if (compare(e, p->next->data))
				cout << i << " ";
			p = p->next;
			i++;
		}
		cout << endl;
	}
	else cout << "û����" << e << "��ȵ�Ԫ��." << endl;//���û�������û��
}

template <class T>
T Linklist<T>::PriorElem(T cur_e, T& pre_e) {
	//��cur_e��ǰ��Ԫ�أ���pre_e����
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
	{//������ʾ����
		Node<T>* p;//���ù���ָ��
		p = Head->next;//����Ԫ��㿪ʼ����
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
	//�ڵ�i��λ�ò���e
	Node<T>* p = Head, * q;
	int k = 0;
	while (p->next && k < i - 1) {//Ѱ�ҵ�i��λ�õ�ǰ��i-1
		p = p->next;
		k++;
	}
	if (!p->next || k > i - 1) cout << "λ���쳣" << endl;//�ձ�i<0��i���ڱ�
	else {
		q = new Node<T>;
		q->data = e;
		q->next = p->next;
		p->next = q;
	}
}

template <class T>
int Linklist<T>::ListDelete(int i, T& e) {
	//ɾ����i��λ�õ�Ԫ�� ��e����
	Node<T>* p = Head, * q;
	int k = 0;
	while (p->next && k < i - 1) {//�ҵ���i��λ�õ�ǰ������i-1
		p = p->next;
		k++;
	}
	if (!p->next || k > i - 1) {
		cout << "λ���쳣." << endl;
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