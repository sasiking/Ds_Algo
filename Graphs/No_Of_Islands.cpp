#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define ll long long
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define rnd(x) cout<<setprecision((int)(x) +1)

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

const int MAX_N = 1e4 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int ar[MAX_N][MAX_N];
int r,c;

bool visited[MAX_N][MAX_N];

int dx[] = {0,0,-1,+1};
int dy[] = {-1,+1,0,0};

bool isValid(int a,int b){
	debug(a);
	debug(b);
	if( a<1 || a>r || b<1 || b>c || visited[a][b] || !ar[a][b])
		return false;
	return true;
}

void dfs(int x,int y){
	visited[x][y] = 1;
	//cout<<x<<" "<<y<<nl;
	f(i,4){
		if(isValid(x+dx[i], y+dy[i]))
			dfs(x + dx[i], y + dy[i]);
	}
}

void Solve(){
    int col=0;
    cin>>r>>c;
    rep(i,1,r){
    	rep(j,1,c){
    		int x;
    		cin>>x;
    		ar[i][j] = x;
    	}
    }
    rep(i,1,r){
    	rep(j,1,c){
    		if(ar[i][j]&&!visited[i][j]){
    			dfs(i,j);
    			col++;
    		}
    	}
    }
    cout<<"No of Components = "<<col<<nl;
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
	Test case
	6 6
	0 0 1 0 1 1
	0 1 1 0 0 1
	0 1 0 0 0 0
	1 0 1 1 0 0
	0 0 0 1 0 0
	0 1 1 0 1 1
*/