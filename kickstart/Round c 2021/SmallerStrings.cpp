/*
Problem A
You are given an integer K and a string S of length N, consisting of lowercase letters from the first K letters of the English alphabet. Find the number of palindrome strings of length N which are lexicographically smaller than S and consist of lowercase letters from the first K letters of the English alphabet.
A string composed of ordered letters a1,a2,…,an is lexicographically smaller than another string of the same length b1,b2,…,bn if ai<bi, where i is the first index where characters differ in the two strings. For example, the following strings are arranged in lexicographically increasing order: aaa, aab, aba, cab.
A palindrome is a string that is the same written forwards and backwards. For example, anna, racecar, aaa and x are all palindromes, while ab, frog and yoyo are not.
As the number of such strings can be very large, print the answer modulo 109+7.

Input
The first line of the input gives the number of test cases, T. T test cases follow.
Each test case consists of two lines. The first line contains two integers N and K. The second line contains a string S of length N, consisting of lowercase letters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of lexicographically smaller palindrome strings modulo 109+7.


Memory limit: 1 GB.
1≤T≤100.
1≤N≤10^5.
1≤K≤26.

The string S consists of lowercase letters from the first K letters of the English alphabet.

Sample Input
3
2 3
bc
5 5
abcdd
1 5
d

Sample Output
Case #1: 2
Case #2: 8
Case #3: 3

In Sample Case #1, the palindromes are ["aa", "bb"].
In Sample Case #2, the palindromes are ["aaaaa", "aabaa", "aacaa", "aadaa", "aaeaa", "ababa", "abbba", "abcba"].
In Sample Case #3, the palindromes are ["a", "b", "c"].

*/
#include <iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
const long long mod   =  1e9 + 7;
long long modpow(long long x, unsigned int y, int p)
{
    long long res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
long long solve(string s, int k, int n){
    long long res=0;
    if(n==1) return (s[n-1]-'a');
    int p=(n+1)/2;
    for(int i=0;i<p;i++){
        long long ind=(s[i]-'a');
        res=(res%mod + (ind*modpow(k,p-1-i,mod)%mod))%mod;
    }
    
    string t2=s.substr(0,n/2);
    for(int i=n/2;i<n;i++){
        t2+=s[n-1-i];
    }
    if(t2<s) (++res)%mod;
    return res%mod;
}
int main() {
	int t; cin >> t;
	for (int kek = 0; kek < t; kek++) {
		int n;int k;
		cin>>n>>k;
		string s;
		cin>>s;
		long long res=solve(s,k,n);
		cout << "Case #" << kek + 1 << ": " << res << endl;
	}
	
	return 0;
}
