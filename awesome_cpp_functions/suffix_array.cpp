#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
char S[1001];
int SA[1001], n;
int SA_cmp(const void *a, const void *b) { 
	return strcmp(S + *(int*)a, S + *(int*)b); }

int main() { 
    n = strlen(gets(S));
    for (int i = 0; i < n; i++) SA[i] = i; // sort
    qsort(SA, n, sizeof(int), SA_cmp);
	for (int i = 0; i < n; ++i)
	{
		cout << SA[i] << endl;
	}
	
	for (int i = 0; i < n; i++) printf("%d %s\n", SA[i], S+SA[i]);
} 	