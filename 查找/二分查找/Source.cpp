#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define ElemType int

int Binary_Search(ElemType e, ElemType* arr, int n) {
	int low = 0, high = n - 1, mid;//记录数组下标
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == e) {
			return mid;
		}
		else if (e < arr[mid]) {
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
}

int main() {
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i = Binary_Search(7, arr, 10);
	printf("%d\n", i);
}