
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define int long long

template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using pbds_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void myerase(pbds_multiset<int>& t,int v){
    int rank = t.order_of_key(v);
    auto it = t.find_by_order(rank);
    t.erase(it);
}

// find_by_order(k) returns iterator to the kth element (0-based index) in the set
// order_of_key(x) returns the count of elements strictly less than x
//less<int>  greater<int>.  less_equal<int> for multiset or greater_equal<int>

const int M=1e9+7;//998244353;
const int N=2e5+10;
const int INF=2147483647;

bool issafe(vector<vector<char>>& board,int row, int col,char dig){
    for(int i=0;i<9;i++){
        if(board[i][col]==dig)return false;
    }
    for(int i=0;i<9;i++){
        if(board[row][i]==dig)return false;
    }
    int sr=(row/3)*3;
    int sc=(col/3)*3;
    for(int i=sr;i<sr+3;i++){
        for(int j=sc;j<sc+3;j++){
            if(board[i][j]==dig)return false;
        }
    }
    return true;
}
bool helper(vector<vector<char>>& board,int row, int col){
    if(row==9)return true;
    int nrow=row,ncol=col+1;
    if(ncol==9)ncol=0,nrow+=1;
    if(board[row][col]!='.'){
        return helper(board,nrow,ncol);
    }else{
        for(char i='1';i<='9';i++){
            if(issafe(board,row,col,i)){
                board[row][col]=i;
                if(helper(board,nrow,ncol))return true;
                board[row][col]='.';
            }
        }
        return false;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector<vector<char>> board;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)cin>>board[i][j];
    }    
    helper(board,0,0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }cout<<"\n";
    }
}