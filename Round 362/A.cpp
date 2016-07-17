// Codeforces #362 Prob. A
// Tianhao Liu
// 07/17/2016

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <map>

using namespace std;

typedef long long LL;

map<LL, LL>mp;

LL work(LL u, LL v, LL w) {
    LL ret = 0;
    while (u != v) {
        if (u > v) {
            ret += mp[u];
            mp[u] += w;
            u = u >> 1;
        } else {
            ret += mp[v];
            mp[v] += w;
            v = v / 2;
        }
    }
    return ret;
}

void init() {
}

void solve() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            LL u, v, w;
            scanf("%lld%lld%lld", &u, &v, &w);
            work(u, v, w);
        } else {
            LL u, v;
            scanf("%lld%lld", &u, &v);
            printf("%lld\n",work(u, v, 0));
        }
    }
}

int main(int argc, const char * argv[]) {
    init();
    solve();
    return 0;
}
