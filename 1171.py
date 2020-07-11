N = int(input())
l = []
l2 = []

for i in range(N):
  num = int(input())
  l.append(num)
  if num not in l2: l2.append(num)

for i in sorted(l2):
  print(i, "aparece", l.count(i), "vez(es)")
