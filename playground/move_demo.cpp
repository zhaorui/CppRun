#include <iostream>
#include <utility>
#include <vector>
#include <string>

void move_demo() {
    std::string str = "Hello";
    std::vector<std::string> v;

    // 使用 push_back(const T&) 重载，
    // 表示我们将带来复制 str 的成本
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";

    
}