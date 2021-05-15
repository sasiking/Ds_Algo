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
vi a;

//another approach
int Repeat(){
    unordered_map<int,int> m;
    for(auto x:a)
        m[x]++;
    rep(i,0,n-1)
        if(m[a[i]]>1)
        return i+1;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n;
    rep(i,1,n){
        int x;
        cin>>x;
        a.eb(x);
    }
    vi ser(MOD,-1);
    int mi = INT_MAX;
    rep(i,0,n-1){
        if(ser[a[i]]==-1)
            ser[a[i]] = i;
        else
            mi = min(mi, a[i]);
    }
    if(mi==INT_MAX)
        cout<<-1;
    else
        cout<<mi;
    cout<<endl;


    cout<<Repeat()<<endl;
}