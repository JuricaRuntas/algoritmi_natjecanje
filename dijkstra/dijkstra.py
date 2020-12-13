#!/usr/env/python3
from math import inf
import heapq

def dijkstra(adj_list, src):
  dist = [inf for i in range(len(adj_list))]
  dist[src] = 0
  q = [(0, src)]
  while len(pq) > 0:
    current_distance, current_vertex = heapq.heappop(pq)
    if current_distance > dist[current_vertex]: continue
    for neighbor, w in adj_list[current_vertex]:
      if current_distance+w < dist[neighbor]:
        dist[neighbor] = current_distance+w
        heapq.heappush(pq, (current_distance+w, neighbor))
  return dist
