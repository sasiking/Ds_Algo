#include <bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
#define fi  first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define debug(x) cerr<<#x<<x;
#define forn(i,n) for(int i = 0;i <(int)(n);++i)
#define fora(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define ar array
#define ll long long
//#define ps(x,y) fixed<<setprecision(y)<<x
 
typedef vector<int> vi;
typedef pair<int, int> pi;
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
 
int n; 
vi a[MAX_N];
unordered_map<int,int> visited;

void bfs(vi a[],int s){
    queue<int> q;
    q.push(s);
    visited[s]=1;
    vi path;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        path.eb(top);
        for(auto x:a[top]){
            if(!visited[x]){
                q.push(x);
                visited[x] = 1;
            }
        }
    }
    cout<<endl;
    for(auto x:path)
        cout<<x<<" ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int e;
    cin>>n>>e;
    // fora(i,1,n){
    //     visited[i]=0;
    //     a[i].eb(i);
    // }

    // for(auto x:a){
    //     for(auto i:x)
    //         cout<<i<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        a[x].eb(y);
        a[y].eb(x);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" -> ";
        for(auto x:a[i])
            cout<<x<<" ";
        cout<<endl;
    }
    bfs(a,1);
}