#include <iostream>
#include <string>

using namespace std;
// aaaabbxxxxaaxa => abxaxa
// AaabbBBBCc => AabBCc

string remove_duplicates(string text) {
    char text2_char[text.size() + 1];
    text2_char[0] = text[0];
    int text2_index = 1;
    for (int i = 1; i < text.size(); ++i)
        if (text[i - 1] != text[i])
            text2_char[text2_index++] = text[i];
    text2_char[text2_index] = 0;
    return string(text2_char);
}

// aaaabbxxAxxaaxa => abxA

string unique_characters(string text) {
    constexpr size_t CHARACTERS_COUNT = 128;
    char text2_char[CHARACTERS_COUNT + 1];
    bool has_seen_before[CHARACTERS_COUNT] = {false};
    int text2_index = 0;
    for (int i = 0; i < text.size(); ++i)
        if (!has_seen_before[text[i]]) {
            text2_char[text2_index++] = text[i];
            has_seen_before[text[i]] = true;
        }
    text2_char[text2_index] = 0;
    return string(text2_char);
}

class IsPalindromeHolder {
private:
    static bool is_palindrome_inner(const string &text, int start, int end) {
        if (end - start < 2)
            return true;
        if (text[start] == text[end])
            return is_palindrome_inner(text, start + 1, end - 1);
        return false;
    }

    static bool is_semi_palindrome_inner(const string &text, int start, int end) {
        if (end - start < 3)
            return true;
        if (text[start] == text[end])
            return is_semi_palindrome_inner(text, start + 1, end - 1);
        return is_palindrome_inner(text, start, end - 1)
            || is_palindrome_inner(text, start + 1, end);
    }

public:

    static bool is_palindrome(const string &text) {
        is_palindrome_inner(text, 0, text.size() - 1);
    }

    static bool is_semi_palindrome(const string &text) {
        is_semi_palindrome_inner(text, 0, text.size() - 1);
    }
};

// racebcar

int main() {
//    cout << remove_duplicates("aaaabbxxxxaaxa") << endl;
//    cout << remove_duplicates("AaabbBBBCc") << endl;
//
//    cout << unique_characters("aaaabbxxxxaaxa") << endl;
//    cout << unique_characters("AaabbBBBCc") << endl;

    cout << IsPalindromeHolder::is_palindrome("racecar") << endl;
    cout << IsPalindromeHolder::is_palindrome("myracecar") << endl;
}