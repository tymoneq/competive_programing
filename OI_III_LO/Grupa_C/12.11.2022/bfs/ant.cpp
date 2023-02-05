#include <bits/stdc++.h>

using namespace std;

struct book
{
    string title;
    string title_to_compare;
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
            int rhs_dl = rhs.title_to_compare.size();
            int lhs_dl = lhs.title_to_compare.size();
            if (lhs_dl <= rhs_dl)
                for (int i = 0; i < lhs_dl; i++)
                {
                    if (i == lhs_dl - 1)
                    {
                        for (int j = i + 1; j < rhs_dl; j++)
                        {
                            if (lhs.title_to_compare[i] < rhs.title_to_compare[j])
                                return true;
                        }
                    }
                    else if (lhs.title_to_compare[i] < rhs.title_to_compare[i])
                        return true;
                }
            else
            {
                for (int i = 0; i < rhs_dl; i++)
                {
                    if (i == rhs_dl - 1)
                    {
                        for (int j = i + 1; j < lhs_dl; j++)
                        {
                            if (lhs.title_to_compare[j] < rhs.title_to_compare[i])
                                return true;
                        }
                    }
                    else if (lhs.title_to_compare[i] < rhs.title_to_compare[i])
                        return true;
                }
            }
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
        string word, word_without_space = "";
        int st = 0, sprz = 0;
        string s;
        getline(cin, s);
        getline(cin, word);
        scanf("%d", &st);
        scanf("%d", &sprz);
        book bok;
        word_without_space = word;
        transform(word_without_space.begin(), word_without_space.end(), word_without_space.begin(), ::tolower);
        bok.title = word;
        bok.pages = st;
        bok.sold = sprz;
        bok.title_to_compare = word_without_space;
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