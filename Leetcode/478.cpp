/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

/* Rejection Sampling */
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;
public:
    Solution(double radius, double x_center, double y_center): dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}
    
    vector<double> randPoint() {
        while(true) {
            double x = dis(gen), y = dis(gen);
            if(x * x + y * y <= r * r) return {xc + x, yc + y};
        }
    }
};

/* calulate CDF */
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center): dis(0, 1), xc(x_center), yc(y_center), r(radius) {}
    
    vector<double> randPoint() {
        double u = dis(gen), theta = dis(gen) * 2 * acos(-1.0);
        double r = sqrt(u);
        return {xc + r * cos(theta) * this->r, yc + r * sin(theta) * this->r};
    }
};