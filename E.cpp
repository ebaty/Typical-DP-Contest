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
#define M 1000000007

using namespace std;

typedef long long ll;

ll dp[105][10005];
ll dp2[105][10005];

int main() {
  int D;
  string N;
  cin >> D >> N;

  memset(dp, 0, sizeof(dp));
  memset(dp, 0, sizeof(dp2));

  dp[0][0] = 1;
  dp2[0][0] = 1;

  REP(j, N.length()+1) REP(i, D) REP(k, 10) {
    if ( j == 0 ) continue;

    dp[(i + k) % D][j] = (dp[(i + k) % D][j] + dp[i][j-1]) % M;
  }

  REP(j, N.length()+1) REP(i, D) {
    if ( j == 0 ) continue;

    int num = N[N.length() - j] - '0';
    REP(k, 10) {
      if ( k == num )
        dp2[(i + k) % D][j] = (dp2[(i + k) % D][j] + dp2[i][j-1]) % M;
      else if ( k < num )
        dp2[(i + k) % D][j] = (dp2[(i + k) % D][j] + dp[i][j-1]) % M;
    }
  }
 
  cout << dp2[0][N.length()] - 1 << endl;

	return 0;
}
