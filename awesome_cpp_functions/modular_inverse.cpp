void extEuclid(int a, int b, int &x, int &y, int &gcd) {
    x = 0; y = 1; gcd = b;
    int m, n, q, r;
    for (int u=1, v=0; a != 0; gcd=a, a=r) {
        q = gcd / a; r = gcd % a;
        m = x-u*q; n = y-v*q;
        x=u; y=v; u=m; v=n;
    }
}
 
    // The result could be negative, if it's required to be positive, then add "m"
int modInv(int n, int m) {
    int x, y, gcd;
    extEuclid(n, m, x, y, gcd);
    if (gcd == 1) return x % m;
        return 0;
}