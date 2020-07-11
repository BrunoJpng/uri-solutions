while True:
  n = int(input())
  if(n == 0): break

  cartas = [i for i in range(1,n+1)]
  descart = []

  while(len(cartas) > 1):
    descart.append(cartas.pop(0))
    cartas.append(cartas.pop(0))

  print("Discarded cards: ", end="")
  for i in range(len(descart) - 1):
    print(str(descart[i])+", ", end="")
  print(descart[-1])
  print("Remaining card:", cartas[0])
