#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum = sum+nums[j];
                sums.push_back(sum);
            }

        }
        for(int i=0;i<sums.size();i++){
            cout<<sums[i]<<"  ";
        }
        cout<<endl;
        sort(sums.begin(), sums.end());
        for(int i=0;i<sums.size();i++){
            cout<<sums[i]<<"  ";
        }
        int s=0;
        for(int i=left-1;i<right;i++){
            s=s+sums[i];
        }
        return s;
    }
};
int main()
{
    Solution ss;
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    cout<<ss.rangeSum(s,4,1,5);

}