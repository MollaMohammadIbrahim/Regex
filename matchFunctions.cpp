#include <iostream>
#include <regex>

int main() {
    std::string text = "abc123def456ghi";
    std::regex pattern("\\d+");

    std::smatch matches;

    if (std::regex_search(text, matches, pattern)) {
        std::cout << "Full match: " << matches[0] << std::endl;
        std::cout << "Start position: " << matches.position(0) << std::endl;
        std::cout << "Length: " << matches.length(0) << std::endl;
        std::cout << "Prefix: " << matches.prefix() << std::endl;
        std::cout << "Suffix: " << matches.suffix() << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}
