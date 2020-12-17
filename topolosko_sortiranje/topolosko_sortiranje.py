#!/usr/env/python3

g = [[0, 0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0, 0],
     [0, 0, 0, 1, 0, 0],
     [0, 1, 0, 0, 0, 0],
     [1, 1, 0, 0, 0, 0],
     [1, 0, 1, 0, 0, 0]]

visited = [False]*len(g)
ans = []

def dfs(g, v):
  visited[v] = True
  for i in range(len(g)):
    if not visited[i] and g[v][i]:
      dfs(g, i)
  ans.append(v)

def topolosko_sortiranje():
  for i in range(len(g)):
    if not visited[i]:
      dfs(g, i)
  return list(reversed(ans))

print(topolosko_sortiranje())
