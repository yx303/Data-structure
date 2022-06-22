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
	cout << "************主菜单***************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "1-建立交通图" << endl;
	cout << "2-求交通图顶点(城市)个数" << endl;
	cout << "3-求交通图边数" << endl;
	cout << "4-判断顶点(城市)是否在图中" << endl;
	cout << "5-判断是否存在某边" << endl;
	cout << "6-添加顶点(城市)" << endl;
	cout << "7-添加边" << endl;
	cout << "8-删除边" << endl;
	cout << "9-求最短路径" << endl;
	cout << "101-退出系统" << endl;
	cout << "Enter your choice:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choice;
	while (choice != 101) {
		switch (choice) {
		case 1://建立交通图
			CreateGraph(G);
			cout << "创建完成!" << endl;
			system("pause");
			break;
		case 2://求交通图顶点(城市)个数
			num = getNumVertices(G);
			cout << "顶点个数为:" << num << endl;
			system("pause");
			break;
		case 3://求交通图边数
			num = getNumEdges(G);
			cout << "边数为:" << num/2 << endl;
			system("pause");
			break;
		case 4://判断顶点(城市)是否在图中
			cout << "请输入目标城市:";
			cin >> city;
			if (!ValidVertex(G, city))
				cout << "城市‘" << city << "’不在交通图中!" << endl;
			else
				cout << "城市‘" << city << "’在交通图中!" << endl;
			system("pause");
			break;
		case 5://判断是否存在某边
			cout << "请依次输入两个目标城市:";
			cin >> u >> v;
			if (!HasEdge(G, u, v))
				cout << u << "与" << v << "之间不存在边!" << endl;
			else
				cout << u << "与" << v << "之间存在边!" << endl;
			system("pause");
			break;
		case 6://添加顶点(城市)
			cout << "请输入目标城市:";
			cin >> city;
			if (!ValidVertex(G, city)) {
				AddVertex(G, city);
				cout << "插入成功!" << endl;
			}
			else
				cout << "城市‘" << city << "’已在交通图中!" << endl;
			system("pause");
			break;
		case 7://添加边
			cout << "请依次输入两个目标城市:";
			cin >> u >> v;
			if (!HasEdge(G, u, v)) {
				cout << "请依次输入‘" << u << "’到‘" << v << "’的路程及费用:";
				cin >> adj >> money;
				AddEdge(G, u, v, adj, money);
				cout << "插入成功!" << endl;
			}
			else
				cout << u << "与" << v << "已之间存在边!" << endl;
			system("pause");
			break;
		case 8://删除边
			cout << "请依次输入两个目标城市:";
			cin >> u >> v;
			if (!HasEdge(G, u, v))
				cout << u << "与" << v << "之间不存在边!" << endl;
			else {
				RemoveEdge(G, u, v);
				cout << "删除完成!" << endl;
			}
			system("pause");
			break;
		case 9://求最短路径
			Floyd(G, PathLength, PathMoney);
			cout << "请依次输入起点城市和终点城市:";
			cin >> u >> v;
			cout << "路径最短的方式为:";
			PrintLength(G, u, v, PathLength);
			cout << "费用最少的方式为:";
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