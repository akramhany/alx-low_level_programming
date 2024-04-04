#!/usr/bin/python3
"""
a function def island_perimeter(grid): that returns the perimeter of
the island described in grid
"""


def island_perimeter(grid):
    """Returns the perimeter of island in grid"""

    height = len(grid)

    island_blocks = 0
    for i in range(height):
        for num in grid[i]:
            if num == 1:
                island_blocks += 1

    if island_blocks == 0:
        return 0
    return island_blocks * 2 + 2
