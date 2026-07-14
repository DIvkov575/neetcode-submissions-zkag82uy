class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time_acc = 0;

        int bptr = 0;    
        int tptr;

        while (bptr < colors.size() - 1) {
            tptr = bptr + 1;

            
            while ((colors[tptr] == colors[bptr]) && (tptr < colors.size())) { 
                ++tptr;
             }


            int sum = accumulate(neededTime.begin() + bptr, neededTime.begin() + tptr, 0);
            int max_val = *max_element(neededTime.begin() + bptr, neededTime.begin() + tptr);
            time_acc = time_acc + sum - max_val;
            
            bptr = tptr;
        }

        return time_acc;
    }
};
