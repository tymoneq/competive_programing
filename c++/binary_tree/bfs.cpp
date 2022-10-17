#include <bits/stdc++.h>

using namespace std;
struct tree
{

    tree *left;
    tree *right;
    char val;
};
int main()
{

    tree G = {NULL, NULL, 'G'};
    tree H = {NULL, NULL, 'H'};
    tree I = {NULL, NULL, 'I'};
    tree J = {NULL, NULL, 'J'};
    tree K = {NULL, NULL, 'K'};

    tree D = {&H, &I, 'D'};
    tree E = {&J, NULL, 'E'};
    tree F = {&K, NULL, 'F'};
    tree B = {&D, &E, 'B'};
    tree C = {&F, &G, 'C'};

    tree A = {&B, &C, 'A'};

    queue<tree> Q;
    Q.push(A);
    while (!Q.empty())
    {
        tree v = Q.front();
        Q.pop();
        cout << v.val << " ";
        if (v.left != NULL)
            Q.push(v.left);
        if (v.right != NULL)
            Q.push(v.right);
    }
    return 0;
}