#include <stdio.h>

#define n 4

int Board[n][n] = { 0 };

int flag = 1;

void ChessBoard(int tr, int tc, int dr, int dc, int size) {
	if (size < 2) {
		return;
	}
	int t = flag++;
	size /= 2;
	if (dr < tr + size && dc < tc + size) {
		ChessBoard(tr, tc, dr, dc, size);
	}
	else {
		Board[tr + size - 1][tc + size - 1] = t;
		ChessBoard(tr, tc, tr + size - 1, tc + size - 1, size);
	}
	if (dr < tr + size && dc >= tc + size) {
		ChessBoard(tr, tc + size, dr, dc, size);
	}
	else {
		Board[tr+size-1][tc+size] = t;
		ChessBoard(tr, tc + size, tr + size - 1, tc + size, size);
	}
	if (dr >= tr + size && dc < tc + size) {
		ChessBoard(tr + size, tc, dr, dc, size);
	}
	else {
		Board[tr + size][tc + size - 1] = t;
		ChessBoard(tr + size, tc, tr + size, tc + size - 1, size);
	}
	if (dr >= tr + size && dc >= tc + size) {
		ChessBoard(tr + size, tc + size, dr, dc, size);
	}
	else {
		Board[tr + size][tc + size] = t;
		ChessBoard(tr + size, tc + size, tr + size, tc + size, size);
	}
}


int main() {
	ChessBoard(0, 0, 2, 2, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d", Board[i][j]);
		}
		printf("\n");
	}
	return 0;
}