#include "CoreOthello.h"

CoreOthello::CoreOthello(bool Multiplayer)
{
	this->Multiplayer = Multiplayer;
	CurrentPlayer = 0;
	Enemy = 1;
	ScoreCurrentPlayer = 0;
	ScoreEnemy = 0;
	GameOver = false;
	Matrix = new int*[Size];
	for (int K = 0; K < Size; K++)
	{
		Matrix[K] = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			Matrix[K][i] = -1;
		}
	}
}
void CoreOthello::Init()
{
	CurrentPlayer = 0;
	Enemy = 1;
	ScoreCurrentPlayer = 0;
	ScoreEnemy = 0;
	GameOver = false;
	for (int K = 0; K < Size; K++)
	{
		for (int i = 0; i < Size; i++)
		{
			Matrix[K][i] = -1;
		}
	}
	setMoves(3, 3, true);
	setMoves(4, 3, true);
	setMoves(4, 4, true);
	setMoves(3, 4, true);
	GameOver = false;
	//PossibleMoves();
}
void CoreOthello::setMoves(int Row, int Columns)
{
	RowChanged.clear();
	ColumnsChanged.clear();

	Matrix[Row][Columns] = CurrentPlayer;
	ScoreCurrentPlayer++; 

	bool EnemyFound = false;


	// LEFT TILES
	for (int k = Columns - 1; k >= 0; k--)
	{
		if (Matrix[Row][k] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[Row][k] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k + 1 < Columns)
				{
					k++;
					Matrix[Row][k] = CurrentPlayer;
					RowChanged.push_back(Row);
					ColumnsChanged.push_back(k);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	// RIGHT TILES
	for (int k = Columns + 1; k < Size; k++)
	{
		if (Matrix[Row][k] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[Row][k] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k - 1 > Columns)
				{
					k--;
					Matrix[Row][k] = CurrentPlayer;
					RowChanged.push_back(Row);
					ColumnsChanged.push_back(k);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	// TOP TILES
	for (int k = Row - 1; k >= 0; k--)
	{
		if (Matrix[k][Columns] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[k][Columns] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k + 1 < Row)
				{
					k++;
					Matrix[k][Columns] = CurrentPlayer;
					RowChanged.push_back(k);
					ColumnsChanged.push_back(Columns);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	// BOTTOM TILES
	for (int k = Row + 1; k < Size; k++)
	{
		if (Matrix[k][Columns] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[k][Columns] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k - 1 > Row)
				{
					k--;
					Matrix[k][Columns] = CurrentPlayer;
					RowChanged.push_back(k);
					ColumnsChanged.push_back(Columns);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	int r, c;
	// TOP LEFT DIAGONAL
	r = Row - 1;
	c = Columns - 1;
	while (r >= 0 && c >= 0)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r + 1) < Row && (c + 1) < Columns)
				{
					r++;
					c++;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r--;
		c--;
	}
	EnemyFound = false;


	// TOP RIGHT DIAGONAL
	r = Row - 1;
	c = Columns + 1;
	while (r >= 0 && c < Size)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r + 1) < Row && (c - 1) > Columns)
				{
					r++;
					c--;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r--;
		c++;
	}
	EnemyFound = false;


	// BOTTOM LEFT DIAGONAL
	r = Row + 1;
	c = Columns - 1;
	while (r < Size && c >= 0)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r - 1) > Row && (c + 1) < Columns)
				{
					r--;
					c++;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r++;
		c--;
	}


	// BOTTOM RIGHT DIAGONAL
	r = Row + 1;
	c = Columns + 1;
	while (r < Size && c < Size)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r - 1) > Row && (c - 1) > Columns)
				{
					r--;
					c--;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r++;
		c++;
	}

	PossibleMoves();
}
void CoreOthello::setMoves(int Row, int Columns, bool SwapPlayer)
{
	RowChanged.clear();
	ColumnsChanged.clear();

	Matrix[Row][Columns] = CurrentPlayer;
	ScoreCurrentPlayer++; 

	bool EnemyFound = false;


	// LEFT TILES
	for (int k = Columns - 1; k >= 0; k--)
	{
		if (Matrix[Row][k] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[Row][k] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k + 1 < Columns)
				{
					k++;
					Matrix[Row][k] = CurrentPlayer;
					RowChanged.push_back(Row);
					ColumnsChanged.push_back(k);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	// RIGHT TILES
	for (int k = Columns + 1; k < Size; k++)
	{
		if (Matrix[Row][k] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[Row][k] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k - 1 > Columns)
				{
					k--;
					Matrix[Row][k] = CurrentPlayer;
					RowChanged.push_back(Row);
					ColumnsChanged.push_back(k);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	// TOP TILES
	for (int k = Row - 1; k >= 0; k--)
	{
		if (Matrix[k][Columns] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[k][Columns] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k + 1 < Row)
				{
					k++;
					Matrix[k][Columns] = CurrentPlayer;
					RowChanged.push_back(k);
					ColumnsChanged.push_back(Columns);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	// BOTTOM TILES
	for (int k = Row + 1; k < Size; k++)
	{
		if (Matrix[k][Columns] == Enemy) { EnemyFound = true; }
		else
		{
			// 1 or more enemy pieces are between the current tile and this tile
			if (EnemyFound && Matrix[k][Columns] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while (k - 1 > Row)
				{
					k--;
					Matrix[k][Columns] = CurrentPlayer;
					RowChanged.push_back(k);
					ColumnsChanged.push_back(Columns);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
	}
	EnemyFound = false;


	int r, c;
	// TOP LEFT DIAGONAL
	r = Row - 1;
	c = Columns - 1;
	while (r >= 0 && c >= 0)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r + 1) < Row && (c + 1) < Columns)
				{
					r++;
					c++;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r--;
		c--;
	}
	EnemyFound = false;


	// TOP RIGHT DIAGONAL
	r = Row - 1;
	c = Columns + 1;
	while (r >= 0 && c < Size)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r + 1) < Row && (c - 1) > Columns)
				{
					r++;
					c--;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r--;
		c++;
	}
	EnemyFound = false;


	// BOTTOM LEFT DIAGONAL
	r = Row + 1;
	c = Columns - 1;
	while (r < Size && c >= 0)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r - 1) > Row && (c + 1) < Columns)
				{
					r--;
					c++;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r++;
		c--;
	}


	// BOTTOM RIGHT DIAGONAL
	r = Row + 1;
	c = Columns + 1;
	while (r < Size && c < Size)
	{
		if (Matrix[r][c] == Enemy) { EnemyFound = true; }
		else
		{
			if (EnemyFound && Matrix[r][c] == CurrentPlayer)
			{
				// Change all tiles between the current tile and the given tile to the player's color
				while ((r - 1) > Row && (c - 1) > Columns)
				{
					r--;
					c--;
					Matrix[r][c] = CurrentPlayer;
					RowChanged.push_back(r);
					ColumnsChanged.push_back(c);
					ScoreCurrentPlayer++; ScoreEnemy--;
				}
			}
			break;
		}
		r++;
		c++;
	}

	if (SwapPlayer)
	{
		SwapCurrentPlayer();
	}

	
}
void CoreOthello::SwapCurrentPlayer()
{
	int tmp = ScoreCurrentPlayer;
	ScoreCurrentPlayer = ScoreEnemy;
	ScoreEnemy = tmp;
	if (CurrentPlayer == 1)
	{
		Enemy = 1;
		CurrentPlayer = 0;
	}
	else
	{
		Enemy = 0;
		CurrentPlayer = 1;
		
	}
	PossibleMoves();
}
void CoreOthello::PossibleMoves()
{
	RowPossibileMoves.clear();
	ColumnsPossibileMoves.clear();
	NumberOfPossibileMoves = 0;

	if (CurrentPlayer == 1)
	{
		Enemy = 0;
	}
	else
	{
		Enemy = 1;
	}


	bool EnemyFound;
	for (int K = 0; K < Size; K++)
	{
		for (int i = 0; i < Size; i++)
		{
			EnemyFound = false;
			if (Matrix[K][i] != Enemy && Matrix[K][i] != CurrentPlayer) //Blank Cell
			{
				bool Added = false;
				//Left Tiles
				for (int j = i - 1; j >= 0; j--)
				{
		
					if (Matrix[K][j] == Enemy)
					{
						EnemyFound = true;
					}
					else
					{
						// 1 or more enemy pieces are between the current tile and this tile
						if (EnemyFound && Matrix[K][j] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
				}
				EnemyFound = false;

				// RIGHT TILES
				for (int j = i + 1; j < Size && Added==false; j++)
				{
					if (Matrix[K][j] == Enemy)
					{
						EnemyFound = true;
					}
					else
					{
						// 1 or more enemy pieces are between the current tile and this tile
						if (EnemyFound && Matrix[K][j] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
				}
				EnemyFound = false;

				// TOP TILES
				for (int j = K - 1; j >= 0 && Added == false; j--)
				{
					if (Matrix[j][i] == Enemy) { EnemyFound = true; }
					else
					{
						if (EnemyFound && Matrix[j][i] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
				}
				EnemyFound = false;

				// BOTTOM TILES
				for (int j = K + 1; j < Size && Added == false; j++)
				{
					if (Matrix[j][i] == Enemy) { EnemyFound = true; }
					else
					{
						if (EnemyFound && Matrix[j][i] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
				}
				EnemyFound = false;

				int r, c;

				// TOP LEFT DIAGONAL
				r = K - 1;
				c = i - 1;
				while (r >= 0 && c >= 0 && Added == false)
				{
					if (Matrix[r][c] == Enemy) { EnemyFound = true; }
					else
					{
						if (EnemyFound && Matrix[r][c] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
					r--;
					c--;
				}
				EnemyFound = false;

				// TOP RIGHT DIAGONAL
				r = K - 1;
				c = i + 1;
				while (r >= 0 && c < Size && Added == false)
				{
					if (Matrix[r][c] == Enemy) { EnemyFound = true; }
					else
					{
						if (EnemyFound && Matrix[r][c] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
					r--;
					c++;
				}
				EnemyFound = false;

				// BOTTOM LEFT DIAGONAL
				r = K + 1;
				c = i - 1;
				while (r < Size && c >= 0 && Added == false)
				{
					if (Matrix[r][c] == Enemy) { EnemyFound = true; }
					else
					{
						if (EnemyFound && Matrix[r][c] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
					r++;
					c--;
				}
				EnemyFound = false;

				// BOTTOM RIGHT DIAGONAL
				r = K + 1;
				c = i + 1;
				while (r < Size && c < Size && Added == false)
				{
					if (Matrix[r][c] == Enemy) { EnemyFound = true; }
					else
					{
						if (EnemyFound && Matrix[r][c] == CurrentPlayer)
						{
							RowPossibileMoves.push_back(K);
							ColumnsPossibileMoves.push_back(i);
							NumberOfPossibileMoves++;
							Added = true;
						}
						EnemyFound = false;
						break;
					}
					r++;
					c++;
				}
			}
		}
	}

	if (NumberOfPossibileMoves == 0)
	{
		GameOver = true;
	}
}

int* CoreOthello::IAMove()
{
	int NumberChanged = 0;
	int NumberOfChanged;
	int* FinalRowColumns = new int[2];
	

	for (int J = 0; J < NumberOfPossibileMoves; J++)
	{
		NumberOfChanged = 0;
		bool EnemyFound = false;


		// LEFT TILES
		for (int k = ColumnsPossibileMoves[J] - 1; k >= 0; k--)
		{
			if (Matrix[RowPossibileMoves[J]][k] == Enemy) { EnemyFound = true; }
			else
			{
				// 1 or more enemy pieces are between the current tile and this tile
				if (EnemyFound && Matrix[RowPossibileMoves[J]][k] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while (k + 1 < ColumnsPossibileMoves[J])
					{
						k++;
						NumberOfChanged++;
						
					}
				}
				break;
			}
		}
		EnemyFound = false;


		// RIGHT TILES
		for (int k = ColumnsPossibileMoves[J] + 1; k < Size; k++)
		{
			if (Matrix[RowPossibileMoves[J]][k] == Enemy) { EnemyFound = true; }
			else
			{
				// 1 or more enemy pieces are between the current tile and this tile
				if (EnemyFound && Matrix[RowPossibileMoves[J]][k] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while (k - 1 > ColumnsPossibileMoves[J])
					{
						k--;
						NumberOfChanged++;
					}
				}
				break;
			}
		}
		EnemyFound = false;


		// TOP TILES
		for (int k = RowPossibileMoves[J] - 1; k >= 0; k--)
		{
			if (Matrix[k][ColumnsPossibileMoves[J]] == Enemy) { EnemyFound = true; }
			else
			{
				// 1 or more enemy pieces are between the current tile and this tile
				if (EnemyFound && Matrix[k][ColumnsPossibileMoves[J]] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while (k + 1 < RowPossibileMoves[J])
					{
						k++;
						NumberOfChanged++;
					}
				}
				break;
			}
		}
		EnemyFound = false;


		// BOTTOM TILES
		for (int k = RowPossibileMoves[J] + 1; k < Size; k++)
		{
			if (Matrix[k][ColumnsPossibileMoves[J]] == Enemy) { EnemyFound = true; }
			else
			{
				// 1 or more enemy pieces are between the current tile and this tile
				if (EnemyFound && Matrix[k][ColumnsPossibileMoves[J]] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while (k - 1 > RowPossibileMoves[J])
					{
						k--;
						NumberOfChanged++;
					}
				}
				break;
			}
		}
		EnemyFound = false;


		int r, c;
		// TOP LEFT DIAGONAL
		r = RowPossibileMoves[J] - 1;
		c = ColumnsPossibileMoves[J] - 1;
		while (r >= 0 && c >= 0)
		{
			if (Matrix[r][c] == Enemy) { EnemyFound = true; }
			else
			{
				if (EnemyFound && Matrix[r][c] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while ((r + 1) < RowPossibileMoves[J] && (c + 1) < ColumnsPossibileMoves[J])
					{
						r++;
						c++;
						NumberOfChanged++;
					}
				}
				break;
			}
			r--;
			c--;
		}
		EnemyFound = false;


		// TOP RIGHT DIAGONAL
		r = RowPossibileMoves[J] - 1;
		c = ColumnsPossibileMoves[J] + 1;
		while (r >= 0 && c < Size)
		{
			if (Matrix[r][c] == Enemy) { EnemyFound = true; }
			else
			{
				if (EnemyFound && Matrix[r][c] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while ((r + 1) < RowPossibileMoves[J] && (c - 1) > ColumnsPossibileMoves[J])
					{
						r++;
						c--;
						NumberOfChanged++;
					}
				}
				break;
			}
			r--;
			c++;
		}
		EnemyFound = false;


		// BOTTOM LEFT DIAGONAL
		r = RowPossibileMoves[J] + 1;
		c = ColumnsPossibileMoves[J] - 1;
		while (r < Size && c >= 0)
		{
			if (Matrix[r][c] == Enemy) { EnemyFound = true; }
			else
			{
				if (EnemyFound && Matrix[r][c] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while ((r - 1) > RowPossibileMoves[J] && (c + 1) < ColumnsPossibileMoves[J])
					{
						r--;
						c++;
						NumberOfChanged++;
					}
				}
				break;
			}
			r++;
			c--;
		}


		// BOTTOM RIGHT DIAGONAL
		r = RowPossibileMoves[J] + 1;
		c = ColumnsPossibileMoves[J] + 1;
		while (r < Size && c < Size)
		{
			if (Matrix[r][c] == Enemy) { EnemyFound = true; }
			else
			{
				if (EnemyFound && Matrix[r][c] == CurrentPlayer)
				{
					// Change all tiles between the current tile and the given tile to the player's color
					while ((r - 1) > RowPossibileMoves[J] && (c - 1) > ColumnsPossibileMoves[J])
					{
						r--;
						c--;
						NumberOfChanged++;
					}
				}
				break;
			}
			r++;
			c++;
		}

		if (NumberOfChanged > NumberChanged)
		{
			NumberChanged = NumberOfChanged;
			FinalRowColumns[0] = RowPossibileMoves[J];
			FinalRowColumns[1] = ColumnsPossibileMoves[J];
		}
	}

	setMoves(FinalRowColumns[0], FinalRowColumns[1], true);
	
	return FinalRowColumns;
	
}
