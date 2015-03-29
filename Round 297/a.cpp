#include <iostream>
#include <stdio.h>

using namespace std;

int cnt[30];
int n,ans;

void Init()
{
    scanf("%d\n",&n);
}

void Main()
{
    ans=0;
    char temp;
    for (int i=1; i<=(n-1)*2; ++i) {
        scanf("%c",&temp);
        if (i%2==1) {
            cnt[temp-96]++;
        }
        else {
            if (cnt[temp-64]) {
                cnt[temp-64]--;
            }
            else ans++;
        }
    }
    printf("%d",ans);
}

int main(int argc, const char * argv[]) {
    
    Init();
    Main();
    
    return 0;
}