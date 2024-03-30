#include <bits/stdc++.h>
using namespace std;
int main()
{
    double m = 1;
    double g = 9.81;
    double v_poczatkowe = 0;
    double delta_v_cel = 0.0001;

    vector<double> c_values = {0.1, 0.5, 1.0};
    vector<double> delta_t_values = {0.1, 0.01, 0.001};

    for (double c : c_values)
    {
        for (double delta_t : delta_t_values)
        {
            double s = 0;
            double v = v_poczatkowe;
            double delta_v = 0;
            int n = 0;

            while (true)
            {
                double a = g - (c * v);
                double v_nowe = v + a * delta_t;
                delta_v = v_nowe - v;
                n++;

                if (delta_v <= delta_v_cel)
                {
                    break;
                }
                v = v_nowe;
                s += v * delta_t;
            }

            double v_graniczna = (m * g) / c;
            double s_graniczna = s + v_graniczna * delta_t;

            cout << "V graniczna w while dla c=" << c << " i delta_t=" << delta_t << ": " << v << " m/s" << endl;
            cout << "V graniczna z wzoru dla c=" << c << " i delta_t=" << delta_t << ": " << v_graniczna << " m/s" << endl;
            cout << "T dla V granicznej c=" << c << " i delta_t=" << delta_t << ": " << delta_t * n << " s" << endl;
            cout << "S przebyte przed V graniczna dla c=" << c << " i delta_t=" << delta_t << ": " << s_graniczna << " m" << std::endl;
            cout << "------------------------" << endl;
        }
    }

    return 0;
}
