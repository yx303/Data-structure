#include<iostream>
#include<cstring>
#include<random>
#include<ctime>
#include"Sort.h"

using namespace std;

int main() {
	KeyType InsSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };//由于排序后原数组顺序发生变化，故定义七个相同的数组
	KeyType SelectSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType BubbleSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType ShellSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType HeapSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType QKSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType MergeSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 }, MergeSort1_1[11];//辅助数组
	KeyType InsSort2[100001], SelectSort2[100001], BubbleSort2[100001], ShellSort2[100001], HeapSort2[100001], QKSort2[100001], MergeSort2[100001];
	KeyType MergeSort2_1[100001];//辅助数组
	uniform_int_distribution<int> u(0, 1000000);
	default_random_engine e(time(0));
	for (int i = 1; i < 100001; i++)
		InsSort2[i] = u(e) % 200000 + 1;
	memcpy(SelectSort2, InsSort2, sizeof(InsSort2));//同样定义七个数组
	memcpy(BubbleSort2, InsSort2, sizeof(InsSort2));
	memcpy(ShellSort2, InsSort2, sizeof(InsSort2));
	memcpy(HeapSort2, InsSort2, sizeof(InsSort2));
	memcpy(QKSort2, InsSort2, sizeof(InsSort2));
	memcpy(MergeSort2, InsSort2, sizeof(InsSort2));
	//10个数据
	cout << "**********10个数据**********" << endl;
	cout << "----------插入排序----------" << endl;
	InsSort(InsSort1, 11);
	cout << "--------简单选择排序--------" << endl;
	SelectSort(SelectSort1, 11);
	cout << "----------冒泡排序----------" << endl;
	BubbleSort(BubbleSort1, 11);
	cout << "----------希尔排序----------" << endl;
	ShellSort(ShellSort1, 11);
	cout << "----------堆排序----------" << endl;
	HeapSort(HeapSort1, 11);
	cout << "----------快速排序----------" << endl;
	Print(QKSort1, 11);
	QKSort(QKSort1, 11, 1, 10);
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	compare = 0; moving = 0;
	cout << "----------归并排序----------" << endl;
	Print(MergeSort1, 11);
	MergeSort(MergeSort1, MergeSort1_1, 1, 10, 11);
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	compare = 0; moving = 0;
	cout << endl;
	//100000个数据
	cout << "**********10万个数据**********" << endl;
	cout << "----------插入排序----------" << endl;
	InsSort(InsSort2, 100001);
	BubbleSort(InsSort2, 100001);//检测排序准确性
	cout << "--------简单选择排序--------" << endl;
	SelectSort(SelectSort2, 100001);
	BubbleSort(SelectSort2, 100001);//检测排序准确性
	cout << "----------冒泡排序----------" << endl;
	BubbleSort(BubbleSort2, 100001);
	BubbleSort(BubbleSort2, 100001);//检测排序准确性
	cout << "----------希尔排序----------" << endl;
	ShellSort(ShellSort2, 100001);
	BubbleSort(ShellSort2, 100001);//检测排序准确性
	cout << "----------堆排序----------" << endl;
	HeapSort(HeapSort2, 100001);
	BubbleSort(HeapSort2, 100001);//检测排序准确性
	cout << "----------快速排序----------" << endl;
	QKSort(QKSort2, 100001, 1, 100000);
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	BubbleSort(QKSort2, 100001);//检测排序准确性
	cout << "----------归并排序----------" << endl;
	MergeSort(MergeSort2, MergeSort2_1, 1, 100000, 100001);
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	BubbleSort(MergeSort2, 100001);//检测排序准确性
	return 0;
}