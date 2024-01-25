class Solution {
public:
    bool memo[100001] = {};
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int reachableInRange = 0;
        vector<bool> reachable(n, false);
        reachable[0] = true;
        
        for(int i = 1; i < n; i++) {
            int min = i - minJump;
            int max = i - maxJump;
            
            if(min >= 0 && reachable[min]) {
                reachableInRange += 1; 
            }
            if(max > 0 && reachable[max - 1]) {
                reachableInRange -= 1;
            }
            
            int flag = 1;
            if(reachableInRange == 0) {
                flag = 0;
            }
            
            reachable[i] = (flag > (s[i] - '0'));
        }
        
        return reachable[n - 1];
    }
};
