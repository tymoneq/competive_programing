a_range = int(input())  # ilość graczy
suma_l = []

for i in range(a_range):
    lista_kart = []
    karty = input()
    dl = len(karty)
    for j in range(1, dl):
        lista_kart.append(karty[-j])
    lista_kart.append(karty[0])
    suma = 0
    for a in lista_kart:
        if suma > 21:
            continue
        try:
            int_a = int(a)
            suma += int_a

        except:
            if a == 'T' or a == 'J' or a == 'Q' or a =='K':
                suma += 10

            if a == 'A':
                if suma + 10 <= 21:
                    suma += 11

                elif suma + 10 > 21:
                    suma += 1


    suma_l.append(suma)


max = 0
for elemt in suma_l:
    if elemt > max:
        max = elemt

wynik = 0
for elemt_a in suma_l:
    if elemt_a == max:
        wynik+=1





print(wynik)

