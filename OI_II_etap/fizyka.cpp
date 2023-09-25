#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
// initializacja danych
constexpr double M = 1, g = 9.81, prec = 1e-4;
double C[] = {0.1, 0.2, 0.5}, Deltat[] = {0.1, 0.01, 1e-4};
constexpr int X = 3;
inline double deltaV(double V, double C, double DeltaT) { return (g - (C / M * V)) * DeltaT; };

ofstream Rout, Vout, Sout; // Rout - results Vout - V Sout - S
int main()
{
    ios_base::sync_with_stdio(0);
    Rout.tie(0), Vout.tie(0), Sout.tie(0);
    Vout.open("V.txt"), Rout.open("R.txt"), Sout.open("S.txt");
    double Vn, Sn, Vtemp, Stemp;
    ull timer;
    for (int k = 0; k < X; k++)
    {
        for (int i = 0; i < X; i++)
        {
            Vtemp = 0, Sn = 0, Stemp = 0, timer = 1;
            Vn = Vtemp + deltaV(Vtemp, C[i], Deltat[k]);
            Sn = Stemp + (Vn * Deltat[k]);
            while (Vn - Vtemp >= prec)
            {
                timer++;
                Vout << Vtemp << "\n";
                Sout << Stemp << "\n";
                Vtemp = Vn;
                Stemp = Sn;
                Vn = Vtemp + deltaV(Vtemp, C[i], Deltat[k]);
                Sn = Stemp + (Vtemp * Deltat[k]);
            }
            Vout << Vtemp << "\n"
                 << Vn << "\n";
            Sout << Sn << "\n";
            Stemp = Sn;
            Sn = Stemp + (Vn * Deltat[k]);
            Sout << Sn << "\n";
            timer++;
            Vout << "!\n";
            Sout << "!\n";
            Rout << "For C = " << C[i] << " Delta T = " << Deltat[k] << " Time = " << timer * Deltat[k] << "\n";
        }
    }
    return 0;
}