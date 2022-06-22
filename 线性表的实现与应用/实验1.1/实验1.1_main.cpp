#include<iostream>
#include "Linklist.h"
#include "Linklist.cpp"
using namespace std;

int main() {
	int choice, i, cnt;
	ElemType e, pre_e, key;
	Linklist<int> L;
	do
	{//显示主菜单
		//cout << "0-初始化单链表\n";
		cout << "1-尾插法创建单链表\n";
		cout << "2-按位序插入\n";
		cout << "3-按位序删除\n";
		cout << "4-按位序查找\n";
		cout << "5-按值查找\n";
		cout << "6-按值求前驱\n";
		cout << "7-判表空\n";
		cout << "8-求表长\n";
		cout << "9-显示链表\n";
		cout << "101-退出\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice) {
		case 1://尾插法创建链表
			cout << "请输入创建链表中元素个数:";
			cin >> i;
			L.IninList(i);
			cout << endl;
			break;
		case 2://在指定位置插入元素
			cout << "请输入插入位置:";
			cin >> i;
			//cout << endl;
			cout << "请输入插入元素的值:";
			cin >> e;
			cout << endl;
			L.ListInsert(i, e);
			break;
		case 3://在指定位置删除元素
			cout << "请输入删除位置:";
			cin >> i;
			cnt=L.ListDelete(i, e);
			if(cnt) cout << "被删除的元素为:" << e << endl;
			cout << endl;
			break;
		case 4://按位置查找
			cout << "请输入要查询的元素位置:";
			cin >> i;
			cnt=L.GetElem(i, e);
			if (cnt) cout << "第" << i << "个元素为:" << e << endl;
			cout << endl;
			break;
		case 5://按值查找
			cout << "请输入要查询的值:";
			cin >> key;
			L.LocatcElem(key);
			cout << endl;
			break;
		case 6://按值找前驱
			cout << "请输入元素:";
			cin >> e;
			cout << "元素" << e << "的前驱为:" << L.PriorElem(e, pre_e) << "\n" << endl;
			break;
		case 7://判表空
			cnt = L.Empty();
			if (cnt) cout << "表空\n" << endl;
			else cout << "表非空\n" << endl;
			break;
		case 8://求表长
			cnt = L.ListLength();
			cout << "表长为:" << cnt << endl;
			cout << endl;
			break;
		case 9://显示链表
			L.ListTraverse();
			cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}