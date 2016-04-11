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

double dp[101][70][40][30];

int main() {
  ll N, D;
  cin >> N >> D;

  int I = 0, J = 0, K = 0;
  memset(dp, 0.0, sizeof(dp));

  while ( D % 2 == 0 ) {
    I++;
    D /= 2;
  }
  while ( D % 3 == 0 ) {
    J++;
    D /= 3;
  }
  while ( D % 5 == 0 ) {
    K++;
    D /= 5;
  }

  if ( D != 1 ) {
    cout << "0.0" << endl;
    return 0;
  }

  dp[0][0][0][0] = 1.0;
  REP(n, N) REP(i, I+1) REP(j, J+1) REP(k, K+1) {
    double p = dp[n][i][j][k] / 6.0;
    int i1 = min(i+1, I);
    int i2 = min(i+2, I);
    int j1 = min(j+1, J);
    int k1 = min(k+1, K);
    dp[n+1][i][j][k]   += p;
    dp[n+1][i1][j][k]  += p;
    dp[n+1][i][j1][k]  += p;
    dp[n+1][i2][j][k]  += p;
    dp[n+1][i][j][k1]  += p;
    dp[n+1][i1][j1][k] += p;
  }

  printf("%0.6lf\n", dp[N][I][J][K]);

	return 0;
}
