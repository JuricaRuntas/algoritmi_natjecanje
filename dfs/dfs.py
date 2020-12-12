#!/usr/env/python3

def dfs(adj_mat, start, visited):
  visited[start] = True
  print(start, end=" ")
  for i in range(len(adj_mat)):
    if not visited[i] and adj_mat[start][i]:
      dfs(adj_mat, i, visited)

if __name__ == "__main__":
  v = int(input())
  e = int(input())

  adj_mat = [[0 for i in range(v)] for j in range(v)]
  visited = [False]*v

  adj_mat[0][1] = 1;
  adj_mat[0][2] = 1;
  adj_mat[0][3] = 1;
  adj_mat[1][0] = 1;
  adj_mat[1][2] = 1;
  adj_mat[2][0] = 1;
  adj_mat[2][1] = 1;
  adj_mat[2][4] = 1;
  adj_mat[3][0] = 1;
  adj_mat[4][2] = 1;
  
  dfs(adj_mat, 0, visited)
