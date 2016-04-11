#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
  int K;
  cin >> K;

  int R[1024];
  REP(i, 1 << K) cin >> R[i];

  double dp[11][1024];

  REP(i, K+1) {
    REP(j, 1 << K) {
      if ( i == 0 ) dp[0][j] = 1;
      else {
        int s = j ^ (1 << (i-1));
        s = s & (0xffffffff << (i-1));

        double sum = 0.0;
        FOR(k, s, s + (1 << (i-1))) {
          sum += dp[i-1][k] / (1.0 + pow(10.0, (R[k] - R[j]) / 400.0));
        }
        dp[i][j] = dp[i-1][j] * sum;
      }
    }
  }

  REP(i, 1 << K) {
    printf("%0.6lf\n", dp[K][i]);
  }
	return 0;
}
