/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(q.empty()==false){
            auto f = q.front();
            q.pop();
            TreeNode* curr = f.first;
            int vertical = f.second.first;
            int level = f.second.second;
            ans[vertical][level].insert(curr->val);
            if(curr->left){
                q.push({curr->left,{vertical-1,level+1}});
            }
            if(curr->right){
                q.push({curr->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>> ret;
        for(auto i : ans){
            vector<int> le;
            for(auto it : i.second){
                le.insert(le.end(),it.second.begin(),it.second.end());
            }
            ret.push_back(le);
        }
        return ret;
    }
};
