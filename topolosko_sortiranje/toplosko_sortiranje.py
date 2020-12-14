#!/usr/env/python3

v = int(input())
visited = [False]*v
ans = []

def dfs(adj_list, start):
  visited[start] = True
  for i in range(len(adj[i])):
    if not visited[i]:
      dfs(adj_list, i)
  ans.append(v)

def topolosko_sortiranje(adj_list):
  visited = [False]*v
  ans = []
  for i in range(v):
    if not visited[i]:
      dfs(adj_list, i)
  print(reversed(ans))
