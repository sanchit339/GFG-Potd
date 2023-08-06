#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void Permutation(int idx , string s , vector<string>& ans){
        // base case
        if(idx == s.size()){
            ans.push_back(s); // as we are swapping we dont need temp (DS)
            return;
        }

        for(int i = idx ; i < s.size() ; i++){
            swap(s[i] , s[idx]);
            Permutation(idx + 1 , s , ans);
            swap(s[i] , s[idx]);
        }
    }
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        Permutation(0 , S , ans);
        sort(ans.begin() , ans.end());
        return ans;
    }
};