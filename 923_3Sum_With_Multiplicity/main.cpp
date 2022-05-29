class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int N = 1e9+7;
        long long res = 0; 
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            int  j = i+1; int k = arr.size()-1;
            while(j < k){
                if(arr[i] + arr[j] + arr[k] == target) {
                    if(arr[j] != arr[k]){
                        int left = 1, right =1;
                        while(j+1 < k && arr[j] == arr[j+1]) {j++; left++;}
                        while(k-1 > j && arr[k] == arr[k-1]) {k--; right++;}
                        res += left * right;
                        res = res % N; // now j and k are still statisfy the equition
                        j++; k--;
                    }else{
                        res += (k - j + 1) * (k - j) / 2; // choose 2 from k-j+1
                        res = res % N;
                        break;
                    }
                }
                else if(target - arr[i] > arr[j] + arr[k]) j++;
                else k--;
            }
        }
        return res;
    }
};

class Solution2{
    public:
        int threeSumMulti（vector<int>& arr, int target){
			int N = 1e9+7;
            long long res = 0;
            vector<int> count(101, 0);
			// x != y != z
            for(auto& n : arr)count[n]++;
            for(int i = 0; i < 101; i++){
                for(int j = i+1; j < 101; j++){
                    int z = target - i - j;
                    if(z <= 100 && j < z){ 
                        res += count[i] * count[j] * count[z];
                        res = res % N;
                    }
                }
            }
			// case 2 and case 3 are both necessary 2, 1, 1, 2. 211, 112 are both accepetable
			// x == y, y != z
            for(int i = 0; i < 101; i++){
                int z = target - 2 * i;
                if(z > i && z <= 100){ 
                    res += count[i] * (count[i]-1)/ 2 * count[z];
                    res = res % N;
                }
            }
			// x != y, y == z
            for(int i = 0 ; i < 101; i++){
                if((target - i) % 2 == 0){
                    int y = (target-i)/2;
                    if(y > i && y <= 100){
                        res += count[y] * (count[y]-1) / 2 * count[i];
                        res %= N;
                    }
                }
            }
			// x == y == z
            for(int i = 0; i < 101; i++){
                if(count[i] >= 3 && i * 3 ==target){
                    long long temp = (long long)count[i] * (long long)(count[i] - 1) * (long long)(count[i] - 2) / (3 * 2);
                    res += temp % N;
                    res = res % N;
                }
            }
            return res;
        }
}
