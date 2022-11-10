#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int closureSum(int inputNum) {
    int sum = 0;
    // get number of digits
    int numDigits = 0;
    int temp = inputNum;
    while (temp > 0) {
        numDigits++;
        temp /= 10;
    }

    while (inputNum != 0) {
        int add = inputNum / pow(10, numDigits - 1);
        if (numDigits == 1) {
            sum += add;
            numDigits--;
            break;
        }
        else {
            add = add * 10 + inputNum % 10;
            sum += add;
            inputNum /= 10;
            inputNum = inputNum % (int)pow(10, numDigits - 2);
            numDigits -= 2;
        }
    }

    return sum;
}

int main()
{
    int inputNum = 25806847;
    cout << closureSum(inputNum);

    return 0;
}