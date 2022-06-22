#include "Graph.h"
#include<iostream>
#include "Windows.h"
using namespace std;

int main() {
	VertexData u, v, city;
	AdjList G = new AdjMatrix;
	int choice, num, adj, money;
	Path PathLength, PathMoney;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "************���˵�***************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "1-������ͨͼ" << endl;
	cout << "2-��ͨͼ����(����)����" << endl;
	cout << "3-��ͨͼ����" << endl;
	cout << "4-�ж϶���(����)�Ƿ���ͼ��" << endl;
	cout << "5-�ж��Ƿ����ĳ��" << endl;
	cout << "6-��Ӷ���(����)" << endl;
	cout << "7-��ӱ�" << endl;
	cout << "8-ɾ����" << endl;
	cout << "9-�����·��" << endl;
	cout << "101-�˳�ϵͳ" << endl;
	cout << "Enter your choice:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choice;
	while (choice != 101) {
		switch (choice) {
		case 1://������ͨͼ
			CreateGraph(G);
			cout << "�������!" << endl;
			system("pause");
			break;
		case 2://��ͨͼ����(����)����
			num = getNumVertices(G);
			cout << "�������Ϊ:" << num << endl;
			system("pause");
			break;
		case 3://��ͨͼ����
			num = getNumEdges(G);
			cout << "����Ϊ:" << num/2 << endl;
			system("pause");
			break;
		case 4://�ж϶���(����)�Ƿ���ͼ��
			cout << "������Ŀ�����:";
			cin >> city;
			if (!ValidVertex(G, city))
				cout << "���С�" << city << "�����ڽ�ͨͼ��!" << endl;
			else
				cout << "���С�" << city << "���ڽ�ͨͼ��!" << endl;
			system("pause");
			break;
		case 5://�ж��Ƿ����ĳ��
			cout << "��������������Ŀ�����:";
			cin >> u >> v;
			if (!HasEdge(G, u, v))
				cout << u << "��" << v << "֮�䲻���ڱ�!" << endl;
			else
				cout << u << "��" << v << "֮����ڱ�!" << endl;
			system("pause");
			break;
		case 6://��Ӷ���(����)
			cout << "������Ŀ�����:";
			cin >> city;
			if (!ValidVertex(G, city)) {
				AddVertex(G, city);
				cout << "����ɹ�!" << endl;
			}
			else
				cout << "���С�" << city << "�����ڽ�ͨͼ��!" << endl;
			system("pause");
			break;
		case 7://��ӱ�
			cout << "��������������Ŀ�����:";
			cin >> u >> v;
			if (!HasEdge(G, u, v)) {
				cout << "���������롮" << u << "������" << v << "����·�̼�����:";
				cin >> adj >> money;
				AddEdge(G, u, v, adj, money);
				cout << "����ɹ�!" << endl;
			}
			else
				cout << u << "��" << v << "��֮����ڱ�!" << endl;
			system("pause");
			break;
		case 8://ɾ����
			cout << "��������������Ŀ�����:";
			cin >> u >> v;
			if (!HasEdge(G, u, v))
				cout << u << "��" << v << "֮�䲻���ڱ�!" << endl;
			else {
				RemoveEdge(G, u, v);
				cout << "ɾ�����!" << endl;
			}
			system("pause");
			break;
		case 9://�����·��
			Floyd(G, PathLength, PathMoney);
			cout << "���������������к��յ����:";
			cin >> u >> v;
			cout << "·����̵ķ�ʽΪ:";
			PrintLength(G, u, v, PathLength);
			cout << "�������ٵķ�ʽΪ:";
			PrintMoney(G, u, v, PathMoney);
			system("pause");
			break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "Enter your choice:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> choice;
	}
	return 0;
}