#include<bits/stdc++.h>
using namespace std;

bool isNumeric(const string& str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string number;
    while (true) {
        cout << "Please enter a number to validate: ";
        cin >> number;
        if (number == "exit")
            break;
        else if (!isNumeric(number)) {
            cout << "Bad input! ";
            continue;
        }
        int length = number.length();
        int evenSum = 0;
        for (int i = length - 2; i >= 0; i = i - 2) {
            int doubleVal = ((number[i] - '0') * 2);
            if (doubleVal > 9) {
                doubleVal = (doubleVal / 10) + (doubleVal % 10);
            }
            evenSum += doubleVal;
        }
        for (int i = length - 1; i >= 0; i = i - 2) {
            evenSum += (number[i] - '0');
        }
        cout << (evenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;
        continue;
    }
    return 0;
}