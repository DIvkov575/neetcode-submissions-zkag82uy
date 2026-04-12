class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        size_t ptr = arr.size() - 1;

        int gelem = arr[ptr];
        int gidx = ptr;
        int tmp_elem;

        while (ptr != 0) {
            while (ptr > 0 && arr[ptr] <= gelem) ptr--;
            tmp_elem = arr[ptr];

            for (int i = ptr; i < gidx; ++i) { 
                arr[i] = gelem;
            }

            gidx = ptr;
            gelem = tmp_elem;
        }

        arr[arr.size() - 1] = -1;


        return arr;

        
    }
};