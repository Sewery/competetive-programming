#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define X first
#define Y second
#define  up_limit 500002
#define INF= 1000000007;
#define ll long long

template<class T>
struct Seg_tree
{
    ll siz;
    vector<T> data;
    T base_val;
    T (*func)(T obj1, T obj2);
    Seg_tree(vector<T> a,int n, T base_val, T (*func)(T obj1, T obj2)):base_val(base_val)
    {
        this->func=func;
        init(a,n);
    }

    void build(vector<T> &a, ll node,ll down,ll up )
    {
        if(up-down==1)
        {
            if(down<(int)a.size())data[node]=a[down];
            return;
        }
        int mid = (down+up)/2;
        build(a, 2*node+1, down, mid);
        build(a, 2*node+2, mid, up);
    
        data[node]=func(data[2*node+1], data[2*node+2]);
    }
    void init(vector<T> a,int n)
    {
        siz=1;
        while(siz<=n)siz*=2;
        data.assign(2*siz,base_val);
        build(a,0,0,siz);
    }
    void upd(ll k ,T u , ll node,ll down,ll up )
    {
        if(up-down==1){ data[node]=u;return;}
        ll mid = (up+down)/2;
        if(k<mid) upd(k,u,2* node+1,down,mid);
        else upd(k,u,2*node+2 ,mid,up );
    
        data[node]=func(data[node*2 +1],data[(node*2)+2]);
    }
// this works in range <a,b) 
    T range(ll a, ll b,ll node , ll down , ll up )
    {
        if(down>=a && up<=b)
            return data[node];
        if(down>=b || a>=up)
            return base_val;
        ll mid = (down+ up)/2;
        return func(range( a,b,2*node +1 , down,mid),range(a,b,2*node+2, mid,up));
    }

};    
struct item
{
    ll war, kr;
};
item base_val={0,0};
item calc(item a , item b)
{
    if(a.war==b.war) return {a.war,a.kr+b.kr};
    if(a.kr>b.kr) return {a.war,a.kr-b.kr};
    else if(b.kr>a.kr) return {b.war,b.kr-a.kr};
    return {0,0};
}

int arr[up_limit]={};
pii queries[up_limit]={};
vector<int> beg_seg[up_limit]={};
vector<int> end_seg[up_limit]={};
int sum_for_queries[up_limit]={};
int counter[up_limit]={};
int candidates[up_limit]={};
int n,m;

int main()
{
    cin.tie(); ios_base::sync_with_stdio(0);
      
    cin>>n>>m;
    vector<item> vec(n);
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
        vec[i]={arr[i],1};
    }
    Seg_tree<item> seg(vec,n,base_val,calc);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        a--;b--;
        queries[i]={a,b};
        beg_seg[a].pb(i);
        end_seg[b].pb(i);
        item it=seg.range(a,b+1,0,0,seg.siz);
        candidates[i]=it.war;
    }
    for(int i=0; i<n;i++)
    {
        int liczba=arr[i];
        
        for(auto w: beg_seg[i])
        {
            sum_for_queries[w]-=counter[candidates[w]];
        }
        counter[liczba]++;
        for(auto w: end_seg[i])
        {
            sum_for_queries[w]+=counter[candidates[w]];
        }
    }
    for(int i=0; i<m;i++)
    {

        if(sum_for_queries[i]>(queries[i].Y-queries[i].X+1)/2)cout<<candidates[i]<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}