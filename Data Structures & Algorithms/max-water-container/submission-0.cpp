class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int max_area = 0;

        while(left < right)
        {
            int current_height = min(heights[left], heights[right]);
            int current_width = right - left;
            int current_area = current_height * current_width;
            max_area = max(max_area, current_area);
            if (heights[left] < heights[right]) {
                left++; 
            } else {
                right--; 
            }
        }
        return max_area;
    }
};
