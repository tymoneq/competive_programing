#include <bits/stdc++.h>

using namespace std;

ifstream a_in, b_in, c_in;
ofstream wynik;
double min_ob = 0, max_pol = 0;
double min_obw(double obw)
{

    if (obw > min_ob)
    {
        min_ob = obw;
    }
    return min_ob;
}

double max_her(double her)
{

    if (her > max_pol)
    {
        max_pol = her;
    }
    return max_pol;
}

int main()
{
    a_in.open("a.txt");
    b_in.open("b.txt");
    c_in.open("c.txt");
    wynik.open("zadanie3.txt");
    int a, b, c, d, e, f;
    double result_obw = 0, result_her = 0;

    while ((a_in >> a >> b) && (b_in >> c >> d) && (c_in >> e >> f))
    {
        double dl_a, dl_b, dl_c, obw, heron, p;
        dl_a = sqrt(pow((a - c), 2) + pow((b - d), 2));
        dl_b = sqrt(pow((a - e), 2) + pow((b - f), 2));
        dl_c = sqrt(pow((e - c), 2) + pow((f - d), 2));

        obw = dl_c + dl_b + dl_a;
        p = obw / 2;
        heron = sqrt(p * (p - dl_a) * (p - dl_b) * (p - dl_c));
        result_obw = min_obw(obw);
        result_her = max_her(heron);
    }

    wynik << " Najmniejszy obwód : " << result_obw << "\n Największe pole : " << result_her;
    a_in.close();
    b_in.close();
    c_in.close();
    wynik.close();
    return 0;
}
