#pragma once
#ifndef _LINKLIST_H
#define _LINKLIST_H

struct PolyNode {
	float coef;//ϵ����
	int exp;//ָ����
	PolyNode* next;//ָ���򣬴����һ�����ĵ�ַ
};
typedef PolyNode* Polylist;

Polylist Polycreate();//��������ʽ����
void Polysort(Polylist L);//�Զ���ʽ��������ʹ�䰴���ݵ���ʽ����
void Polydisplay(Polylist L);//�������ʽ
Polylist Polyderivative(Polylist L);//�Զ���ʽ������
Polylist Polyadd(Polylist LA, Polylist LB);//����������ʽ֮��
Polylist Polymult(Polylist LA, Polylist LB);//����������ʽ֮��
Polylist Polysub(Polylist LA, Polylist LB);//����������ʽ֮��

#endif//_LINKLIST_H