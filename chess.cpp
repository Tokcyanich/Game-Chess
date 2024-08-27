#include <stdlib.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

struct figure_move
{
	// откуда?
	int x; // x это индекс массива i
	int y; // y это индекс массива j
	int number_figure; // что за фигура

	// куда?
	int where_x; // x это индекс массива i
	int where_y; // y это индекс массива j

	// koordi vizual
	int x1, y1, x2, y2;
	int	allowe = 0;
	// король не ходил для рокировки
	int b_one_move_king = 0, w_one_move_king = 0;
	// ладья не ходила для локировки
	int b_one_move_rook1 = 0, b_one_move_rook2 = 0, w_one_move_rook1 = 0, w_one_move_rook2 = 0;
};

const int  w = 1200; // Длина окна
const int  h = 800; // Высота окна 
void outputv_mass(int chess_boardv[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf(" %3d", chess_boardv[i][j]);
		}
		printf("\n\n");
	}
}
void chess_board(SDL_Renderer* renderer) // 	Функция для рисования шахматной доски
{
	int x = 0;
	int y = 0;
	int size_square = 50;
	for (int i = 0; i < 64; i++)
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		if (i % 8 == 0)
		{
			// рисуем 1 строку и по высоте +50, а x обнуляем
			y += size_square;
			x = 0;
			SDL_Rect rect = { x += size_square,y,size_square,size_square };
			SDL_RenderDrawRect(renderer, &rect);
		}
		else
		{
			SDL_Rect rect = { x += size_square,y,size_square,size_square };
			SDL_RenderDrawRect(renderer, &rect);
		}
	}
	SDL_RenderPresent(renderer);
}
void ris_figure_start(SDL_Renderer* renderer, SDL_Texture* b_bishop1, SDL_Texture* b_bishop2, SDL_Texture* b_night1,
	SDL_Texture* b_night2, SDL_Texture* b_king, SDL_Texture* b_queen, SDL_Texture* b_rook1,
	SDL_Texture* b_rook2, SDL_Texture* w_bishop1, SDL_Texture* w_bishop2, SDL_Texture* w_rook1, SDL_Texture* w_king,
	SDL_Texture* w_rook2, SDL_Texture* w_night1, SDL_Texture* w_night2, SDL_Texture* b_pawn1, SDL_Texture* b_pawn2,
	SDL_Texture* b_pawn3, SDL_Texture* b_pawn4, SDL_Texture* b_pawn5,
	SDL_Texture* b_pawn6, SDL_Texture* b_pawn7, SDL_Texture* b_pawn8, SDL_Texture* w_pawn1, SDL_Texture* w_pawn2,
	SDL_Texture* w_pawn3, SDL_Texture* w_pawn4, SDL_Texture* w_pawn5,
	SDL_Texture* w_pawn6, SDL_Texture* w_pawn7, SDL_Texture* w_pawn8, SDL_Texture* w_queen, struct figure_move* move)
{
	
	
	SDL_Rect b_b1 = { 150, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_bishop1, NULL, &b_b1);

	SDL_Rect b_b2 = { 300, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_bishop2, NULL, &b_b2);

	SDL_Rect b_k = { 250, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_king, NULL, &b_k);

	SDL_Rect b_n1 = { 100, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_night1, NULL, &b_n1);

	SDL_Rect b_n2 = { 350, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_night2, NULL, &b_n2);

	SDL_Rect b_p1 = { 50, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn2, NULL, &b_p1);

	SDL_Rect b_p2 = { 100, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn2, NULL, &b_p2);

	SDL_Rect b_p3 = { 150, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn3, NULL, &b_p3);

	SDL_Rect b_p4 = { 200, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn4, NULL, &b_p4);

	SDL_Rect b_p5 = { 250, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn5, NULL, &b_p5);

	SDL_Rect b_p6 = { 300, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn6, NULL, &b_p6);

	SDL_Rect b_p7 = { 350, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn7, NULL, &b_p7);

	SDL_Rect b_p8 = { 400, 100, 50, 50 };
	SDL_RenderCopy(renderer, b_pawn8, NULL, &b_p8);

	SDL_Rect b_q = { 200, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	SDL_Rect b_r1 = { 50, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_rook1, NULL, &b_r1);

	SDL_Rect b_r2 = { 400, 50, 50, 50 };
	SDL_RenderCopy(renderer, b_rook2, NULL, &b_r2);

	SDL_Rect w_b1 = { 150, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_bishop1, NULL, &w_b1);

	SDL_Rect w_b2 = { 300, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_bishop2, NULL, &w_b2);

	SDL_Rect w_k = { 250, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_king, NULL, &w_k);

	SDL_Rect w_n1 = { 100, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_night1, NULL, &w_n1);

	SDL_Rect w_n2 = { 350, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_night2, NULL, &w_n2);

	SDL_Rect w_p1 = { 50, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn1, NULL, &w_p1);

	SDL_Rect w_p2 = { 100, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn2, NULL, &w_p2);

	SDL_Rect w_p3 = { 150, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn3, NULL, &w_p3);

	SDL_Rect w_p4 = { 200, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn4, NULL, &w_p4);

	SDL_Rect w_p5 = { 250, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn5, NULL, &w_p5);

	SDL_Rect w_p6 = { 300, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn6, NULL, &w_p6);

	SDL_Rect w_p7 = { 350, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn7, NULL, &w_p7);

	SDL_Rect w_p8 = { 400, 350, 50, 50 };
	SDL_RenderCopy(renderer, w_pawn8, NULL, &w_p8);

	SDL_Rect w_q = { 200, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	SDL_Rect w_r1 = { 50, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_rook1, NULL, &w_r1);

	SDL_Rect w_r2 = { 400, 400, 50, 50 };
	SDL_RenderCopy(renderer, w_rook2, NULL, &w_r2);

}
void ris_figure(SDL_Renderer* renderer, SDL_Texture* b_bishop1, SDL_Texture* b_bishop2, SDL_Texture* b_night1,
	SDL_Texture* b_night2, SDL_Texture* b_king, SDL_Texture* b_queen, SDL_Texture* b_rook1,
	SDL_Texture* b_rook2, SDL_Texture* w_bishop1, SDL_Texture* w_bishop2, SDL_Texture* w_rook1, SDL_Texture* w_king,
	SDL_Texture* w_rook2, SDL_Texture* w_night1, SDL_Texture* w_night2, SDL_Texture* b_pawn1, SDL_Texture* b_pawn2,
	SDL_Texture* b_pawn3, SDL_Texture* b_pawn4, SDL_Texture* b_pawn5,
	SDL_Texture* b_pawn6, SDL_Texture* b_pawn7, SDL_Texture* b_pawn8, SDL_Texture* w_pawn1, SDL_Texture* w_pawn2,
	SDL_Texture* w_pawn3, SDL_Texture* w_pawn4, SDL_Texture* w_pawn5,
	SDL_Texture* w_pawn6, SDL_Texture* w_pawn7, SDL_Texture* w_pawn8, SDL_Texture* w_queen, struct figure_move* move,
	int* x_b_b1, int* y_b_b1, int* x_b_b2, int* y_b_b2, int* x_b_k, int* y_b_k, int* x_b_n1, int* y_b_n1,
	int* x_b_n2, int* y_b_n2, int* x_b_p1, int* y_b_p1, int* x_b_p2, int* y_b_p2,
	int* x_b_p3, int* y_b_p3, int* x_b_p4, int* y_b_p4, int* x_b_p5, int* y_b_p5,
	int* x_b_p6, int* y_b_p6, int* x_b_p7, int* y_b_p7, int* x_b_p8, int* y_b_p8,
	int* x_b_q, int* y_b_q, int* x_b_r1, int* y_b_r1, int* x_b_r2, int* y_b_r2,
	int* x_w_b1, int* y_w_b1, int* x_w_b2, int* y_w_b2, int* x_w_k, int* y_w_k, int* x_w_n1, int* y_w_n1,
	int* x_w_n2, int* y_w_n2, int* x_w_p1, int* y_w_p1, int* x_w_p2, int* y_w_p2,
	int* x_w_p3, int* y_w_p3, int* x_w_p4, int* y_w_p4, int* x_w_p5, int* y_w_p5,
	int* x_w_p6, int* y_w_p6, int* x_w_p7, int* y_w_p7, int* x_w_p8, int* y_w_p8,
	int* x_w_q, int* y_w_q, int* x_w_r1, int* y_w_r1, int* x_w_r2, int* y_w_r2)
{
	// white_figures
	if (move->number_figure == -3 && move->y1 == *y_b_b1 && move->x1 == *x_b_b1)
	{
		*x_b_b1 = move->x2;
		*y_b_b1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_b1 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_bishop1, NULL, &b_b1);
	}

	if (move->number_figure == -3 && move->y1 == *y_b_b2 && move->x1 == *x_b_b2)
	{
		*x_b_b2 = move->x2;
		*y_b_b2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_b2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_bishop2, NULL, &b_b2);
	}

	if (move->number_figure == -10 && move->y1 == *y_b_k && move->x1 == *x_b_k)
	{
		*x_b_k = move->x2;
		*y_b_k = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_k = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_king, NULL, &b_k);
		if (move->x2 == 150 && move->b_one_move_rook1==0)
		{
			*x_b_r1 = 200;
			*y_b_r1 = 50;
			SDL_Rect del = { 50, 50, 50, 50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del);
			SDL_Rect b_r1 = { 200, 50, 50, 50 };
			SDL_RenderCopy(renderer, b_rook1, NULL, &b_r1);
			move->b_one_move_rook1 = 1;
		}
		else if (move->x2 == 350 && move->b_one_move_rook2 == 0)
		{
			*x_b_r2 = 300;
			*y_b_r2 = 50;
			SDL_Rect del = { 400, 50, 50, 50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del);
			SDL_Rect b_r2 = { 300, 50, 50, 50 };
			SDL_RenderCopy(renderer, b_rook2, NULL, &b_r2);
			move->b_one_move_rook2 = 1;
		}
	}

	if (move->number_figure == -4 && move->y1 == *y_b_n1 && move->x1 == *x_b_n1)
	{
		*x_b_n1 = move->x2;
		*y_b_n1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_n1 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_night1, NULL, &b_n1);
	}

	if (move->number_figure == -4 && move->y1 == *y_b_n2 && move->x1 == *x_b_n2)
	{
		*x_b_n2 = move->x2;
		*y_b_n2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_n2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_night2, NULL, &b_n2);
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p1 && move->x1 == *x_b_p1)
	{
		*x_b_p1 = move->x2;
		*y_b_p1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p1 = { move->x2, move->y2,50,50 };
		SDL_RenderCopy(renderer, b_pawn1, NULL, &b_p1);
		if (*y_b_p1 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p2 && move->x1 == *x_b_p2)
	{
		*x_b_p2 = move->x2;
		*y_b_p2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_pawn2, NULL, &b_p2);
		if (*y_b_p2 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p3 && move->x1 == *x_b_p3)
	{
		*x_b_p3 = move->x2;
		*y_b_p3 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p3 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_pawn3, NULL, &b_p3);
		if (*y_b_p3 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p4 && move->x1 == *x_b_p4)
	{
		*x_b_p4 = move->x2;
		*y_b_p4 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p4 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_pawn4, NULL, &b_p4);
		if (*y_b_p4 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p5 && move->x1 == *x_b_p5)
	{
		*x_b_p5 = move->x2;
		*y_b_p5 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p5 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_pawn5, NULL, &b_p5);
		if (*y_b_p5 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p6 && move->x1 == *x_b_p6)
	{
		*x_b_p6 = move->x2;
		*y_b_p6 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p6 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_pawn6, NULL, &b_p6);
		if (*y_b_p6 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p7 && move->x1 == *x_b_p7)
	{
		*x_b_p7 = move->x2;
		*y_b_p7 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p7 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_pawn7, NULL, &b_p7);
		if (*y_b_p7 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -1 && move->y1 == *y_b_p8 && move->x1 == *x_b_p8)
	{
		*x_b_p8 = move->x2;
		*y_b_p8 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_p8 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_pawn8, NULL, &b_p8);
		if (*y_b_p8 == 400)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect b_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
		}
	}

	if (move->number_figure == -9 && move->y1 == *y_b_q && move->x1 == *x_b_q)
	{
		*x_b_q = move->x2;
		*y_b_q = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);
	}
	else if (move->number_figure == -9 && *y_b_p1 == move->y1)
	{
		*x_b_p1 = move->x2;
		*y_b_p1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}
	else if (move->number_figure == -9 && *y_b_p2 == move->y1)
	{
		*x_b_p2 = move->x2;
		*y_b_p2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}
	else if (move->number_figure == -9 && *y_b_p3 == move->y1)
	{
		*x_b_p3 = move->x2;
		*y_b_p3 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}
	else if (move->number_figure == -9 && *y_b_p4 == move->y1)
	{
		*x_b_p4 = move->x2;
		*y_b_p4 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}
	else if (move->number_figure == -9 && *y_b_p5 == move->y1)
	{
		*x_b_p5 = move->x2;
		*y_b_p5 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}
	else if (move->number_figure == -9 && *y_b_p6 == move->y1)
	{
		*x_b_p6 = move->x2;
		*y_b_p6 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}
	else if (move->number_figure == -9 && *y_b_p7 == move->y1)
	{
		*x_b_p7 = move->x2;
		*y_b_p7 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}
	else if (move->number_figure == -9 && *y_b_p8 == move->y1)
	{
		*x_b_p8 = move->x2;
		*y_b_p8 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_queen, NULL, &b_q);

	}

	if (move->number_figure == -5 && move->y1 == *y_b_r1 && move->x1 == *x_b_r1)
	{
		*x_b_r1 = move->x2;
		*y_b_r1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_r1 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_rook1, NULL, &b_r1);
		move->b_one_move_rook1 = 1;
	}

	if (move->number_figure == -5 && move->y1 == *y_b_r2 && move->x1 == *x_b_r2)
	{
		*x_b_r2 = move->x2;
		*y_b_r2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect b_r2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, b_rook1, NULL, &b_r2);
		move->b_one_move_rook2 = 1;
	}

	// white figures
	if (move->number_figure == 3 && move->y1 == *y_w_b1 && move->x1 == *x_w_b1)
	{
		*x_w_b1 = move->x2;
		*y_w_b1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_b1 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_bishop1, NULL, &w_b1);
	}

	if (move->number_figure == 3 && move->y1 == *y_w_b2 && move->x1 == *x_w_b2)
	{
		*x_w_b2 = move->x2;
		*y_w_b2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_b2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_bishop2, NULL, &w_b2);
	}

	if (move->number_figure == 10 && move->y1 == *y_w_k && move->x1 == *x_w_k)
	{
		*x_w_k = move->x2;
		*y_w_k = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_k = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_king, NULL, &w_k);
		if (move->x2 == 150 && move->w_one_move_rook1 == 0)
		{
			*x_b_r1 = 200;
			*y_b_r1 = 400;
			SDL_Rect del = { 50, 400, 50, 50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del);
			SDL_Rect w_r1 = { 200, 400, 50, 50 };
			SDL_RenderCopy(renderer, w_rook1, NULL, &w_r1);
			move->w_one_move_rook1 = 1;
		}
		else if (move->x2 == 350 && move->w_one_move_rook2 == 0)
		{
			*x_b_r2 = 300;
			*y_b_r2 = 400;
			SDL_Rect del = { 400, 400, 50, 50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del);
			SDL_Rect w_r2 = { 300, 400, 50, 50 };
			SDL_RenderCopy(renderer, w_rook2, NULL, &w_r2);
			move->w_one_move_rook2 = 1;
		}
	}

	if (move->number_figure == 4 && move->y1 == *y_w_n1 && move->x1 == *x_w_n1)
	{
		*x_w_n1 = move->x2;
		*y_w_n1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_n1 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_night1, NULL, &w_n1);
	}

	if (move->number_figure == 4 && move->y1 == *y_w_n2 && move->x1 == *x_w_n2)
	{
		*x_w_n2 = move->x2;
		*y_w_n2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_n2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_night2, NULL, &w_n2);
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p1 && move->x1 == *x_w_p1)
	{
		*x_w_p1 = move->x2;
		*y_w_p1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p1 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn1, NULL, &w_p1);
		if (*y_w_p1 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p2 && move->x1 == *x_w_p2)
	{
		*x_w_p2 = move->x2;
		*y_w_p2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn2, NULL, &w_p2);
		if (*y_w_p2 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p3 && move->x1 == *x_w_p3)
	{
		*x_w_p3 = move->x2;
		*y_w_p3 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p3 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn3, NULL, &w_p3);
		if (*y_w_p3 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p4 && move->x1 == *x_w_p4)
	{
		*x_w_p4 = move->x2;
		*y_w_p4 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p4 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn4, NULL, &w_p4);
		if (*y_w_p4 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p5 && move->x1 == *x_w_p5)
	{
		*x_w_p5 = move->x2;
		*y_w_p5 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p5 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn5, NULL, &w_p5);
		if (*y_w_p5 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p6 && move->x1 == *x_w_p6)
	{
		*x_w_p6 = move->x2;
		*y_w_p6 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p6 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn6, NULL, &w_p6);
		if (*y_w_p6 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p7 && move->x1 == *x_w_p7)
	{
		*x_w_p7 = move->x2;
		*y_w_p7 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p7 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn7, NULL, &w_p7);
		if (*y_w_p8 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 1 && move->y1 == *y_w_p8 && move->x1 == *x_w_p8)
	{
		*x_w_p8 = move->x2;
		*y_w_p8 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_p8 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_pawn8, NULL, &w_p8);
		if (*y_w_p8 == 50)
		{
			SDL_Rect del1 = { move->x2,move->y2,50,50 };
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderFillRect(renderer, &del1);
			SDL_Rect w_q = { move->x2, move->y2,50,50 };
			SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
		}
	}

	if (move->number_figure == 9 && move->y1 == *y_w_q && move->x1 == *x_w_q)
	{
		*x_w_q = move->x2;
		*y_w_q = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);
	}
	else if (move->number_figure == 9 && *y_w_p1 == move->y1)
	{
		*x_w_p1 = move->x2;
		*y_w_p1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}
	else if (move->number_figure == 9 && *y_w_p2 == move->y1)
	{
		*x_w_p2 = move->x2;
		*y_w_p2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}
	else if (move->number_figure == 9 && *y_w_p3 == move->y1)
	{
		*x_w_p3 = move->x2;
		*y_w_p3 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}
	else if (move->number_figure == 9 && *y_w_p4 == move->y1)
	{
		*x_w_p4 = move->x2;
		*y_w_p4 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}
	else if (move->number_figure == 9 && *y_w_p5 == move->y1)
	{
		*x_w_p5 = move->x2;
		*y_w_p5 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}
	else if (move->number_figure == 9 && *y_w_p6 == move->y1)
	{
		*x_w_p6 = move->x2;
		*y_w_p6 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}
	else if (move->number_figure == 9 && *y_w_p7 == move->y1)
	{
		*x_w_p7 = move->x2;
		*y_w_p7 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}
	else if (move->number_figure == 9 && *y_w_p8 == move->y1)
	{
		*x_w_p8 = move->x2;
		*y_w_p8 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_q = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_queen, NULL, &w_q);

	}

	if (move->number_figure == 5 && move->y1 == *y_w_r1 && move->x1 == *x_w_r1)
	{
		*x_w_r1 = move->x2;
		*y_w_r1 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_r1 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_rook1, NULL, &w_r1);
		move->w_one_move_rook1 = 1;
	}

	if (move->number_figure == 5 && move->y1 == *y_w_r2 && move->x1 == *x_w_r2)
	{
		*x_w_r2 = move->x2;
		*y_w_r2 = move->y2;
		SDL_Rect del = { move->x1, move->y1, 50, 50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del);
		SDL_Rect del1 = { move->x2,move->y2,50,50 };
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &del1);
		SDL_Rect w_r2 = { move->x2, move->y2, 50, 50 };
		SDL_RenderCopy(renderer, w_rook1, NULL, &w_r2);
		move->w_one_move_rook2 = 1;
	}
	SDL_RenderPresent(renderer);
}
void otkuda(int chess_boardv[8][8], struct figure_move *move, int x, int y)
{
	// koordi x
	if (x > 50 && x < 100)
	{
		move->x = 0;
		move->x1 = 50;
	}
	else if (x > 100 && x < 150)
	{
		move->x = 1;
		move->x1 = 100;
	}
	else if (x > 150 && x < 200)
	{
		move->x = 2;
		move->x1 = 150;
	}
	else if (x > 200 && x < 250)
	{
		move->x = 3;
		move->x1 = 200;
	}
	else if (x > 250 && x < 300)
	{
		move->x = 4;
		move->x1 = 250;
	}
	else if (x > 300 && x < 350)
	{
		move->x = 5;
		move->x1 = 300;
	}
	else if (x > 350 && x < 400)
	{
		move->x = 6;
		move->x1 = 350;
	}
	else if (x > 400 && x < 450)
	{
		move->x = 7;
		move->x1 = 400;
	}

	// koordi y
	if (y > 50 && y < 100)
	{
		move->y = 0;
		move->y1 = 50;
	}
	else if (y > 100 && y < 150)
	{
		move->y = 1;
		move->y1 = 100;
	}
	else if (y > 150 && y < 200)
	{
		move->y = 2;
		move->y1 = 150;
	}
	else if (y > 200 && y < 250)
	{
		move->y = 3;
		move->y1 = 200;
	}
	else if (y > 250 && y < 300)
	{
		move->y = 4;
		move->y1 = 250;
	}
	else if (y > 300 && y < 350)
	{
		move->y = 5;
		move->y1 = 300;
	}
	else if (y > 350 && y < 400)
	{
		move->y = 6;
		move->y1 = 350;
	}
	else if (y > 400 && y < 450)
	{
		move->y = 7;
		move->y1 = 400;
	}
	move->number_figure = chess_boardv[move->y][move->x];

	// pawn
	if (move->number_figure == -1)
	{
		if (chess_boardv[move->y + 1][move->x] == 0 || chess_boardv[move->y + 1][move->x+1] >=0 
			|| chess_boardv[move->y + 1][move->x - 1] >= 0)
		{
			move->allowe = 1;
		}
	}
	else if (move->number_figure == 1)
	{
		if (chess_boardv[move->y - 1][move->x] == 0|| chess_boardv[move->y - 1][move->x + 1] <= 0
			|| chess_boardv[move->y - 1][move->x - 1] <= 0)
		{
			move->allowe = 1;
		}
	}

	// bishop
	if (move->number_figure == -3)
	{
		if (chess_boardv[move->y + 1][move->x + 1] >= 0 || chess_boardv[move->y - 1][move->x + 1] >= 0
			|| chess_boardv[move->y + 1][move->x - 1] >= 0 || chess_boardv[move->y - 1][move->x - 1] >= 0)
		{
			move->allowe = 1;
		}
	} 
	else if (move->number_figure == 3)
	{
		if (chess_boardv[move->y + 1][move->x + 1] <= 0 || chess_boardv[move->y - 1][move->x + 1] <= 0
			|| chess_boardv[move->y + 1][move->x - 1] <= 0 || chess_boardv[move->y - 1][move->x - 1] <= 0)
		{
			move->allowe = 1;
		}
	}

	// knight
	if (move->number_figure == -4)
	{
		if (chess_boardv[move->y+2][move->x+1]>=0 || chess_boardv[move->y + 2][move->x - 1] >= 0 || chess_boardv[move->y - 2][move->x - 1] >= 0
			|| chess_boardv[move->y + 2][move->x + 1] >= 0 || chess_boardv[move->y + 1][move->x - 2] >= 0 || chess_boardv[move->y + 1][move->x + 2] >= 0
			|| chess_boardv[move->y - 1][move->x - 2] >= 0 || chess_boardv[move->y - 1][move->x + 2] >= 0)
		{
			move->allowe = 1;
		}
	}
	else if (move->number_figure == 4)
	{
		if (chess_boardv[move->y + 2][move->x + 1] <= 0 || chess_boardv[move->y + 2][move->x - 1] <= 0 || chess_boardv[move->y - 2][move->x - 1] <= 0
			|| chess_boardv[move->y + 2][move->x + 1] <= 0 || chess_boardv[move->y + 1][move->x - 2] <= 0 || chess_boardv[move->y + 1][move->x + 2] <= 0
			|| chess_boardv[move->y - 1][move->x - 2] <= 0 || chess_boardv[move->y - 1][move->x + 2] <= 0)
		{
			move->allowe = 1;
		}
	}

	// rook
	if (move->number_figure == -5)
	{
		if (chess_boardv[move->x + 1][move->y] >= 0 || chess_boardv[move->x - 1][move->y] >= 0
			|| chess_boardv[move->x][move->y + 1] >= 0 || chess_boardv[move->x][move->y - 1] >= 0)
		{
			move->allowe = 1;
		}
	}
	else if (move->number_figure == 5)
	{
		if (chess_boardv[move->y + 1][move->x] <= 0 || chess_boardv[move->y - 1][move->x] <= 0
			|| chess_boardv[move->y][move->x + 1] <= 0 || chess_boardv[move->y][move->x - 1] <= 0)
		{
			move->allowe = 1;
		}
	}

	// queen
	if (move->number_figure == -9)
	{
		if (chess_boardv[move->y + 1][move->x] >= 0 || chess_boardv[move->y - 1][move->x] >= 0
			|| chess_boardv[move->y + 1][move->x + 1] >= 0 || chess_boardv[move->y - 1][move->x + 1] >= 0
			|| chess_boardv[move->y + 1][move->x - 1] >= 0 || chess_boardv[move->y - 1][move->x - 1] >= 0
			|| chess_boardv[move->y][move->x + 1] >= 0 || chess_boardv[move->y][move->x - 1] >= 0)
		{
			move->allowe = 1;
		}
	}
	else if (move->number_figure == 9)
	{
		if (chess_boardv[move->y + 1][move->x] <= 0 || chess_boardv[move->y - 1][move->x] <= 0
			|| chess_boardv[move->x + 1][move->y + 1] <= 0 || chess_boardv[move->x - 1][move->y + 1] <= 0
			|| chess_boardv[move->y + 1][move->x - 1] <= 0 || chess_boardv[move->y - 1][move->x - 1] <= 0
			|| chess_boardv[move->y][move->x + 1] <= 0 || chess_boardv[move->y][move->x - 1] <= 0)
		{
			move->allowe = 1;
		}
	}

	// king
	if (move->number_figure == -10)
	{
		if (chess_boardv[move->y+1][move->x] >= 0 || chess_boardv[move->y - 1][move->x] >= 0 
			|| chess_boardv[move->y + 1][move->x+1] >= 0 || chess_boardv[move->y - 1][move->x+1] >= 0
			|| chess_boardv[move->y + 1][move->x-1] >= 0 || chess_boardv[move->y - 1][move->x-1] >= 0
			|| chess_boardv[move->y ][move->x+1] >= 0 || chess_boardv[move->y][move->x-1] >= 0)
		{
			move->allowe = 1;
		}
	} 
	else if (move->number_figure == 10)
	{
		if (chess_boardv[move->y + 1][move->x] <= 0 || chess_boardv[move->y - 1][move->x] <= 0
			|| chess_boardv[move->y + 1][move->x + 1] <= 0 || chess_boardv[move->y - 1][move->x + 1] <= 0
			|| chess_boardv[move->y + 1][move->x - 1] <= 0 || chess_boardv[move->y - 1][move->x - 1] <= 0
			|| chess_boardv[move->y][move->x + 1] <= 0 || chess_boardv[move->y][move->x - 1] <= 0)
		{
			move->allowe = 1;
		}
	}
}
void kuda(int chess_boardv[8][8], struct figure_move *move,int x,int y)
{
	// koordi x
	if (x > 50 && x < 100)
	{
		move->where_x = 0;
		move->x2 = 50;
	}
	else if (x > 100 && x < 150)
	{
		move->where_x = 1;
		move->x2 = 100;
	}
	else if (x > 150 && x < 200)
	{
		move->where_x = 2;
		move->x2 = 150;
	}
	else if (x > 200 && x < 250)
	{
		move->where_x = 3;
		move->x2 = 200;
	}
	else if (x > 250 && x < 300)
	{
		move->where_x = 4;
		move->x2 = 250;
	}
	else if (x > 300 && x < 350)
	{
		move->where_x = 5;
		move->x2 = 300;
	}
	else if (x > 350 && x < 400)
	{
		move->where_x = 6;
		move->x2 = 350;
	}
	else if (x > 400 && x < 450)
	{
		move->where_x = 7;
		move->x2 = 400;
	}

	// koordi y
	if (y > 50 && y < 100)
	{
		move->where_y = 0;
		move->y2 = 50;
	}
	else if (y > 100 && y < 150)
	{
		move->where_y = 1;
		move->y2 = 100;
	}
	else if (y > 150 && y < 200)
	{
		move->where_y = 2;
		move->y2 = 150;
	}
	else if (y > 200 && y < 250)
	{
		move->where_y = 3;
		move->y2 = 200;
	}
	else if (y > 250 && y < 300)
	{
		move->where_y = 4;
		move->y2 = 250;
	}
	else if (y > 300 && y < 350)
	{
		move->where_y = 5;
		move->y2 = 300;
	}
	else if (y > 350 && y < 400)
	{
		move->where_y = 6;
		move->y2 = 350;
	}
	else if (y > 400 && y < 450)
	{
		move->where_y = 7;
		move->y2 = 400;
	}
	// pawn
	if (move->number_figure == -1) //  black_pawn
	{
		if (move->where_y == 7)
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = -9;
		}
		else if (move->y == 1 && move->where_y == 3 && chess_boardv[move->where_y][move->where_x]==0 
			&& chess_boardv[move->where_y-1][move->where_x] == 0 && move->where_x == move->x) // 2 хода вперед
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
		}
		else if ((move->where_x == move->x + 1 || move->where_x == move->x - 1) && (move->where_y-move->y==1) 
			&& (chess_boardv[move->where_y][move->where_x] >0 )) // битьё
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
		}
		else if(move->where_y > move->y && move->where_x == move->x && move->where_y - move->y == 1
			&& chess_boardv[move->where_y][move->where_x] == 0) // обычные ходы 
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
		}
	} 
	else if(move->number_figure==1) // white pawn
	{
		if (move->where_y == 0)
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = 9;
		}
		else if (move->y == 6 && move->where_y == 4 && chess_boardv[move->where_y][move->where_x] == 0
			&& chess_boardv[move->where_y + 1][move->where_x] == 0 && move->where_x == move->x)
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
		}
		else if ((move->where_x == move->x + 1 || move->where_x == move->x - 1) 
			&& abs(move->where_y - move->y) == 1 && chess_boardv[move->where_y][move->where_x] <0)
		{		
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
		}
		else if (move->where_y < move->y && move->where_x == move->x && abs(move->where_y - move->y) == 1
				&& chess_boardv[move->where_y][move->where_x] == 0)
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
	}
	
	// bishop
	if (move->number_figure == -3 && (abs(move->x - move->where_x) == abs(move->y - move->where_y)))
	{
		int k = 0;
		if (move ->where_y > move->y && move->where_x > move->x) // right_down
		{
			while (move->y +1+k!= move->where_y)
			{
				k++;	
				if (chess_boardv[move->y + k][move->x + k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x + k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x]>=0 || (chess_boardv[move->where_y][move->where_x] >= 0 
				&& abs(move->y-move->where_y)==1))
			{
				move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y < move->y && move->where_x > move->x) // right_up
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x + k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x + k] != 0)
				{
					move->allowe = 0;
					break;
				}

			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		} 
		else if (move->where_y < move->y && move->where_x < move->x) // left_up
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x - k] != 0)
				{
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y > move->y && move->where_x < move->x) // left_down
		{
			while (move->y + 1 + k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y + k][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x - k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
	}
	else if (move->number_figure == 3 && (abs(move->x - move->where_x) == abs(move->y - move->where_y)))
	{
		int k = 0;
		if (move->where_y > move->y && move->where_x > move->x) // right_down
		{
			while (move->y + 1 + k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y + k][move->x + k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x + k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y < move->y && move->where_x > move->x) // right_up
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x + k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x + k] != 0)
				{
					move->allowe = 0;
					break;
				}

			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y < move->y && move->where_x < move->x) // left_up
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x - k] != 0)
				{
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y > move->y && move->where_x < move->x) // left_down
		{
			while (move->y + 1 + k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y + k][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x - k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
	}
	
	// knight
	if (move->number_figure == -4)
	{
		if (((abs(move->y - move->where_y) == 2 && abs(move->x - move->where_x) == 1) || (abs(move->y - move->where_y) == 1 &&
			abs(move->x - move->where_x) == 2))
			&& chess_boardv[move->where_y][move->where_x] >= 0)
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
		}
	}
	else if (move->number_figure == 4)
	{
		if (((abs(move->y - move->where_y) == 2 && abs(move->x - move->where_x) == 1) || (abs(move->y - move->where_y) == 1 
			&& abs(move->x - move->where_x) == 2))
			&& chess_boardv[move->where_y][move->where_x] <= 0)
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
		}
	}

	// rook
	if (move->number_figure == -5)
	{
		int k = 0;
		if (move->where_y > move->y && move->where_x == move->x) // up
		{
			while (move->y + 1 + k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y + k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y < move->y && move->where_x == move->x) // down
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x > move->x) // right
		{
			while (move->x + 1 + k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y ][move->x+k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y ][move->x+k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x < move->x) // left
		{
			while (move->x - 1 - k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y][move->x - k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
	}
	else if (move->number_figure == 5)
	{
		int k = 0;
		if (move->where_y > move->y && move->where_x == move->x) // up
		{
			while (move->y + 1 + k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y + k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y < move->y && move->where_x == move->x) // down
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x > move->x) // right
		{
			while (move->x + 1 + k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y][move->x + k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y][move->x + k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x < move->x) // left
		{
			while (move->x - 1 - k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y][move->x - k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
	}

	// queen
	if (move->number_figure == -9)
	{
		int k = 0;
		if ((abs(move->x - move->where_x) == abs(move->y - move->where_y)))
		{
			if (move->where_y > move->y && move->where_x > move->x) // right_down
			{
				while (move->y + 1 + k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y + k][move->x + k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y + k][move->x + k] != 0)
					{
						move->allowe = 0;
						break;
					}
				}
				if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
			else if (move->where_y < move->y && move->where_x > move->x) // right_up
			{
				while (move->y - 1 - k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y - k][move->x + k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y - k][move->x + k] != 0)
					{
						move->allowe = 0;
						break;
					}

				}
				if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
			else if (move->where_y < move->y && move->where_x < move->x) // left_up
			{
				while (move->y - 1 - k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y - k][move->x - k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y - k][move->x - k] != 0)
					{
						break;
					}
				}
				if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
			else if (move->where_y > move->y && move->where_x < move->x) // left_down
			{
				while (move->y + 1 + k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y + k][move->x - k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y + k][move->x - k] != 0)
					{
						move->allowe = 0;
						break;
					}
				}
				if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
		}
		if (move->where_y > move->y && move->where_x == move->x) // up
		{
			while (move->y + 1 + k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y + k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y < move->y && move->where_x == move->x) // down
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x > move->x) // right
		{
			while (move->x + 1 + k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y][move->x + k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y][move->x + k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x < move->x) // left
		{
			while (move->x - 1 - k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y][move->x - k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] >= 0 || (chess_boardv[move->where_y][move->where_x] >= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
	}
	else if (move->number_figure == 9)
	{
		int k = 0;
		if (move->where_y > move->y && move->where_x == move->x) // up
		{
			while (move->y + 1 + k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y + k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y + k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y < move->y && move->where_x == move->x) // down
		{
			while (move->y - 1 - k != move->where_y)
			{
				k++;
				if (chess_boardv[move->y - k][move->x] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y - k][move->x] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->y - move->where_y) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x > move->x) // right
		{
			while (move->x + 1 + k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y][move->x + k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y][move->x + k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		else if (move->where_y == move->y && move->where_x < move->x) // left
		{
			while (move->x - 1 - k != move->where_x)
			{
				k++;
				if (chess_boardv[move->y][move->x - k] == 0)
				{
					move->allowe = 1;
				}
				else if (chess_boardv[move->y][move->x - k] != 0)
				{
					move->allowe = 0;
					break;
				}
			}
			if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
				&& abs(move->x - move->where_x) == 1))
			{
				move->allowe = 1;
				chess_boardv[move->y][move->x] = 0;
				chess_boardv[move->where_y][move->where_x] = move->number_figure;
			}
			else move->allowe = 0;
		}
		if ((abs(move->x - move->where_x) == abs(move->y - move->where_y)))
		{
			if (move->where_y > move->y && move->where_x > move->x) // right_down
			{
				while (move->y + 1 + k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y + k][move->x + k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y + k][move->x + k] != 0)
					{
						move->allowe = 0;
						break;
					}
				}
				if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
			else if (move->where_y < move->y && move->where_x > move->x) // right_up
			{
				while (move->y - 1 - k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y - k][move->x + k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y - k][move->x + k] != 0)
					{
						move->allowe = 0;
						break;
					}

				}
				if ((move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0) || (chess_boardv[move->where_y][move->where_x] <= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
			else if (move->where_y < move->y && move->where_x < move->x) // left_up
			{
				while (move->y - 1 - k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y - k][move->x - k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y - k][move->x - k] != 0)
					{
						break;
					}
				}
				if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
			else if (move->where_y > move->y && move->where_x < move->x) // left_down
			{
				while (move->y + 1 + k != move->where_y)
				{
					k++;
					if (chess_boardv[move->y + k][move->x - k] == 0)
					{
						move->allowe = 1;
					}
					else if (chess_boardv[move->y + k][move->x - k] != 0)
					{
						move->allowe = 0;
						break;
					}
				}
				if (move->allowe == 1 && chess_boardv[move->where_y][move->where_x] <= 0 || (chess_boardv[move->where_y][move->where_x] <= 0
					&& abs(move->y - move->where_y) == 1))
				{
					move->allowe = 1;
					chess_boardv[move->y][move->x] = 0;
					chess_boardv[move->where_y][move->where_x] = move->number_figure;
				}
				else move->allowe = 0;
			}
		}
	}

	// king
	if (move->number_figure == -10)
	{
		if (move->where_x == 2 && chess_boardv[0][1] == 0 && chess_boardv[0][2] == 0 && chess_boardv[0][3] == 0 
			&& move->b_one_move_king == 0 && move->b_one_move_rook1==0)// длинная рокирова
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
			chess_boardv[0][0] = 0;
			chess_boardv[0][3] = -5;
			move->b_one_move_king = 1;
		}
		else if (move->where_x == 6 && chess_boardv[0][6] == 0 && chess_boardv[0][5] == 0 
			&& move->b_one_move_king == 0 && move->b_one_move_rook2==0) // короткая рокировка
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
			chess_boardv[0][7] = 0;
			chess_boardv[0][5] = -5;
			move->b_one_move_king = 1;
		}
		if (((abs(move->where_y - move->y) == 1 && abs(move->where_x - move->x) == 1) || ((abs(move->where_y - move->y) == 1) && (move->x==move->where_x)) 
			|| ((abs(move->where_x - move->x) == 1) && (move->y == move->where_y)))&& (chess_boardv[move->where_y][move->where_x]>=0))
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
			move->b_one_move_king = 1;
		}
	}
	else if (move->number_figure == 10)
	{
		if (move->where_x == 2 && chess_boardv[7][1] == 0 && chess_boardv[7][2] == 0 && chess_boardv[7][3] == 0
			&& move->w_one_move_king == 0 && move->w_one_move_rook1 == 0)// длинная рокирова
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
			chess_boardv[7][0] = 0;
			chess_boardv[7][3] = 5;
			move->w_one_move_king = 1;
		}
		else if (move->where_x == 6 && chess_boardv[7][6] == 0 && chess_boardv[7][5] == 0
			&& move->w_one_move_king == 0 && move->w_one_move_rook2 == 0) // короткая рокировка
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
			chess_boardv[7][7] = 0;
			chess_boardv[7][5] = 5;
			move->w_one_move_king = 1;
		}
		if (((abs(move->where_y - move->y) == 1 && abs(move->where_x - move->x) == 1) || ((abs(move->where_y - move->y) == 1) && (move->x == move->where_x))
			|| ((abs(move->where_x - move->x) == 1) && (move->y == move->where_y))) && (chess_boardv[move->where_y][move->where_x] <= 0))
		{
			move->allowe = 1;
			chess_boardv[move->y][move->x] = 0;
			chess_boardv[move->where_y][move->where_x] = move->number_figure;
			move->w_one_move_king = 1;
		}
	}
}
int main(int argc, char** args)
{
	setlocale(LC_ALL, "RUS");	
	// картинки каждой шахматной фигуры
	SDL_Surface* bb = SDL_LoadBMP("figures/bb.bmp");
	SDL_Surface* bk = SDL_LoadBMP("figures/bk.bmp");
	SDL_Surface* bn = SDL_LoadBMP("figures/bn.bmp");
	SDL_Surface* bp = SDL_LoadBMP("figures/bp.bmp");
	SDL_Surface* bq = SDL_LoadBMP("figures/bq.bmp");
	SDL_Surface* br = SDL_LoadBMP("figures/br.bmp");
	SDL_Surface* wb = SDL_LoadBMP("figures/wb.bmp");
	SDL_Surface* wk = SDL_LoadBMP("figures/wk.bmp");
	SDL_Surface* wn = SDL_LoadBMP("figures/wn.bmp");
	SDL_Surface* wp = SDL_LoadBMP("figures/wp.bmp");
	SDL_Surface* wq = SDL_LoadBMP("figures/wq.bmp");
	SDL_Surface* wr = SDL_LoadBMP("figures/wr.bmp");

	figure_move move = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	// черные фигуры
	int black_pawn = -1;
	int black_knight = -4;
	int black_bishop = -3;
	int black_rook = -5;
	int black_queen = -9;
	int black_king = -10;

	// белые фигура
	int white_pawn = 1;
	int white_knight = 4;
	int white_bishop = 3;
	int white_rook = 5;
	int white_queen = 9;
	int white_king = 10;
	//Создание массива для шахматной доски
	//Обозначение:
	// 1 - Пешка 
	// 3 - Слон
	// 4 - Конь
	// 5 - Ладья
	// 9 - Ферзь
	// 10 - Король
	// отрицательные числа это черные фигуры, положительные белые

	int chess_boardv[8][8] = { black_rook, black_knight,black_bishop,black_queen, black_king,black_bishop, black_knight, black_rook,
							  black_pawn,black_pawn,black_pawn,black_pawn,black_pawn,black_pawn,black_pawn,black_pawn,
							  0,0,0,0,0,0,0,0,
							  0,0,0,0,0,0,0,0,
							  0,0,0,0,0,0,0,0,
							  0,0,0,0,0,0,0,0,
							  white_pawn,white_pawn,white_pawn,white_pawn,white_pawn,white_pawn,white_pawn,white_pawn,
							  white_rook,white_knight,white_bishop,white_queen,white_king,white_bishop,white_knight,white_rook };
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Window* window = SDL_CreateWindow(u8"Шахматная доска",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	// создание текстур
	SDL_Texture* b_rook1 = SDL_CreateTextureFromSurface(renderer, br);
	SDL_Texture* b_rook2 = SDL_CreateTextureFromSurface(renderer, br);
	SDL_Texture* b_night1 = SDL_CreateTextureFromSurface(renderer, bn);
	SDL_Texture* b_night2 = SDL_CreateTextureFromSurface(renderer, bn);
	SDL_Texture* b_bishop1 = SDL_CreateTextureFromSurface(renderer, bb);
	SDL_Texture* b_bishop2 = SDL_CreateTextureFromSurface(renderer, bb);
	SDL_Texture* b_queen = SDL_CreateTextureFromSurface(renderer, bq);
	SDL_Texture* b_king = SDL_CreateTextureFromSurface(renderer, bk);
	SDL_Texture* b_pawn1 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* b_pawn2 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* b_pawn3 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* b_pawn4 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* b_pawn5 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* b_pawn6 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* b_pawn7 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* b_pawn8 = SDL_CreateTextureFromSurface(renderer, bp);
	SDL_Texture* w_rook1 = SDL_CreateTextureFromSurface(renderer, wr);
	SDL_Texture* w_rook2 = SDL_CreateTextureFromSurface(renderer, wr);
	SDL_Texture* w_night1 = SDL_CreateTextureFromSurface(renderer, wn);
	SDL_Texture* w_night2 = SDL_CreateTextureFromSurface(renderer, wn);
	SDL_Texture* w_bishop1 = SDL_CreateTextureFromSurface(renderer, wb);
	SDL_Texture* w_bishop2 = SDL_CreateTextureFromSurface(renderer, wb);
	SDL_Texture* w_queen = SDL_CreateTextureFromSurface(renderer, wq);
	SDL_Texture* w_king = SDL_CreateTextureFromSurface(renderer, wk);
	SDL_Texture* w_pawn1 = SDL_CreateTextureFromSurface(renderer, wp);
	SDL_Texture* w_pawn2 = SDL_CreateTextureFromSurface(renderer, wp);
	SDL_Texture* w_pawn3 = SDL_CreateTextureFromSurface(renderer, wp);
	SDL_Texture* w_pawn4 = SDL_CreateTextureFromSurface(renderer, wp);
	SDL_Texture* w_pawn5 = SDL_CreateTextureFromSurface(renderer, wp);
	SDL_Texture* w_pawn6 = SDL_CreateTextureFromSurface(renderer, wp);
	SDL_Texture* w_pawn7 = SDL_CreateTextureFromSurface(renderer, wp);
	SDL_Texture* w_pawn8 = SDL_CreateTextureFromSurface(renderer, wp);

	// Заливание окно белым цветом
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);
	outputv_mass(chess_boardv);
	SDL_Event event;

	bool quit = false;
	int clickcounter=0; // для функций по очереди откуда куда
	int x = 0, y = 0, x1 = 0, y1 = 0;
	int leftMouseButtonClicked = 0; // для фикса бага несколько раз нажатия левой кнопкой мыши
	int x_b_b1 = 150, y_b_b1 = 50; // Координаты x и y для черного слона 1
	int x_b_b2 = 300, y_b_b2 = 50; // Координаты x и y для черного слона 2
	int x_b_k = 250, y_b_k = 50; // Координаты x и y для черного короля
	int x_b_n1 = 100, y_b_n1 = 50; // Координаты x и y для черного коня 1
	int x_b_n2 = 350, y_b_n2 = 50; // Координаты x и y для черного коня 2
	int x_b_p1 = 50, y_b_p1 = 100; // Координаты x и y для черной пешки 1
	int x_b_p2 = 100, y_b_p2 = 100; // Координаты x и y для черной пешки 2
	int x_b_p3 = 150, y_b_p3 = 100; // Координаты x и y для черной пешки 3
	int x_b_p4 = 200, y_b_p4 = 100; // Координаты x и y для черной пешки 4
	int x_b_p5 = 250, y_b_p5 = 100; // Координаты x и y для черной пешки 5
	int x_b_p6 = 300, y_b_p6 = 100; // Координаты x и y для черной пешки 6
	int x_b_p7 = 350, y_b_p7 = 100; // Координаты x и y для черной пешки 7
	int x_b_p8 = 400, y_b_p8 = 100; // Координаты x и y для черной пешки 8
	int x_b_q = 200, y_b_q = 50; // Координаты x и y для черной королевы
	int x_b_r1 = 50, y_b_r1 = 50; // Координаты x и y для черной ладьи 1
	int x_b_r2 = 400, y_b_r2 = 50; // Координаты x и y для черной ладьи 2
	int x_w_b1 = 150, y_w_b1 = 400; // Координаты x и y для белого слона 1
	int x_w_b2 = 300, y_w_b2 = 400; // Координаты x и y для белого слона 2
	int x_w_k = 250, y_w_k = 400; // Координаты x и y для белого короля
	int x_w_n1 = 100, y_w_n1 = 400; // Координаты x и y для белого коня 1
	int x_w_n2 = 350, y_w_n2 = 400; // Координаты x и y для белого коня 2
	int x_w_p1 = 50, y_w_p1 = 350; // Координаты x и y для белой пешки 1
	int x_w_p2 = 100, y_w_p2 = 350; // Координаты x и y для белой пешки 2
	int x_w_p3 = 150, y_w_p3 = 350; // Координаты x и y для белой пешки 3
	int x_w_p4 = 200, y_w_p4 = 350; // Координаты x и y для белой пешки 4
	int x_w_p5 = 250, y_w_p5 = 350; // Координаты x и y для белой пешки 5
	int x_w_p6 = 300, y_w_p6 = 350; // Координаты x и y для белой пешки 6
	int x_w_p7 = 350, y_w_p7 = 350; // Координаты x и y для белой пешки 7
	int x_w_p8 = 400, y_w_p8 = 350; // Координаты x и y для белой пешки 8
	int x_w_q = 200, y_w_q = 400; // Координаты x и y для белой королевы
	int x_w_r1 = 50, y_w_r1 = 400; // Координаты x и y для белой ладьи 1
	int x_w_r2 = 400, y_w_r2 = 400; // Координаты x и y для белой ладьи 2
	ris_figure_start(renderer, b_bishop1, b_bishop2, b_night1,
		b_night2, b_king, b_queen, b_rook1,
		b_rook2, w_bishop1, w_bishop2, w_rook1, w_king,
		w_rook2, w_night1, w_night2, b_pawn1, b_pawn2,
		b_pawn3, b_pawn4, b_pawn5,
		b_pawn6, b_pawn7, b_pawn8, w_pawn1, w_pawn2,
		w_pawn3, w_pawn4, w_pawn5,
		w_pawn6, w_pawn7, w_pawn8, w_queen, &move);
	int white_black = 1; // по очереди белые черные
	bool b_king_present = false; // для конца игры
	bool w_king_present = false; // для конца  игры
	while (!quit)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			quit = true;
		chess_board(renderer);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT && !leftMouseButtonClicked)
				{
					if (event.button.x > 50 && event.button.x < 450 && event.button.y>50 && event.button.y < 450)
					{
						if (clickcounter == 0)
						{
							leftMouseButtonClicked = 1; // флаг для клика
							x = event.button.x;
							y = event.button.y;
							otkuda(chess_boardv, &move, x, y);
							if (move.allowe == 1 && white_black==1 && move.number_figure>0) // определяет что 1 ходят белые
							{
								clickcounter = 1; // разрешение на функцию куда
							}
							else if (move.number_figure < 0 && move.allowe == 1 && white_black == 0)
							{
								clickcounter = 1; // разрешение на функцию куда
							}
							move.allowe = 0;
						}
						else if (clickcounter == 1)
						{
							if (move.number_figure > 0 && white_black==1)
							{
								x1 = event.button.x;
								y1 = event.button.y;
								kuda(chess_boardv, &move, x1, y1);
								if (move.allowe == 1)
								{
									ris_figure(renderer, b_bishop1, b_bishop2, b_night1,
										b_night2, b_king, b_queen, b_rook1,
										b_rook2, w_bishop1, w_bishop2, w_rook1, w_king,
										w_rook2, w_night1, w_night2, b_pawn1, b_pawn2,
										b_pawn3, b_pawn4, b_pawn5,
										b_pawn6, b_pawn7, b_pawn8, w_pawn1, w_pawn2,
										w_pawn3, w_pawn4, w_pawn5,
										w_pawn6, w_pawn7, w_pawn8, w_queen, &move, &x_b_b1, &y_b_b1, &x_b_b2, &y_b_b2, &x_b_k, &y_b_k, &x_b_n1, &y_b_n1,
										&x_b_n2, &y_b_n2, &x_b_p1, &y_b_p1, &x_b_p2, &y_b_p2,
										&x_b_p3, &y_b_p3, &x_b_p4, &y_b_p4, &x_b_p5, &y_b_p5,
										&x_b_p6, &y_b_p6, &x_b_p7, &y_b_p7, &x_b_p8, &y_b_p8,
										&x_b_q, &y_b_q, &x_b_r1, &y_b_r1, &x_b_r2, &y_b_r2,
										&x_w_b1, &y_w_b1, &x_w_b2, &y_w_b2, &x_w_k, &y_w_k, &x_w_n1, &y_w_n1,
										&x_w_n2, &y_w_n2, &x_w_p1, &y_w_p1, &x_w_p2, &y_w_p2,
										&x_w_p3, &y_w_p3, &x_w_p4, &y_w_p4, &x_w_p5, &y_w_p5,
										&x_w_p6, &y_w_p6, &x_w_p7, &y_w_p7, &x_w_p8, &y_w_p8,
										&x_w_q, &y_w_q, &x_w_r1, &y_w_r1, &x_w_r2, &y_w_r2);
									white_black = 0;
									move.allowe = 0;
								}
								clickcounter = 0;
							}
							else if (move.number_figure < 0 && white_black == 0)
							{
								x1 = event.button.x;
								y1 = event.button.y;
								kuda(chess_boardv, &move, x1, y1);
								if (move.allowe == 1)
								{
									ris_figure(renderer, b_bishop1, b_bishop2, b_night1,
										b_night2, b_king, b_queen, b_rook1,
										b_rook2, w_bishop1, w_bishop2, w_rook1, w_king,
										w_rook2, w_night1, w_night2, b_pawn1, b_pawn2,
										b_pawn3, b_pawn4, b_pawn5,
										b_pawn6, b_pawn7, b_pawn8, w_pawn1, w_pawn2,
										w_pawn3, w_pawn4, w_pawn5,
										w_pawn6, w_pawn7, w_pawn8, w_queen, &move, &x_b_b1, &y_b_b1, &x_b_b2, &y_b_b2, &x_b_k, &y_b_k, &x_b_n1, &y_b_n1,
										&x_b_n2, &y_b_n2, &x_b_p1, &y_b_p1, &x_b_p2, &y_b_p2,
										&x_b_p3, &y_b_p3, &x_b_p4, &y_b_p4, &x_b_p5, &y_b_p5,
										&x_b_p6, &y_b_p6, &x_b_p7, &y_b_p7, &x_b_p8, &y_b_p8,
										&x_b_q, &y_b_q, &x_b_r1, &y_b_r1, &x_b_r2, &y_b_r2,
										&x_w_b1, &y_w_b1, &x_w_b2, &y_w_b2, &x_w_k, &y_w_k, &x_w_n1, &y_w_n1,
										&x_w_n2, &y_w_n2, &x_w_p1, &y_w_p1, &x_w_p2, &y_w_p2,
										&x_w_p3, &y_w_p3, &x_w_p4, &y_w_p4, &x_w_p5, &y_w_p5,
										&x_w_p6, &y_w_p6, &x_w_p7, &y_w_p7, &x_w_p8, &y_w_p8,
										&x_w_q, &y_w_q, &x_w_r1, &y_w_r1, &x_w_r2, &y_w_r2);
									white_black = 1;
									move.allowe = 0;
								}
								clickcounter = 0;
							}
						}
						// конец игры
						for (int i = 0; i < 8; i++)
						{
							for (int j = 0; j < 8; j++)
								{
								if (chess_boardv[i][j] == -10)
								{
									b_king_present = true;
								}
								else if (chess_boardv[i][j] == 10)
								{
									w_king_present = true;
								}
							}
						}
						if (!b_king_present)
						{
							quit = true;
							printf("Белые выиграли!");
						}
						else if (!w_king_present)
						{
							quit = true;
							printf("Черные выиграли!");
						}
						b_king_present = false; 
						w_king_present = false;
					}
				}
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					leftMouseButtonClicked = 0; // Сбрасывает флаг, чтобы позволить следующий клик
				}
			}
		}
	}
	printf("\n\n");
	outputv_mass(chess_boardv);
	SDL_Delay(200);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}