#include <bits/stdc++.h>

#define ll long long
using namespace std;

typedef ll  item;
item base_v=-100;
item NO_OP=INT_MAX;
item NEUTRAL_ELEMENT=0;
item modif(item a , item b, ll len){
        return a+b;
}
void modifier(item & a, item b, ll len){
    a=modif(a,b,len);
}
item calc(item a , item b){
    return max(a,b);
}
template<class T>
struct Seg_tree
{
    ll siz;
    vector<T> ops;
    vector<T> vals;
    T base_val;
    T (*func)(T obj1, T obj2);
    Seg_tree(vector<T> o,int n, T base_val, T (*func)(T obj1, T obj2)):base_val(base_val)
    {
        this->func=func;
        init(o,n);
    }
    void init(vector<T>  a,int n)
    {
        siz=1;
        while(siz<=n)siz*=2;
        ops.assign(2*siz,0);
        vals.assign(2*siz,0);
        build(a,0,0,siz,vals);
    }
    void build(vector<T> &a, ll node,ll down,ll up, vector<T> &data )
    {
        if(up-down==1)
        {
            if(down<(int)a.size())data[node]=a[down];
            return;
        }
        ll mid = (down+up)/2;
        build(a, 2*node+1, down, mid,data);
        build(a, 2*node+2, mid, up,data);
        
        data[node]=func(data[2*node+1], data[2*node+2]);
    }
    void propagate(ll node , ll down , ll up)
    { 
        if(up-down==1 || ops[node]==0)return ;
        int mid=(down+ up)/2;
        modifier(ops[2*node+1],ops[node],1);
        modifier(vals[2*node+1],ops[node],mid-down);
        modifier(ops[2*node+2],ops[node],1);
        modifier(vals[2*node+2],ops[node],up-mid);
        ops[node]=0;
    }
    void add(ll a, ll b,ll z,ll node , ll down , ll up )
    {  
        propagate(node,down,up);
        if(down>=b || a>=up)return ;
        if(down>=a && up<=b)
        { 
            modifier(ops[node],z,1);
            modifier(vals[node],z,up-down);
            return ;
        }
        ll mid = (down+ up)/2;
        add( a,b,z,2*node +1 , down,mid);
        add(a,b,z,2*node+2, mid,up);
        vals[node]=calc(vals[2*node+1],vals[2*node+2]);
    }
     void upd(ll k ,T u , ll node,ll down,ll up )
    {
        propagate(node,down,up);
        if(up-down==1){ vals[node]=u;return;}
        ll mid = (up+down)/2;
        if(k<mid) upd(k,u,2* node+1,down,mid);
        else upd(k,u,2*node+2 ,mid,up );
    
        vals[node]=func(vals[node*2 +1],vals[(node*2)+2]);
    }
    T get(ll a, ll b , ll node,ll down,ll up )
    {
        if(down>=b || a>=up)return NEUTRAL_ELEMENT;
        propagate(node,down,up);
        if(down>=a && up<=b)
            return vals[node];
        ll mid = (down+ up)/2;
        auto left = get( a,b,2*node +1 , down,mid);auto right =get(a,b,2*node+2, mid,up);
        auto res = calc(left, right);
        return res;
    }
    ll find (ll k , ll l , ll node ,ll down ,ll up)
    {
        propagate(node,down,up);
        if(up<=l)return -1;
        if(vals[node]<k)return -1;
        if(up-down==1)return down;
        int mid =(down +up)/2;
        auto res=  find(k,l,2*node+1, down , mid);
        if(res==-1)res=  find(k,l,2*node+2, mid , up);
        return res;
    }
};
int n;
ll odp[500003]={};
ll suff[500003]={};
int main()
{
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        odp[n]+=a[i];
    }
    vector<ll> si(n);
    for(int i=n-1;i>=0;i--)
    {
        si[i]=a[i]-suff[i+1];
        suff[i]=suff[i+1]+a[i];
    }
    Seg_tree<item> seg(si,n,base_v,calc);
   // for(int i=0; i<n;i++)
  //      cout<<si[i]<<" ";
  //  cout<<'\n';    
    for(int i=n-1;i>=1;i--)
    {
        ll j= seg.find(1,0,0,0,seg.siz);
        //cout<<j<<" ";
        odp[i]=odp[i+1]-a[j];
        seg.add(0,j,a[j],0,0,seg.siz);
        seg.upd(j,-NO_OP,0,0,seg.siz);
    }
   // cout<<'\n';
    for(int i=1;i<=n;i++)
        cout<<odp[i]<<" ";
    return 0;
}