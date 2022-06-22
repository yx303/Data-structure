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
	Linklist();//���캯��������һ��������
	~Linklist();//����������ɾ����ռ�
	void IninList(int n);//��ʼ��������������n��Ԫ�ص�����
	//void DestroyList();//��������
	int ListLength();//��������
	int GetElem(int i, T& e);//��������i��Ԫ��ֵ
	void LocatcElem(T e);//�����������e����compare��ϵ��Ԫ��λ��
	int compare(T a, T b);//��a==b������1�����򷵻�0
	T PriorElem(T cur_e, T& pre_e);//��������Ԫ��cur_e��ǰ��
	void ListTraverse();//��������
	void ListInsert(int i, T e);//�ڵ�i��λ�ò���e
	int ListDelete(int i, T& e);//ɾ����i��Ԫ�أ���e����
	int Empty();//�б�գ���շ���1����ǿշ���0��
private:
	Node<T>* Head;
};
#endif//_LINKLIST_H