#include <bits/stdc++.h>

using namespace std;

const int WIDTH = 1000;
int barn[WIDTH + 1][WIDTH + 1];
int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int rect_num, paint_req;
    cin >> rect_num >> paint_req;

    for (int i = 0; i < rect_num; i++)
    {
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;
        // Set up the prefix sums array with all the corners of the given rectangle
        barn[start_x][start_y]++;
        barn[start_x][end_y]--;
        barn[end_x][start_y]--;
        barn[end_x][end_y]++;
    }

    int valid_area = 0;
    // Run 2D prefix sums on the array
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            if (x > 0)
                barn[x][y] += barn[x - 1][y];
            if (y > 0)
                barn[x][y] += barn[x][y - 1];
            if (x > 0 && y > 0)
                barn[x][y] -= barn[x - 1][y - 1];
            valid_area += barn[x][y] == paint_req;
        }
    }
    cout << valid_area << endl;
}