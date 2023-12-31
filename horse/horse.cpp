﻿#include <iostream>
#include <ctime>
//размерность поля
#define DS 5

//создание массива
int desk[DS][DS];
int step[8][2] = { {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2} };
int n;


//выводим элементы двумерного массива desk
void print_desk()
{
	// перебираем строки массива desk
	for (int i = 0; i < DS; i++)
	{
		//перебираем столбцы массива desk
		for (int j = 0; j < DS; j++)
			printf(" %2d", desk[i][j]);
		printf("\n");
	}
}

bool set_horse(int x, int y)
{
	// проверка параметров x и y
	if ((x < 0) || (x >= DS) || (y < 0) || (y >= DS))
		return false;

	if (desk[x][y] != 0)
		return false;

	//устанавливаем фигуру "конь" на ячейку с координатами x и y
	n++;
	desk[x][y] = n;

	//Если все ячейки доски заполнены, функция возвращает true, что означает, что игра завершена
	if (n == DS * DS)
		return true;

	//функция рекурсивно вызывает саму себя для каждого из 8 возможных ходов коня. Если хотя бы один из этих вызовов вернет true, то функция также вернет true
	for (int i = 0; i < 8; i++)
		if (set_horse(x + step[i][0], y + step[i][1]))
			return true;
	//Если ни один из возможных ходов не приводит к завершению игры, функция уменьшает счетчик n и снимает фигуру "конь" с ячейки с координатами x и y.
	n--;
	desk[x][y] = 0;

	return false;
}


//осуществляем вызов функции set_horse для установки фигуры "конь" на шахматной доске. 
int main()
{
	time_t t_start, t_end;

	setlocale(LC_ALL, "RUSSIAN");
	time(&t_start);

	//заполняем массив нулями,представляющими пустые ячейки доски.
	n = 0;
	for (int i = 0; i < DS; i++)
		for (int j = 0; j < DS; j++)
			desk[i][j] = 0;

    //начальные координаты
	set_horse(0, 0);

	//выводим текущее состояние доски
	print_desk();

	//вычисляем время окончания выполнения программы и выводим на экран время, затраченное на поиск решения
	time(&t_end);
	std::cout << std::endl << "Решение найдено за " << t_end - t_start << " секунд" << std::endl;
	system("pause");
}