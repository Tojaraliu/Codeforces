//Test git

#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#define ll long long
int const N = 2005;
int const M = 205;
int const inf = 1000000000;
ll const mod = 1000000007;

using namespace std;

int n,m;
char s[N][N];
int dirx[]={-1,-1,0,1,1,1,0,-1};
int diry[]={0,1,1,1,0,-1,-1,-1};
int used[N][N];

typedef struct
{
    int x;
    int y;
}PP;

void ini()
{
    int i;
    for(i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    memset(used,0,sizeof(used));
}

int isok(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m && s[x][y]=='.')
        return 1;
    else
        return 0;
}

int check(int x,int y)
{
    if (x<1 || x>n || y<1 || y>m || s[x][y]=='.') return 0;
    int i;
    int d[10];
    for(i=0;i<8;i++){
        d[i]=isok(x+dirx[i],y+diry[i]);
    }
    d[8]=d[0];
    for(i=0;i<8;i+=2){
        if(d[i] && d[i+1] && d[i+2])
        return 1;
    }
    return 0;
}

void solve()
{
    queue< PP > que;
    PP te,nt;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(check(i,j)==1){
                te.x=i;te.y=j;
                que.push(te);
                used[i][j]=1;
            }
        }
    }

    while(que.size()>=1){
        te=que.front();que.pop();
        s[te.x][te.y]='.';
        for(i=0;i<8;i++){
            nt.x=te.x+dirx[i];
            nt.y=te.y+diry[i];
            if(used[nt.x][nt.y]==0 && check(nt.x,nt.y)==1){
                used[nt.x][nt.y]=1;
                que.push(nt);
            }
        }
    }
}

void out()
{
    int i;
    for(i=1;i<=n;i++){
        printf("%s\n",s[i]+1);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    ini();
    solve();
    out();
    return 0;
}