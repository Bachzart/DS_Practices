class Solution {
public:
	long long getTime(vector<int>& piles, int speed) {
		long long time = 0;
		for(int i: piles) {
			int curtime = (i + speed - 1) / speed;
			time += curtime;
		}
		return time;
	}
    int minEatingSpeed(vector<int>& piles, int h) {
    	int low = 1, high = *max_element(piles.begin(), piles.end());
    	int ans = high;
    	while(low < high) {
    		int speed = (high - low) / 2 + low;
    		long long time = getTime(piles, speed);
    		if(time <= h) {
    			ans = speed;
    			high = speed;
    		} else low = speed + 1;
    	}
    	return ans;
    }
};