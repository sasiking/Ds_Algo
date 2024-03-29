#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define ar array
#define ll long long
#define rnd(x) cout<<setprecision((int)(x) +1)
#define nl "\n"

typedef vector<int> vi;
typedef pair<int, int> pi;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" = ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

template<class T> void _print(T a){
    cerr<<a; 
}

template<class T> void _print(vector<T> vi){
    cerr<<"[ ";
    for(T i:vi){ _print(i); cerr<<" ";}
    cerr<<"]"; 
}

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vi adj[MAX_N];
int visited[MAX_N];
stack<int> s;

/*
	We can also use vector instead of stack 
	and print the elements in reverse order
*/

void dfs(int src){
	visited[src] = 1;
	for(auto x:adj[src]){
		if(!visited[x])
			dfs(x);
	}
	s.push(src);
}

void Solve(){
	int e;
	cin>>n>>e;
	f(i,e){
	    int x,y;
	    cin>>x>>y;
	    adj[x].eb(y);
	}
	rep(i,1,n){
		if(!visited[i])
			dfs(i);
	}
	vi ans;
	while(!s.empty()){
		ans.eb(s.top());
		s.pop();
	}
	debug(ans);
	for(auto x:ans)
		cout<<x<<" ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    int t = 1;
    //cin>>t;
    while(t--){
        Solve();
    }
}
