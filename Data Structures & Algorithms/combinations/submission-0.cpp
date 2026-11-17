class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> out;
        out.reserve(1024); //...


        // n; 1,2,3,4,5,6
        // k = 3

        vector<int> buf;
        buf.reserve(k);
        auto dfs = [&](this auto&& self, int top_num, int depth){
            if (depth == k+1) {
                out.push_back(buf);
                return; // pop?
            }

            // buf.push_back(top_num);  
            // k - depth // how amyn we must place
            for (int i = top_num; i <= n - k + depth; ++i) {
                buf.push_back(i);
                self(i+1, depth+1);
                buf.pop_back();
            }
        };

        dfs(1, 1);
        return out;



        
    }
};