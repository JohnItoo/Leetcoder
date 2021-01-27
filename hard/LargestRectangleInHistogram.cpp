class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indexes;
        int i = 0;
        int n = heights.size();
        int maxArea = 0;
        while (i < n) {
            if (indexes.empty() || heights[i] >= heights[indexes.top()]) {
                indexes.push(i);
            } else {
                while (!indexes.empty() &&
                       heights[i] < heights[indexes.top()]) {
                    int poppedIndex = indexes.top();
                    indexes.pop();
                    int heightAtIndex = heights[poppedIndex];
                    int currentTopIndex = indexes.empty() ? -1 : indexes.top();
                    int distance = i - (currentTopIndex)-1;
                    int area = heightAtIndex * distance;
                    maxArea = max(area, maxArea);
                }
                indexes.push(i);
            }
            i++;
        }

        while (!indexes.empty()) {
            int poppedIndex = indexes.top();
            indexes.pop();
            int heightAtIndex = heights[poppedIndex];
            int currentTopIndex = indexes.empty() ? -1 : indexes.top();
            int distance = i - (currentTopIndex)-1;
            int area = heightAtIndex * distance;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    // TO DO PROCESS STACK IN A SEPERATE FUNCTION
};