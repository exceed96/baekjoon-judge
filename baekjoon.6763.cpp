#include <iostream>

using namespace std;

int main(void)
{
    long long A,B;
    cin >> A >> B;
    if (B - A >= 31) cout << "You are speeding and your fine is $500.";
    else if (B - A >= 21 && B - A <= 30) cout << "You are speeding and your fine is $270.";
    else if (B - A >= 1 && B - A <= 20) cout << "You are speeding and your fine is $100.";
    else cout << "Congratulations, you are within the speed limit!";
}
