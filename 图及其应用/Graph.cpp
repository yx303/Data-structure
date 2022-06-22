#include "Graph.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

int LocateVertex(AdjList& G, VertexData v)
{//求顶点位置
	int j = 0, k;
	for(k=0;k<G->vexnum;k++)
		if (G->vertex[k] == v) {
			j = k;
			break;
		}
	return j;
}

int toint(string s) {//将vector里面的string类型转换为int型
	stringstream stringsin;
	stringsin << s;
	int t;
	stringsin >> t;
	return t;
}

void CreateGraph(AdjList& G)
{//创建一个无向网
	string s;//存放文件中的一行数据
	string s_onpoint;//按空格存放一个数据
	vector<string> str;//存放每行数据
	vector<vector<string>> str_feat;//存放所有数据
	ifstream infile;
	infile.open("Graph.txt", ios::in);//读取所有顶点以及顶点间的关系
	if (!infile) cout << "文件打开失败!" << endl;
	while (!infile.eof()) {
		getline(infile, s);//每次读取一行
		stringstream stringin(s);//使用串流实现对string的输入输出操作
		str.clear();
		while (stringin >> s_onpoint) {
			str.push_back(s_onpoint);
		}
		str_feat.push_back(str);
	}
	infile.close();
	int a, b;
	G->vexnum = str_feat[0].size();//文件中的第一行为所建图的顶点
	G->arcnum = str_feat.size() - 1;//文件中除第一行外其余均为图中边的信息，且为无向网
	for (int i = 0; i < G->vexnum; i++)
		for (int j = 0; j < G->vexnum; j++) {//初始化邻接矩阵
			G->arcs[i][j].adj = GREAT;//两个城市之间的距离
			G->arcs[i][j].money = GREAT;//两个城市之间的费用
		}
	for (int i = 0; i < G->vexnum; i++)
		G->vertex[i] = str_feat[0][i];//将图顶点依次存入
	for (int j = 0; j < G->arcnum ; j++) {
		a = LocateVertex(G, str_feat[j + 1][0]);
		b = LocateVertex(G, str_feat[j + 1][1]);
		G->arcs[a][b].adj = toint(str_feat[j + 1][2]);
		G->arcs[a][b].money = toint(str_feat[j + 1][3]);
		G->arcs[b][a].adj = G->arcs[a][b].adj;
		G->arcs[b][a].money = G->arcs[a][b].money;
	}
}

int getNumVertices(AdjList& G)
{//求图G的顶点个数
	return G->vexnum;
}

int getNumEdges(AdjList& G)
{//求图G的边数
	int num = 0;
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++)
			if (G->arcs[i][j].adj != GREAT) num++;
	}
	return num;
}

bool ValidVertex(AdjList& G, VertexData v)
{//判断顶点v是否在图中
	for (int i = 0; i < G->vexnum; i++)
		if (G->vertex[i] == v) return true;
	return false;
}

bool HasEdge(AdjList& G, VertexData u, VertexData v)
{//判断是否存在u到v的有向边
	int i = LocateVertex(G, u);
	int j = LocateVertex(G, v);
	if (G->arcs[i][j].adj != GREAT) return true;
	return false;
}

void AddVertex(AdjList& G, VertexData u)
{//若图中不存在u，则将其插入
	if (!ValidVertex(G, u)) G->vertex[G->vexnum++] = u;
	else cout << "顶点‘" << u << "’已存在!" << endl;
}

void AddEdge(AdjList& G, VertexData u, VertexData v, int adj, int money)
{//若不存在u到v的有向边，则加入该边，权值为w
	if (!HasEdge(G, u, v)) {
		int i = LocateVertex(G, u);
		int j = LocateVertex(G, v);
		G->arcs[i][j].adj = adj;
		G->arcs[i][j].money = money;
	}
	else cout << "存在顶点‘" << u << "’到顶点‘" << v << "’的边!" << endl;
}

void RemoveEdge(AdjList& G, VertexData u, VertexData v)
{//若存在u到v的有向边，则去除该边
	if (HasEdge(G, u, v)) {
		int i = LocateVertex(G, u);
		int j = LocateVertex(G, v);
		G->arcs[i][j].adj = GREAT;
		G->arcs[i][j].money = GREAT;
	}
	else cout << "不存在顶点‘" << u << "’到顶点‘" << v << "’的边!" << endl;
}

void Floyd(AdjList& G, Path& PathLength, Path& PathMoney)
{//求最短路径
	int i, j, n = G->vexnum;
	int** L = new int* [n], ** M = new int* [n];
	for (int k = 0; k < n; k++) {
		L[k] = new int[n];
		M[k] = new int[n];
	}
	for(i=0;i<n;i++)//初始化
		for (j = 0; j < n; j++) {
			L[i][j] = G->arcs[i][j].adj;
			M[i][j] = G->arcs[i][j].money;
			PathLength[i][j] = j;
			PathMoney[i][j] = j;
		}
	for(int h=0;h<n;h++)
		for(i=0;i<n;i++)
			for (j = 0; j < n; j++) {
				if (L[i][j] > L[i][h] + L[h][j]) {
					L[i][j] = L[i][h] + L[h][j];
					PathLength[i][j] = PathLength[i][h];
				}
				if (M[i][j] > M[i][h] + M[h][j]) {
					M[i][j] = M[i][h] + M[h][j];
					PathMoney[i][j] = PathMoney[i][h];
				}
			}
	for (int k = 0; k < n; k++) {//释放空间
		delete[] L[k], M[k];
	}
	delete[] L, M;
}

void PrintLength(AdjList& G, VertexData u, VertexData v, Path PathLength)
{//打印u和v之间的最短路程路径
	int k;
	k = LocateVertex(G, u);
	while (k != LocateVertex(G, v)) {
		cout << G->vertex[k] << "->";
		k = PathLength[k][LocateVertex(G,v)];
	}
	cout << v << endl;
}

void PrintMoney(AdjList& G, VertexData u, VertexData v, Path PathMoney)
{//打印u和v之间的最少费用的路径
	int k;
	k = LocateVertex(G, u);
	while (k != LocateVertex(G, v)) {
		cout << G->vertex[k] << "->";
		k = PathMoney[k][LocateVertex(G, v)];
	}
	cout << v << endl;
}

