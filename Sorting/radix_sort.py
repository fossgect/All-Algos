def radix_sort(nums):
    radix = 10
    placement = 1
    max_digit = max(nums)

    while placement < max_digit:
      buckets = [list() for _ in range(radix)]
      for i in nums:
        temp = int((i / placement) % radix)
        buckets[temp].append(i)
      x = 0
      for y in range(radix):
        buck = buckets[y]
        for i in buck:
          nums[x] = i
          x += 1
      placement *= radix
    return nums
user_input = input("Input numbers separated by a comma:\n").strip()
nums = [int(item) for item in user_input.split(',')]
print(radix_sort(nums))
