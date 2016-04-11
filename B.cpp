#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;

  int a[1001], b[1001];
  REP(i, n) cin >> a[i];
  REP(i, m) cin >> b[i];

  int dp[1001][1001];
  dp[0][0] = 0;

  REP(i, n+1) {
    REP(j, m+1) {
      if ( !(i | j) ) continue;

      int t = (n + m - (i + j)) % 2;
      int left = 0, right = 0;

      if ( i > 0 ) {
        left = dp[i-1][j] + a[n-i];
      }

      if ( j > 0 ) {
        right = dp[i][j-1] + b[m-j];
      }

      if ( !t )
        dp[i][j] = max(left, right);
      else {
        if ( i == 0 )
          dp[i][j] = dp[0][j-1];
        else if ( j == 0 )
          dp[i][j] = dp[i-1][0];
        else
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp[n][m] << endl;
	return 0;
}
