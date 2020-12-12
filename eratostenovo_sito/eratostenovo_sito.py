#!/usr/env/python3

def eratostenovo_sito(n):
  assert n > 1, "broj mora bit veci od 1"
  prime = [True for i in range(n+1)]
  prime[0] = prime[1] = False
  p = 2
  while (p**2 <= n):
    if prime[p] == True:
      # eliminiraj sve visekratnike trenutnog broja
      for i in range(p*2, n+1, p):
        prime[i] = False
    p += 1
  
  ret = [n for n in range(len(prime)) if prime[n] == True]
  return ret

if __name__ == "__main__":
  print(eratostenovo_sito(int(input())))
