#include<stdio.h>
#include<stdbool.h>
#define BRICK_SIZE 4

void printPyramid(int pyramidLevels);

int main(void)
{
  int levelQuantity = 0;
  int input;
  printf("Please enter blocks amount: ");
  scanf("%d", &input);
  while(levelQuantity < input)
  {
    levelQuantity++;
    input -= levelQuantity;
  }
  printPyramid(levelQuantity);
  printf("\n%d %s built", levelQuantity, levelQuantity > 1 ? "levels were" : "level was");
  printf("\n%d %s remaining\n", input, input > 1 ? "blocks" : "block");
}

void printPyramid(int levelQuantity)
{
  char block[BRICK_SIZE+1] = "[__]";
  for (int i = 1; i <= levelQuantity; i++)
  {
    int spaceLength = (levelQuantity - i) * BRICK_SIZE / 2;
    for (int k = 0; k < spaceLength; k++)
    {
      printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
      printf("%s", block);
    }
    printf("\n");
  }
}