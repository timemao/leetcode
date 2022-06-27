#include <stdio.h>
#include <iostream>
#include <string>

#define MAX_STRING 100

using namespace std;

#define MIN(x, y)		((x)<(y)?(x):(y))
#define INFINITY 1000000;

struct pnt
{
	int x;
	int y;
};

int map[6] = { 10, 30, 10,0, 5, 5 };
int max_dist = 10;

int dist(int *h_vals,int i, int j, int k, int l,int rows,int cols)
{
	int dist_val = -1;
	dist_val = h_vals[k*cols + l]- h_vals[i*cols + j];
	if (dist_val > max_dist)
		dist_val = INFINITY;
	return dist_val;
}

int path_is_done(pnt* path,int n_path, int x, int y)
{
	for (int i = 0; i < n_path; i++)
	{
		if (path[i].x == x && path[i].y == y)
			return 1;
	}
	return 0;
}

int fun(pnt *path,int n_done, int i,int j,int rows,int cols)
{
	int f1, f2, f3, f4;
	if (i < 0 || j < 0)
		return INFINITY;

	if (path_is_done(path,n_done, i, j)==1)
		return INFINITY
	else
	{
		path[n_done].x = 1;
		path[n_done].y = 1;
		n_done = n_done + 1;
	}

	if (i == rows && j == cols)
		return -1;
	f1=dist(map, i, j, i - 1, j, rows, cols) + fun(path,n_done, i - 1, j, rows, cols);
	f2=dist(map, i, j, i + 1, j, rows, cols) + fun(path,n_done, i + 1, j, rows, cols);
	f3=dist(map, i, j, i, j-1, rows, cols) + fun(path,n_done, i, j-1, rows, cols);
	f4=dist(map, i, j, i, j+1, rows, cols) + fun(path,n_done, i, j+1, rows, cols);

	int dist_ij = MIN(f4,MIN(f3,MIN(f1, f2)));
	return dist_ij;
}

int main()
{
	int n = 2;
	int m = 3;

	pnt path[100] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		path[i].x = -1;
		path[i].y = -1;
	}

	//------------- vali data -------------//
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", map[i*m+j]);
		}
		printf("\n");
	}
	//-------------- calc dist ----------------//
	int startx, starty;
	startx = 0;
	starty = 0;
	int n_done = 0;
	int dist_ij=fun(path,n_done, 0, 0, n, m);

	printf("min_dist=%d\n", dist_ij);
	getchar();
	return 0;
}