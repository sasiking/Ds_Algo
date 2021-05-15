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
  
int n; 
vi a[MAX_N];
int visited[MAX_N];
int dist[MAX_N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=1;
    //vi path;
    dist[s] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        //path.eb(top);
        for(auto x:a[top]){
            if(!visited[x]){
                q.push(x);
                dist[x] = dist[top] +1;
                visited[x] = 1;
                //cout<<"Pushed element = "<<x<<" Distance x = "<<dist[x]<<" Distance top = "<<dist[top]<<endl;
            }
        }
    }
    // for(auto x:path)
    //     cout<<x<<" ";
    //cout<<endl;
    // rep(i,1,n)
    //     cout<<dist[i]<<" ";
    // cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int e;
        cin>>n>>e;
        // fora(i,1,n){
        //     visited[i]=0;
        //     a[i].eb(i);
        // }

        rep(i,1,n){
            a[i].clear();
            visited[i] = 0;
        }
        rep(i,1,e){
            int x,y;
            cin>>x>>y;
            a[x].eb(y);
            a[y].eb(x);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<i<<" -> ";
        //     for(auto x:a[i])
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        bfs(1);
        cout<<dist[n]<<endl;
    }
}