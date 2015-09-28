#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#define SIZE 10000
using namespace std;

vector < vector <int> > g;
int vis[SIZE];
int dur[SIZE];
int low[SIZE];
int art[SIZE];
int counter;
int parent[SIZE];

int find_articulation(int x)
{
	int child;
	int y;

	counter++;
	vis[x] = 1;
	child = 0;

	dur[x] = low[x] = counter;

	for (int i = 0; i < g[x].size(); i++) {
		y = g[x][i];
		child++;

		if(vis[y] == 0) {
			parent[y] = x;
			find_articulation(y);
			low[x] = min(low[x], low[y]);

			if(low[y] > dur[x]) {
				cout << x << " " << y << endl;
			}
		}

		else {
			if(y != parent[x]) {
				low[x] = min(low[x], dur[y]);
			}
		}

	}


}

int main()
{

	int t;
	int n;
	int m;
	int x;
	int y;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		scanf("%d", &n);
		scanf("%d", &m);

		vector < vector <int> > tg(n + 2);
		swap(tg, g);
		memset(parent, -1, sizeof parent);
		memset(vis, 0, sizeof vis);
		memset(art, 0, sizeof art);
		counter = 0;

		for (int i = 0; i <  m; i++) {
			cin >> x;
			cin >> y;
			
			g[x].push_back(y);
			g[y].push_back(x);

		}

		for (int i = 0; i <= n; i++) {
			if(!vis[i]) {
				find_articulation(i);
			}
		}

		for (int i = 0; i <= n; i++) {
			if(art[i]) {
				cout << i << " ";
			}
		}
		cout << endl;


	}

}




