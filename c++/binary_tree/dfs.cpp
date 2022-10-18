#include <bits/stdc++.h>

using namespace std;

struct tree
{

    tree *left;
    tree *right;
    char val;
};
void preorder(tree *v)
{
    if (v)
    {
        cout << v->val << " ";
        preorder(v->left);
        preorder(v->right);
    }
}
void inorder(tree *v)
{
    if (v)
    {
        inorder(v->left);
        cout << v->val << " ";
        inorder(v->right);
    }
}
void postorder(tree *v)
{
    if (v)
    {
        postorder(v->left);
        postorder(v->right);
        cout << v->val << " ";
    }
}
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
    preorder(&A);
    cout << "\n";
    inorder(&A);
    cout << "\n";
    postorder(&A);
    return 0;
}