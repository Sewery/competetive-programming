    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    #define pii pair<int,int>
    #define maxer 200001
    #define moder 1000000007
    int n,p;
     
    ll dp[maxer]={};
    ll g[maxer]={};
    set<ll> secik;
    ll highestPowerof2(ll n)
    {
        if(n==1)return 0;
       ll p = (ll)log2(n);
       return p;
    }
    void solve(vector<ll>  vec)
    {
     
        sort(vec.begin(),vec.end());
     
        for(ll i =0; i<vec.size();i++)
        {
            ll w= vec[i];
     
            bool ha=0;
            while(w>0)
            {
                if( secik.find(w)!=secik.end())
                {
                    ha=1;
                    break;
                }
                if(w%2==1)
                    w=w>>1;
                else if(w%4==0)
                    w=w>>2;    
                else
                    break;    
            }
             if(ha==1)continue;
           
             secik.insert(vec[i]);
        }
        auto it=secik.begin();
       while(it!=secik.end())
        {
           //cout<<highestPowerof2(*it);
            g[highestPowerof2(*it)]++;
            it++;
        }
           
        dp[0]=g[0];
        dp[1]=g[1] +dp[0];
        ll solution=dp[0]+dp[1];
        for(int i=2;i<p;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2] +g[i])%moder;
            solution = (solution + dp[i])%moder;
        }
     
        cout<<solution;
     
    }     
    int main()
    {
        cin.tie(NULL); ios_base::sync_with_stdio(false); 
        cin>>n>>p;
        vector<ll> vec(n);
        for(auto & w: vec) cin>>w;
           
        solve(vec);
        return 0;
    }