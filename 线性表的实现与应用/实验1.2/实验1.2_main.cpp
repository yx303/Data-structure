#include<iostream>
#include "Polynome.h"
using namespace std;

int main() {
	Polylist LA = NULL, LB = NULL, LC = NULL, DL /*= new PolyNode*/;
	int choice;
	do {//��ʾ���˵�
		cout << "1-��������ʽ\n";
		cout << "2-�������ʽ\n";
		cout << "3-�����ʽ��x���ĵ���\n";
		cout << "4-����������ʽ�ĺ�\n";
		cout << "5-����������ʽ�ĳ˻�\n";
		cout << "6-����������ʽ�Ĳ�\n";
		cout << "101-�˳�\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice) {
		case 1://��������ʽ
			LA=Polycreate();
			cout << endl;
			break;
		case 2://�������ʽ
			Polysort(LA);
			Polydisplay(LA);
			cout << endl;
			break;
		case 3://��
			cout << "�ö���ʽ�ĵ���Ϊ:";
			DL = Polyderivative(LA);
			Polysort(DL);
			Polydisplay(DL);
			cout << endl;
			break;
		case 4://���
			cout << "��������ʽLB:" ;
			LB=Polycreate();
			cout << "�Ͷ���ʽΪ:";
			LC = Polyadd(LA, LB);
			Polydisplay(LC);
			cout << endl;
			break;
		case 5://���
			cout << "��������ʽLB:";
			LB = Polycreate();
			cout << "������ʽΪ:";
			LC = Polymult(LA, LB);
			Polydisplay(LC);
			cout << endl;
			break;
		case 6:
			cout << "��������ʽLB:";
			LB = Polycreate();
			cout << "�����ʽΪ:";
			LC = Polyadd(LA, LB);
			Polydisplay(LC);
			cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}