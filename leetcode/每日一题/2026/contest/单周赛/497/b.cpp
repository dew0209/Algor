class Solution {
public:

    double get_d(double d){
        double radians = acos(d);
        double degrees = radians * 180.0 / M_PI; 
        return degrees;
    }
    
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());

        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        vector<double> res;
        if(c - a < b && a + b > c){
            res.push_back(get_d((1.0 * b * b + c * c - a * a ) / (2.0 * b * c)));
            res.push_back(get_d((1.0 * a * a + c * c - b * b) / (2.0 * a * c)));
            res.push_back(get_d((1.0 * a * a + b * b - c * c) / (2.0 * a * b)));
        }
        
        
        return res;
    }
};