class Solution {
public:
    double angleClock(int hour, double minutes) {
        double a = (double(hour%12)*60+minutes) / 720;
        double b = minutes / 60;

        double diff = abs(a - b);
        return 360*min(diff, 1- diff);
    }
};
