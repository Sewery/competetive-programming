
//89/100 points - it doesn't pass one test from https://szkopul.edu.pl/problemset/problem/07Q0fFk7fU2TmGr6wpPeDCZj/site/?key=statement
#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define pii pair<ll,ll>
#define pb push_back
#define  X  first
#define  Y second
#define INF 1000000007
#define MAXN 2000002

ll arr[MAXN]={};
ll tab_d[MAXN]={};
ll pref_sum[MAXN]={};
int visited[MAXN]={};
ll n,p,d;
queue<pii> q;
deque<pii> dq;

void push(ll a,ll i)
{
    while( !dq.empty() && dq.back().X>a)
        dq.pop_back();
    dq.push_back({a,i});
    q.push({a,i});
}
void rem()
{
    if(!dq.empty() && !q.empty() && dq.front().X==q.front().X && dq.front().Y==q.front().Y)dq.pop_front();
    q.pop();

}
ll maxer()
{
    if(dq.empty())return 0;
    return dq.front().X;
}
int main()
{
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>p>>d;
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    int it=0;
    for(int i=0;i<n;i++)
    {
        pref_sum[i]=arr[i];    
        if(i>0)
            pref_sum[i]+=pref_sum[i-1];  
    }   
    for(int i=0;i<n-d;i++)
    {
        ll pre=i==0?0:pref_sum[i-1];
         tab_d[d+i-1]=pref_sum[d+i-1]-pre; 
    }
       
    ll sol=d;
    ll j=d-1;
    for(ll i=0;i<(n-d);i++)
    {
        j=max(j, i+d-1);
        if(visited[i+d-1]==0)push(-tab_d[i+d-1],i+d-1);
        visited[i+d-1]=1;
        ll pre=i==0?0:pref_sum[i-1];
        if((j+1)<n && !visited[j+1])
        {
            push(-tab_d[j+1],j+1);
            visited[j+1]=1;
        }
        //cout<<pref_sum[j+1]-pre+maxer()<<"!!";
        while( (pref_sum[j+1]-pre+maxer())<=p && (j+1)<n)
        {
            j++;
            if(visited[j+1]==0 && (j+1)<n) push(-tab_d[j+1],j+1);
            visited[j+1]=1;
        }
       // cout<<-maxer()<<" "<<i<<'\n';
        rem();
        sol=max(sol,j-i+1);
        
    }
    cout<<sol;
    return 0;
}