#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c){
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
    return false;
}

int solve(string &s){
    if(s.size()==1) return 0;
    int count=0;
    int con=0,vow=0;
    int freqcon=INT_MIN,freqvow=INT_MIN;
    unordered_map<char,int> map;
    for(int i=0;i<s.size();i++){
        map[s[i]]++;
        if(isvowel(s[i])==true) {vow++;
            freqvow=max(map[s[i]],freqvow);
        }
        else {
            con++;
            freqcon=max(map[s[i]],freqcon);
        }
    }
    if(freqcon==s.size() || freqvow==s.size()){
        return 0;
    }
    int count1=0,count2=0;
    int l1=vow-freqvow;
    count1=(l1*2)+con;
    int l2=con-freqcon;
    count2=(l2*2)+vow;
    count=min(count1,count2);
    return count;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string s;
        cin>>s;
        cout<<"Case #"<<i<<": "<<solve(s)<<endl;
    }
    
}
