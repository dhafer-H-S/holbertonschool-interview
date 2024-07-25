#include "slide_line.h"

/**
 * slide_left - Slides and merges the line to the left.
 * @line: Pointer to array of integers.
 * @size: Number of elements in array.
 */
void slide_left(int *line, size_t size)
{
    size_t i, j;
    int last_merged = -1;

    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] == 0)
            continue;
        if (last_merged != -1 && line[last_merged] == line[i])
        {
            line[last_merged] *= 2;
            line[i] = 0;
            last_merged = -1;
        }
        else
        {
            if (j != i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            last_merged = j;
            j++;
        }
    }
}

/**
 * slide_right - Slides and merges the line to the right.
 * @line: Pointer to array of integers.
 * @size: Number of elements in array.
 */
void slide_right(int *line, size_t size)
{
    size_t i, j;
    int last_merged = -1;

    for (i = size - 1, j = size - 1; (int)i >= 0; i--)
    {
        if (line[i] == 0)
            continue;
        if (last_merged != -1 && line[last_merged] == line[i])
        {
            line[last_merged] *= 2;
            line[i] = 0;
            last_merged = -1;
        }
        else
        {
            if (j != i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            last_merged = j;
            j--;
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers to the left or right.
 * @line: Pointer to array of integers.
 * @size: Number of elements in array.
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT).
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return (1);
}
