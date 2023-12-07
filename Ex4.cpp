#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String() : length(0), str(nullptr) {}

    String(char ch) : length(1) {
        str = new char[2];
        str[0] = ch;
        str[1] = '\0';
    }

    String(const char* s) : length(strlen(s)) {
        str = new char[length + 1];
        strcpy(str, s);
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];

        strcpy(result.str, str);
        strcat(result.str, other.str);

        return result;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;

            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    String operator!() const {
        String reversed;
        reversed.length = length;
        reversed.str = new char[length + 1];

        for (int i = 0; i < length; ++i) {
            reversed.str[i] = str[length - i - 1];
        }

        reversed.str[length] = '\0';

        return reversed;
    }

    int getLen() const {
        return length;
    }

    void display() const {
        cout << str;
    }
};

int main() {
    String emptyString;
    String charString('A');
    String helloString("Hello");
    String worldString("World");

    String concatenatedString = helloString + worldString;
    String reversedString = !concatenatedString;

    cout << "Empty String: ";
    emptyString.display();
    cout << ", Length: " << emptyString.getLen() << endl;

    cout << "Char String: ";
    charString.display();
    cout << ", Length: " << charString.getLen() << endl;

    cout << "Hello String: ";
    helloString.display();
    cout << ", Length: " << helloString.getLen() << endl;

    cout << "Concatenated String: ";
    concatenatedString.display();
    cout << ", Length: " << concatenatedString.getLen() << endl;

    cout << "Reversed String: ";
    reversedString.display();
    cout << ", Length: " << reversedString.getLen() << endl;

    return 0;
}
