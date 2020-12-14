arr = [-1, 2, 4, -3, 5, 2, -5, 2]

# O(n³)
best = 0
for i in range(len(arr)):
  for j in range(i, len(arr)):
    ss = 0
    for k in range(i, j+1):
      ss += arr[k]
    best = max(best, ss)
print(best)

# O(n²)
best = 0
for i in range(len(arr)):
  temp = 0
  for j in range(i, len(arr)):
    temp += arr[j]
    best = max(best, temp)
print(best)

# O(n)
best = 0
temp = 0
for i in range(len(arr)):
  temp = max(arr[i], arr[i]+temp)
  best = max(best, temp)
print(best)
