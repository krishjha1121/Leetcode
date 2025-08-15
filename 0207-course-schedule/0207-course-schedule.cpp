class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
	    for(auto it : prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    int n = numCourses;
	    vector<int> indegree(n , 0);
        
        for(int i = 0 ; i < n ;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i < n ;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> res;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return res.size() == n;
    }
};