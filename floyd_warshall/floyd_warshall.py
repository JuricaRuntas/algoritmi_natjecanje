INF = 99999

def floyd_warshall(graph):
  dist = [[column for column in row]for row in graph] 
  for k in range(len(graph)):
    for i in range(len(graph)):
      for j in range(len(graph)):
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
  return dist

if __name__ == "__main__":
  graph = [[0, 5, INF, 10],
           [INF, 0, 3, INF],
           [INF, INF, 0, 1],
           [INF, INF, INF, 0]]
  ss = floyd_warshall(graph)
  for tt in ss:
    for kk in tt:
      if kk == INF: print("I", end=" ")
      else: print(kk, end=" ")
    print()
