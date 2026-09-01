#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈
        int n = temperatures.size();
        vector<int> days(n);
        for(int i=0;i<n-1;i++){
            if(temperatures[i]<temperatures[i+1]){ 
                int j=i,cnt=1;
                while(j>=0 && temperatures[i+1]>temperatures[j]){
                    if(days[j]==0) days[j] = cnt;
                    cnt++;
                    j--;
                }
            }
        }
        return days;
    }
};

int main()
{
    Solution s;
    vector<int> v={73,74,75,71,69,72,76,73};
    s.dailyTemperatures(v);
    return 0;
}