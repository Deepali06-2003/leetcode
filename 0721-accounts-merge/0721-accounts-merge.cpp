class Disjoint{
    public:
    vector<int>parent, size;
    
    Disjoint(int n){
        parent.resize(n, 0);
        size.resize(n , 1);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    
    int FindParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = FindParent(parent[n]);
    }
    
    void UnionBySize(int u, int v){
        int pu = FindParent(u);
        int pv = FindParent(v);
        if(pu == pv) return;
        else if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] = size[pu] + size[pv];
        }
        
        else{     //if size[pv] >= size[pu] -> then ultimate parent of pu is updated
            parent[pu] = pv;
            size[pv] = size[pv] + size[pu];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string, int>mp;          // mail , name(int)

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size(); j++){
                string mail = accounts[i][j];

                if(mp.find(mail) == mp.end()) mp[mail] = i;         // if not found mail
                else ds.UnionBySize(i, mp[mail]);                    //merge
            }
        }

        vector<string>mergeMail[n];
        for(auto i: mp){
            string mail = i.first;
            int node = ds.FindParent(i.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>>res;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string>temp;
            string name = accounts[i][0];
            temp.push_back(name);

            for(auto j: mergeMail[i]){
                temp.push_back(j);
            }

            res.push_back(temp);
        }
        return res;
    }
};