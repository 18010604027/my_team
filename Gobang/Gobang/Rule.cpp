#include"pch.h"
#include"Rule.h"

Rule::Rule()
{
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			two[i][j] = 0;
		}
	}
}

void Rule::change(chess c)
{
	two[c.x][c.y] = c.z;
}
bool Rule::judge(chess c)
{
	int i, j;
	int t;
	t = 0;
	for (i = c.x + 1, j = c.y; t < 4 && i < 15; i++)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	for (i = c.x - 1, j = c.y; t < 4 && i >= 0; i--)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	t = 0;
	for (i = c.x, j = c.y + 1; t < 4 && j < 15; j++)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	for (i = c.x, j = c.y - 1; t < 4 && j >= 0; j--)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	t = 0;
	for (i = c.x + 1, j = c.y + 1; t < 4 && i < 15 && j < 15; i++, j++)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	for (i = c.x - 1, j = c.y - 1; t < 4 && i >= 0 && j >= 0; i--, j--)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	t = 0;
	for (i = c.x + 1, j = c.y - 1; t < 4 && i < 15 && j >= 0; i++, j--)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	for (i = c.x - 1, j = c.y + 1; t < 4 && i >= 0 && j < 15; i--, j++)
	{
		if (two[i][j] != c.z)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	return false;
}
bool Rule::four(const  int board[][15], int c, int x, int y)
{
	int i, j;
	int t;
	t = 0;
	for (i = x + 1, j = y; t < 4 && i < 15; i++)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	for (i = x - 1, j = y; t < 4 && i >= 0; i--)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	t = 0;
	for (i = x, j = y + 1; t < 4 && j < 15; j++)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	for (i = x, j = y - 1; t < 4 && j >= 0; j--)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	t = 0;
	for (i = x + 1, j = y + 1; t < 4 && i < 15 && j < 15; i++, j++)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	for (i = x - 1, j = y - 1; t < 4 && i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	t = 0;
	for (i = x + 1, j = y - 1; t < 4 && i < 15 && j >= 0; i++, j--)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	for (i = x - 1, j = y + 1; t < 4 && i >= 0 && j < 15; i--, j++)
	{
		if (board[i][j] != 0 && board[i][j] != c)
		{
			break;
		}
		t++;
	}
	if (t == 4)
	{
		return true;
	}
	//MessageBox(NULL, L"11", NULL, NULL);
	return false;
}
int Rule::get_chess(int x, int y)
{
	return two[x][y];
}

chess Rule::AI(int c)
{
	chess chess;
	int i, j;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (two[i][j])
			{
				break;
			}
		}
		if (j != 15)
		{
			break;
		}
	}
	if (i == 15 && j == 15)
	{
		chess.x = 7, chess.y = 7, chess.z = c;
		return chess;
	}
	if (search(0, c - 1) == 0 && x == -1 && y == -1)
	{
		MessageBox(NULL, L"电脑已经放弃游戏！", L"温馨提示", NULL);
		chess.z = 0;
	}
	chess.x = x, chess.y = y, chess.z = c;
	return chess;
}
long long Rule::search(int dep, int c)//(深度，棋子类型)
{
	long long max;
	long long score, rem;
	bool first = true;
	chess chess;
	chess.z = c + 1;
	win = false;
	if (dep == 2)
	{
		return 0;
	}
	int i, j;
	x = -1; y = -1;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (two[i][j] == 0 && four(two, c + 1, i, j))
			{
				two[i][j] = c + 1;
				chess.x = i, chess.y = j;
				if (judge(chess))
				{
					two[i][j] = 0;
					x = i, y = j;
					win = true;
					return 9;
				}
				rem = search(dep + 1, !c);
				if (win)//只有两步有用
				{
					two[i][j] = 0;
					return 9;
				}
				score = getscore(two, c) - rem;
				if (first)
				{
					max = score;
					x = i, y = j;
					first = !first;
				}

				if (score > max)
				{
					max = score;
					x = i, y = j;
				}
				else if (score == max)
				{
					srand(time(0));
					if (rand() % 3)
					{
						x = i, y = j;
					}
				}
				two[i][j] = 0;
			}
		}
	}
	if (first)
	{
		return 0;
	}
	return max / 2;
}
long long Rule::getscore(const int board[][15], int c)
{
	int i, j, i2, j2;
	long long score = 0;
	int empty, white, black;
	int empty_rem, white_rem, black_rem;
	int empty_rem2;
	for (i = 0; i < 15; i++)
	{
		empty = 0, empty_rem = 0, empty_rem2 = 0;
		white = 0, white_rem = 0;
		black = 0, black_rem = 0;
		for (j = 0; j < 15; j++)
		{
			if (board[i][j] == 0)
			{
				if (white != 0)
				{
					if (white_rem + white == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (!c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					white_rem = white;
					white = 0;
				}
				if (black != 0)
				{
					if (black_rem + black == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					black_rem = black;
					black = 0;
				}
				if (empty == 0)
				{
					if (white_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (!c)
							{
								score += me[white_rem * 2 - 2];
							}
							else
							{
								score -= me[white_rem * 2 - 2];
							}
						}
						else
						{
							if (!c)
							{
								score += me[1 + white_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + white_rem * 2 - 2];
							}
						}
					}
					else if (black_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (c)
							{
								score += me[black_rem * 2 - 2];
							}
							else
							{
								score -= me[black_rem * 2 - 2];
							}
						}
						else
						{
							if (c)
							{
								score += me[1 + black_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + black_rem * 2 - 2];
							}
						}
					}
				}
				empty++;
			}
			else if (board[i][j] == 1)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (black != 0)
				{
					if (empty_rem != 0)
					{
						if (c)
						{

							score += me[black * 2 - 2];
						}
						else
						{
							score -= me[black * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					black_rem = 0;
					black = 0;
				}
				white++;
			}
			else if (board[i][j] == 2)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (white != 0)
				{
					if (empty_rem != 0)
					{
						if (!c)
						{
							score += me[white * 2 - 2];
						}
						else
						{
							score -= me[white * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					white_rem = 0;
					white = 0;
				}
				black++;

			}
		}
	}

	for (j = 0; j < 15; j++)
	{
		empty = 0, empty_rem = 0;
		white = 0, white_rem = 0;
		black = 0, black_rem = 0;
		for (i = 0; i < 15; i++)
		{
			if (board[i][j] == 0)
			{
				if (white != 0)
				{
					if (white_rem + white == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (!c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					white_rem = white;
					white = 0;
				}
				if (black != 0)
				{
					if (black_rem + black == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					black_rem = black;
					black = 0;
				}
				if (empty == 0)
				{
					if (white_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (!c)
							{
								score += me[white_rem * 2 - 2];
							}
							else
							{
								score -= me[white_rem * 2 - 2];
							}
						}
						else
						{
							if (!c)
							{
								score += me[1 + white_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + white_rem * 2 - 2];
							}
						}
					}
					else if (black_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (c)
							{
								score += me[black_rem * 2 - 2];
							}
							else
							{
								score -= me[black_rem * 2 - 2];
							}
						}
						else
						{
							if (c)
							{
								score += me[1 + black_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + black_rem * 2 - 2];
							}
						}
					}
				}
				empty++;
			}
			else if (board[i][j] == 1)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (black != 0)
				{
					if (empty_rem != 0)
					{
						if (c)
						{

							score += me[black * 2 - 2];
						}
						else
						{
							score -= me[black * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					black_rem = 0;
					black = 0;
				}
				white++;
			}
			else if (board[i][j] == 2)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (white != 0)
				{
					if (empty_rem != 0)
					{
						if (!c)
						{
							score += me[white * 2 - 2];
						}
						else
						{
							score -= me[white * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					white_rem = 0;
					white = 0;
				}
				black++;

			}
		}
	}

	for (i2 = 0, j2 = 0; i2 < 15; i2++)
	{
		empty = 0, empty_rem = 0;
		white = 0, white_rem = 0;
		black = 0, black_rem = 0;
		for (i = i2, j = j2; j < 15 && i < 15; i++, j++)
		{
			if (board[i][j] == 0)
			{
				if (white != 0)
				{
					if (white_rem + white == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (!c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					white_rem = white;
					white = 0;
				}
				if (black != 0)
				{
					if (black_rem + black == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					black_rem = black;
					black = 0;
				}
				if (empty == 0)
				{
					if (white_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (!c)
							{
								score += me[white_rem * 2 - 2];
							}
							else
							{
								score -= me[white_rem * 2 - 2];
							}
						}
						else
						{
							if (!c)
							{
								score += me[1 + white_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + white_rem * 2 - 2];
							}
						}
					}
					else if (black_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (c)
							{
								score += me[black_rem * 2 - 2];
							}
							else
							{
								score -= me[black_rem * 2 - 2];
							}
						}
						else
						{
							if (c)
							{
								score += me[1 + black_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + black_rem * 2 - 2];
							}
						}
					}
				}
				empty++;
			}
			else if (board[i][j] == 1)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (black != 0)
				{
					if (empty_rem != 0)
					{
						if (c)
						{

							score += me[black * 2 - 2];
						}
						else
						{
							score -= me[black * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					black_rem = 0;
					black = 0;
				}
				white++;
			}
			else if (board[i][j] == 2)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (white != 0)
				{
					if (empty_rem != 0)
					{
						if (!c)
						{
							score += me[white * 2 - 2];
						}
						else
						{
							score -= me[white * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					white_rem = 0;
					white = 0;
				}
				black++;

			}
		}
	}
	for (i2 = 0, j2 = 1; j2 < 15; j2++)
	{
		empty = 0, empty_rem = 0;
		white = 0, white_rem = 0;
		black = 0, black_rem = 0;
		for (i = i2, j = j2; j < 15 && i < 15; i++, j++)
		{
			if (board[i][j] == 0)
			{
				if (white != 0)
				{
					if (white_rem + white == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (!c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					white_rem = white;
					white = 0;
				}
				if (black != 0)
				{
					if (black_rem + black == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					black_rem = black;
					black = 0;
				}
				if (empty == 0)
				{
					if (white_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (!c)
							{
								score += me[white_rem * 2 - 2];
							}
							else
							{
								score -= me[white_rem * 2 - 2];
							}
						}
						else
						{
							if (!c)
							{
								score += me[1 + white_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + white_rem * 2 - 2];
							}
						}
					}
					else if (black_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (c)
							{
								score += me[black_rem * 2 - 2];
							}
							else
							{
								score -= me[black_rem * 2 - 2];
							}
						}
						else
						{
							if (c)
							{
								score += me[1 + black_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + black_rem * 2 - 2];
							}
						}
					}
				}
				empty++;
			}
			else if (board[i][j] == 1)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (black != 0)
				{
					if (empty_rem != 0)
					{
						if (c)
						{

							score += me[black * 2 - 2];
						}
						else
						{
							score -= me[black * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					black_rem = 0;
					black = 0;
				}
				white++;
			}
			else if (board[i][j] == 2)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (white != 0)
				{
					if (empty_rem != 0)
					{
						if (!c)
						{
							score += me[white * 2 - 2];
						}
						else
						{
							score -= me[white * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					white_rem = 0;
					white = 0;
				}
				black++;

			}
		}
	}

	for (i2 = 0, j2 = 0; j2 < 15; j2++)
	{
		empty = 0, empty_rem = 0;
		white = 0, white_rem = 0;
		black = 0, black_rem = 0;
		for (i = i2, j = j2; j >= 0 && i < 15; i++, j--)
		{
			if (board[i][j] == 0)
			{
				if (white != 0)
				{
					if (white_rem + white == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (!c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					white_rem = white;
					white = 0;
				}
				if (black != 0)
				{
					if (black_rem + black == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					black_rem = black;
					black = 0;
				}
				if (empty == 0)
				{
					if (white_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (!c)
							{
								score += me[white_rem * 2 - 2];
							}
							else
							{
								score -= me[white_rem * 2 - 2];
							}
						}
						else
						{
							if (!c)
							{
								score += me[1 + white_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + white_rem * 2 - 2];
							}
						}
					}
					else if (black_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (c)
							{
								score += me[black_rem * 2 - 2];
							}
							else
							{
								score -= me[black_rem * 2 - 2];
							}
						}
						else
						{
							if (c)
							{
								score += me[1 + black_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + black_rem * 2 - 2];
							}
						}
					}
				}
				empty++;
			}
			else if (board[i][j] == 1)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (black != 0)
				{
					if (empty_rem != 0)
					{
						if (c)
						{

							score += me[black * 2 - 2];
						}
						else
						{
							score -= me[black * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					black_rem = 0;
					black = 0;
				}
				white++;
			}
			else if (board[i][j] == 2)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (white != 0)
				{
					if (empty_rem != 0)
					{
						if (!c)
						{
							score += me[white * 2 - 2];
						}
						else
						{
							score -= me[white * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					white_rem = 0;
					white = 0;
				}
				black++;

			}
		}
	}
	for (i2 = 1, j2 = 14; i2 < 15; i2++)
	{
		empty = 0, empty_rem = 0;
		white = 0, white_rem = 0;
		black = 0, black_rem = 0;
		for (i = i2, j = j2; j >= 0 && i < 15; i++, j--)
		{
			if (board[i][j] == 0)
			{
				if (white != 0)
				{
					if (white_rem + white == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (!c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					white_rem = white;
					white = 0;
				}
				if (black != 0)
				{
					if (black_rem + black == 3 && empty == 1 && empty_rem2 > 0)
					{
						if (c)
						{
							score += me[5];
						}
						else
						{
							score -= me[5];
						}
					}
					black_rem = black;
					black = 0;
				}
				if (empty == 0)
				{
					if (white_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (!c)
							{
								score += me[white_rem * 2 - 2];
							}
							else
							{
								score -= me[white_rem * 2 - 2];
							}
						}
						else
						{
							if (!c)
							{
								score += me[1 + white_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + white_rem * 2 - 2];
							}
						}
					}
					else if (black_rem != 0)
					{
						if (empty_rem == 0)
						{
							if (c)
							{
								score += me[black_rem * 2 - 2];
							}
							else
							{
								score -= me[black_rem * 2 - 2];
							}
						}
						else
						{
							if (c)
							{
								score += me[1 + black_rem * 2 - 2];
							}
							else
							{
								score -= me[1 + black_rem * 2 - 2];
							}
						}
					}
				}
				empty++;
			}
			else if (board[i][j] == 1)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (black != 0)
				{
					if (empty_rem != 0)
					{
						if (c)
						{

							score += me[black * 2 - 2];
						}
						else
						{
							score -= me[black * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					black_rem = 0;
					black = 0;
				}
				white++;
			}
			else if (board[i][j] == 2)
			{
				if (empty != 0)
				{
					empty_rem2 = empty_rem;
					empty_rem = empty;
					empty = 0;
				}
				if (white != 0)
				{
					if (empty_rem != 0)
					{
						if (!c)
						{
							score += me[white * 2 - 2];
						}
						else
						{
							score -= me[white * 2 - 2];
						}
					}
					empty_rem2 = 0;
					empty_rem = 0;
					white_rem = 0;
					white = 0;
				}
				black++;

			}
		}
	}
	return score;
}
int Rule::getmax(const  int score[][15])
{
	int i, j;
	int max = score[0][0];
	x = 0, y = 0;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (max < score[i][j])
			{
				max = score[i][j];
				x = i, y = j;
			}
		}
	}
	return max;
}


