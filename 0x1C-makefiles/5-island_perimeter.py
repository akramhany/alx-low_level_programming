#!/usr/bin/python3
"""
a function def island_perimeter(grid): that returns the perimeter of
the island described in grid
"""


def island_perimeter(grid):
    """Returns the perimeter of island in grid"""

    height = len(grid)

    island_perimeter = 0
    for i in range(height):
        width = len(grid[i])

        for j in range(width):
            if grid[i][j] == 0:
                continue
            num = 4
            if i + 1 < height and grid[i+1][j] == 1:
                num -= 1
            if i - 1 >= 0 and grid[i-1][j] == 1:
                num -= 1
            if j + 1 < width and grid[i][j+1] == 1:
                num -= 1
            if j - 1 >= 0 and grid[i][j-1] == 1:
                num -= 1
            island_perimeter += num

    return island_perimeter
