#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii= pair<int,int>;
using pll = pair<ll, ll>;
#define  X first 
#define  Y second 
#define  pb push_back
#define  pf push_front
#define  mp make_pair
#define all(x) begin(x), end(x)

constexpr int MOD= 1e9 +7;
void _speed()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
const int MAXN=1000000;
int preprocessAdd[MAXN]={}; 
void preprocess()
{
    int add=0;
    int factor=10;
    for(int i=0; i<MAXN;i++)
    {
        if(i/factor >0)
        {
            add++;
            factor*=10;
        }
        preprocessAdd[i]=add;
    }
}

void solve()
{
    int k; cin>>k;
    int sol=1;
    int digit=0,num=0,toAdd=0;
    while(digit<k)
    {
        num++;
        toAdd+=preprocessAdd[num];
        digit+=num+toAdd;
        
    }
    if(digit>k)
    {
        digit-=num+toAdd-1;
        int num=1;
        while(digit<k)
        {
           
            num++;
            digit+=1+preprocessAdd[num];
        }
        if(digit>k)
        {
            int diff=digit-k;
            sol=(num%((int)pow(10 ,diff+1)))/pow(10,diff);
        }
        else
        {
            sol=num%10;
        }
    }else
    {
        sol=num%10;
    }
    cout<<sol<<'\n';
}
int main() {
    _speed();
    int n;
    cin>>n;
    preprocess();
     for(int i=0; i<n;i++){
         solve();
     }  
}
