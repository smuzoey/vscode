#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[100010][2];
int ans[10000][10000];

int main() {
	int num = 0;
	while(scanf("%d %d", &dp[num][0], &dp[num][1])) {
		num++;
	}
	
	int num1 = 0, num2 = 0, num3 = num / 2;
	ans[0][0] = 0;
	for(int i = 0; i < num; i++) {
		ans[num1+1][num2+1] = max(ans[num1+1][num2], ans[num1][num2] + dp[i][0]);
		ans[num1][num2+1] = max(ans[num][num2+1], ans[num1][num2] + dp[i][1]);
	}
	printf("%d\n", ans[num1][num2]);
	
}
