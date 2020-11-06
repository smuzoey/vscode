#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstdlib>
#include<map>
using namespace std;
const int inf = 0x3f3f3f3f;

int mp[25][25];
int dp[25][1010000];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			scanf("%d", &mp[i][j]);
	// Çódp[0][2^n-1]
	for(int i = 0; i < n; i++) dp[i][0] = mp[i][0];
	//dp[1][i] , dp[2[i], dp[i][0];

	
	return 0;
}
