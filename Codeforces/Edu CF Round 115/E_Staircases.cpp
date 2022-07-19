#include <bits/stdc++.h>
    using namespace std;      
using ll =long long;
using pii- pair<int,int>;
using pll = pair<ll, ll>;
#define  X first 
#define  Y second 
#define  pb push_back
#define  pf push_front
#define  mp make_pair
#define all(x) begin(x), end(x)

constexpr double PI =3.141592654; 
constexpr int MOD= 1e9 +7;

void _speed()
{
	ios_base::sync_with_stdio(false);     cin.tie(NULL);
}

const int MAXN = 2e5  + 20, INF = 1e9 + 10; const ll L_INF = LLONG_MAX /2; const int NUM = 2502; 
   
     
     
    int main () 
    {     
        int n,m,q;     
        _speed();     
        cin>>n>>m>>q;
        int ans=0;
        int grid[n][m]={1};
        for(int i=0; i<n;i++)
        {
            for(int j= 0; j <m;j++)
            {
                grid[i][j]=1;
                if(i==0)
                {
                    for(int k =1; ;k++)
                    {
                        int x = i + k/2;
                        int y=  j + (k+1)/2;
                        if(x==n || y==m)break;
                        ans+=k;
                    }
                }
                if(j==0)
                {
                    for(int k =1; ;k++)
                    {
                        int x = i + (k+1)/2;
                        int y=  j + k/2;
                        if(x==n || y==m)break;
                        ans+=k;
                    }
                }
            }
        }     
        ans+=n*m;
        for(int r=0; r<q;r++)
        {
     
            int var=0;
            int i,j;  cin>>i>>j;i--;j--;
            int a =1, b=1;
            while(1)
            {
                int x= i + (a+0)/2;
                int y= j+ (a+1)/2;
                if(x==n || y==m || grid[x][y]==0)break;
                a++;
                
            }
             while(1)
            {
                int x= i - (b+1)/2;
                int y= j -  (b+0)/2;
                if(x<0 || y<0 || grid[x][y]==0)break;
                b++;
                
            }
            var+=a*b; a=b=1;
             while(1)
            {
               int x= i + (a+1)/2;
                int y= j+ (a+0)/2;
                if(x==n || y==m || grid[x][y]==0)break;
                a++;
                
            }
     
             while(1)
            {
                int x= i - (b+0)/2;
                int y= j -  (b+1)/2;
                if(x<0 || y<0 || grid[x][y]==0)break;
                b++;
                
            }
            var+=a*b; a=b=1;
            ans+=grid[i][j];
            if(grid[i][j]==1){
                ans-=var;
            }else ans+=var;
            grid[i][j]^=1;
            ans -= grid[i][j];
            cout<<ans<<"\n";
     
     
        
        }
    }