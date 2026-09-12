#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length()) return {};
        int nol=-100000;
        vector<int> words_num(26,nol);
        int p_len = p.length();
        for(int i=0;i<p_len;i++){
            int idx = p[i]-'a';
            if(words_num[idx]<0) words_num[idx] = 0;
            words_num[idx] += 1;
        }
        vector<int> ans;
        int cnt=p_len;
        for(int i=0;i<p_len;i++){
            int idx = s[i]-'a';
            if(words_num[idx]==nol) continue;
            if(words_num[idx]>0) cnt--;
            words_num[idx]--;
        }
        if(!cnt) ans.push_back(0);
        for(int i=p_len;i<s.length();i++){
            if(s[i]==s[i-p_len]){
                if(!cnt) ans.push_back(i-p_len+1);
            }else{
                int idx=s[i-p_len]-'a',idx1=s[i]-'a';
                if(words_num[idx]!=nol){
                    if(words_num[idx]>=0) cnt++;
                    words_num[idx]++;
                }
                if(words_num[idx1]!=nol){
                    if(words_num[idx1]>0) cnt--;
                    words_num[idx1]--;
                }
                if(!cnt) ans.push_back(i-p_len+1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s="cbaebabacd",p="abc";
    sol.findAnagrams(s,p);
    return 0;
}