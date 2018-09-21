#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
int nums[100005];
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n, x;
    multiset<int> other;
    scanf("%d%d", &n, &x);
    for (int i=0; i<2; ++i){
    	for(int j=0;j<n;++j){
    		int x; cin >>x;
    		if (i) nums[j]=x;
    		else other.insert(x);
    	}
    }

    int num=0;
    for (int i=0; i<n; ++i) {
    	int k = x-nums[i];
    	auto it = other.lower_bound(k);
    	if (it == other.end()) continue;
    	++num; other.erase(it);
    }
    printf("1 %d\n", num);
}
