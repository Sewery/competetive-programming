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
ll gcd(ll a, ll b)
{
    if(a<b)
        swap(a,b);
    if(b==0)
        return a;

    return gcd(b,a%b);
}

ll n;
int main() {
    _speed();
    cin>>n;
    ll maxer=0;
    vector<ll> vec;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        ll x; cin>>x;
        maxer=max(x,maxer);
        vec.pb(x);
    }
    ll nwd=0; 
     for(int i=0;i<n;i++)
    {   
        nwd=gcd(maxer-vec[i],nwd);
        if(vec[i]!=maxer)
        sum+=maxer-vec[i];
    }
    cout<<sum/nwd<<" "<<nwd;
       
}
