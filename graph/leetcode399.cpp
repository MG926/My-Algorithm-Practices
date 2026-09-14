#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> map;
        int n=equations.size();
        for(int i=0;i<n;i++){
            string start=equations[i][0],target=equations[i][1];
            double weight=values[i];
            map[start][target] = weight;
            map[target][start] = 1.0/weight;
        }
        int qn = queries.size();
        vector<double> ans(qn,-1);
        for(int i=0;i<qn;i++){
            string start=queries[i][0],target=queries[i][1];
            if(!map.count(start) || !map.count(target)) continue;
            if(start==target){
                ans[i] = 1.0;
                continue;
            }
            queue<pair<string,double>> q;
            unordered_map<string,bool> visited;
            q.push({start,1.0});
            visited[start] = true;
            while(!q.empty()){
                string curr=q.front().first;
                double curr_val=q.front().second;
                q.pop();
                if(curr==target){
                    ans[i] = curr_val;
                    break;
                }
                for(auto neighbor:map[curr]){
                    string nxt=neighbor.first;
                    double nxt_val=neighbor.second;
                    if(!visited[nxt]){
                        visited[nxt] = true;
                        q.push({nxt,curr_val*nxt_val});
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> equation={
        {"a","b"},{"a","b"}
    };
    vector<double> val={3.0,2.0};
    vector<vector<string>> query={{"a","b"}};
    sol.calcEquation(equation,val,query);
}