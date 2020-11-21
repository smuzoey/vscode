#include<bits/stdc++.h>
using namespace std;

struct node{
	int id;
	int val;
}arr[1010];

int a[1010];

bool cmp(node s1,  node s2) {
	return s1.val > s2.val;
}

int main() {
	int n, k, p1, p2;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &k);
		while(k--) {
			scanf("%d%d", &p1, &p2);
			a[p1] += p2;
			a[i] -= p2;
		}
	}

	
	for(int i = 0; i < n; i++) {
	 	arr[i].id = i+1;
		arr[i].val = a[i+1];
	}
	sort(arr, arr + n, cmp);

	for(int i = 0; i < n; i++) {
		printf("%d %.2f\n", arr[i].id, arr[i].val/100.0);
	}
	
	return 0;
}
