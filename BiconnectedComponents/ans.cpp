#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A;
    for (int i=0; i<N; ++i) {
        int x; cin >> x;
        A.push_back(x);
    }
    vector<int>B;
    for (int i=0; i<M; ++i) {
        int x; cin >> x;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int x=0, y=0;
    for (int i=min(N-1, M-1); i>=0; --i){
           if (A[i] > B[i]) ++x;
           else ++y;
    }
    printf("%d %d\n", x, y);
    return 0;
}