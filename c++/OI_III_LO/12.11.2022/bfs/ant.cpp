#include <bits/stdc++.h>

using namespace std;

struct book
{
    string title;
    int dl;
    int pages;
    int sold;
};
bool sortowanie(book lhs, book rhs)
{
    if (lhs.sold > rhs.sold)
        return true;
    else if (lhs.sold == rhs.sold)
    {
        if (lhs.pages < rhs.pages)
            return true;
        else if (lhs.pages == rhs.pages)
        {
            if (lhs.dl < rhs.dl)
                return true;
        }
    }
    return false;
}
int main()
{

    int n;
    scanf("%d", &n);
    vector<book> Books;

    for (int i = 0; i < n; i++)
    {
        string word;
        int st = 0, sprz = 0;
        string s;
        getline(cin, s);
        getline(cin, word);
        scanf("%d", &st);
        scanf("%d", &sprz);
        book bok;
        int spac = 0;
        for (int j = 0; j < word.size(); j++)
        {
            if (word[j] == ' ')
                spac += 1;
        }
        int x = word.size();
        bok.title = word;
        bok.pages = st;
        bok.sold = sprz;
        bok.dl = word.size() - spac;
        Books.push_back(bok);
    }
    sort(Books.begin(), Books.end(), sortowanie);
    for (auto el : Books)
    {

        printf("%d ", el.sold);
        printf("%s ", el.title.c_str());
        printf("%d \n", el.pages);
    }
    return 0;
}