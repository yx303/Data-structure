#include<iostream>
#include "Linklist.h"
#include "Linklist.cpp"
using namespace std;

int main() {
	int choice, i, cnt;
	ElemType e, pre_e, key;
	Linklist<int> L;
	do
	{//��ʾ���˵�
		//cout << "0-��ʼ��������\n";
		cout << "1-β�巨����������\n";
		cout << "2-��λ�����\n";
		cout << "3-��λ��ɾ��\n";
		cout << "4-��λ�����\n";
		cout << "5-��ֵ����\n";
		cout << "6-��ֵ��ǰ��\n";
		cout << "7-�б��\n";
		cout << "8-���\n";
		cout << "9-��ʾ����\n";
		cout << "101-�˳�\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice) {
		case 1://β�巨��������
			cout << "�����봴��������Ԫ�ظ���:";
			cin >> i;
			L.IninList(i);
			cout << endl;
			break;
		case 2://��ָ��λ�ò���Ԫ��
			cout << "���������λ��:";
			cin >> i;
			//cout << endl;
			cout << "���������Ԫ�ص�ֵ:";
			cin >> e;
			cout << endl;
			L.ListInsert(i, e);
			break;
		case 3://��ָ��λ��ɾ��Ԫ��
			cout << "������ɾ��λ��:";
			cin >> i;
			cnt=L.ListDelete(i, e);
			if(cnt) cout << "��ɾ����Ԫ��Ϊ:" << e << endl;
			cout << endl;
			break;
		case 4://��λ�ò���
			cout << "������Ҫ��ѯ��Ԫ��λ��:";
			cin >> i;
			cnt=L.GetElem(i, e);
			if (cnt) cout << "��" << i << "��Ԫ��Ϊ:" << e << endl;
			cout << endl;
			break;
		case 5://��ֵ����
			cout << "������Ҫ��ѯ��ֵ:";
			cin >> key;
			L.LocatcElem(key);
			cout << endl;
			break;
		case 6://��ֵ��ǰ��
			cout << "������Ԫ��:";
			cin >> e;
			cout << "Ԫ��" << e << "��ǰ��Ϊ:" << L.PriorElem(e, pre_e) << "\n" << endl;
			break;
		case 7://�б��
			cnt = L.Empty();
			if (cnt) cout << "���\n" << endl;
			else cout << "��ǿ�\n" << endl;
			break;
		case 8://���
			cnt = L.ListLength();
			cout << "��Ϊ:" << cnt << endl;
			cout << endl;
			break;
		case 9://��ʾ����
			L.ListTraverse();
			cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}