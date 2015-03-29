#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int maxn=200000;
char a[maxn+50000];
int cnt[maxn+50000];
int n,m;

void swap(char &a, char &b){
    char t;
    t=a;a=b;b=t;
}

void Init()
{
    char ch;
    n=0;
    while (1) {
        scanf("%c",&ch);
        if (ch=='\n') break;
        ++n;
        a[n]=ch;
    }
    scanf("%d",&m);
}

void Main()
{
    int temp;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=m;++i){
        scanf("%d",&temp);
        cnt[temp]++;
    }
    for(int i=1;i<=n/2;++i){
        cnt[i]+=cnt[i-1];
        if (cnt[i]%2==1) swap(a[i],a[n-i+1]);
    }
    for(int i=1;i<=n;++i){
        printf("%c",a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    Init();
    Main();
    
    return 0;
}