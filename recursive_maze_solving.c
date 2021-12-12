/******************************************************************************

Mase Solving by Recursion

reference: 
https://tinyurl.com/2ftbjxyp

OnlineGDB link: 
https://onlinegdb.com/eaD0l_vid3

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 8
#define HEIGHT 8

void printMaze(char maze[WIDTH][HEIGHT]) {

    for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                    printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool findPath(char maze[WIDTH][HEIGHT], int x, int y) {

    maze[x][y] = '.';

    if (x == WIDTH - 1 && y == HEIGHT - 1) {
        return true;
    }

    if (x + 1 < WIDTH && maze[x + 1][y] == ' ') {
        if (findPath(maze, x + 1, y)) {
            return true;
        }
    }

    if (x - 1 >= 0 && maze[x - 1][y] == ' ') {
        if (findPath(maze, x - 1, y)) {
            return true;
        }
    }

    if (y + 1 < HEIGHT && maze[x][y + 1] == ' ') {
        if (findPath(maze, x, y + 1)) {
            return true;
        }
    }

    if (y - 1 >= 0 && maze[x][y - 1] == ' ') {
        if (findPath(maze, x, y - 1)) {
            return true;
        }
    }

    maze[x][y] = ' ';

    return false;
}

int main() {

    char maze[WIDTH][HEIGHT] = {
        {' ', ' ', 'x', 'x', 'x', 'x', 'x', 'x'},
        {' ', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {' ', 'x', 'x', 'x', ' ', ' ', ' ', 'x'},
        {' ', ' ', ' ', ' ', ' ', 'x', ' ', ' '},
        {'x', 'x', 'x', 'x', ' ', 'x', ' ', ' '},
        {'x', 'x', 'x', 'x', ' ', 'x', ' ', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', ' ', ' '},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', ' '},
    };

    printMaze(maze);
    printf("\n");

    if (findPath(maze, 0, 1)) {
        printf("Maze completed!\n");
        printMaze(maze);
    } else {
        printf("No path found!");
    }

    return 0;
}
