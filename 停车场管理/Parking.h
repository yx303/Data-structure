#pragma once
#ifndef _PARKING_H
#define _PARKING_H
#define maxstacksize 4
#define maxqueuesize 6
#define fee 0.1//一分钟0.1元
#include<string>

struct Time {//时间节点
	int hour;
	int min;
};

struct Car {//车辆信息
	std::string num;
	Time reach;//车辆到达时间
	Time leave;//车辆离开时间
	int pos;//车在停车场或者临时便道上的位置
};

struct Stack {//停车场栈
	Car C[maxstacksize];
	int top;//栈顶元素的下标，top为-1表示栈空
};

struct Queue {//临时便道队列
	Car S[maxqueuesize];
	int front;//队列第一个元素下标
	int rear;//队列最后一个元素下标，front==rear队列为空6
};

void InitStack(Stack& P);//初始化栈
void Push(Stack& P, Car& e);//入栈
void Pop(Stack& P, Car& e);//出栈
void InitQueue(Queue& Q);//初始化队列
void EnterQueue(Queue& Q, Car& e);//入队
void DeleteQueue(Queue& Q, Car& e);//出队
void Arrive(Stack& Enter, Queue& W, Car& p);//车辆到达
void Leave(Stack& Enter, Queue& W, Car& p);//车辆离开
void ShowStack(Stack& S);//显示停车场信息
void ShowQueue(Queue& Q);//显示临时便道信息
void InitCar(Car& p);//初始化车辆信息

#endif //_PARKING_H