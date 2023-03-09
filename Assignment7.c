/*
DESCRIPTION: Programming Excerise Seven
CLASS: COSC 1420.SO1
AUTHOR: TYLER ECHOLS
DATE: Mar 2019
*/
#pragma warning (disable:4996)

#include <memory.h>		
#include <time.h>		
#include <stdlib.h>	
#include <stdio.h>



#define MaxCols 60
#define MaxRows 60


int main()
{

	const time_t	WaitTime=2;
	char	Board[MaxRows + 2][MaxCols + 2];
	int		Col;
	char	NextBoard[MaxRows + 2][MaxCols + 2];
	int		Generation =0 ;
	int		Row;
	int counter;
	time_t	StopTime;


	memset(Board, 0, (MaxRows + 2) * (MaxCols + 2));

	printf(" Enter Value 1 and Value 2, then type 0 and 0 to begin \n");

	for (;;)
	{
		scanf("%d", &Row);

		scanf("%d", &Col);
		if (Row == 0 && Col == 0)
			break;
		if (Row < 0 && Col < 0)
			printf("Invalid Input \n");
		else
			Board[Row][Col] = 1;
	}



	for (;;)
	{
		printf("\tGeneration", "%d", Generation++);
		printf(" Alive cells will be indicated by *, and dead cells are indicated by - \n");
		for (Row = 1; Row <= MaxRows; Row++)
		{
			for (Col = 1; Col <= MaxCols; Col++)
				printf("%c", Board[Row][Col] ? '*' : '-');

		}


		for (Row = 1; Row <= MaxRows; Row++)
		{
			for (Col = 1; Col <= MaxCols; Col++)
			{
				if (Board[Row - 1][Col - 1] == 1)

				{
					counter++;
				}

				if (Board[Row - 1][Col] == 1)

				{
					counter++;
				}

				if (Board[Row - 1][Col + 1] == 1)

				{
					counter++;
				}

				if (Board[Row][Col + 1] == 1)

				{
					counter++;
				}

				if (Board[Row + 1][Col + 1] == 1)

				{
					counter++;
				}

				if (Board[Row + 1][Col] == 1)

				{
					counter++;
				}

				if (Board[Row + 1][Col - 1] == 1)

				{
					counter++;
				}

				if (Board[Row][Col - 1] == 1)

				{
					counter++;
				}


				if (counter >= 4)
					NextBoard[Row][Col] = 0;

				if (counter <= 1)
					NextBoard[Row][Col] = 0;


				if (counter == 3)
					NextBoard[Row][Col] = 1;

				if (counter == 2)
					NextBoard[Row][Col] = Board[Row][Col];

				counter = 0;


			}
		}

		char cont;
		for (;;)
		{
			printf("Continue? Y/N");
			scanf("%c", &cont); 
			if ((cont == 'Y') || (cont == 'y'))
				break;
			if ((cont == 'N') || (cont == 'n'))
				exit(0);

		}

		memcpy(Board, NextBoard, MaxRows * MaxCols );


	}
	
}