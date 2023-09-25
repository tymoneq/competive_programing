import matplotlib.pyplot as plt

X = 3
FileS = open("S.txt", "r")
FileV = open("V.txt", "r")

V_split = []
S_split = []
for V in FileV:
    if V != "!\n":
        V_split.append(int(V))

for S in FileS:
    if S != "!\n":
        S_split.append(int(S))


plt.plot(S_split,V_split)
plt.xlabel("S")
plt.ylabel("V")
plt.grid(True)
plt.title("fizyka")
plt.show()
