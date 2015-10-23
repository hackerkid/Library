int modPow(long long b, long long e, int m) {
	long long res = 1;
    for (; e; e >>= 1, b = b*b%m) if (e & 1) res = res*b%m;
    	return res;
    }
}
