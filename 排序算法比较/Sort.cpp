#include"Sort.h"
#include<iostream>
#include<cmath>
using namespace std;

unsigned long long int compare = 0;//比较次数
unsigned long long int moving = 0;//移动次数

void Print(KeyType r[], int n)
{//输出数组
	for (int i = 1; i < n; i++)
		cout << r[i] << " ";
	cout << endl;
}

void InsSort(KeyType r[], int n)
{//插入排序
	compare = 0;
	moving = 0;
	if (n < 101) Print(r, n);//若元素个数小于一百则输出原始顺序及每趟排序后的顺序，下同
	for (int i = 2; i < n; i++) {
		r[0] = r[i];
		moving++;
		int j = i - 1;
		while (r[0] < r[j]) {
			r[j + 1] = r[j];
			j--;
			compare++;
			moving++;
		}
		compare++;
		r[j + 1] = r[0];
		moving++;
		if (n < 101) Print(r, n);
	}
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	compare = 0;
	moving = 0;
}

void SelectSort(KeyType r[], int n)
{//简单选择排序
	if (n < 101) Print(r, n);
	for (int i = 1; i < n - 1; i++) {
		int k = i;
		for (int j = i + 1; j <= n - 1; j++) {
			if (r[j] < r[k]) k = j;
			compare++;
		}
		if (k != i) {
			int x = r[i];
			r[i] = r[k];
			r[k] = x;
			moving += 2;
		}
		if (n < 101) Print(r, n);
	}
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	compare = 0;
	moving = 0;
}

void BubbleSort(KeyType r[], int n)
{//冒泡排序
	compare = 0;
	moving = 0;
	if (n < 101) Print(r, n);
	bool change = true;
	for (int i = 1; i < n && change; i++) {
		change = false;
		for (int j = 1; j < n - i; j++) {
			if (r[j] > r[j + 1]) {
				int x = r[j];
				r[j] = r[j + 1];
				r[j + 1] = x;
				change = true;
				moving += 2;
			}
			compare++;
		}
		if (n < 101 && change == true) Print(r, n);
	}
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	compare = 0;
	moving = 0;
}

void ShellSort(KeyType r[], int n)
{//希尔排序
	compare = 0;
	moving = 0;
	if (n < 101) Print(r, n);
	int h = 1, j;
	int delta;//增量
	do {
		delta = n / pow(3, h++) + 1;
		for (int i = 1 + delta; i < n; i++) {
			if (r[i] < r[i - delta]) {
				r[0] = r[i];
				moving++;
				for (j = i - delta; j > 0 && r[0] < r[j]; j -= delta) {
					r[j + delta] = r[j];
					moving++;
				}
				r[j + delta] = r[0];
				moving++;
			}
			compare++;
		}
		if (n < 101) Print(r, n);
	} while (delta > 1);
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	compare = 0;
	moving = 0;
}

void sift(KeyType r[], int k, int m)
{//重建堆
	int root = r[k];//暂存根记录
	moving++;
	int i = k;
	int j = 2 * i;
	bool finished = false;
	while (j <= m && !finished) {
		if (r[j] < r[j + 1] && j + 1 <= m) j++;
		compare++;
		if (root >= r[j]) finished = true;
		else {
			r[i] = r[j];
			moving++;
			i = j;
			j = 2 * i;
		}
		compare++;
	}
	r[i] = root;
	moving++;
}

void crt_heap(KeyType r[], int n)
{//建初堆
	for (int i = n / 2; i >= 1; i--)
		sift(r, i, n);
}

void HeapSort(KeyType r[], int n)
{//堆排序
	if (n < 101) Print(r, n);
	crt_heap(r, n);
	for (int i = n - 1; i > 1; i--) {
		int x = r[1];//将堆顶记录和堆尾记录交换
		r[1] = r[i];
		r[i] = x;
		moving += 2;
		sift(r, 1, i - 1);
		if (n < 101) Print(r, n);
	}
	cout << "比较次数为:" << compare << " 移动次数为:" << moving << endl;
	compare = 0;
	moving = 0;
}

int QKPass(KeyType r[], int n, int left, int right)
{//一趟快速排序
	int base = r[left];//选择基准记录
	while (left < right) {
		while (left < right && r[right] >= base) {
			right--;
			compare++;
		}
		if (left < right) {
			compare++;
			r[left++] = r[right];
			moving++;
		}
		while (left < right && r[left] < base) {
			left++;
			compare++;
		}
		if (left < right) {
			compare++;
			r[right--] = r[left];
			moving++;
		}
	}
	r[left] = base;
	if (n < 101) Print(r, n);
	return left;
}

void QKSort(KeyType r[], int n, int left, int right)
{//快速排序
	if (left >= right) return;
	int pos = QKPass(r, n, left, right);
	QKSort(r, n, left, pos - 1);
	QKSort(r, n, pos + 1, right);
}

void _Merge(KeyType r[], int low, int mid, int high, KeyType temp[], int n)
{//归并排序的“治”
	int left = low;
	int right = mid + 1;
	int k = low;
	while (left <= mid && right <= high) {
		if (r[left] > r[right])
			temp[k++] = r[right++];
		else
			temp[k++] = r[left++];
		compare++;
		moving++;
	}
	while (left <= mid) {
		temp[k++] = r[left++];
		moving++;
	}
	while (right <= high) {
		temp[k++] = r[right++];
		moving++;
	}
	for (int i = low; i <= high; i++) {
		r[i] = temp[i];
		moving++;
	}
	if (n < 101) Print(r, n);
}

void MergeSort(KeyType r[], KeyType temp[], int low, int high, int n)
{//归并排序
	//出口条件
	if (low >= high) return;
	else {
		int mid = low + (high - low) / 2;
		//分
		MergeSort(r, temp, low, mid, n);
		MergeSort(r, temp, mid + 1, high, n);
		//治
		_Merge(r, low, mid, high, temp, n);
	}
}