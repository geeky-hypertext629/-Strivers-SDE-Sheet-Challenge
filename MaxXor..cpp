#include<bits/stdc++.h>

/* IDEA:
1) Put all numbers of array in trie in correct bits wise
2) Again with each number of array find the maximum xor with trie.

*/

struct TrieNode
{
      TrieNode * child[2];
       TrieNode(){
           child[0] = NULL;
           child[1] = NULL;
       }
};

class Trie{
    private :
    TrieNode * root ;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode * curr = root;
//         5 -> 0000000000000101
//             31--------------1-0
        for(int i = 31 ;i>=0 ; i--)
        {
            int index = ((num>>i)& 1);
            if(curr->child[index] == NULL)
            {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
    }
    int getMax(int x){
        TrieNode * curr = root;
        int maxans = 0;
        for(int i = 31; i>=0 ;i-- ){
            int index = ((x>>i) & 1);
            if(curr->child[1-index] != NULL){
                maxans = (maxans) | (1<<i) ;
                curr= curr->child[1-index];//go to that bit
            }
            else{
                curr = curr->child[index];
            }
        }
        return maxans;
    }
    
};



vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>>offlineQueries;
    int q = queries.size();
    for(int i = 0 ; i<q ; i++){
//         till and x  and index
        offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(offlineQueries.begin(),offlineQueries.end());
    vector<int>ans(q,0);
    int n = arr.size();
    Trie t ;
    int ind = 0;
    for(int i = 0 ; i< q; i++){
//         moving through queries
        int till = offlineQueries[i].first;
        int x  = offlineQueries[i].second.first;
        int index = offlineQueries[i].second.second;
        while(ind<n and arr[ind] <=till){
            t.insert(arr[ind]);
            ind++;
        }
        if(ind == 0){
            ans[index] = -1;
        }
        else{
            ans[index] = t.getMax(x);
        }
    }
    
    
    return ans;

    
    
}