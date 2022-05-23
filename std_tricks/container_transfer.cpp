#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main(){
    vector<pair<int, int>> test_pair;
    // insert pair with curly braces
    test_pair.push_back({1,2}); // inserted a pair of (1,2)
    // convert a dictionary to vector
    unordered_map<int, int> dic;
    dic[1] = 2;
    dic[2] = 4;
    vector<pair<int, int>> mapToVec(dic.begin(), dic.end());
    return  0;
}
