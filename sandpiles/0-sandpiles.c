#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - Prints the grid
 * @grid: The grid to be printed
 */
void print_grid(int grid[3][3]);

/**
 * is_stable - Checks if the grid is stable
 * @grid: The grid to be checked
 * Return: True if stable, False otherwise
 */
bool is_stable(int grid[3][3]);

/**
 * stabilize - Stabilizes the grid
 * @grid: The grid to be stabilized
 */
void stabilize(int grid[3][3]);

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: The first sandpile
 * @grid2: The second sandpile, to be added to the first
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Step 1: Add the two sandpiles */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Step 2 & 3: Check stability, print and stabilize if needed */
	while (!is_stable(grid1))
	{
		print_grid(grid1);
		stabilize(grid1);
	}
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: Sandpile to check
 * Return: True if stable, false otherwise
 */
bool is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (false);
			}
		}
	}

	return (true);
}

/**
 * print_grid - Prints a 3x3 grid
 * @grid: Grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stabilize - Stabilizes a sandpile
 * @grid: Sandpile to stabilize
 */
void stabilize(int grid[3][3])
{
	int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}
