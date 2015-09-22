#include <iostream>
#include <stdio.h>
using namespace std;
int q;


inline int zeros(int n) {
	int ret = 0;
	while(n > 0) {
		n /= 5;
		ret += n;
	}
	return ret;
}

}
