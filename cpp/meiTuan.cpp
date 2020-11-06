#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int T, n;
	int arr[100010];
	int sum1[100010], sum2[100010];
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

		sum1[0] = 0, sum2[0] = 0;

		int ans1 = 0, tmp = 0, maxx = 0;
		for(int i = 1; i <= n; i++) {
			tmp += arr[i];
			maxx = max(maxx, tmp);
			sum1[i] = maxx;

			if(sum2[i-1] > 0) sum2[i] = sum2[i] + arr[i];
			else sum2[i] = arr[i];

			ans1 = max(ans1, sum2[i]);
		}

		int ans2 = 0;
		maxx = 0, tmp = 0;
		
		for(int i = n; i > 0; i--) {
			tmp += arr[i];
			maxx = max(maxx, tmp);
			ans2 = max(ans2, sum1[i-1] + maxx);
		}
		
		printf("%d\n", max(ans1, ans2));
	}

	return 0;
}
