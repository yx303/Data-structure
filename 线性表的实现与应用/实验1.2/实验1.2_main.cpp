#include<iostream>
#include "Polynome.h"
using namespace std;

int main() {
	Polylist LA = NULL, LB = NULL, LC = NULL, DL /*= new PolyNode*/;
	int choice;
	do {//显示主菜单
		cout << "1-创建多项式\n";
		cout << "2-输出多项式\n";
		cout << "3-求多项式在x处的导数\n";
		cout << "4-求两个多项式的和\n";
		cout << "5-求两个多项式的乘积\n";
		cout << "6-求两个多项式的差\n";
		cout << "101-退出\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice) {
		case 1://创建多项式
			LA=Polycreate();
			cout << endl;
			break;
		case 2://输出多项式
			Polysort(LA);
			Polydisplay(LA);
			cout << endl;
			break;
		case 3://求导
			cout << "该多项式的导数为:";
			DL = Polyderivative(LA);
			Polysort(DL);
			Polydisplay(DL);
			cout << endl;
			break;
		case 4://求和
			cout << "创建多项式LB:" ;
			LB=Polycreate();
			cout << "和多项式为:";
			LC = Polyadd(LA, LB);
			Polydisplay(LC);
			cout << endl;
			break;
		case 5://求积
			cout << "创建多项式LB:";
			LB = Polycreate();
			cout << "积多项式为:";
			LC = Polymult(LA, LB);
			Polydisplay(LC);
			cout << endl;
			break;
		case 6:
			cout << "创建多项式LB:";
			LB = Polycreate();
			cout << "差多项式为:";
			LC = Polyadd(LA, LB);
			Polydisplay(LC);
			cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}