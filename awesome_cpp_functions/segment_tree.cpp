#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

long long a[5000];
vector <long long> tree;

int N;
int length;

int create_tree(int l, int r, int i)
{
	
	long long x;
	long long y;
	
	if(l == r) {
		tree[i] = a[l];
		return a[l];
	}

	x = create_tree(l, (l+r)/2, i * 2);
	y = create_tree((l+r)/2 + 1, r, i * 2 + 1);

	tree[i] = x + y;

	return tree[i];

}


int rmq(int i, int j, int b, int e, int node)
{
	
	long long x;
	long long y;
	
	if(b <= i and e >= j) {
		return tree[node];
	}

	if(e < i or b > j) {
		return 0;
	}

	x = rmq(i, (i + j) / 2, b, e, node * 2);
	y = rmq((i+j)/2 + 1, j, b, e, node * 2 + 1);

	return x + y;
}




int main()
{

	int t;
	int b;
	int e;

	cin >> N;

	length = 2 * pow((floor(log2(N)) + 1), 2);
	
	vector <long long> temp(length + 3);
	swap(temp, tree);
	
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	create_tree(0, N-1, 1);
	
	cin >> t;

	for (int cs = 0; cs < t; cs++) {
		cin >> b;
		cin >> e;
		cout << rmq(0, N-1, b, e, 1)<< endl;
	}



}

