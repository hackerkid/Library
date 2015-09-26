#include <iostream>
#define SIZE 10000

using namespace std;

int dj_a[SIZE];
int dj_size[SIZE];

int dj_parent(int x)
{

	if(dj_a[x] == x) {
		return x;
	}

	else {
		dj_a[x] = dj_a[dj_a[x]];
		x = dj_a[x];
		return dj_parent(x);
	}

}

int dj_union(int x, int y)
{
	int par_a;
	int par_b;

	if(dj_parent(x) == dj_parent(y)) {
		return 0;
	}

	par_a = dj_parent(x);
	par_b = dj_parent(y);

	if(dj_size[par_a] > dj_size[par_b]) {
		dj_a[par_b] = par_a;
		dj_size[par_a] = dj_size[par_a] + dj_size[par_b];
	}

	else {
		dj_a[par_a] = par_b;
		dj_size[par_b] = dj_size[par_a] + dj_size[par_b];
	}

}

int find(int x, int y)
{

	if(dj_parent(x) == dj_parent(y)) {
		return true;
	}

	else {
		return false;
	}

}



int main()
{

	int n;
	n = 10;

	for (int i = 0; i < n; i++) {
		dj_a[i] = i;
		dj_size[i] = 1;
	}

	dj_union(1, 2);
	cout << dj_parent(1) << endl;
	cout << dj_parent(2) << endl;
	dj_union(2, 3);
	cout << dj_parent(3) << endl;
	
	dj_union(4, 5);
	dj_union(5, 6);
	dj_union(6, 7);
	dj_union(7, 8);
	dj_union(1, 5);
	dj_union(1, 9);

	for (int i = 1; i < n; i++) {
		cout << dj_parent(i) << " ";
	}

	cout << endl;
}


