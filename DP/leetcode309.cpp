#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int fi0=-prices[0],fi1=0,fi2=0;
        for(int i=1;i<n;i++){
            int fj0,fj1,fj2;
            fj0 = max(fi0,fi2-prices[i]);
            fj1 = fi0+prices[i];
            fj2 = max(fi1,fi2);
            fi0 = fj0;
            fi1 = fj1;
            fi2 = fj2;
        }
        return max(fi0,max(fi1,fi2));
    }
};

int main()
{
    vector<int> prices={1,2,3,0,2};
    Solution sol;
    sol.maxProfit(prices);
}