#include <iostream>
#include <vector>
using namespace std;

bool checkPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

vector<int> findPerfectNumbers(int n) {
    vector<int> result;
    for (int i = 1; i < n; ++i) {
        if (checkPerfect(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    vector<int> perfectNumbersList = findPerfectNumbers(n);

    cout << "Perfect numbers from 1 to " << n << ": ";
    for (size_t i = 0; i < perfectNumbersList.size(); ++i) {
        cout << perfectNumbersList[i] << " ";
    }
    cout << endl;

    return 0;
}

