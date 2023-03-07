//BackTracking
class Solution
{
public:
    void findSubset(vector<vector<int>> &subset, int index, vector<int> &nums, vector<int> &current)
    {
        //adding the empty list first of all
        subset.push_back(current);
        for (int i = index; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            findSubset(subset, i + 1, nums, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subset;
        vector<int> current; //to save the small lists
        findSubset(subset, 0, nums, current);
        return subset;
    }
};

