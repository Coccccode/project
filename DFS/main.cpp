#include "maze_EE.h"
int main()
{ 
	RatInMaze a, b;
	    // The first Maze matrix 
	int maze1[4][5] = {
		 { 1, 0, 1, 1, 0 },
		 { 1, 1, 1, 0, 1 },
		 { 0, 1, 0, 1, 1 },
		 { 1, 1, 1, 1, 1 }
		 };
	int** mz = new int* [4];
	for (int i = 0; i < 5; i++) {
		mz[i] = new int[5];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			mz[i][j] = maze1[i][j];
		}
	}
	     // Food coordinates 
	int fx = 2;
	int fy = 3;
	a.get_food_coordinate(fx, fy);
    a.get_maze(mz, 4, 5);
    if (a.isReachable()) {
	cout << "Path Found!" << '\n';
	}
	else
	cout << "No Path Found!" << '\n';
	a.print_visitedited();
	 // The second Maze matrix 
	int maze2[5][6] = {
	{ 1, 0, 1, 1, 0, 1},
	{ 1, 1, 0, 0, 1, 1},
	{ 0, 1, 0, 1, 1, 0},
	{ 1, 1, 1, 0, 1, 0},
	{ 1, 0, 1, 0, 1, 0},
	};
	mz = new int* [5];
	for (int i = 0; i < 5; i++) {
		mz[i] = new int[6];
    }
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			mz[i][j] = maze2[i][j];
		}
	}
		// Food coordinates 
	fx = 3;
	fy = 4;
	b.get_food_coordinate(fx, fy);
	b.get_maze(mz, 5, 6);
	if (b.isReachable()) {
	cout << "Path Found!" << '\n';
	}
	else
	cout << "No Path Found!" << '\n';
	b.print_visitedited();
	return 0;
 }
