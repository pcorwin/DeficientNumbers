/* Phoebe Corwin
 * 16 Jan 2023
 * Deficient Number Algorithm
 *      This program takes input from the user in the form of a positive integer
 *      and outputs whether the number is deficient.
 *
 * Definitions
 *      Deficient Number: A number, n, for which the sum of all divisors is less than 2n
 */
#include <iostream>
#include <cmath>
using namespace std;

void print(const string& s){
    cout<<s<<endl;
}

//getDivisorSum returns the sum of all divisors of n except for n
int getDivisorSum(int n){
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n%i == 0){
            sum = sum + i;
            if (n/i != i) {
                sum = sum + (n/i);
            }
        }
    }
    sum = sum - n;
    return sum;
};

//isDeficient does not check against 2n, as n is not included in the sum
bool isDeficient(int n){
    return (getDivisorSum(n)<n);
};

void userInput(){
    int x = 0;
    while (x != -1) {
        print("Enter a positive integer for deficiency check (-1 to quit): ");
        cin >> x;
        if (x != -1) {
            if (isDeficient(x)) {
                print("Number is deficient");
            } else {
                print("Number is not deficient");
            }
        }
    }
}

int main() {
    userInput();
    return 0;
}
