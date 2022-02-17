#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void Print(int a[], int n) {
	for (size_t i = 0; i < n; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

void swap(int& a, int& b) {
	int c;
	c = a;
	a = b;
	b = c;
}

void Bubble_Sort(int a[], int n) {
	bool flag;
	n = n - 1;
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = n; j > i; j--)
		{
			if (a[j-1] > a[j])
			{
				flag = true;
				swap(a[j-1], a[j]);
			}
		}
		if (flag == false)
		{
			return;
		}
	}
}

int Partition(int a[], int low, int high) {
	int pivot = a[low];//取出第一个元素作为枢轴
	while (low<high)
	{
		while (low < high && a[high] >= pivot) {
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low] <= pivot)
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}

void QuickSort(int a[], int low, int high) {
	if (low < high) {
		int pivotpos = Partition(a, low, high);//low,high分别为指针
		QuickSort(a, low, pivotpos - 1);
		QuickSort(a, pivotpos + 1, high);
	}
}

void InsertSort(int a[], int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			a[0] = a[i];
			for (j = i - 1; a[0] < a[j]; j--) {
				a[j + 1] = a[j];
			}
			a[j + 1] = a[0];
		}
	}
}

int main() {
	int a[10];
	int b[10];
	int c[11];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	memcpy(b, a, sizeof(a));
	memcpy(c+1, a, sizeof(a));


	Bubble_Sort(a, 10);
	Print(a, 10);

	QuickSort(b, 0, 9);
	Print(b,10);

	InsertSort(c, 10);
	Print(c+1, 10);

	return 0;
}