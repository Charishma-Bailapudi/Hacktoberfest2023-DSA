#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void calculate(vector<int> &indegree,vector<int> adj[],int child)
	{
	    for(auto& neighbour:adj[child])
	    {
	        indegree[neighbour]++;
	    }
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> ans;
	    queue<int> q;
	    vector<int> indegree(v,0);
	    
	    for(int i=0;i<v;i++)
	    {
	        calculate(indegree,adj,i);
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    while(q.size()!=0)
	    {
	        int front = q.front();
	        ans.push_back(front);
	        q.pop();
	        for(auto& neighbour:adj[front])
	        {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
	        }
	    }
	   return ans;
	}
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        for(auto&i:res)
        {
        	cout << i<<" ";
        }
    }
    
    return 0;
}