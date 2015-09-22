int extendedEuclid(int A, int B, int &X, int &Y) {
	int x, y, a, b, m, n, u, v, q, r;
	v = x = 0, u = y = 1;
	for(a = A, b = B; a; b = a, a = r, x = u, y = v, u = m, v = n) {
		q = b / a, r = b % a;
		m = x - (u * q), n = y - (v * q);
	}
	X = x, Y = y;
	return b;
}

int modularInverse(int a, int n) {
	int x, y, r;
	extendedEuclid(a, n, x, y);
	r = x % n;
	return r < 0? r + n : r;
}

