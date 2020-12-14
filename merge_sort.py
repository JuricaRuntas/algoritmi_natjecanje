arr = [3,123123,4,12,0,4]

def merge_sort(arr):
  if len(arr) <= 1: return arr
  else:
    l = arr[:len(arr)//2]
    r = arr[len(arr)//2:]
    
    merge_sort(l)
    merge_sort(r)

    i = j = k = 0
    while i < len(l) and j < len(r):
      if l[i] < r[j]:
        arr[k] = l[i]
        i += 1
      elif l[i] >= r[j]:
        arr[k] = r[j]
        j += 1
      k += 1
    while i < len(l):
      arr[k] = l[i]
      i += 1
      k += 1
    while j < len(r):
      arr[k] = r[j]
      j += 1
      k += 1
  return arr

print(merge_sort(arr))
