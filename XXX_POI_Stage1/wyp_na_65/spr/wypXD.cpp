 if (must_check)
    {
        // gdy V_1> V_2
        // sprawdzaj dystans między nimi i jakie musiałoby być V żeby się dogoniły i gdzie występuje to V
        for (int i = 1; i < index; i++)
        {
            if (Distance_b_tracks[i] == 1)
                continue;
            if (i == index - 1)
            {
                double time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
                double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
                double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
                if (kon_drugiej - pocz_pierwszej >= D)
                    wyprzedone += 1;
                continue;
            }
            double time = (poz[i].poz_start + D) / (V_auto - poz[i].v);
            double pocz_pierwszej = poz[i].poz_start + poz[i].v * time;
            double kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * time;
            if (pocz_pierwszej + D <= poz[i + 1].poz_start - poz[i + 1].dl)
                wyprzedone += 1;

            else if (kon_drugiej - pocz_pierwszej >= D)
            {
                float distans = 0;
                if (kon_drugiej + poz[i + 1].dl <= poz[i + 2].poz_start - poz[i + 2].dl)
                {
                    wyprzedone += 1;
                    continue;
                }
                bool wyprz = true;
                for (int j = i + 2; j <= index; j++)
                {
                    if (poz[j].v >= poz[i + 1].v)
                        distans += poz[j].dl;
                    else
                    {
                        if (poz[j].poz_start - poz[j].dl - distans > poz[i + 1].v * time + poz[i + 1].poz_start)
                        {
                            wyprzedone += 1;
                            wyprz = false;
                            break;
                        }
                        else
                        {
                            double timer = (poz[j].poz_start - poz[j].dl - distans - poz[i + 1].poz_start) / (poz[i + 1].v - poz[j].v);
                            if (timer < time)
                            {
                                kon_drugiej = poz[i + 1].poz_start - poz[i + 1].dl + poz[i + 1].v * timer + poz[j].v * (time - timer);
                                distans += poz[j].dl;
                                if (kon_drugiej - pocz_pierwszej < D)
                                {
                                    wyprz = false;
                                    break;
                                }
                                else if (kon_drugiej - pocz_pierwszej >= D && j == index)
                                {
                                    wyprzedone += 1;
                                    wyprz = false;
                                }
                            }
                        }
                    }
                }
                if (wyprz)
                    wyprzedone += 1;
            }
        }
    }