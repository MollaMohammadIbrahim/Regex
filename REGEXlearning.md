# What is regex?
A regular expression, often abbreviated as regex, is a powerful tool used in computing to define search patterns. It's a sequence of characters that forms a search pattern
# Important sites:
1. Online Regex Editor : [Regex101](https://regex101.com/)
2. C++ Regex Tutorial: [Tutorials Point](https://www.tutorialspoint.com/cpp_standard_library/regex.htm)

# C++ regex library
**Header File**  #include<regex>
## Regex instantiation:

n C++, you can instantiate a regular expression in different ways. Here are a few examples:

**Method** 1: Using the std::regex Constructor
```

int main() {
    std::string pattern = "\\d{3}-\\d{2}-\\d{4}"; // Regular expression pattern for a social security number
    std::regex regexObj(pattern);
}
```
**Method** 2: Using Raw String Literal

```

int main() {
    std::string pattern = R"(\d{3}-\d{2}-\d{4})"; // Regular expression pattern for a social security number

    std::regex regexObj(pattern);

    return 0;
}
```
**Method** 3: Using a Basic String Literal

```
int main() {
    std::string pattern = "\\d{3}-\\d{2}-\\d{4}"; // Regular expression pattern for a social security number

    std::basic_regex<char> regexObj(pattern);

    return 0;
}
```
**Method 4:** Using a std::regex with Flags
```
int main() {
    std::string pattern = "\\d{3}-\\d{2}-\\d{4}"; // Regular expression pattern for a social security number

    std::regex regexObj(pattern, std::regex::ECMAScript | std::regex::icase);

    return 0;
}
```
**Method** 5: Using Template Arguments

```
int main() {
    std::basic_regex<char> regexObj("\\d{3}-\\d{2}-\\d{4}", std::regex::ECMAScript | std::regex::icase)
```
## Regex Operations
1. ### regex_match 
**Return type:** Bool
**Parameters:** it can take parameters on various ways:
1. regex_match(string, regex);
2. regex_match(string.begin(),string.end(), regex);
3.  smatch matcher -> regex_match(string, matcher, regex);
4.  **Using iterator:** 

2. ### regex_search
**Return Value**
- `true` if the regular expression pattern is found in the input sequence, `false` otherwise.
**Functionality**
- `std::regex_search` searches for the first occurrence of the regular expression pattern in the specified range defined by `[first, last)`.
- It can find partial matches within the range.
- It populates the `std::match_results` object with information about the matches found.
### regex_replace

**Introduction**
The `std::regex_replace` function in C++ is used for replacing occurrences of a regular expression pattern within a string with a specified replacement. It's a powerful tool for text manipulation and transformation.

**Return** Value
An output iterator pointing to the end of the modified content.

**Functionality**
- `std::regex_replace` searches for all occurrences of the regular expression pattern within the range `[first, last)` and replaces them with the specified format string.
- The modified content is written to the output iterator specified by `out`.

**Example** Usage
```
std::string text = "The quick brown fox jumps over the lazy dog";
std::regex pattern("fox");

std::string result = std::regex_replace(text, pattern, "cat");
```
## Regex match_instansiation
1. cmatch
2. wcmatch
3. smatch
4. wsmatch

## Regex Meta Characters

\\ or R is used in c++ instead of \

1. \d  =  any digit
2. \D =  any non digit character
3. .   = any char excep white space
4. \\.  = period
5. [abc]  = any from abbc
5. ^a  = except a
6. \w  = a-z, A-Z, 0-9, _ ( any alpha numeric character)
7. \w = any non alpha numeric character
8. {m,n} =  m to n repitation
9. {m} = m repetition
10.     * = zero or more repetitions
11.     + = one or more repetitions
12. \? = optional (one or zero repetitions)
13. \s = whitespace or tab
14. \t = tab
15. \S = non white space
16. ^ or \\b = starts of group
17. $ or \\b = ends of group
18. () = capture group
19. (a(bc)) = capture sub group
20. (.*) = capture all
21. (ab|bc)= match ab or cd
22. \ = escape character
23. []= character set

## Regex Falg
1. regex::global = g = matching everywhere
2. multiline = m = 
3. insensitive = i = case insensitive
4. extend  = x = ignore white space
5. unicode = u= match with full unicode

## smatch Details
### Functions associated with this:

In C++, the std::smatch class provides various member functions to access information about matched substrings. Some of the commonly used member functions include:

operator[]: Allows you to access matched substrings by index. For example, matches[0] accesses the entire matched substring.

1. str(): Returns the matched substring as a std::string.

2. prefix(): Returns the prefix (text before the match) as a std::string.

3. suffix(): Returns the suffix (text after the match) as a std::string.

4. position(): Returns the starting position of a matched substring.

5. length(): Returns the length of a matched substring.

6. begin() and end(): Provide iterators to the beginning and end of the matched substring sequence.

7. empty(): Checks if the match is empty.

8. size(()): Returns the total number of matches.

code examle:
```

int main() {
    std::string text = "abc123def456ghi";
    std::regex pattern("\\d+");

    std::smatch matches;

    if (std::regex_search(text, matches, pattern)) {
        // Using operator[]
        std::cout << "Full match: " << matches[0] << std::endl;

        // Using str()
        std::cout << "Match as string: " << matches.str() << std::endl;

        // Using prefix()
        std::cout << "Prefix: " << matches.prefix() << std::endl;

        // Using suffix()
        std::cout << "Suffix: " << matches.suffix() << std::endl;

        // Using position()
        std::cout << "Start position: " << matches.position(0) << std::endl;

        // Using length()
        std::cout << "Length: " << matches.length(0) << std::endl;

        // Using begin() and end()
        auto it = matches.begin();
        for (; it != matches.end(); ++it) {
            std::cout << "Match: " << *it << std::endl;
        }

        // Using empty()
        std::cout << "Is match empty? " << (matches.empty() ? "Yes" : "No") << std::endl;

        // Using size()
        std::cout << "Total matches found: " << matches.size() << std::endl;
    } else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}


```
Output:
```
Full match: 123
Match as string: 123
Prefix: abc
Suffix: def456ghi
Start position: 3
Length: 3
Match: 123
Is match empty? No
Total matches found: 1


```
## Limitng the lenght of string
```
^(?=.{1,10}$)[\w.]+@gmail\.[\w.]+$
```
**Explanation:**
```
1. ^: Asserts the start of the string.
2. (?=.{1,10}$): Positive lookahead assertion. Checks that the entire string is between 1 and 10 characters in length.
3. [\w.]+: Matches one or more word characters or dots (for the username part).
4. @gmail\.: Matches the literal string "@gmail.".
5. [\w.]+: Matches one or more word characters or dots (for the domain part).
6. $: Asserts the end of the string.
```
