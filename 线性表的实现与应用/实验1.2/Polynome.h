#pragma once
#ifndef _LINKLIST_H
#define _LINKLIST_H

struct PolyNode {
	float coef;//系数域
	int exp;//指数域
	PolyNode* next;//指针域，存放下一个结点的地址
};
typedef PolyNode* Polylist;

Polylist Polycreate();//创建多项式链表
void Polysort(Polylist L);//对多项式进行排序，使其按升幂的形式排列
void Polydisplay(Polylist L);//输出多项式
Polylist Polyderivative(Polylist L);//对多项式进行求导
Polylist Polyadd(Polylist LA, Polylist LB);//求两个多项式之和
Polylist Polymult(Polylist LA, Polylist LB);//求两个多项式之积
Polylist Polysub(Polylist LA, Polylist LB);//求两个多项式之差

#endif//_LINKLIST_H