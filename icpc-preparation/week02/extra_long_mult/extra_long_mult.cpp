#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class LongArithmetic
{
public:
    // Function to add two long integers represented as strings
    static std::string add(const std::string &a, const std::string &b)
    {
        std::string result;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        std::reverse(result.begin(), result.end());
        return result;
    }

    // Function to subtract two long integers represented as strings
    static std::string subtract(const std::string &a, const std::string &b)
    {
        if (a < b)
        {
            throw std::invalid_argument("Result is negative");
        }

        std::string result;
        int borrow = 0;
        int i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0)
        {
            int sub = (a[i] - '0') - borrow;
            if (j >= 0)
                sub -= (b[j--] - '0');
            if (sub < 0)
            {
                sub += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            result.push_back(sub + '0');
            i--;
        }

        std::reverse(result.begin(), result.end());
        return result.erase(0, result.find_first_not_of('0')); // Remove leading zeros
    }

    // Function to multiply two long integers represented as strings
    static std::string multiply(const std::string &a, const std::string &b)
    {
        if (a == "0" || b == "0")
            return "0";

        std::vector<int> result(a.size() + b.size(), 0);
        for (int i = a.size() - 1; i >= 0; --i)
        {
            for (int j = b.size() - 1; j >= 0; --j)
            {
                int mul = (a[i] - '0') * (b[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        std::string resultStr;
        for (int num : result)
        {
            if (!(resultStr.empty() && num == 0))
            { // Avoid leading zeros
                resultStr.push_back(num + '0');
            }
        }
        return resultStr.empty() ? "0" : resultStr;
    }

    // Function to divide two long integers represented as strings
    // static std::string divide(const std::string &a, const std::string &b)
    // {
    //     if (b == "0")
    //         throw std::invalid_argument("Division by zero");
    //     if (a < b)
    //         return "0";

    //     std::string result;
    //     std::string current;
    //     for (char digit : a)
    //     {
    //         current += digit;
    //         int count = 0;
    //         while (current >= b)
    //         {
    //             current = subtract(current, b);
    //             count++;
    //         }
    //         result += std::to_string(count);
    //     }

    //     return result.erase(0, result.find_first_not_of('0')); // Remove leading zeros
    // }
};

int main()
{
    std::string num1, num2;

    // Example usage
    num1 = "123456789123456789123456789";
    num2 = "987654321987654321987654321";

    std::cout << "Addition: " << LongArithmetic::add(num1, num2) << std::endl;
    std::cout << "Subtraction: " << LongArithmetic::subtract(num2, num1) << std::endl;
    std::cout << "Multiplication: " << LongArithmetic::multiply(num1, num2) << std::endl;
    // std::cout << "Division: " << LongArithmetic::divide(num2, num1) << std::endl;

    return 0;
}
