#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#define MaxVertices 30//��ඥ�����
#define GREAT 32768//��ʾ�����(��)
#include<string>
using std::string;

//ͼ������:DG-����ͼ��DN-��������UDG-����ͼ��UDN-������
enum GraphKind{DG,DN,UDG,UDN} ;
typedef string VertexData;//���趥������Ϊ�ַ���

typedef int Path[MaxVertices][MaxVertices];//������·��

struct ArcNode {
	int adj;//����Ȩͼ����1��0��ʾ�Ƿ�����,����Ȩͼ����ΪȨֵ����
	int money;//��ͨͼ�еķ���
};

struct AdjMatrix {
	VertexData vertex[MaxVertices];//��������
	ArcNode arcs[MaxVertices][MaxVertices];//�ڽӾ���
	int vexnum, arcnum;//�������ͻ���
	GraphKind kind;//ͼ�������־
};
typedef AdjMatrix* AdjList;

int LocateVertex(AdjList& G, VertexData v);//�󶥵�λ��
void CreateGraph(AdjList& G);//����һ��������
int getNumVertices(AdjList& G);//����ͼG�ж������
int getNumEdges(AdjList& G);//����ͼG�б���
bool ValidVertex(AdjList& G, VertexData v);//�ж϶���v�Ƿ���ͼ��
bool HasEdge(AdjList& G, VertexData u, VertexData v);//�ж��Ƿ����u��v�������
void AddVertex(AdjList& G, VertexData u);//��ͼ�в�����u���������
void AddEdge(AdjList& G, VertexData u, VertexData v, int adj,int money);//��������u��v�ıߣ������ñ�
void RemoveEdge(AdjList& G, VertexData u, VertexData v);//������u��v�ıߣ���ȥ���ñ�
void Floyd(AdjList& G, Path& PathLength, Path& PathMoney);//PathLength��PathMoney�ֱ��Ź���·�̺�·�ѵ����·��
void PrintLength(AdjList& G, VertexData u, VertexData v, Path PathLength);//��ӡu��v֮������·��·��
void PrintMoney(AdjList& G, VertexData u, VertexData v, Path PathMoney);//��ӡu��v֮������ٷ��õ�·��

#endif//GRAPH_H