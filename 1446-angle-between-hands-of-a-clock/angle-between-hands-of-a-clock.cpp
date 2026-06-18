class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour%12) * 30 + minutes*0.5;
        double minAngle = minutes*6; 
        double ans = abs(hourAngle - minAngle);
        
        if (ans > 180) {
            ans = 360.0 - ans;
        }
        return ans;
    }
};