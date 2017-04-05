// horse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#define WIDTH 100
#define HEIGHT 100
int move(int board[WIDTH][HEIGHT], int sizeX, int sizeY, int x, int y, int count) {
	board[x][y] = count;
	if (count == sizeX*sizeY) {
		return 1;
	}
	if ((x >= 2) && (y >= 1) && (0 == board[x - 2][y - 1]) && (move(board, sizeX, sizeY, x - 2, y - 1, count + 1))) {                  //(-2,-1)
		return 1;
	}
	if ((x >= 1) && (y >= 2) && (0 == board[x - 1][y - 2]) && (move(board, sizeX, sizeY, x - 1, y - 2, count + 1))) {                  //(-1,-2)
		return 1;
	}
	if (((x + 1)<sizeX) && (y >= 2) && (0 == board[x + 1][y - 2]) && (move(board, sizeX, sizeY, x + 1, y - 2, count + 1))) {             //(1,-2)
		return 1;
	}
	if (((x + 2)<sizeX) && (y >= 1) && (0 == board[x + 2][y - 1]) && (move(board, sizeX, sizeY, x + 2, y - 1, count + 1))) {               //(2,-1)
		return 1;
	}
	if (((x + 2)<sizeX) && ((y + 1) < sizeY) && (0 == board[x + 2][y + 1]) && (move(board, sizeX, sizeY, x + 2, y + 1, count + 1))) {          //(2,1)
		return 1;
	}
	if (((x + 1)<sizeX) && ((y + 2) < sizeY) && (0 == board[x + 1][y + 2]) && (move(board, sizeX, sizeY, x + 1, y + 2, count + 1))) {         //(1,2)
		return 1;
	}
	if ((x >= 1) && ((y + 2) < sizeY) && (0 == board[x - 1][y + 2]) && (move(board, sizeX, sizeY, x - 1, y + 2, count + 1))) {           //(-1,2)
		return 1;
	}
	if ((x >= 2) && ((y + 1) < sizeY) && (0 == board[x - 2][y + 1]) && (move(board, sizeX, sizeY, x - 2, y + 1, count + 1))) {           //(-2,1)
		return 1;
	}

	board[x][y] = 0;
	return 0;
}

int main()
{
	int board[WIDTH][HEIGHT];
	int i, j, sizeX, sizeY, x, y, horse;


	printf("Enter the size of the field x ");
	scanf_s("%d", &sizeX);
	if ((0 >= sizeX) || (WIDTH < sizeX)) { //проверка переменной sizeW (по x)
		return -1;
	}

	printf("Enter the size of the field y ");
	scanf_s("%d", &sizeY);
	if ((0 >= sizeY) || (HEIGHT < sizeY)) { //проверка переменной sizeH (по y)
		return -1;
	}

	printf("\n Enter the coordinates of the horse");
	scanf_s("%d %d", &x, &y);
	if (((x < 0) || (y < 0)) || ((x >= sizeX) || (y >= sizeY))) { //проверка координат коня
		return -1;
	}

	for (i = 0; i < sizeY; i++) {
		for (j = 0; j < sizeX; j++) {
			board[j][i] = 0;
		}
	}


	horse = move(board, sizeX, sizeY, x, y, 1);
	if (horse) {
		for (i = 0; i < sizeY; i++) {
			for (j = 0; j < sizeX; j++) {
				printf("%4d", board[j][i]);
				
			}
			printf("\n");
		}
	}
	else
		printf("NO");
	return 0;
}