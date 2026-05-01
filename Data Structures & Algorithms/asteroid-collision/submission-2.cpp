#include<queue>
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> output;
        deque<int> s;
        for (int asteroid: asteroids) {
            if (asteroid < 0 && s.empty()) {s.push_back(asteroid);}
            
            if (asteroid < 0) {
                while (!s.empty() && s.back() + asteroid < 0) {s.pop_back();}

                if (s.empty()) {
                    output.push_back(asteroid);
                    continue;
                }

                if (s.back() + asteroid > 0) {
                    continue;
                } else if (s.back() + asteroid == 0) {
                    s.pop_back();
                } 

            } else {
                s.push_back(asteroid);
            }
        }


        for (int asteroid: s) {
            output.push_back(asteroid);
        }

        return output;
        
    }
};