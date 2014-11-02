#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30

int n,m;

int coins[] = {1, 5, 10, 25, 50};
long long dp[30005];

int main(){

	int n;
	while(scanf("%d",&n)!=-1){
		for(int i = 0; i <= n; i++) dp[i] = 0LL;
		dp[0] = 1LL;
		for(int i = 0; i < 5; i++){
			for(int j = coins[i]; j <= n; j++){
				dp[j] += dp[j-coins[i]];
			}
		}
		if (dp[n]==1LL){
			 
			printf("There is only 1 way to produce %d cents change.\n",n);
		}else
			printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
	}
	
	return 0;
}
