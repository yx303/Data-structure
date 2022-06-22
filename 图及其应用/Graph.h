#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#define MaxVertices 30//最多顶点个数
#define GREAT 32768//表示无穷大(∞)
#include<string>
using std::string;

//图的种类:DG-有向图，DN-有向网，UDG-无向图，UDN-无向网
enum GraphKind{DG,DN,UDG,UDN} ;
typedef string VertexData;//假设顶点数据为字符型

typedef int Path[MaxVertices][MaxVertices];//存放最短路径

struct ArcNode {
	int adj;//对无权图，用1或0表示是否相邻,对有权图，则为权值数字
	int money;//交通图中的费用
};

struct AdjMatrix {
	VertexData vertex[MaxVertices];//顶点向量
	ArcNode arcs[MaxVertices][MaxVertices];//邻接矩阵
	int vexnum, arcnum;//顶点数和弧数
	GraphKind kind;//图的种类标志
};
typedef AdjMatrix* AdjList;

int LocateVertex(AdjList& G, VertexData v);//求顶点位置
void CreateGraph(AdjList& G);//创建一个无向网
int getNumVertices(AdjList& G);//返回图G中顶点个数
int getNumEdges(AdjList& G);//返回图G中边数
bool ValidVertex(AdjList& G, VertexData v);//判断顶点v是否在图中
bool HasEdge(AdjList& G, VertexData u, VertexData v);//判断是否存在u到v的有向边
void AddVertex(AdjList& G, VertexData u);//若图中不存在u，则将其插入
void AddEdge(AdjList& G, VertexData u, VertexData v, int adj,int money);//若不存在u到v的边，则加入该边
void RemoveEdge(AdjList& G, VertexData u, VertexData v);//若存在u到v的边，则去除该边
void Floyd(AdjList& G, Path& PathLength, Path& PathMoney);//PathLength和PathMoney分别存放关于路程和路费的最短路径
void PrintLength(AdjList& G, VertexData u, VertexData v, Path PathLength);//打印u和v之间的最短路程路径
void PrintMoney(AdjList& G, VertexData u, VertexData v, Path PathMoney);//打印u和v之间的最少费用的路径

#endif//GRAPH_H