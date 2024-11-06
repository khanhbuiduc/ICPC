#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<int> myUnorderedSet;

    // Inserting elements
    myUnorderedSet.insert(10);
    myUnorderedSet.insert(20);
    myUnorderedSet.insert(30);
    myUnorderedSet.insert(20); // Duplicate, will not be inserted

    // Displaying elements
    std::cout << "Elements in unordered set: ";
    for (const auto &element : myUnorderedSet)
    {
        std::cout << element << " "; // Output will vary in order
    }
    std::cout << std::endl;

    // Finding an element
    auto it = myUnorderedSet.find(20);
    if (it != myUnorderedSet.end())
    {
        std::cout << "Element found: " << *it << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    // Removing an element
    myUnorderedSet.erase(20);
    std::cout << "Elements in unordered set after erasing 20: ";
    for (const auto &element : myUnorderedSet)
    {
        std::cout << element << " "; // Output will vary in order
    }
    std::cout << std::endl;

    // Size of the unordered set
    std::cout << "Size of unordered set: " << myUnorderedSet.size() << std::endl;

    return 0;
}
