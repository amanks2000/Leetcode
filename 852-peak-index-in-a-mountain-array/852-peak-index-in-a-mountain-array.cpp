class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 1, e = n-1;

        while(s <= e) {
            int mid = (s + e) >> 1;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) // mountain
                return mid;
            else if(arr[mid] < arr[mid+1]) // increasing sequence
                s = mid;
            else if(arr[mid] > arr[mid+1]) // decreasing sequence
                e = mid;
        }
        return -1;
    }
};