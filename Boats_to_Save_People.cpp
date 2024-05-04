#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j =people.size()-1;
        int count =0;
        while(i<=j){
           if(people[i] + people[j] <= limit){
               count++;
               i++;
               j--;
           }
            else{
                count++;
                j--;
            }
        }
        return count;
    }
};
int main()
{
    vector<int> nums={1,4,3,2,2,4};
Solution sc;
int ans = sc.numRescueBoats(nums,5);
cout<<" ans is:"<<ans<<endl;

   return 0;
}