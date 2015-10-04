#include <iostream>
#define MOD 10000000
using namespace std;


int multi(int a[2][2], int b[2][2], int result[2][2])
{

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				result[i][j] = result[i][j] + a[i][k] * b[k][j];
				result[i][j] = result[i][j];
			}
		}
	}

}
int exponentation(int z[2][2], int result[2][2], int n)
{
	int temp[2][2];

	result[0][0] = 1;
	result[0][1] = 0;
	result[1][0] = 0;
	result[1][1] = 1;

	while(n) {
		
		if(n % 2) {
			
			multi(result, z, temp);

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					result[i][j] = temp[i][j];
				}
			}
		}

		multi(z, z, temp);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				z[i][j] = temp[i][j];
			}
		}

		n = n / 2;
	}
}
	
int main()
{

	int z[2][2];
	int inp[2][2];
	int result[2][2];
	int k;

	
	for (int i = 3; i <= 10; i++) {

		z[0][0] = 1;
		z[0][1] = 1;
		z[1][0] = 1;
		z[1][1] = 0;

		result[0][0] = 1;
		result[1][0] = 2;


		exponentation(z, result, i - 2);

		cout << i - 2  << " " << result[0][0] << endl;
	}


}
	









