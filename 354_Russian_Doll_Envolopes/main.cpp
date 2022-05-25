class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
		sort(envelopes.begin(), envelopes.end(), [](auto& e1, auto& e2){return e1[0]==e2[0]?e1[1]>e2[1]:e1[0]<e2[0];});
        vector<int> dp;
        for(auto& e : envelopes){
            auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
            if(iter == dp.end())
                dp.push_back(e[1]);
            else
                *iter = e[1];
        }
        return dp.size();
    }
};
