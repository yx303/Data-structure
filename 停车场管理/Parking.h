#pragma once
#ifndef _PARKING_H
#define _PARKING_H
#define maxstacksize 4
#define maxqueuesize 6
#define fee 0.1//һ����0.1Ԫ
#include<string>

struct Time {//ʱ��ڵ�
	int hour;
	int min;
};

struct Car {//������Ϣ
	std::string num;
	Time reach;//��������ʱ��
	Time leave;//�����뿪ʱ��
	int pos;//����ͣ����������ʱ����ϵ�λ��
};

struct Stack {//ͣ����ջ
	Car C[maxstacksize];
	int top;//ջ��Ԫ�ص��±꣬topΪ-1��ʾջ��
};

struct Queue {//��ʱ�������
	Car S[maxqueuesize];
	int front;//���е�һ��Ԫ���±�
	int rear;//�������һ��Ԫ���±꣬front==rear����Ϊ��6
};

void InitStack(Stack& P);//��ʼ��ջ
void Push(Stack& P, Car& e);//��ջ
void Pop(Stack& P, Car& e);//��ջ
void InitQueue(Queue& Q);//��ʼ������
void EnterQueue(Queue& Q, Car& e);//���
void DeleteQueue(Queue& Q, Car& e);//����
void Arrive(Stack& Enter, Queue& W, Car& p);//��������
void Leave(Stack& Enter, Queue& W, Car& p);//�����뿪
void ShowStack(Stack& S);//��ʾͣ������Ϣ
void ShowQueue(Queue& Q);//��ʾ��ʱ�����Ϣ
void InitCar(Car& p);//��ʼ��������Ϣ

#endif //_PARKING_H