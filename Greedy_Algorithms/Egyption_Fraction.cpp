// Egyption Fraction Problem
#include<bits/stdc++.h>

using namespace std;

void print(int num, int deno) {
    if(num ==  0 || deno == 0)
        return ;
    if(deno % num == 0) {
        cout << "1/" << deno / num << "\n";
        return ;
    }
    int temp = ceil((float)deno / num);
    cout << "1/" << temp << " + ";
    print(num * temp - deno, deno * temp);
}

int main() {
    // num is Numerator & deno is Denominator
    int num, deno;
    cout << "Numerator: ";
    cin >> num;
    cout << "Denominator: ";
    cin >> deno;
    cout << "Egyptian Fraction Representation of " << num << "/" << deno << " is: ";
    print(num, deno); 
    return 0;
}

