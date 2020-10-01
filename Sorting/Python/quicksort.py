import random

def partition(a, left, right):
    x = a[left]
    j = left
    for i in range(left + 1, right + 1):
        if a[i] <= x:
            j += 1
            a[i], a[j] = a[j], a[i]
    a[left], a[j] = a[j], a[left]
    return j


def randomized_quick_sort(a, left, right):
    if left >= right:
        return
    k = random.randint(left, right)
    a[left], a[k] = a[k], a[left]
    middle = partition(a, left, right)
    randomized_quick_sort(a, left, middle - 1)
    randomized_quick_sort(a, middle + 1, right)

if __name__ == '__main__':
    n = int(input())                            # no. of elements in the array
    a = list(map(int, input().split()))         # elements to be sorted
    randomized_quick_sort(a, 0, n - 1)
    for x in a:
        print(x, end=' ')
