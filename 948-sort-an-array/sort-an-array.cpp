class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int randomIndex = low + random() % (high - low + 1);
        swap(nums[randomIndex], nums[high]);

        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};