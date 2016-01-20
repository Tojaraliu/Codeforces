//最大不相交区间集

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define For(i,l,r) for(int i=l;i<=r;++i)
#define Fordown(i,r,l) for(int i=r;i>=l;--i)

using namespace std;

const int maxn=200000;
int x[maxn+100],y[maxn+100];
int n,maxsize;

void Q(int l,int r)
{
    int i=l,j=r,mid=y[(l+r)>>1];
    static int tmp;
    while(i<=j){
        while (y[i]<mid) ++i;
        while (y[j]>mid) --j;
        if (i<=j) {
            tmp=x[i];x[i]=x[j];x[j]=tmp;
            tmp=y[i];y[i]=y[j];y[j]=tmp;
            ++i;--j;
        }
    }
    if (i<r) Q(i,r);
    if (l<j) Q(l,j);
}

void Init()
{
    int a,b;
    scanf("%d",&n);
    For(i,1,n){
        scanf("%d%d",&a,&b);
        x[i]=a-b;
        y[i]=a+b;
    }
    Q(1,n);
}

void Main()
{
    maxsize=1;
    int last=y[1];
    For(i,2,n) {
        if (x[i]>=last){
            last=y[i];
            ++maxsize;
        }
    }   
    printf("%d\n", maxsize);
}

int main() {
    
    Init();
    Main();
    
    return 0;
}