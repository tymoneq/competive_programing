#include "zag.h"

void rozpocznij(int k)
{
    int i = 2, h = 0, c = 2;
    int v = 1;
    while (!otworz(i))
    {
        if (h == c)
            i++, h = 0, c += v;
        if (c == k / 2)
            v = -1;
    }
}
