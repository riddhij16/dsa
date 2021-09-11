#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++){
        int n;
        cin>>n;
        vector<vector<char>> mat(n,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        int r=INT_MAX,c=INT_MAX;
        set<vector<pair<int,int>>> allones;
        unordered_map<int,vector<int>> posrc;
        for(int i=0;i<n;i++){
            bool flag1=false,flag2=false;
            int tr=0,tc=0;
            vector<pair<int,int>> row;
            vector<pair<int,int>> col;
            for(int j=0;j<n;j++){
                if(mat[i][j]=='O'){
                    flag1=true;
                }else if(flag1==false and mat[i][j]=='.'){
                    tr++;
                    row.push_back({i,j});
                }
                if(mat[j][i]=='O'){
                    flag2=true;
                }else if(flag2==false and mat[j][i]=='.'){
                    tc++;
                    col.push_back({j,i});
                }
                if(flag1==true and flag2==true) break;
            }
            if(flag1==false) {r=min(r,tr);
                if(tr==1 and row.size()==1){
                    allones.insert(row);
                }
                posrc[tr].push_back(i);
            }
            if(flag2==false) {c=min(c,tc);
                if(tc==1 and col.size()==1 ){
                    allones.insert(col);
                }
                posrc[tc].push_back(i);
            }

        }
        if(r==INT_MAX and c==INT_MAX) cout<<"Case #"<<t<<": Impossible"<<endl;
        else{
            int res=min(r,c);
            int ans=0;
            if(res==1){
                ans=allones.size();
            }else{
                ans=posrc[res].size();
            }
            cout<<"Case #"<<t<<": "<<res<<" "<<ans<<endl;
        } 
    }

    return 0;
}
/*

HINT: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/solutions

INPUT:
8
2
XO
..
2
X.
.O
3
...
...
...
3
.OX
X..
..O
3
OXO
X.X
OXO
3
.XO
O.X
XO.
4
X...
.O.O
.XX.
O.XO
5
OX.OO
X.XXX
OXOOO
OXOOO
XXXX.

OUTPUT:
Case #1: 1 1
Case #2: 1 2
Case #3: 3 6
Case #4: 2 2
Case #5: 1 1
Case #6: Impossible
Case #7: 2 2
Case #8: 1 2
*/
