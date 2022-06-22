#include "Graph.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

int LocateVertex(AdjList& G, VertexData v)
{//�󶥵�λ��
	int j = 0, k;
	for(k=0;k<G->vexnum;k++)
		if (G->vertex[k] == v) {
			j = k;
			break;
		}
	return j;
}

int toint(string s) {//��vector�����string����ת��Ϊint��
	stringstream stringsin;
	stringsin << s;
	int t;
	stringsin >> t;
	return t;
}

void CreateGraph(AdjList& G)
{//����һ��������
	string s;//����ļ��е�һ������
	string s_onpoint;//���ո���һ������
	vector<string> str;//���ÿ������
	vector<vector<string>> str_feat;//�����������
	ifstream infile;
	infile.open("Graph.txt", ios::in);//��ȡ���ж����Լ������Ĺ�ϵ
	if (!infile) cout << "�ļ���ʧ��!" << endl;
	while (!infile.eof()) {
		getline(infile, s);//ÿ�ζ�ȡһ��
		stringstream stringin(s);//ʹ�ô���ʵ�ֶ�string�������������
		str.clear();
		while (stringin >> s_onpoint) {
			str.push_back(s_onpoint);
		}
		str_feat.push_back(str);
	}
	infile.close();
	int a, b;
	G->vexnum = str_feat[0].size();//�ļ��еĵ�һ��Ϊ����ͼ�Ķ���
	G->arcnum = str_feat.size() - 1;//�ļ��г���һ���������Ϊͼ�бߵ���Ϣ����Ϊ������
	for (int i = 0; i < G->vexnum; i++)
		for (int j = 0; j < G->vexnum; j++) {//��ʼ���ڽӾ���
			G->arcs[i][j].adj = GREAT;//��������֮��ľ���
			G->arcs[i][j].money = GREAT;//��������֮��ķ���
		}
	for (int i = 0; i < G->vexnum; i++)
		G->vertex[i] = str_feat[0][i];//��ͼ�������δ���
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
{//��ͼG�Ķ������
	return G->vexnum;
}

int getNumEdges(AdjList& G)
{//��ͼG�ı���
	int num = 0;
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++)
			if (G->arcs[i][j].adj != GREAT) num++;
	}
	return num;
}

bool ValidVertex(AdjList& G, VertexData v)
{//�ж϶���v�Ƿ���ͼ��
	for (int i = 0; i < G->vexnum; i++)
		if (G->vertex[i] == v) return true;
	return false;
}

bool HasEdge(AdjList& G, VertexData u, VertexData v)
{//�ж��Ƿ����u��v�������
	int i = LocateVertex(G, u);
	int j = LocateVertex(G, v);
	if (G->arcs[i][j].adj != GREAT) return true;
	return false;
}

void AddVertex(AdjList& G, VertexData u)
{//��ͼ�в�����u���������
	if (!ValidVertex(G, u)) G->vertex[G->vexnum++] = u;
	else cout << "���㡮" << u << "���Ѵ���!" << endl;
}

void AddEdge(AdjList& G, VertexData u, VertexData v, int adj, int money)
{//��������u��v������ߣ������ñߣ�ȨֵΪw
	if (!HasEdge(G, u, v)) {
		int i = LocateVertex(G, u);
		int j = LocateVertex(G, v);
		G->arcs[i][j].adj = adj;
		G->arcs[i][j].money = money;
	}
	else cout << "���ڶ��㡮" << u << "�������㡮" << v << "���ı�!" << endl;
}

void RemoveEdge(AdjList& G, VertexData u, VertexData v)
{//������u��v������ߣ���ȥ���ñ�
	if (HasEdge(G, u, v)) {
		int i = LocateVertex(G, u);
		int j = LocateVertex(G, v);
		G->arcs[i][j].adj = GREAT;
		G->arcs[i][j].money = GREAT;
	}
	else cout << "�����ڶ��㡮" << u << "�������㡮" << v << "���ı�!" << endl;
}

void Floyd(AdjList& G, Path& PathLength, Path& PathMoney)
{//�����·��
	int i, j, n = G->vexnum;
	int** L = new int* [n], ** M = new int* [n];
	for (int k = 0; k < n; k++) {
		L[k] = new int[n];
		M[k] = new int[n];
	}
	for(i=0;i<n;i++)//��ʼ��
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
	for (int k = 0; k < n; k++) {//�ͷſռ�
		delete[] L[k], M[k];
	}
	delete[] L, M;
}

void PrintLength(AdjList& G, VertexData u, VertexData v, Path PathLength)
{//��ӡu��v֮������·��·��
	int k;
	k = LocateVertex(G, u);
	while (k != LocateVertex(G, v)) {
		cout << G->vertex[k] << "->";
		k = PathLength[k][LocateVertex(G,v)];
	}
	cout << v << endl;
}

void PrintMoney(AdjList& G, VertexData u, VertexData v, Path PathMoney)
{//��ӡu��v֮������ٷ��õ�·��
	int k;
	k = LocateVertex(G, u);
	while (k != LocateVertex(G, v)) {
		cout << G->vertex[k] << "->";
		k = PathMoney[k][LocateVertex(G, v)];
	}
	cout << v << endl;
}

