/**
 * @file DAG_ShortestPath.cpp
 * @author your name Striver Graph series
 * @brief DO TOPOLOGICAL and Update the Distance
 * @version 0.1
 * @date 2023-08-03
 */

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node , vector<int> &vis , stack<int> &st , vector<pair<int,int>> graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            int v = it.first;
            if(vis[v]) continue; // check its adj
            dfs(v , vis , st , graph);
        }
        st.push(node);
    }
public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // Create Graph
        vector<pair<int,int>> graph[N]; // U -> N ... pair[i].F = v , .S = wt
        for(int i = 0 ; i < M ; ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            graph[u].push_back({v , wt});
        }

        // DFS all the node
        // N(N+E)  
        vector<int>vis(N , 0);
        stack<int>st;
        for(int i = 0 ; i < N ; ++i){
            if(!vis[i]){
                dfs(i , vis , st , graph);
            }
        }

        // Dist vector update
        vector<int> dist(N);
        for(int i = 0 ; i < N ; ++i){
            dist[i] = 1e9;
        }

        dist[0] = 0; // start from given node here (0)
        
        while(!st.empty()){
            int node = st.top();
            st.pop();

            for(auto it : graph[node]){
                int v = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[v]){ // from node to v ... node + wt
                    dist[v] = dist[node] + wt;
                }
            }
        }
        return dist; // dist from 0 to all node 
    }
};

// BFS implementation

class Solution{
public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        // create a Graph

        vector<pair<int,int>> graph[N]; // U -> N ... pair[i].F = v , .S = wt
        for(int i = 0 ; i < M ; ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            graph[u].push_back({v , wt});
        }

        vector<int> dist(N , INT_MAX);
        dist[0] = 0;
        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                int v = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                    q.push(v);
                }
            }
        }
        for(auto it : dist){
            if(it = INT_MAX){
                it = -1;
            }
        }
        return dist;
    }
};