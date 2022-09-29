class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        long long sum = 0;
        int index = binarySearch(arr, x, 0, n-1);
        int lo, hi;
        if(index+1-k < 0){
            lo = 0;
            hi = k-1;
        }
        else{
            lo = index + 1 - k;
            hi = index;
        }
        for(int i = lo; i <= hi; i++)
            sum += abs(x-arr[i]);
        int mlo = lo, mhi = hi;
        long long msum = sum;
        // cout << lo << " " << hi << " " << sum << endl;
        for(int i = lo; i <= index && hi+1 < n; i++) {
            hi++;
            sum -= abs(x-arr[i]);
            sum += abs(x-arr[hi]);
            if(sum < msum){
                mlo = i+1;
                mhi = hi;
                msum = sum;
            }
        }
        for(int i = mlo; i <= mhi; i++)
            ans.push_back(arr[i]);
        return ans;
    }
    
    int binarySearch(vector<int> arr, int key, int s, int e) {
        if(arr[s] > key)
            return s;
        if(arr[e] < key)
            return e;
        int mid = (s + e)/2;
        if(arr[mid] == key)
            return mid;
        
        else if(arr[mid] < key) {
            if(arr[mid+1] > key) {
                if(abs(key-arr[mid]) <= abs(key-arr[mid+1]))
                    return mid;
                else
                    return mid+1;
            }
            return binarySearch(arr, key, mid+1, e);
        }
        
        else {
            if(arr[mid-1] < key) {
                if(abs(key-arr[mid-1]) <= abs(key-arr[mid]))
                    return mid-1;
                else
                    return mid;
            }
            return binarySearch(arr, key, s, mid-1);
        }
    }
    
};