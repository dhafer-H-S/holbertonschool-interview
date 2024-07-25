#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_menger - Determines if a cell at (x, y) should be filled in a Menger sponge
 * @x: The x coordinate of the cell
 * @y: The y coordinate of the cell
 *
 * Return: 1 if the cell should be filled, 0 otherwise
 */
int is_menger(int x, int y)
{
    while (x > 0 && y > 0)
    {
        if (x % 3 == 1 && y % 3 == 1)
            return (0);
        x /= 3;
        y /= 3;
    }
    return (1);
}

/**
 * menger - Draws a 2D Menger Sponge of a given level
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
    int size, x, y;

    if (level < 0)
        return;
    size = pow(3, level);
    for (y = 0; y < size; y++)
    {
        for (x = 0; x < size; x++)
        {
            if (is_menger(x, y))
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}
