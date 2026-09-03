#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> _edges;
    vector<int> _nodes;
    bool valid=true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //找出环
        _edges.resize(numCourses);
        _nodes.resize(numCourses);
        for(auto edge:prerequisites){
            _edges[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<numCourses && valid;i++){
            if(_nodes[i]==2) continue;
            dfs(i);
        }
        return valid;
    }
    void dfs(int u){
        _nodes[u] = 1;
        for(auto v:_edges[u]){
            if(_nodes[v]==0){
                dfs(v);
                if(!valid) return;
            }else if(_nodes[v]==1){
                valid = false;
                return;
            }
        }
        _nodes[u] = 2;
    }
};