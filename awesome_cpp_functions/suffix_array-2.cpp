
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAXN 200010
int RA[MAXN], SA[MAXN], LCP[MAXN], *FC, *SC, step;
char S[MAXN], Q[MAXN];
bool cmp(int a, int b) {
    if (step==-1 || FC[a]!=FC[b]) return FC[a] < FC[b];
    return FC[a+(1<<step)] < FC[b+(1<<step)];
}
void suffix_array(char *S, int n) { // O(n log^2(n))
    for (int i=0; i<n; i++) RA[i] = S[SA[i] = i];
    for (FC=RA, SC=LCP, step=-1; (1<<step)<n; step++) {
        sort(SA, SA+n, cmp);
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (i>0 && cmp(SA[i-1],SA[i])) cnt++;
            SC[SA[i]] = cnt;
        }
        if (cnt==n-1) break; // all distinct, no need to continue
        swap(FC,SC);
    }
    for (int i=0; i<n; i++) RA[SA[i]] = i;
} 