#include <iostream>
#include <any.h>
#include <vector>
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> bad_type;
    any val1(8.5);
    any val2(val1);
    any val3 = 2.5f;
    std::cout <<val3.get<float>() << std::endl;
    any val4 = std::string("hello world");
    std::string test("test");
    std::cout << val4.get<std::string>() << std::endl;
    std::cout << val4.type().name() << std::endl;
    any val5;
    std::cout << val5.size() << std::endl;
    std::cout << std::boolalpha << val4.has_value() << std::endl;
    any val6 = std::move(val4);
    std::cout << val6.get<std::string>() << std::endl;
    std::cout << std::boolalpha << val4.has_value() << std::endl;


    return 0;
}