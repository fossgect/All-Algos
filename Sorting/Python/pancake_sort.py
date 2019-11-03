def pancake_sort(nums):
    arr_len = len(nums)
    while arr_len > 1:
        vl = nums.index(max(nums[0:arr_len]))
        nums = nums[vl::-1] + nums[vl+1:len(nums)]
        nums = nums[arr_len-1::-1] + nums[arr_len:len(nums)]
        arr_len -= 1
    return nums

user_input = input("Input numbers separated by a comma:\n").strip()
nums = [int(item) for item in user_input.split(',')]
print(pancake_sort(nums))
