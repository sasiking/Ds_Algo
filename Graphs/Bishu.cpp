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
#define deb(x) cout<<#x<< " = "<<x<<endl
#define ar array
#define ll long long
 
typedef vector<int> vi;
typedef pair<int, int> pi;
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vi a[MAX_N];
int visited[MAX_N];
int dist[MAX_N];

void dfs(int start, int d){
    visited[start] = 1;

    dist[start] = d;
    for(auto x:a[start])
        if(visited[x]==0)
            dfs(x, dist[start] + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n;
    debug(n);
    int it=0;
    f(i,n-1){
        int x,y;
        cin>>x>>y;
        a[x].eb(y);
        a[y].eb(x);
    it++;
    }
    debug(it);
    dfs(1,0);
    int q;
    cin>>q;
    debug(q);
    int ans=INT_MAX, mindist = INT_MAX;
    while(q--){
        int girl;
        cin>>girl;
        if(dist[girl] < mindist){
            mindist = dist[girl];
            ans = girl;
        }
        else if(dist[girl] == mindist && girl<ans)
            ans = girl;
    }
    cout<<ans<<endl;
    rep(i,1,n)
    cout<<dist[i]<<" ";
    cout<<endl;
    rep(i,1,n){
        cout<<i<<" -> ";
        for(auto x:a[i])
            cout<<x<<" ";
        cout<<endl;
    }
}