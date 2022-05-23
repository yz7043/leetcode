#include <iostream>
#include <priority_queue>
using namespace std;
typedef pair<int, int> pi;
class Comparator{
    public:
        bool operator()(pi p1, pi, p2){
            retrun p1.second < p2.second;
        }
}
int main(){
    // Max heap with user defined comparator;
    priority_queue<pi, vector<pi>, Comparator> pq;
    return 0;
}
