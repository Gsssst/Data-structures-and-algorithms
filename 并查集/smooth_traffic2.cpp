#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node(101, 0);

bool cmp(vector<int> a, vector<int> b) {
    return a[2] > b[2];
}

void init(int n) {
    for (int i = 0; i < n; i++) {
        node[i] = i;
    }
}

int getroot(int i) {
    while (node[i] != i) {
        i = node[i];
    }
    return i;
}

void uniontree(int a, int b) {
    int roota = getroot(a);
    int rootb = getroot(b);
    node[roota] = rootb;
}

int main() {
    int n;
    int x, y, e;
    while (cin >> n) { 
        if (n == 0) break;
        vector<vector<int>> mp(n * (n - 1) / 2, vector<int>(3, 0));
        init(n);
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            cin >> mp[i][0] >> mp[i][1] >> mp[i][2];
        }
        int ans = 0;
        int cnt = 0;
        while(cnt!=n-1){
            sort(mp.begin(), mp.end(), cmp);
            if (getroot(mp[mp.size()-1][0]) != getroot(mp[mp.size()-1][1])) {
                ans += mp[mp.size()-1][2];
                uniontree(mp[mp.size()-1][0], mp[mp.size()-1][1]);
                cnt++;
            }
            mp.pop_back();
        }
        cout << ans << endl;
    }
    return 0;
}
