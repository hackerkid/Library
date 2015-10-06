#include <iostream>
#include <string.h>
using namespace std;


int create_tree(int input[],int tree[], int n)
{	
	int x;

	for (int i = 1; i <= n; i++) {
		x = i;

		while(x <= n) {
			tree[x] += input[i];
			x += (x & (-x));
		}
	}
}


int update(int tree[], int x, int val, int n)
{
	while(x <= n) {
		tree[x] +=  val;
		x += (x & (-x);
	}
}

int query(int tree[], int x)
{	
	int sum;
	sum = 0;

	while(x > 0) {
		sum += tree[x];
		x -= (x & (-x));
	}

	return sum;
}
int main()
{
	int a[1000];
	int tree[1005];
	int n;
	int x;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(tree, 0, sizeof(tree));

	create_tree(a, tree, n);
	
	cout << query(tree, 4) << endl;
	
	update(tree, 3, 7,n);


	cout << query(tree, 4) << endl;

	
	cout << query(tree, 5) << endl;

}
