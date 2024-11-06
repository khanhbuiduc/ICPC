#include <bits/stdc++.h>
int main()
{
    std::vector<int> vec;

    // Add elements to the vector
    for (int i = 1; i <= 5; i++)
    {
        vec.push_back(i);
    }
    // delete element by value
    int valueToRemove = 3;
    vec.erase(std::remove(vec.begin(), vec.end(), valueToRemove), vec.end());
    // 2. Removing Elements by Position
    vec.erase(vec.begin() + 2);
    // Remove all even numbers
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x)
                             { return x % 2 == 0; }),
              vec.end());

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    return 0;
}