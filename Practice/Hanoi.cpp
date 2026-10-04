#include <stdio.h>

void hanoi(int num, char from, char buffer, char to) {

	if (num > 1) {
		hanoi(num - 1, from, to, buffer);
		hanoi(1, from, buffer, to);
		hanoi(num - 1, buffer, from, to);
	}
	else if (num == 1) {
		printf("Move %c to %c\n", from, to);
	}

}

int main() {
	int num = 5;
	hanoi(num, 'A', 'B', 'C');
	return 0;
}