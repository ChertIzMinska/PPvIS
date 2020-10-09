#include"Header.h"
/*!
\file
\brief Файл , в котором описаны все методы и функции

Данный файл содержит в себе логику , принцип работы программы
*/
using namespace std;
int  Game::Counter(int index_string, int index_colons,int &for_x,int &for_zero)
{
	
	if (map[index_string][index_colons] == 1)
	{
		for_x++;
		if (for_x == size)
		{
			cout << "Player X win\n";
			return 1;
		}
	}
	else if (map[index_string][index_colons] == 0)
	{
		for_zero++;
		if (for_zero == size)
		{
			cout << "Player 0 win\n";
			return 0;
		}
	}
	return -1;
}
Game::Game(int size)
{
	this->size = size;
	map = new int* [size];
	for (int i = 0; i < size; i++)
	{
		map[i] = new int[size];
	}
	this->size = size;
	for (int i = 0; i < size; i++)
		for (int g = 0; g < size; g++)
			map[i][g] = -1;
}
bool Game::_Is(int index_strings, int index_colons)
{
	if (map[index_strings][index_colons] == -1)
		return false;
	return true;
}
int* Game::operator[](const int index)
{
	return map[index];
}
int& Game::operator=(const int& right)
{
	int value = right;
	return value;
}
int Game::_Win()
{
	int str_x = 0;
	int col_x = 0;
	int diog_x = 0;
	int op_diog_x = 0;

	int str_y = 0;
	int col_y = 0;
	int diog_y = 0;
	int op_diog_y = 0;

	int result = 0;
	int draw = 0;

	for (int i = 0; i < size; i++)
	{
		str_x = 0;
		col_x = 0;
		str_y = 0;
		col_y = 0;



     	for (int g = 0; g < size; g++)
		{
			if (map[i][g] == -1)
				draw++;

			result = Counter(i, g, str_x, str_y);

			if (result != -1)
				return result;

			result = Counter(g, i, col_x, col_y);

				if (result != -1)
					return result;
			
		}
		result = Counter(i, i, diog_x, diog_y);

		if (result!=-1)
			return result;

		result = Counter(size - i - 1, size - i - 1, op_diog_x, op_diog_y);

		if (result != -1)
			return result;
	

	}

	if (draw == (size*size))
	{
		cout << "Draw!We don't have a winner\n";
		return draw;
	}
	return -1;


}
int Game::_Get_size()
{
	return size;
}
void _Logic(Game& game)
{
	int r = 0;
	int position_str;
	int position_con;



	cout << "Вводите сперва номер строки(от 0 до n),а затем номер столбца(от 0 до n)\n";


	do {
		game._Create_map();


		cin >> position_str;
		cin >> position_con;



		if (position_str >= game._Get_size() || position_con >= game._Get_size())
		{
			cout << "Ошибка.Выход за пределы поля!\n";
			continue;
		}




		if (!game._Is(position_str, position_con))
		{
			game[position_str][position_con] = r;
		}
		else {
			cout << "Это место уже занято\n";
			continue;
		}



		if (r == 0)
			r = 1;
		else
			r = 0;


		system("cls");
	} while (game._Win() == -1);

}
void Game::_Create_map()
{
	for (int i = 0; i < size; i++)
	{
		for (int g = 0; g < size; g++)
		{
			if (map[i][g] == 1)
				cout << "X";
			else if (map[i][g] == 0)
				cout << "0";
			else { cout << " "; }
			cout << "\t";
		}
		cout << endl;
	}



}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	cout << "Введите размер карты\n";
	int size;
	cin >> size;


	Game game(size);

	_Logic(game);
}
