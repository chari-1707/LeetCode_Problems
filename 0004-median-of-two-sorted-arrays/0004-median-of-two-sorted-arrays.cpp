class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if (m > n)
            return findMedianSortedArrays(b, a);

        int lo = 0, hi = m;
        int left = (m + n + 1) / 2; // works both for even and odd
        int q = m + n;
        while (lo <= hi) {
            int mid1 = lo + (hi - lo) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < m) r1 = a[mid1];
            if (mid2 < n) r2 = b[mid2];
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (q % 2 != 0) return max(l1, l2);
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }else if(l1 > r2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }
        return 0;
        // T.C : O(min{log(m) , log(n)}) --> O(min{log(m+n)})
    }
};