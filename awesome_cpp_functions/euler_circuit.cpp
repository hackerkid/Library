/*
PROG: fence
ID: bornawe1
LANG: C++
*/
#include <queue>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <limits.h>
#include <algorithm>
using namespace std;

int a[1028][1028];
int n;
int end;
int circuit[1028];
int index;
int edge_count[1028];


fstream cin;
fstream cout;

vector < vector <int> > q(1028);
int euler(int x)
{
	int y;
	
	if(edge_count[x] == 0) {
		circuit[index] = x;
		index++;
		return 0;
	}

	for (int i = 0; i < q[x].size(); i++) {
		y = q[x][i];
		if(a[x][y] != 0) {
			a[x][y]--;
			a[y][x]--;
			edge_count[x]--;
			edge_count[y]--;
			euler(y);
		}

	}
	circuit[index] = x;
	index++;

}







int main()
{
	int x;
	int y;
	int start;
	int mini;

	mini = INT_MAX;
	
	cin.open("fence.in", ios::in);
	cout.open("fence.out", ios::out);
	start = 0;
	end = 0;


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> y;
		mini = min(mini, min(x, y));
		a[x][y]++;
		a[y][x]++;
		edge_count[x]++;
		edge_count[y]++;
		q[x].push_back(y);
		q[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {

		
		if(q[i].size() % 2 == 1 and start == 0) {
			start = i;
			break;
		}
		
		
	}

	if(start == 0) {
		start = mini;
	}
	
	index = 0;

	for (int i = 0; i <= 501; i++) {
		sort(q[i].begin(), q[i].end());
	}
	euler(start);

	for (int i = index-1; i >= 0; i--) {
		cout << circuit[i] << endl;
	}


}
