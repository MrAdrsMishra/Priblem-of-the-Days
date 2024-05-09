#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
class Solution {
   static bool compare(int a , int b){
        return a>b;
    }
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(),compare); // Sort in non-increasing order
    
        long long totalHappiness = happiness[0];
           int i = 1;
        while(i< k && (happiness[i]-i)> 0 && i < happiness.size()){
            cout<<happiness[i]-i<<" ";
            totalHappiness += happiness[i]-i;
            i++;
        }
        return totalHappiness;
    }
};
int main()
{
Solution ob;
vector<int> happiness= {67,413,584,625};
cout<<" ans is :"<<ob.maximumHappinessSum(happiness,)<<endl;

   return 0;
}
