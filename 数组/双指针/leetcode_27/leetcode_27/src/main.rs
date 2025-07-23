struct Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut LeftIndex = 0;
        let N = nums.len();
        for RightIndex in 0..N {
            if nums[RightIndex]!= val {
                nums[LeftIndex] = nums[RightIndex];
                LeftIndex += 1;
            }
        }
        LeftIndex as i32
    }
}


fn main() {
    let mut nums = vec![3, 2, 2, 3];
    let val = 3;

    let new_len = Solution::remove_element(&mut nums, val);

    println!("移除值 {} 后的新长度为: {}", val, new_len);
    println!("新的数组内容为: {:?}", &nums[..new_len as usize]);
}
