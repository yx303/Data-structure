#pragma once
#ifndef TREE_H
#define TREE_H
#include<string>
typedef std::string DataType;
#define m 100

//����һ��������������
struct BiTree {
	DataType data;
	BiTree* LChild = NULL;
	BiTree* RChild = NULL;
};
typedef BiTree* BiList;

void InitBiTree(BiList Tree);//��ʼ��һ�ö�����
void DestroyBiTree(BiList Tree);//���ٶ�����
void CreateBiTree(BiList& Tree);//����һ�ö�����
int BiTreeLength(BiList Tree);//����������
BiList PostOrder(BiList& Tree, DataType p);//�������������,�ڶ�������Ѱ�ҽ��Ԫ��Ϊp�Ľ��
void InsertChild(BiList& Tree, DataType p, int LR, DataType c);//����LR����ż����c����p���Һ��ӻ�������
void DisplayBiTree(BiList Tree);//������н��,�ǵݹ��������
void DisplayLeaf(BiList Tree);//���Ҷ���
void DisplayDegree1(BiList Tree);//�����Ϊ1�Ľ��
void DisplayDegree2(BiList Tree);//�����Ϊ2�Ľ��
void SwopChild(BiList Tree);//�������н������Һ��ӽ��
void PrintTree(BiList Tree, int Layer);//����״��ӡ������


#endif //TREE_H