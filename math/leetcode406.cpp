#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>& u, const vector<int>& v){
            return u[0]<v[0] || u[0]==v[0] && u[1]<v[1];
        });
        int n=people.size();
        vector<vector<int>> ans(n,vector<int>(2,1000001));
        int p_num=0;
        for(auto p:people){
            p_num = p[1]+1;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(ans[i][0]>=p[0]) cnt++;
                if(cnt==p_num){
                    ans[i] = p;
                    break;
                }
            }
        }
        return ans;
    }
};