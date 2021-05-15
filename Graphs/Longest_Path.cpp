#include <bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
#define mp make_pair
#define fi  first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define debug(x) cerr<<#x<<" = "<<x<<endl;
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define deb(x) cout<<#x<< " = "<< x<<endl
#define ar array
#define ll long long
 
typedef vector<int> vi;
typedef pair<int, int> pi;
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, maxd,maxnode;
vi a[MAX_N];
int visited[MAX_N];

void dfs(int src,int d){
    visited[src] = 1;
    if(d>maxd)
        maxd = d, maxnode = src;
    for(auto x:a[src])
        if(!visited[x])
            dfs(x,d+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n;
    maxd=-1;
    rep(i,1,n-1){
        int x,y;
        cin>>x>>y;
        a[x].eb(y);
        a[y].eb(x);
    }
    // rep(i,1,n){
    //     cout<<i<<" -> ";
    //     for(auto x:a[i])
    //         cout<<x<<" ";
    //     cout<<endl;
    // }
    dfs(1,0);
    maxd = -1;
    rep(i,1,n) visited[i]=0;
    dfs(maxnode,0);
    cout<<maxd<<endl;
}