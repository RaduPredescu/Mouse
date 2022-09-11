#include <bits/stdc++.h>
using namespace std;
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
char A[1001][1001];
int TR[1001][1001];
int n,m,a,amax,nr,xf,yf,xp,yp;
bool ok;
char s[1001];
void bec(int x, int y)
{
    if(!ok){
    A[x][y]=2;
    nr++;
    TR[x][y]=nr;
    if(x==xf and y==yf){
        ok=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cout<<TR[i][j]<<" ";
            cout<<"\n";
        }
    }
    else{
        for(int k=0;k<4;k++){
            int l = x+dx[k];
            int c = y+dy[k];
            if(l>0 and l<=n and c>0 and c<=m)
                if(!A[l][c])bec(l,c);
        }
    }
    A[x][y]=0;
    TR[x][y]=0;
    nr--;
    }
}

int main()
{
    freopen("soarece1.in","r",stdin);
    freopen("soarece1.out","w",stdout);
    cin>>n>>m;
    cin.get();
    for(int i=1;i<=n;i++){
        cin.getline(s,1001);
        for(int j=0;j<strlen(s);j++)
            if(s[j]=='#')A[i][j+1]=1;
            else if(s[j]=='S'){
                xp=i;yp=j+1;
            } else if(s[j]=='B') {
                xf=i;yf=j+1;
        }
    }
    bec(xp,yp);
    if(ok==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)
                    cout<<"0 ";
                cout<<"\n";
        }
    }
    return 0;
}

