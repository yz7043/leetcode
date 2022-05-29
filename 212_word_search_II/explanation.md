## Solution
1. Key idea: backtracing and Trie
2. First, build a Trie structure that stores target words (make use of unordered map)
3. Use backtracing to explore the tree and to see if there is a matched string.
    - If there is one matching, set that dictionary to null because you don't want to match it agiain.
