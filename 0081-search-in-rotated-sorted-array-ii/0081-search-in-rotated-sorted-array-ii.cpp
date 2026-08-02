class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target found
            if (arr[mid] == k) {
                return true;
            }

            // Duplicates make it difficult to identify
            // which half of the array is sorted.
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (arr[low] <= arr[mid]) {

                // Target lies in the sorted left half
                if (arr[low] <= k && k < arr[mid]) {
                    high = mid - 1;
                }
                else {
                    // Search in the right half
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in the sorted right half
                if (arr[mid] < k && k <= arr[high]) {
                    low = mid + 1;
                }
                else {
                    // Search in the left half
                    high = mid - 1;
                }
            }
        }

        // Target is not present
        return false;
    }
};