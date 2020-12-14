arr = [1, 3, 4]
memo = {}

def solve_recur(x):
  best = 9999999
  if x < 0: return 99999999
  if x == 0: return 0
  if(x in memo): return memo[x]
  for i in range(len(arr)):
    best = min(best, solve_recur(x-arr[i])+1)
  memo[x] = best
  return best

print(solve_recur(10))
