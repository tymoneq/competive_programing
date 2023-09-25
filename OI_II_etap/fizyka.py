import matplotlib.pyplot as plt

FileS = open("S.txt", "r")
FileV = open("V.txt", "r")
point1 = 0
point2 = 0

V = []
S = []
for line in FileV:
    V.append(line)

for line in FileS:
    S.append(line)
for i in range(9):
    V_split = []
    S_split = []
    while point1 >= 0:
        if V[point1] != "!\n":
            V_split.append(float(V[point1]))
            point1 += 1
        else:
            point1 += 1
            break

    while point2 >= 0:
        if S[point2] != "!\n":
            S_split.append(float(S[point2]))
            point2 += 1
        else:
            point2 += 1
            break

    plt.plot(S_split, V_split)
    plt.xlabel("S")
    plt.ylabel("V")
    name = 'wykres' + str(i) +'.png'
    plt.savefig(name)
    plt.title("V graniczne")
    plt.show()
