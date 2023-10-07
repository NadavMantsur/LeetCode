#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insertIdx = m + n - 1;

        while (0 != m && 0 != n)
        {
            if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[insertIdx] = nums1[m - 1];
                m -= 1;
            }
            else{
                nums1[insertIdx] = nums2[n - 1];
                n -= 1;
            }

            --insertIdx;
        }

        while (0 < m)
        {
            nums1[insertIdx] = nums1[m - 1];
            m -= 1;
            --insertIdx;
        }

        while (0 < n)
        {
            nums1[insertIdx] = nums2[n - 1];;
            n -= 1;
            --insertIdx;
        }
    // or merge nums2 into nums1 using std::merge (#include <algorithm>)
    // std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.end(), 
                                                            // nums1.begin());
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    for (auto val : nums1)
    {
        cout << val << ',';
    }

    cout << endl;

    return 0;
}