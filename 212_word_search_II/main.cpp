class Solution {
public:
    class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        string word = ""; 
    };
    vector<string> _result;
    TrieNode* root;
    vector<vector<char>> board;
    vector<vector<int>> displace = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        root = new TrieNode();
        for(string& w : words){
            TrieNode* curNode = root;
            for(char& c : w){ 
                if(curNode->children.find(c) == curNode->children.end()){
                    curNode->children[c] = new TrieNode(); 
                }
                curNode = curNode->children[c];
            }
            curNode->word = w;
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(root->children.find(board[i][j]) != root->children.end()){
                    backtracking(i, j, root);
                }
            }
        }
        return _result;
    }
    void backtracking(int row, int col, TrieNode* root){
        char curC = board[row][col];
        TrieNode* curNode = root->children[curC];
        if(!curNode->word.empty()){
            _result.push_back(curNode->word);
            curNode->word = ""; 
        }
        board[row][col] = '#';
        for(int i = 0; i < 4; i++){
            int ncol = col + displace[i][1];
            int nrow = row + displace[i][0];
            if(nrow < 0 || nrow >= board.size() || ncol < 0 || ncol >= board[0].size())
                continue;
            curNode->children;
            if(curNode->children.find(board[nrow][ncol]) != curNode->children.end()){
                backtracking( nrow, ncol, curNode);
            }
        }
        board[row][col] = curC;
        if(curNode->children.empty()){
            root->children.erase(curC);
        }
    }
};
