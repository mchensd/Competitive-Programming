#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
int n;
int p1[3], p2[3];

int main() {
    #ifdef SUBLIME_RUN
    freopen("D.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    cin >> p1[0] >> p1[1] >> p1[2];
    cin >> p2[0] >> p2[1] >> p2[2];

    int diffC = 0, dimDiff = -1;
    for(int i = 0 ;i < 3; i++)
    {
        if((p1[i] == 0 && p2[i] == n) || (p1[i] == n && p2[i] == 0))
        {
            dimDiff = i;
            diffC++;
        }
    }

    ll ans = 0;
    if(diffC != 1)
        ans = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) + abs(p1[2] - p2[2]);
    else
    {
        ans = 99999999999;
        ll edgeDiff = 999999999999, otherDist = 999999999999;
        for(int i = 0; i < 3; i++)
        {
            int odim = -1;
            for(int j =0 ; j <3 ;j++)
                if(j != i && j != dimDiff)
                    odim = j;

            if(i != dimDiff)
            {
                edgeDiff = min(edgeDiff, abs(p1[i] - 0) + abs(p2[i] - 0) + abs(p1[odim] - p2[odim]));
                edgeDiff = min(edgeDiff, abs(p1[i] - n) + abs(p2[i] - n) + abs(p1[odim] - p2[odim]));
            }
            else
            {
                otherDist = abs(p1[i] - p2[i]);
            }
        }
        ans = min(ans, edgeDiff + otherDist);
    }

    cout << ans << endl;
}
