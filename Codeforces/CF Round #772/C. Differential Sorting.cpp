    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    #define pii pair<int,int>
    #define INF 2000000001
     
     
    void solve(vector<int>  vec )
    {
        vector<int> sol;
        int sz= vec.size();
        if(vec[sz-1] < vec[sz-2])
        {
            cout<<-1<<"\n";
            return;
        }
     
        if(vec[sz-1]<0 &&  vec[sz-2] <0)
        {
            int pre=-INF;
            for(auto w: vec)
            {
                if(w<pre)
                {
                    cout<<-1<<"\n"; return;
                }
                pre=w;
            }
            cout<<0<<"\n"; return;
        }
        cout<<sz-2<<'\n';
        for(int i=0;i<sz-2;i++)
        {
            cout<<i+1<<" "<<sz-1<<" "<<sz<<'\n';
        }
        
    }     
    int n;
    int main()
    {
        cin.tie(NULL); ios_base::sync_with_stdio(false); 
        cin>>n;
        for(int i=0; i<n;i++)
        {
            int k, x; cin>>k;
            vector<int> vec(k);
     
            for(auto & w: vec)
                cin>>w;
            solve(vec);
        }
        return 0;
    }