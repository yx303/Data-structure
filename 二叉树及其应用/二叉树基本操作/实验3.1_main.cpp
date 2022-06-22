#include<iostream>
#include<conio.h>
#include "windows.h"
#include "Tree.h"
using namespace std;

int main() {
	BiList root = new BiTree;
	int choice, len, LR;
	DataType p, c;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	//显示主菜单
	cout << "1-初始化二叉树" << endl;
	cout << "2-根据扩展先序遍历序列创建二叉链表" << endl;
	cout << "3-求二叉树的深度" << endl;
	cout << "4-插入结点" << endl;
	cout << "5-按中序遍历二叉树" << endl;
	cout << "6-输出叶结点" << endl;
	cout << "7-输出度为1的结点" << endl;
	cout << "8-输出度为2的结点" << endl;
	cout << "9-交换所有结点的左右孩子结点" << endl;
	cout << "10-按树状打印二叉树" << endl;
	cout << "11-销毁二叉树" << endl;
	cout << "101-退出" << endl;
	cout << "Enter choice:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choice;
	while (choice != 101) {
		switch (choice) {
		case 1://初始化二叉树
			InitBiTree(root);
			cout << "初始化完成！" << endl;
			system("pause");
			break;
		case 2://根据扩展先序遍历序列创建二叉链表
			cout << "请输入二叉树扩展先序遍历序列(用'.'表示空子树)<如:AB..CD...>:" << endl;
			CreateBiTree(root);
			system("pause");
			break;
		case 3://求二叉树深度
			len = BiTreeLength(root);
			cout << "该二叉树的深度为：" << len << endl;
			system("pause");
			break;
		case 4://插入结点
			cout << "请输入目标结点元素:";
			cin >> p;
			cout << "请输入插入结点元素:";
			cin >> c;
			cout << "请输入需要将该结点插做左或右孩子结点(偶数为左孩子、奇数为右孩子):";
			cin >> LR;
			InsertChild(root, p, LR, c);
			system("pause");
			break;
		case 5://按中序遍历二叉树
			cout << "中序遍历后的二叉树为:";
			DisplayBiTree(root);
			cout << endl;
			system("pause");
			break;
		case 6://输出叶结点
			cout << "叶结点为:";
			DisplayLeaf(root);
			cout << endl;
			system("pause");
			break;
		case 7://输出度为1的结点
			cout << "度为1的结点：";
			DisplayDegree1(root);
			cout << endl;
			system("pause");
			break;
		case 8://输出度为2的结点
			cout << "度为2的结点为:";
			DisplayDegree2(root);
			cout << endl;
			system("pause");
			break;
		case 9://交换所有结点的左右孩子结点
			SwopChild(root);
			cout << "交换完成！" << endl;
			system("pause");
			break;
		case 10://按树状打印二叉树
			PrintTree(root, 0);
			cout << "打印完成！" << endl;
			system("pause");
			break;
		case 11://销毁二叉树
			DestroyBiTree(root);
			cout << "已销毁！" << endl;
			system("pause");
			break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "Enter choice:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> choice;
	}
	return 0;
}