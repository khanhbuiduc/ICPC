#include <bits/stdc++.h>
using namespace std;

// Define constants
#define NAME "covr_2."
#define INF INT32_MAX
ifstream fi(string(NAME) + "inp");
ofstream fo(string(NAME) + "out");

typedef tuple<int, int, int, int> tiibi;
typedef pair<int, bool> pib;
int main()
{
    int n, a, b, c, t, m;
    int i0 = 0, free_p, ans = 0, count = 0;
    fi >> n;
    vector<tiibi> x;
    vector<pib> y;
    vector<bool> flg(n, false);
    vector<int> res;
    vector<int> vt;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        fi >> a >> b >> t;
        if (t == 0)
        {
            y.emplace_back(a, false);
            y.emplace_back(b, true);
        }
        else
        {
            x.emplace_back(make_tuple(a, 0, 1, i));
            x.emplace_back(make_tuple(b, 1, 1, i));
        }
    }

    cout << "Step 2: Process special banned points if they exist\n";
    if (!y.empty())
    {
        sort(y.begin(), y.end());

        int u = INF, v = -1;
        for (auto &t0 : y)
        {
            a = t0.first;
            c = t0.second;
            cout << "t0={" << a << "," << c << "}\n";
            cout << "uv={" << u << "," << v << "}\n";
            if (!c)
            { // If this is a start point
                count++;
                if (count == 1)
                { // First active banned segment
                    if (i0 == 0)
                    { // Initialize the first banned segment
                        u = a;
                        i0 = 1;
                        v = a; // Update v
                        continue;
                    }
                    if (v + 1 == a) // Check for consecutive points
                    {
                        cout << "consecution\n";
                        v = a; // Update v
                        continue;
                    }
                    cout << "add to x\n";
                    // Add a new banned segment between u and v
                    x.emplace_back(make_tuple(u, 0, 0, n + 1)); // Start point of new banned segment
                    x.emplace_back(make_tuple(v, 2, 0, n + 1)); // End point of new banned segment
                    u = a;                                      // Update the current start
                    v = a;                                      // Update v
                    continue;
                }
            }
            else
            { // If this is an end point
                count--;
                if (count == 0)
                {          // Last active banned segment
                    v = a; // Update v
                }
            }
        }

        // After processing all special banned points, if there's an open segment, add it to x
        if (i0 == 1 && u != INF && v != -1 && u != v)
        {
            x.emplace_back(make_tuple(u, 0, 0, n + 1)); // Start point of new banned segment
            x.emplace_back(make_tuple(v, 2, 0, n + 1)); // End point of new banned segment
        }
    }

    // Step 3: Sort x vector before processing
    sort(x.begin(), x.end(), [&](const tiibi &a, const tiibi &b) -> bool
         {
            if (get<0>(a) == get<0>(b))
            {
                // Define priority: start (0) < end (1) < new end (2)
                return get<1>(a) < get<1>(b);
            }
            return get<0>(a) < get<0>(b); });

    // Reset counters for processing
    count = 0;
    for (auto &z : x)
    {
        tie(a, c, t, m) = z; // Unpack tuple values (coordinate, point_type, segment_type, segment_index)
        cout << "a,c,t,m={" << a << "," << c << "," << t << "," << m << "}\n";
        if (c == 0)
        { // If this is a start point
            if (t == 0)
            { // Regular segment start
                count = 1;
                free_p = a - 1; // Set free point to the previous coordinate
                cout << "free_p=" << free_p << "\n";
                continue;
            }
            if (t == 1 && count == 0)
            {               // Banned segment start when no regular segment is active
                free_p = a; // Update free point
                cout << "free_p=" << free_p << "\n";
                vt.emplace_back(m); // Track active banned segment
                continue;
            }
            if (t == 1 && count == 1 && !flg[m])
            {              // Active banned segment that hasn't been covered
                mp[m] = a; // Record the position of the banned segment
                cout << "free_p=" << free_p << "\n";
                continue;
            }
        }
        else
        { // If this is an end point
            if (c == 2)
            {                   // End of a new regular segment
                count = 0;      // Reset active regular segment count
                free_p = a + 1; // Update free point
                cout << "free_p=" << free_p << "\n";
                continue;
            }
            if (count == 1 && !flg[m])
            { // Handle overlap with banned segments
                if (free_p < mp[m])
                {              // If free point doesn't overlap with banned segment
                    fo << '0'; // No valid covering possible
                    return 0;
                }
            }
            if (count == 0 && !flg[m])
            { // If the regular segment hasn't been covered
                free_p = a;
                cout << "free_p res=" << free_p << "\n";
                flg[m] = true;            // Mark the segment as covered
                res.emplace_back(free_p); // Add the free point to the result
            }
            if (!flg[m])
            {                             // If the segment is still uncovered
                res.emplace_back(free_p); // Add the free point to the result
                cout << "free_p res=" << free_p << "\n";
                vt.emplace_back(m); // Track the active banned segment
            }
            // Mark all active banned segments as covered
            for (auto &iv : vt)
                flg[iv] = true;
            vt.clear(); // Clear active segments
        }
    }
    fo << res.size() << "\n";
    // Step 4: Output the result
    if (res.empty())
    {
        fo << '0'; // If no points are selected, output 0
    }
    else
    {
        for (int i : res)
        {
            fo << i << ' '; // Output all the selected covering points
        }
    }

    return 0;
}
