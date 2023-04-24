#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'
#define LAST_POSIBLE_MOVE 9
#define ROW_COLUMN_LENGTH 3

bool isThereAWinner(char board[3][3]);
void drawScreen(char board[3][3]);
void cleanScreen();
void gameIteration(char board[3][3], int player);
void gameLoop(char board[3][3]);
bool placePlayerMove(char playerSymbol, int boardCell, char board[3][3]);
void playerTurn(int player, char board[3][3]);

int main(void)
{
  char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
  };
  gameLoop(board);
  return 0;
}

bool isThereAWinner(char board[3][3])
{
  int rows[ROW_COLUMN_LENGTH];
  int columns[ROW_COLUMN_LENGTH];
  for(int i=0; i < ROW_COLUMN_LENGTH; i++)
  {
    // Check horizontal match
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    // Check vertical match
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
  }
  // Check diagonal match
  if(board[1][1] == PLAYER_ONE || board[1][1] == PLAYER_TWO )
  {
    if(board[1][1] == board[0][0] && board[1][1] == board[2][2]) return true;
    if(board[1][1] == board[2][0] && board[1][1] == board[0][2]) return true;
  }
  return 0;
}

void drawScreen(char board[3][3])
{
  printf("Tic Tac Toe\n");
  printf("Made by Germán Chrystan.\n");
  printf("\n-------------\n");
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++) {
      printf("| %c ", board[i][j]);
      if(j == 2)printf("|");
    }
    printf("\n-------------\n");
  }
}

void cleanScreen()
{
  system("clear");
}

void gameIteration(char board[3][3], int player)
{
  drawScreen(board);
  playerTurn(player, board);
  cleanScreen();
}


void gameLoop(char board[3][3])
{
  bool result;
  int player;
  int move = 1;
  cleanScreen();
  do {
    player = player == 1 ? 2 : 1;
    gameIteration(board, player);
    result = isThereAWinner(board);
    move++;
  } while(!result && move <= LAST_POSIBLE_MOVE);
  if (result) printf("Player %d won!!!\n", player);
  else printf("Game Over. No winner\n");
}

bool placePlayerMove(char playerSymbol, int boardCell, char board[3][3])
{
  if (boardCell < 0 || boardCell > 9)
  {
    printf("Invalid move\n");
    return 0;
  }

  boardCell--;
  int x = boardCell / 3;;
  int y = boardCell % 3;
  if (board[x][y] == PLAYER_ONE || board[x][y] == PLAYER_TWO) {
    printf("Invalid move\n");
    return 0;
  }
  board[x][y] = playerSymbol;
  return 1;
}

void playerTurn(int player, char board[3][3])
{
  char symbol = player == 1 ? PLAYER_ONE : PLAYER_TWO;
  int playerMove;
  do {
    printf("Player %d: Enter a board cell: ", player);
    scanf("%d", &playerMove);
  } while(!placePlayerMove(symbol, playerMove, board));
}