#!/usr/env/python3
from collections import deque

def bfs(adj_mat, start):
  visited = [False]*len(adj_mat)
  q = deque()
  q.appendleft(start)
  visited[start] = True
  while q:
    vertex = q.pop()
    print(vertex, end= " ")
    for i in range(len(adj_mat)):
      if (not visited[i] and adj_mat[vertex][i]):
        visited[i] = True
        q.appendleft(i)

if __name__ == "__main__":
  v = int(input())
  e = int(input())
  adj_mat = [[0 for i in range(v)] for j in range(v)]
  
  # primjer za v = 5
  adj_mat[0][1] = 1;
  adj_mat[0][4] = 1;
  adj_mat[1][0] = 1;
  adj_mat[1][2] = 1;
  adj_mat[1][3] = 1;
  adj_mat[1][4] = 1;
  adj_mat[2][1] = 1;
  adj_mat[2][3] = 1;
  adj_mat[3][1] = 1;
  adj_mat[3][2] = 1;
  adj_mat[3][4] = 1;
  adj_mat[4][0] = 1;
  adj_mat[4][1] = 1;
  adj_mat[4][3] = 1;
  
  bfs(adj_mat, 0)
