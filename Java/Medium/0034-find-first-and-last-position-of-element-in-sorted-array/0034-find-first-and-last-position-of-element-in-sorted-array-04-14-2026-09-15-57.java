class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;
        int left_most = findleftmost(nums, target, n);
        int right_most = findrightmost(nums, target, n);
        return new int[] { left_most, right_most };
    }
    public static int findleftmost(int [] nums,int target,int n)
    {
        int low=0;
        int high=n-1;
        int left_most=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                left_most=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        return left_most;
    }
    public static int findrightmost(int [] nums,int target,int n)
    {
        int low=0;
        int high=n-1;
        int right_most=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                right_most=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        return right_most;
    }
}