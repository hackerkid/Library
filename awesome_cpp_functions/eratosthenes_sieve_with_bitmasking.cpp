#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define size 100000000
long long a[size / 64 + 10];
int prime[5761456];

int count;

int sieve_with_bit_masking()
{


	for (long long i = 3; i <= sqrt(size); i += 2) {
		if(!(a[i/64]&(1LL<<(i%64)))) {
			for(long long j = i * i; j <= size; j += 2 * i) {
				a[j/64] |= (1LL<<(j%64));
			}
		}
	}
			

	for (long long i = 3; i <= size; i += 2) {
		if(!(a[i / 64] & (1LL << (i % 64)))) {
			prime[count++] = i;
		}

	}

	return 0;


}

int main()
{	

	sieve_with_bit_masking();
}


