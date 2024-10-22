//tac-tic-toe game井字棋游戏
#include<stdio.h>
#include<stdlib.h>
int check_row_and_column(int position[3][3]);
int check_diagonal(int position[3][3]);
#define size 3
int result = -1;
int position[3][3];
int main()
{
	printf("Let's play the tac-tic-toe game!\n");
	printf("\" X \" is signed by 1 and \" O \" is signed by 0.\n");
	printf("Now,START!\n");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf("%d", &position[i][j]);
	if (check_row_and_column(position) != -1) goto finish;
	else if (check_diagonal(position) != -1) goto finish;
	else
	{
		printf("Great work, both of you are winners!");
		exit(0);
	}
finish:if (result)
printf("The user of \" X \" is the winner!");
else printf("The user of \" O \" is the winner!");
	return 0;
}

int check_row_and_column(int position[3][3])
{
	int NumOf_O = 0,NumOf_X = 0;
	for (int i = 0; i < size && result == -1; i++)
	{
		int NumOf_O = 0, NumOf_X = 0;
		for (int j = 0; j < size; j++)
		{
			if (position[i][j] == 1)
				NumOf_X++;
			else
				NumOf_O++;
			if (NumOf_X == size)
				result = 1;
			else if (NumOf_O == size)
				result = 0;
		}
	}
	if (result != -1) goto END;
	else int NumOf_O = 0, NumOf_X = 0;
		for (int i = 0; i < size && result == -1; i++)
	{
		int NumOf_O = 0, NumOf_X = 0;
		for (int j = 0; j < size; j++)
		{
			if (position[j][i] == 1)
				NumOf_X++;
			else
				NumOf_O++;
			if (NumOf_X == size)
				result = 1;
			else if (NumOf_O == size)
				result = 0;
		}
	}
END:return result;
}

int check_diagonal(int position[3][3])
{
	int NumOf_O = 0, NumOf_X = 0;
	for (int i = 0; i < size&&result==-1; i++)
	{
		if (position[i][size-1-i] == 1)
			NumOf_X++;
		else
			NumOf_O++;
		if (NumOf_X == size)
			result = 1;
		else if (NumOf_O == size)
			result = 0;
	}
	if (result != -1) goto END;
	else 
	{
		int NumOf_O = 0, NumOf_X = 0;
		for (int i = 0; i < size && result == -1; i++)
		{
			if (position[i][i] == 1)
				NumOf_X++;
			else
				NumOf_O++;
			if (NumOf_X == size)
				result = 1;
			else if (NumOf_O == size)
				result = 0;
		}
	}
END:return result;
}