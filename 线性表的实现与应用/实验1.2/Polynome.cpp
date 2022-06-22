#include "Polynome.h"
#include<iostream>
using namespace std;

Polylist Polycreate() {
	//创建含有n项的多项式链表
	Polylist s, rear, L;
	float c;
	int e;
	L = new PolyNode;
	rear = L;
	cout << "请依次输入多项式的系数和指数，以0为结束标志" << endl;
	cin >> c >> e;
	while (c) {
		s = new PolyNode;
		s->coef = c;
		s->exp = e;
		rear->next = s;
		rear = s;//rear指针始终指向链表的末尾
		cin >> c >> e;
	}
	rear->next = NULL;
	return L;
}

void Polysort(Polylist L) {
	//使多项式按升幂形式排列
	Polylist p, q;
	float c;
	int e;
	p = L->next;
	for (; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->exp > q->exp) {
				c = p->coef;
				p->coef = q->coef;
				q->coef = c;
				e = p->exp;
				p->exp = q->exp;
				q->exp = e;
			}
		}
	}
}

void Polydisplay(Polylist L) {
	//输出多项式
	Polylist p;
	for (p = L->next; p != NULL; p = p->next) {
		if (p->coef != 1 && p->coef != -1 && p->coef != 0) cout << p->coef;
		else if (p->coef == -1) cout << "-";
		else if (p->exp == 0 && p->coef != 0) cout << p->coef;
		if (p->exp > 1 || p->exp < 0) cout << "x^" << p->exp;
		else if (p->exp == 1) cout << 'x';
		if (p->next != NULL && p->next->coef > 0 && p->coef != 0) cout << "+";
	}
	cout << endl;

}

Polylist Polyderivative(Polylist L) {
	//求多项式的导数
	Polylist p, q, s;
	q = new PolyNode;
	q->next = NULL;//q指向导数链表的头结点
	for (p = L->next; p != NULL; p = p->next) {
		s = new PolyNode;
		s->coef = p->coef * p->exp;
		s->exp = p->exp - 1;
		s->next = q->next;
		q->next = s;
	}
	return q;
}

Polylist Polyadd(Polylist LA, Polylist LB) {
	Polylist LC, s, p, q, rear;
	float sum;
	p = LA->next;//p和q分别指向LA和LB多项式链表中的第一项
	q = LB->next;
	LC = new PolyNode;//新建一个多项式链表，存放和多项式
	rear = LC;//rear指向和多项式的尾结点
	while (p && q) {
		if (p->exp < q->exp) {//如果p指向的指数小于q指向的指数,p结点加入到和多项式
			s = new PolyNode;
			s->coef = p->coef;
			s->exp = p->exp;
			rear->next = s;
			rear = s;
			p = p->next;
		}
		else if(p->exp==q->exp){//若指数相等 ，则相应的系数想加
			sum = p->coef + q->coef;
			if (sum!=0) {//若系数和不等于0，则将系数和置入新节点
				s = new PolyNode;
				s->coef = sum;
				s->exp = p->exp;
				rear->next = s;
				rear = s;
				p = p->next;
				q = q->next;
			}
			else {//若系数和为0，则p，q均向后移
				p = p->next;
				q = q->next;
			}

		}
		else {//如果p指向的指数大于q指向的指数,q结点加入到和多项式
			s = new PolyNode;
			s->coef = q->coef;
			s->exp = q->exp;
			rear->next = s;
			rear = s;
			q = q->next;
		}
	}
	if (p) //多项式LA有剩余
		rear->next = p;
	else//多项式LB有剩余
		rear->next = q;
	return LC;
}

Polylist Polymult(Polylist LA, Polylist LB) {
	Polylist p, q, s, LC, rear, t;
	p = LA->next;//p和q分别指向LA和LB多项式链表中的第一项
	q = LB->next;
	LC = new PolyNode;//新建一个链表，存放积多项式
	LC->next = NULL;
	t = new PolyNode;
	while (p) {
		q = LB->next;
		rear = t;//rear始终指向多项式的尾结点
		while (q) {
			s = new PolyNode;
			s->coef = p->coef * q->coef;
			s->exp = p->exp + q->exp;
			rear->next = s;
			rear = s;
			rear->next = NULL;
			q = q->next;
		}
		LC = Polyadd(LC, t);
		p = p->next;
	}
	return LC;
}

Polylist Polysub(Polylist LA, Polylist LB) {
	Polylist LC, s, p, q, rear;
	float sub;
	p = LA->next;//p和q分别指向LA和LB多项式链表中的第一项
	q = LB->next;
	LC = new PolyNode;//新建一个多项式链表，存放和多项式
	rear = LC;//rear指向和多项式的尾结点
	while (p && q) {
		if (p->exp < q->exp) {//如果p指向的指数小于q指向的指数,p结点加入到和多项式
			s = new PolyNode;
			s->coef = p->coef;
			s->exp = p->exp;
			rear->next = s;
			rear = s;
			p = p->next;
		}
		else if (p->exp == q->exp) {//若指数相等 ，则相应的系数想加
			sub = p->coef - q->coef;
			if (sub != 0) {//若系数和不等于0，则将系数和置入新节点
				s = new PolyNode;
				s->coef = sub;
				s->exp = p->exp;
				rear->next = s;
				rear = s;
				p = p->next;
				q = q->next;
			}
			else {//若系数和为0，则p，q均向后移
				p = p->next;
				q = q->next;
			}

		}
		else {//如果p指向的指数大于q指向的指数,q结点加入到和多项式
			s = new PolyNode;
			s->coef = q->coef;
			s->exp = q->exp;
			rear->next = s;
			rear = s;
			q = q->next;
		}
	}
	if (p) //多项式LA有剩余
		rear->next = p;
	else//多项式LB有剩余
		rear->next = q;
	return LC;
}