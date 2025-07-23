use core::num;

struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len() as i32 -1;
        while left <= right {
            let mid = left + (right-left)/2;
            let val = nums[mid as usize];
            if  val>target  {
                right = mid - 1;
            }
            if  val< target {
                left = mid + 1;
            }
            if  val == target{
                return mid;
            }
        }
        -1
    }
}
fn main() {
    let nums = vec![-1, 0, 3, 5, 9, 12];
    let target = 9;

    let index = Solution::search(nums, target);

    if index != -1 {
        println!("Found target at index: {}", index);
    } else {
        println!("Target not found.");
    }
}
