
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::unordered_set<long long> eset;
    std::string command;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    
    while (std::cin >> command) {
        if (command == "insert") {
            long long value;
            std::cin >> value;
            eset.insert(value);
        } else if (command == "find") {
            long long value;
            std::cin >> value;
            if (eset.find(value) != eset.end()) {
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        } else if (command == "delete") {
            long long value;
            std::cin >> value;
            eset.erase(value);
        } else if (command == "clear") {
            eset.clear();
        } else if (command == "size") {
            std::cout << eset.size() << "\n";
        } else if (command == "empty") {
            std::cout << (eset.empty() ? "true" : "false") << "\n";
        } else if (command == "iterate") {
            // For speed test, we just iterate without outputting all elements
            // to avoid overwhelming output
            long long sum = 0;
            for (const auto& val : eset) {
                sum += val;
            }
            std::cout << sum << "\n";
        }
    }
    
    return 0;
}
