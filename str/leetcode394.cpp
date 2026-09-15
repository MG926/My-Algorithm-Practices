#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string ans="";
        int n=s.length(),idx=0;
        while(idx<n){
            if(s[idx]>='0' && s[idx]<='9'){
                string ks="";
                while(s[idx]>='0' && s[idx]<='9'){
                    ks += s[idx];
                    idx++;
                }
                int k=stoi(ks);
                pair<string,int> tmp=encode(s,k,idx+1);
                ans += tmp.first;
                idx = tmp.second;
            }else{
                ans += s[idx];
            }
            idx++;
        }
        return ans;
    }
    pair<string,int> encode(string s, int k, int idx){
        string ret="";
        while(s[idx]!=']'){
            if(s[idx]>='0' && s[idx]<='9'){
                string ks="";
                while(s[idx]>='0' && s[idx]<='9'){
                    ks += s[idx];
                    idx++;
                }
                int k1=stoi(ks);
                pair<string,int> tmp=encode(s,k1,idx+1);
                ret += tmp.first;
                idx = tmp.second;
            }else{
                ret += s[idx];
            }
            idx++;
        }
        string ret1="";
        for(int i=0;i<k;i++){
            ret1 += ret;
        }
        pair<string,int> retpair(ret1,idx);
        return retpair;
    }
};