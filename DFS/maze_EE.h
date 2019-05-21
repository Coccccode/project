#ifndef maze_EE_h 
#define maze_EE_h 
#include <iostream> 
#include <stack>
using namespace std;
class node {
public:
	int x, y;
	int dir;

	node(int i, int j)
	{
		x = i;
		y = j;

		// Initially direction 
		// set to 0 
		dir = 0;
	}
};
class RatInMaze {
private:     int fx, fy;  // Food coordinates 
			 bool** visited;
			 int** maze;
			 int m, n;
			 stack<node> s;

public:
	void get_maze(int** mz, int m, int n);
	void get_food_coordinate(int X, int Y);
	bool isReachable();
	void print_visitedited();
};
void RatInMaze::get_maze(int** mz, int m, int n) {
	maze = new int* [m];
	this->m = m;
	this->n = n;
	for (int i = 0; i < m; i++) {
		maze[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			 maze[i][j]=mz[i][j];
		}
	}
}
void RatInMaze::get_food_coordinate(int X, int Y){
	fx = X;
	fy = Y;
}
bool RatInMaze::isReachable(){
	node q(0, 0);
	int mark=0;
	visited = new bool* [m];
	for (int i = 0; i < m; i++) {
		visited[i] = new bool[n];
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;
	visited[0][0] = true;
	s.push(q);
	while (!s.empty())
	{
		node tmp = s.top();
		if (tmp.x == fx && tmp.y == fy) {
			mark = 1;
			break;
		}
		int dir;
		for (dir = 0; dir < 4; dir++) {
			int i, j;
			if (dir == 0) {//up
				i = -1;
				j = 0;
			}
			else if (dir == 1) {//left
				i = 0;
				j = -1;
			}
			else if (dir == 2) {//down
				i = 1;
				j = 0;
			}
			else if (dir == 3) {//right
				i = 0;
				j = 1;
			}
			if (tmp.x+i>=0&&tmp.x+i<m&&tmp.y + j>= 0 && tmp.y + j <n&&maze[tmp.x + i][tmp.y + j] == 1 && !visited[tmp.x + i][tmp.y + j]) {
				tmp.x = tmp.x + i;
				tmp.y = tmp.y + j;

				tmp.dir = dir;
				visited[tmp.x][tmp.y] = true;
				s.push(tmp);
				break;
			}
		}
		if (dir == 4) {//说明无路可走，当前节点出栈
			visited[s.top().x][s.top().y] = true;
			s.pop();
		}
	}
	if (mark == 0)//到达终点mark=1到不达终点mark=0
		return false;
	else
		return true;
}
void RatInMaze::print_visitedited() {
	stack<node> tmps;
while (!s.empty()) {//s里面的顺序是重点到起点的证据			
	node p1 = s.top();
	tmps.push(p1);
	s.pop();
}
while (!tmps.empty()) {//输出tmp里面的路径，这样刚好是从起点到终点的顺序			
	node p1 = tmps.top();
	tmps.pop();
	cout << "(" << p1.x << "," << p1.y << ")";
	if (!tmps.empty()) {
		cout << "-->";
	}
}
cout << endl;
}
#endif /* maze_EE_h */ 