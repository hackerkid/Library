#include <iostream>
#include <vector>
using namespace std;

void printPalindromes(string& str) { 
       int N = str.size();
       vector<vector<bool> > dp(N,vector<bool>(N));
       for (int i=0; i < N; i++) {
             dp[i][i] = 1;
             cout << str[i] << endl; 
       } 
       for (int k=1; k < N; k++)
       {
                for (int i=0, j=k; j < N; j++, i++) 
                { 
                        dp[i][j] = str[i] == str[j] & dp[i+1][j-1];
                        if (dp[i][j]) 
                                  cout << str.substr(i, k) << endl;
                 }
       }
}


int main()
{
	string x = "QWERTYTREWQWERT";
	printPalindromes(x);
}