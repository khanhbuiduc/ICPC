while (q > 0)
    {
        int u, v;
        cin >> u >> v;
        if (s.find({u, v}) != s.end())
        {
            s.erase({u, v});
            s.insert({v, u});
            count1.erase(v);
            count1.insert(u);
        }
        else if (s.find({v, u}) != s.end())
        {
            s.erase({v, u});
            s.insert({u, v});
            count1.erase(u);
            count1.insert(v);
        }
        else
        {
            s.insert({u, v});
            count1.insert(v);
        }
        if (count1.size() == n - 1)
            cout << "true\n";
        else
            cout << "false\n";
        q--;
    }