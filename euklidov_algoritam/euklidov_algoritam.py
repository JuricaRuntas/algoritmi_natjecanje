#!/usr/env/python3

def gcd(a, b):
  while not b == 0:
    a, b = b, a%b
  return a

if __name__ == "__main__":
  a = int(input())
  b = int(input())
  print(gcd(a,b))
