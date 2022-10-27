#include <iostream>
#include <stdlib.h>


using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

char turn = 'X';
char place;
int row;
int column;
int n_turns{ 0 };

void show_board()
{
	cout << "\t\t\n" << "Player 1: X\nPlayer 2: O";
	cout << "\n\n";
	cout << "\t" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
	cout << "\t" << "----------\n";
	cout << "\t" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
	cout << "\t" << "----------\n";
	cout << "\t" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
	cout << "\n";
}

void player_turn()
{
	int not_found_count = 0;

	n_turns++; 

	if (turn == 'X')
	{
		cout << "Player 1 turn: ";
	}
	else if (turn == 'O')
	{
		cout << "Player 2 turn: ";
	}

	cin >> place; 

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == place)
			{
				board[i][j] = turn;
				if (turn == 'X')
				{
					turn = 'O'; 
				}
				else if (turn == 'O')
				{
					turn = 'X';
				}
			}
		}
	}

}

bool game()
{
	bool is_gameover{ false };
	bool draw{ false }; 

	int i; 
	int j; 

	for (i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] || board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			is_gameover = true; 
		}
		else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		{
			is_gameover = true; 
		}
	}

	if (n_turns == 9)
	{
		draw = true; 
	}


	if (is_gameover)
	{
		show_board();
		if (turn == 'O')
		{
			cout << "PLAYER 1 HAS WON!!!"; 
		}
		else if (turn == 'X')
		{
			cout << "PLAYER 2 HAS WON!!!"; 
		}
		return false;
	}
	else if (draw)
	{
		show_board(); 
		cout << "--------------DRAW--------------\n"; 
		return false; 
	}
	else
	{
		return true;
	}

}

int main()
{
	

	while (game())
	{
		show_board(); 
		player_turn(); 
	}
	
	


	return 0; 
}


