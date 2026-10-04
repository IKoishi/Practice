#include <stdio.h>

int func(int func_arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("func_arr[%d] = %d ==> ", i, func_arr[i]);
		func_arr[i] *= 100;
		printf("%d\n", func_arr[i]);
	}
	return 1;
}

void main() {
	int arr[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}	
	
	func(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}