arr = [3, 12, 35, 67, 0, 1]

def partition(arr, start, end):
  pivot = arr[end]
  i = start - 1
  for u in range(start, end):
    if arr[u] <= pivot:
     i += 1
     arr[u], arr[i] = arr[i], arr[u]
  arr[i+1], arr[end] = arr[end], arr[i+1]
  return i+1

def quick_sort(arr, start, end):
  if start < end:
    pivot = partition(arr, start, end)
    quick_sort(arr, start, pivot-1)
    quick_sort(arr, pivot+1, end)
  return arr
print(quick_sort(arr, 0, len(arr)-1))
