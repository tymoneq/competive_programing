#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e8;

struct Straight
{
    int x_start, x_end, y_start, y_end;
};

struct Segment
{
    Straight straight;
};

struct AnsComparator
{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const
    {
        if (lhs.first != rhs.first)
            return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    }
};

struct SegmentComparator
{
    bool operator()(const Segment &lhs, const Segment &rhs) const
    {
        if (lhs.straight.x_start != rhs.straight.x_start)
            return lhs.straight.x_start < rhs.straight.x_start;
        if (lhs.straight.x_end != rhs.straight.x_end)
            return lhs.straight.x_end < rhs.straight.x_end;
        if (lhs.straight.y_start != rhs.straight.y_start)
            return lhs.straight.y_start < rhs.straight.y_start;
        return lhs.straight.y_end < rhs.straight.y_end;
    }
};

struct Tower
{
    int x, y, d;
};

vector<Straight> constructStraights(int i, const vector<Tower> &towers)
{
    // getting cordinates
    int x1 = towers[i].x - towers[i].d;
    int x2 = towers[i].x + towers[i].d;
    int y1 = towers[i].y - towers[i].d;
    int y2 = towers[i].y + towers[i].d;

    // rotating 45 degrees
    int u1 = x1 + towers[i].y;
    int u2 = x2 + towers[i].y;
    int v1 = towers[i].x - y1;
    int v2 = towers[i].x - y2;

    vector<Straight> straights;

    straights.push_back({u1, u2, v1, v1});
    straights.push_back({u1, u2, v2, v2});
    straights.push_back({u1, u1, v1, v2});
    straights.push_back({u2, u2, v1, v2});

    return straights;
}

Straight sprawdzCzyNachodzaX(int y1, int y2, const Straight &odcinek, const Segment &potentialSegment)
{
    Straight newStraight = {-INF, -INF, -INF, -INF};
    if (y1 == y2 && odcinek.x_end >= potentialSegment.straight.x_start && odcinek.x_start <= potentialSegment.straight.x_end)
        newStraight = {max(odcinek.x_start, potentialSegment.straight.x_start), min(odcinek.x_end, potentialSegment.straight.x_end), y1, y1};

    return newStraight;
}

Straight sprawdzCzyNachodzaY(int x1, int x2, const Straight &odcinek, const Segment &potentialSegment)
{
    Straight newStraight = {-INF, -INF, -INF, -INF};
    if (x1 == x2 && odcinek.y_end <= potentialSegment.straight.y_start && odcinek.y_start >= potentialSegment.straight.y_end)
        newStraight = {x1, x1, min(odcinek.y_start, potentialSegment.straight.y_start), max(odcinek.y_end, potentialSegment.straight.y_end)};
    return newStraight;
}

Straight compare(const Straight &odcinek, const Segment &potentialSegment)
{
    Straight newStraight = {-INF, -INF, -INF, -INF};

    // dla poziomych odcinków

    if (odcinek.y_start == odcinek.y_end && potentialSegment.straight.y_start == potentialSegment.straight.y_end)
        newStraight = sprawdzCzyNachodzaX(odcinek.y_start, potentialSegment.straight.y_start, odcinek, potentialSegment);

    // dla pionowych
    if (odcinek.x_start == odcinek.x_end && potentialSegment.straight.x_start == potentialSegment.straight.x_end)
        newStraight = sprawdzCzyNachodzaY(odcinek.x_start, potentialSegment.straight.x_start, odcinek, potentialSegment);

    // dla przecinających się 

    if (odcinek.y_start == odcinek.y_end && potentialSegment.straight.x_start == potentialSegment.straight.x_end)
    {
        int u = potentialSegment.straight.x_start;
        int v = odcinek.y_start;

        if (odcinek.x_start <= u && u <= odcinek.x_end && potentialSegment.straight.y_start >= v && v >= potentialSegment.straight.y_end)
            newStraight = {u, u, v, v};
    }

    if (odcinek.x_start == odcinek.x_end && potentialSegment.straight.y_start == potentialSegment.straight.y_end)
    {
        int u = odcinek.x_start;
        int v = potentialSegment.straight.y_start;

        if (potentialSegment.straight.x_start <= u && u <= potentialSegment.straight.x_end && odcinek.y_start >= v && v >= odcinek.y_end)
            newStraight = {u, u, v, v};
    }

    return newStraight;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<Tower> towers(N);
    for (auto &el : towers)
        cin >> el.x >> el.y >> el.d;

    set<Segment, SegmentComparator> segments;

    // adding first segments

    auto straights = constructStraights(0, towers);

    for (auto &el : straights)
        segments.insert({el});

    for (int i = 1; i < N; i++)
    {
        vector<Segment> toErase;
        vector<Straight> toAdd;

        auto newStraights = constructStraights(i, towers);

        for (const auto &potentialSegment : segments)
        {
            Straight newStraight = {-INF, -INF, -INF, -INF};

            vector<Straight> newSegments;

            for (const auto &odcinek : newStraights)
            {
                newStraight = compare(odcinek, potentialSegment);
                if (newStraight.x_start != -INF)
                    newSegments.push_back(newStraight);
            }

            if (newSegments.size() > 0)
            {
                for (auto s : newSegments)
                    toAdd.push_back(s);
                toErase.push_back(potentialSegment);
            }
            else
                toErase.push_back(potentialSegment);
        }

        for (auto w : toErase)
            if (segments.count(w))
                segments.erase(w);

        for (auto w : toAdd)
            segments.insert({w});
    }
    vector<pair<int, int>> allPoints;

    for (auto el : segments)
    {
        if (el.straight.x_start == el.straight.x_end)
            for (int i = el.straight.y_end; i <= el.straight.y_start; i++)
                allPoints.push_back({el.straight.x_start, i});

        if (el.straight.y_start == el.straight.y_end)
            for (int i = el.straight.x_start; i <= el.straight.x_end; i++)
                allPoints.push_back({i, el.straight.y_end});
    }
    set<pair<int, int>, AnsComparator> Ans;

    for (auto el : allPoints)
    {
        if ((el.first + el.second) % 2 == 1 || (el.first - el.second) % 2 == 1)
            continue;

        int x1 = (el.first + el.second) / 2;
        int y1 = (el.first - el.second) / 2;

        Ans.insert({x1, y1});
    }

    for (auto el : Ans)
        cout << el.first << " " << el.second << "\n";

    return 0;
}