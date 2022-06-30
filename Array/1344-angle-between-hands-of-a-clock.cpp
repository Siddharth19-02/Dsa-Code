class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%60;
        double hourAngle= hour*30 + minutes*0.5 ;
        double minuteAngle= minutes*6;
        double angle = abs(hourAngle-minuteAngle);
        return min(360-angle,angle);
    }
};
