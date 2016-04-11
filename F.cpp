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

ll dp[1000005];
ll sum[1000005];

int main() {
  int N, K;
  cin >> N >> K;

  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(dp));

  dp[0] = 1;
  sum[0] = 1;
  sum[1] = 1;

  FOR(i, 2, N+2) {
    if ( i - 1 - K >= 0 ) dp[i] = (sum[i-1] - sum[i - 1 - K] + M) % M;
    else dp[i] = sum[i-1];

    sum[i] = (sum[i-1] + dp[i]) % M;
  }

  ll ans = 0;
  REP(i, K-1) ans += dp[N-1-i];
  ans %= M;

  cout << ans << endl;

  return 0;
}
