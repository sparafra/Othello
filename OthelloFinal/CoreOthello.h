#ifndef COREOTHELLO_
#define COREOTHELLO_

#include <vector>

using namespace std;

const int Size = 8; // The size of the game board

class CoreOthello
{
private:
	bool Multiplayer;
	int** Matrix;
	bool GameOver;
	int NumberOfPossibileMoves;
	int CurrentPlayer;
	int Enemy;
	int ScoreCurrentPlayer;
	int ScoreEnemy;

	vector<int>RowPossibileMoves;
	vector<int>ColumnsPossibileMoves;
	vector<int>RowChanged;
	vector<int>ColumnsChanged;
public:
	CoreOthello(bool Multiplayer);
	void Init();
	void PossibleMoves();
	bool gameOver() { return GameOver; };
	void ClearPossibleMoves();
	void setMoves(int Row, int Columns);
	void setMoves(int Row, int Columns, bool SwapPlayer);
	vector<int> getRowPossibileMoves() { return RowPossibileMoves; };
	vector<int> getColumnsPossibileMoves() { return ColumnsPossibileMoves; };
	vector<int> getRowChanged() { return RowChanged; };
	vector<int> getColumnsChanged() { return ColumnsChanged; };
	void SwapCurrentPlayer();
	int getCurrentPlayer() { return CurrentPlayer; };
	int getScoreCurrentPlayer() { return ScoreCurrentPlayer; };
	int getScoreEnemy() { return ScoreEnemy; };
	int getSize() { return Size; };
	int** getMatrix() { return Matrix; };
	int getNumberOfPossibileMoves() { return NumberOfPossibileMoves; };

	int* IAMove();
};
#endif