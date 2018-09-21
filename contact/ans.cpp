/*
 ID: mchensd
 LANG: C++11
 TASK: contact
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int cnt[13][1<<13];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int a, b, N; cin >> a >> b >> N;
    string s;
    string t;
    set<int> sizes;
    while (cin>>t) s += t;
    int len=s.size();
    for (int i=a; i<=b; ++i) {
        // cout << "size " << i << endl;
        for (int j=0; j<len; ++j) {
            if (j+i-1 >= len) break;
            int num = 0;
            int mult = 1;
            for (int k=j+i-1; k>=j; --k){
                num += mult*(s[k]-'0');
//                cout << s[k] - '0' << ' ' <<  mult << endl;
                mult*=2;
            }
//            cout << num << endl;
            ++cnt[i][num];
        }
        for (int j=0;j<=(1<<12); ++j) {
            if (cnt[i][j]) sizes.insert(cnt[i][j]);
        }
        // cout << endl;
    }
    auto it = sizes.end();
    // cout << sizes.size() << endl;
    do {
        --it;
        cout << *it << endl;
        int out =0;
        for (int i=a; i<=b; ++i) {
            for (int j=0; j<(1<<12); ++j) {
                int tmp = j;
                if (cnt[i][j] == *it) {
                    string ss = "";
                    for (int k=0;k<i;++k){
                        ss+= to_string(tmp&1);
                        tmp >>=1;
                    }
                    reverse(ss.begin(), ss.end());
                    if (out) cout << ' ';
                    cout << ss;
                    ++out;
                    out %= 6;
                    if (out == 0) cout << '\n';
                }
            }
        }
        if (out != 0)cout<<'\n';
    } while (--N && it!=sizes.begin());
}

