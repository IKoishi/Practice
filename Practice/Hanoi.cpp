//#include <stdio.h>
//
//void hanoi(int num, char from, char buffer, char to) {
//
//	if (num > 1) {
//		hanoi(num - 1, from, to, buffer);
//		hanoi(1, from, buffer, to);
//		hanoi(num - 1, buffer, from, to);
//	}
//	else if (num == 1) {
//		printf("Move %c to %c\n", from, to);
//	}
//
//}
//
//int main() {
//	//汉诺塔层数num
//	int num = 5;
//
//	//起始区域A,缓存区域B,目标区域C
//	hanoi(num, 'A', 'B', 'C');
//	return 0;
//}