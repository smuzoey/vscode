#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int mp[5000][5000];

int main() {

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &mp[i][j]);
			getchar();
		}
	}


	for(int i = 0; i < n; i++) {
		for(int j = n-1; j >= 0; j--) {
			if(i == n-1 && j == 0) printf("%d\n", mp[j][i]);
			else printf("%d,", mp[j][i]);
		}

	}

	return 0;
}
