/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> outDeg;
    unordered_map<TreeNode*, TreeNode*> parent;
    queue<TreeNode*> q;
    vector<vector<int>> findLeaves(TreeNode* root) {
        parent[root] = nullptr;
        findParent(root);
        vector<vector<int>> res;
        while(!q.empty()){
            queue<TreeNode*> temp;
            vector<int> inner;
            while(!q.empty()){
                TreeNode* top = q.top(); q.pop();
                inner.push_back(top->val);
                if(parent[top] != nullptr){
                    outDeg[parent[top]] --;
                    if(outDeg[parent[top]] == 0){
                        temp.push(parent[top]);
                    }
                }
            }
            res.push_back(inner);
            swap(q, temp);
        }
        return res;
    }
    void findParent(TreeNode* root){
        if(root == nullptr)
            return;
        outDeg[root] = 0;
        if(root->left != nullptr){
            outDeg[root]++;
            parent[root->left] = root;
            findParent(root->left);
        }
        if(root->right != nullptr){
            outDeg[root]++;
            parent[root->right] = root;
            findParent(root->right);
        }
        if(outDeg[root] == 0){
            q.push(root);
        }
    }
};
