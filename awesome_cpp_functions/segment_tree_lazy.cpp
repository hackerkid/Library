#include <iostream>
#define size 1000
using namespace std;

long long tree[2 * size + 1];
long long a[size];
long long lazy[size];



long long update(int a, int b, int i, int j, int node, int val)
{
	

	if(lazy[node]) {
		
		tree[node] += lazy[node] * ((b - a) + 1);
		
		if(a != b) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;

	}

	if(b < i or a > j) {
		return 0;
	}


	if(a >= i and b <= j) {
		tree[node] += val * ((b - a) + 1);
		
		if(a != b) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		
		return 0;
	}

	update(a, (a+b)/2, i, j, node * 2, val);
	update((a+b)/2 + 1,b, i, j, node * 2 + 1, val);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];


}

int query(int i, int j,int a, int b,int node)
{
	long long x;
	long long y;

	if(b < a or a > j or b < i) {
		return 0;
	}
	
	if(lazy[node]) {
		tree[node] += lazy[node]  * ((j - i) + 1);
		if(i != j) {
			tree[node * 2] += lazy[node];
			tree[node * 2 + 1] += lazy[node];

		}

		lazy[node] = 0;
	}
	
	if(i >= a and j  <= b) {
		return tree[node];
	}

	x = query(i, (i+j)/2,a,b, node * 2);
	y = query((i+j)/2+1, j,a, b,node * 2 + 1);

	return x + y;

}






	

long long create_tree(int i, int j, int node)
{
	
	long long x;
	long long y;

	if(i == j) {
		tree[node] = a[i];
		return a[i];
	}

	x = create_tree(i, (i+j)/2, node * 2);
	y = create_tree((i+j)/2 + 1, j, node * 2 + 1);

	tree[node] = x + y;

	return x + y;

}



int main()
{

	int n;
	
	n = 5;

	for (int i = 0; i < 5; i++) {
		a[i] = i+1;
	}
	
	create_tree(0, n-1, 1);
	cout << query(0, n-1,0, n-1,1) << endl;
	update(0, n-1, 0, n-1, 1, 2);
	cout << query(0, n-1, 0, n-1,1) << endl;

	
}
	


