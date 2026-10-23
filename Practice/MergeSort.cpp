#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int temp[20];

void Merge(int a[], int low, int m, int high) {
	int i = low, j = m + 1, k = low;
	while (1) {
		if (i > m || j > high) {
			break;
		}
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else if (a[i] > a[j]) {
			temp[k++] = a[j++];
		}
	}
	while (i <= m) temp[k++] = a[i++];
	while (j <= high) temp[k++] = a[j++];
	for (i = low; i <= high; i++) {
		a[i] = temp[i];
	}
}

void MergeSort(int a[], int low, int high) {
	if (low < high) {
		int m = (low + high) / 2;
		MergeSort(a, low, m);
		MergeSort(a, m + 1, high);
		Merge(a, low, m, high);
	}
}

void main() {
	SetConsoleOutputCP(CP_UTF8);

	int a[20];
	int n = 0;

	printf("问题规模:\n");
	scanf("%d", &n);
	printf("输入%d个数组元素:\n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("输入数组如下:\n");
	for (int i = 0; i < n; i++) {
		printf("%3d", a[i]);
	}

	MergeSort(a, 0, n-1);
	printf("\n归并排序后:\n");
	for (int i = 0; i < n; i++) {
		printf("%3d", a[i]);
	}
}