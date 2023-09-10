n, k = map(int, input().split())
top = list(map(int, input().split()))
bottom = list(map(int, input().split()))

total_value = sum(top)  # początkowa wartość monet na górze stosów
diff = []  # różnica między wartościami monet na górze i dole stosów

for i in range(n):
    diff.append(top[i] - bottom[i])

# Wybieraj monety o największej różnicy i dodawaj ich wartość do sumy.
# Przejdź do kolejnego stosu i powtórz krok 2-3.
for i in range(n):
    if k == 0:
        break
    if diff[i] > 0:
        total_value += diff[i]
        k -= 1

print(total_value)
