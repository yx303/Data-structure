#include "Polynome.h"
#include<iostream>
using namespace std;

Polylist Polycreate() {
	//��������n��Ķ���ʽ����
	Polylist s, rear, L;
	float c;
	int e;
	L = new PolyNode;
	rear = L;
	cout << "�������������ʽ��ϵ����ָ������0Ϊ������־" << endl;
	cin >> c >> e;
	while (c) {
		s = new PolyNode;
		s->coef = c;
		s->exp = e;
		rear->next = s;
		rear = s;//rearָ��ʼ��ָ�������ĩβ
		cin >> c >> e;
	}
	rear->next = NULL;
	return L;
}

void Polysort(Polylist L) {
	//ʹ����ʽ��������ʽ����
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
	//�������ʽ
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
	//�����ʽ�ĵ���
	Polylist p, q, s;
	q = new PolyNode;
	q->next = NULL;//qָ���������ͷ���
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
	p = LA->next;//p��q�ֱ�ָ��LA��LB����ʽ�����еĵ�һ��
	q = LB->next;
	LC = new PolyNode;//�½�һ������ʽ������źͶ���ʽ
	rear = LC;//rearָ��Ͷ���ʽ��β���
	while (p && q) {
		if (p->exp < q->exp) {//���pָ���ָ��С��qָ���ָ��,p�����뵽�Ͷ���ʽ
			s = new PolyNode;
			s->coef = p->coef;
			s->exp = p->exp;
			rear->next = s;
			rear = s;
			p = p->next;
		}
		else if(p->exp==q->exp){//��ָ����� ������Ӧ��ϵ�����
			sum = p->coef + q->coef;
			if (sum!=0) {//��ϵ���Ͳ�����0����ϵ���������½ڵ�
				s = new PolyNode;
				s->coef = sum;
				s->exp = p->exp;
				rear->next = s;
				rear = s;
				p = p->next;
				q = q->next;
			}
			else {//��ϵ����Ϊ0����p��q�������
				p = p->next;
				q = q->next;
			}

		}
		else {//���pָ���ָ������qָ���ָ��,q�����뵽�Ͷ���ʽ
			s = new PolyNode;
			s->coef = q->coef;
			s->exp = q->exp;
			rear->next = s;
			rear = s;
			q = q->next;
		}
	}
	if (p) //����ʽLA��ʣ��
		rear->next = p;
	else//����ʽLB��ʣ��
		rear->next = q;
	return LC;
}

Polylist Polymult(Polylist LA, Polylist LB) {
	Polylist p, q, s, LC, rear, t;
	p = LA->next;//p��q�ֱ�ָ��LA��LB����ʽ�����еĵ�һ��
	q = LB->next;
	LC = new PolyNode;//�½�һ��������Ż�����ʽ
	LC->next = NULL;
	t = new PolyNode;
	while (p) {
		q = LB->next;
		rear = t;//rearʼ��ָ�����ʽ��β���
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
	p = LA->next;//p��q�ֱ�ָ��LA��LB����ʽ�����еĵ�һ��
	q = LB->next;
	LC = new PolyNode;//�½�һ������ʽ������źͶ���ʽ
	rear = LC;//rearָ��Ͷ���ʽ��β���
	while (p && q) {
		if (p->exp < q->exp) {//���pָ���ָ��С��qָ���ָ��,p�����뵽�Ͷ���ʽ
			s = new PolyNode;
			s->coef = p->coef;
			s->exp = p->exp;
			rear->next = s;
			rear = s;
			p = p->next;
		}
		else if (p->exp == q->exp) {//��ָ����� ������Ӧ��ϵ�����
			sub = p->coef - q->coef;
			if (sub != 0) {//��ϵ���Ͳ�����0����ϵ���������½ڵ�
				s = new PolyNode;
				s->coef = sub;
				s->exp = p->exp;
				rear->next = s;
				rear = s;
				p = p->next;
				q = q->next;
			}
			else {//��ϵ����Ϊ0����p��q�������
				p = p->next;
				q = q->next;
			}

		}
		else {//���pָ���ָ������qָ���ָ��,q�����뵽�Ͷ���ʽ
			s = new PolyNode;
			s->coef = q->coef;
			s->exp = q->exp;
			rear->next = s;
			rear = s;
			q = q->next;
		}
	}
	if (p) //����ʽLA��ʣ��
		rear->next = p;
	else//����ʽLB��ʣ��
		rear->next = q;
	return LC;
}