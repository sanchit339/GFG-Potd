//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> v, long long n, long long m){
        //code
        sort(v.begin() , v.end());
        int a = 0 , b = m - 1;
        int mini = INT_MAX;
        for(int i = 0 ; i <= n - m ; ++i){
            long long diff = v[b] - v[a];
            // cout << v[b] << " " <<  v[a] << endl;
            if(diff < mini){
                mini = diff;
            }
            ++a , ++b;
        }
        return mini;
    }   
};
