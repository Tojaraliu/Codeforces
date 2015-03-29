#include <iostream>
#include <stdio.h>
#include <string.h>
#define For(i,l,r) for(int i=l;i<=r;++i)
#define Fordown(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

const int maxn=100000,maxl=1000000;
int a[maxn+50000],cnt[maxl+50000],b[maxn+50000];
int n,m,mx;
long long int ll,rr,ans;

void Q(int l,int r)
{
    int i=l,j=r,mid=b[(l+r)>>1],tmp;
    while (i<=j) {
        while (b[i]<mid) ++i;
        while (b[j]>mid) --j;
        if (i<=j) {
            tmp=b[i];b[i]=b[j];b[j]=tmp;
            ++i;--j;
        }
    }
    //printf("%d %d\n",l,r);
    if (l<j) Q(l,j);
    if (i<r) Q(i,r);
    //printf("%d %d\n",l,r);
}

void Init()
{
    scanf("%d",&n);
    mx=0;
    m=0;
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        if (a[i]>mx) mx=a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=mx;++i){
        if (cnt[i]) {
            m++;
            b[m]=i;
        }
    }
    //For(i,1,m) printf("%d ", b[i]);
    //printf("READ\n");
    Q(1,m);
}

void Main()
{
    Fordown(i,m,1) {
        if (cnt[b[i]]%2==1){
            cnt[b[i]]--;
            if (cnt[b[i]-1]>0) cnt[b[i]-1]++;
        }
    }
    ll=0; rr=0; ans=0;
    int i=mx;
    while (1) {
        if (cnt[i]>0) {
            if (ll==0) ll=(long long int)i;
            else {
                rr=(long long int)i;
                ans+=ll*rr;
                ll=0;rr=0;
            }
            cnt[i]-=2;
        }
        if (cnt[i]==0) i--;
        if (i==0) break;
    }
    printf("%lld",ans);
}

int main() {
    
    Init();
    Main();
    
    return 0;
}