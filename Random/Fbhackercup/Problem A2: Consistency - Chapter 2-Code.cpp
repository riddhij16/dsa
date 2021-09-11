#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int solve(){
    string s;
    cin>>s;
    
    int k;
    cin>>k;
    int dist[26][26];
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            dist[i][j]=1000000;// cant use INT_MAX here kyunki initialisation mein woh use aayega
        }
        dist[i][i]=0; // agr same char h to chnge krne ki zarurat nhi h so 0 and not infinte
    }
    for(int i=0;i<k;i++){
        char s,e;
        cin>>s>>e;
        dist[s-'A'][e-'A']=1;//forming graph of the given pair of chars
    }
    
    //applying floyd warshall to find shortest dist btw each node s and e while considering each k as the
    //intermediate node btw them
    // in total for brute force 26 alphabets
    for(int k=0;k<26;k++){
        for(int s=0;s<26;s++){
            for(int e=0;e<26;e++){
                dist[s][e]=min(dist[s][e],(dist[s][k]+dist[k][e]));
            }
        }
    }
    int count=INT_MAX;
    // considering each alphabet so as to find a optimal char to which each char of s be converted to in min secs
    for(int k=0;k<26;k++){
        int temp=0;// agr nhi krna pda kisike liye tb to 0 hi hoga so cant check count ki val int_max h kya for invalid tc as 0 
        //to update hoga hi unless sabmein infinte na aara ho
        for(int i=0;i<s.size();i++){
            temp+=dist[s[i]-'A'][k];
        }
        count=min(count,temp);
    }
    if(count>=1000000) count=-1;// cant use INT_MAX here
    return count;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": "<<solve()<<endl;
    }
}

/* 
input:
7
ABC
2
BA
CA
ABC
2
AB
AC
F
0
BANANA
4
AB
AN
BA
NA
FBHC
4
FB
BF
HC
CH
FOXEN
8
NI
OE
NX
EW
OI
FE
FN
XW
CONSISTENCY
26
AB
BC
CD
DE
EF
FG
GH
HI
IJ
JK
KL
LM
MN
NO
OP
PQ
QR
RS
ST
TU
UV
VW
WX
XY
YZ
ZA

Output:
Case #1: 2
Case #2: -1
Case #3: 0
Case #4: 3
Case #5: -1
Case #6: 8
Case #7: 100
*/
