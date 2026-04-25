
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // Read the first line which contains initialization parameters
    long long init_a, init_b, init_c;
    std::cin >> init_a >> init_b >> init_c;
    
    // We'll maintain 25 sets as indicated in the reference implementation
    std::vector<std::set<long long>> sets(25);
    std::set<long long>::iterator current_it;
    int current_set_idx = -1;
    bool valid_iterator = false;
    int lst = 0;
    
    int op;
    while (std::cin >> op) {
        long long a, b, c;
        switch (op) {
            case 0: {
                std::cin >> a >> b;
                auto result = sets[a].insert(b);
                if (result.second) {  // Element was inserted (not already present)
                    current_set_idx = a;
                    current_it = result.first;
                    valid_iterator = true;
                }
                break;
            }
            case 1: {
                std::cin >> a >> b;
                // Invalidate iterator if it points to the element being deleted
                if (valid_iterator && current_set_idx == a) {
                    if (current_it != sets[a].end() && *current_it == b) {
                        valid_iterator = false;
                    }
                }
                sets[a].erase(b);
                break;
            }
            case 2: {
                std::cin >> a;
                lst++;
                sets[lst] = sets[a];  // Copy set a to set lst
                break;
            }
            case 3: {
                std::cin >> a >> b;
                auto it = sets[a].find(b);
                if (it != sets[a].end()) {
                    std::cout << "true\n";
                    current_set_idx = a;
                    current_it = it;
                    valid_iterator = true;
                } else {
                    std::cout << "false\n";
                }
                break;
            }
            case 4: {
                std::cin >> a >> b >> c;
                // Count elements in range [b, c]
                auto start = sets[a].lower_bound(b);
                auto end = sets[a].upper_bound(c);
                std::cout << std::distance(start, end) << "\n";
                break;
            }
            case 5: {
                // Predecessor of current iterator
                if (valid_iterator) {
                    auto prev_it = current_it;
                    if (current_it == --prev_it) {
                        valid_iterator = false;
                        std::cout << "-1\n";
                    } else {
                        std::cout << *prev_it << "\n";
                    }
                } else {
                    std::cout << "-1\n";
                }
                break;
            }
            case 6: {
                // Successor of current iterator
                if (valid_iterator) {
                    auto next_it = current_it;
                    ++next_it;
                    if (current_it == ++next_it) {
                        valid_iterator = false;
                        std::cout << "-1\n";
                    } else {
                        std::cout << *current_it << "\n";
                    }
                } else {
                    std::cout << "-1\n";
                }
                break;
            }
        }
    }
    
    return 0;
}
