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
typedef vector<pair<int,int>> vii;

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
    for(T i:vi){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]"; 
}

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vii adj[MAX_N];
vi dist(MAX_N,INT_MAX);
int visited[MAX_N];
stack<int> s;

void dfs(int src){
	visited[src] = 1;
	for(auto x:adj[src]){
		if(!visited[x.fi])
			dfs(x.fi);
	}
	s.push(src);
}

/*
	The intution is that we find the toposort of 
	the graph and from that returned stack, we find 
	the shortest path in the weighted DAG.
*/

void shortest(int src){
	rep(i,1,n){
		if(!visited[i])
			dfs(i);
	}
	dist[src] = 0;
	while(!s.empty()){
		int tp = s.top();
		s.pop();
		debug(tp);
		if(dist[tp]!=INT_MAX){
			for(auto x:adj[tp]){
				if(dist[x.fi] > dist[tp] + x.se)
					dist[x.fi] = dist[tp] + x.se;
			}
		}
	}
	rep(i,1,n){
		if(dist[i]!=INT_MAX)
			cout<<dist[i]<<" ";
		else
			cout<<"INF ";
	}
	cout<<nl;
}

void Solve(){
	int e;
	cin>>n>>e;
	f(i,e){
	    int x,y,z;
	    cin>>x>>y>>z;
	    adj[x].eb(y,z);
	}
	shortest(1);
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

/*
	Test Case for the problem
	6 7
	1 2 2
	1 5 1
	2 3 3
	3 4 6
	5 3 2
	5 6 4
	6 4 1
*/