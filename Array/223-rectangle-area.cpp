class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        
        
        int area1 = (ax1-ax2)*(ay1-ay2);
        int area2 = (bx1-bx2)*(by1-by2);
        
        int area = 0;
        if(bx1>=ax2 or ax1>=bx2 or by1>=ay2 or ay1>=by2)
            area = 0;
        else
        {
            area = abs(max(ax1,bx1) - min(ax2,bx2)) * abs(max(ay1,by1) - min(ay2,by2));
        }
        
        return area1+area2-area;
        
        
    }
};
