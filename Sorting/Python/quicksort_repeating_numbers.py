import random

# this program uses three partitions instead of two (which is usually implemented in quicksort)
# this improves the run time significantly when sorting sets of numbers in which many numbers are repeated

def partition3(arr, left, right):
    x = arr[left]
    j = left
    k = right
    i = left + 1
    while i <= k:
        if arr[i] < x:
            j += 1
            arr[i], arr[j] = arr[j], arr[i]
        elif arr[i] > x:
            arr[i], arr[k] = arr[k], arr[i]
            k -= 1
            i -= 1
        i += 1
    arr[left], arr[j] = arr[j], arr[left]
    return j, k


def quick_sort_3(arr, left, right):
    while left < right:
        k = random.randint(left, right)
        arr[left], arr[k] = arr[k], arr[left]
        m1, m2 = partition3(arr, left, right)
        if m1 - left > right - m2:
            quick_sort_3(arr, m2 + 1, right)
            right = m1 - 1
        else:
            quick_sort_3(arr, left, m1 - 1)
            left = m2 + 1
    return


if __name__ == '__main__':
    n = int(input())                                        # no. of elements
    arr = list(map(int, input().split()))                   # elements to be sorted
    quick_sort_3(arr, 0, n - 1)
    for x in arr:
        print(x, end=' ')
