struct Solution;
impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut prefix = vec![0; n + 1];

        // 计算前缀和
        for i in 0..n {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        let mut length = i32::MAX;

        for i in 1..=n {
            let desire = prefix[i] - target;
            let mut pos: i32 = -1;
            let mut low: i32 = 0;
            let mut high: i32 = (i - 1) as i32;

            // 二分查找 prefix[pos] <= desire 的最大 pos
            while low <= high {
                let mid = (low + high) / 2;
                if prefix[mid as usize] <= desire {
                    pos = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if pos != -1 {
                length = length.min((i as i32) - pos);
            }
        }

        if length == i32::MAX {
            0
        } else {
            length
        }
    }
}
fn main() {
    let target = 7;
    let nums = vec![2, 3, 1, 2, 4, 3];
    let result = Solution::min_sub_array_len(target, nums);
    println!("The minimum length of a subarray with sum at least {} is: {}", target, result);
}
