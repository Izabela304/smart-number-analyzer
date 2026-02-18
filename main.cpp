#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
 * ============================================================
 * Smart Number Analyzer
 * Author: Izabela Sandeva
 *
 * Description:
 * Console application that analyzes integer properties
 * such as palindrome check, Armstrong check,
 * digit sum calculation and statistical summary.
 * ============================================================
 */


// Checks whether a given integer is a palindrome number.
// A number is palindrome if it reads the same forward and backward.
bool isPalindrome(int n){
    n = abs(n);
    if(n==0) return true;
    int copy=n;
    int reversed=0;
    while(copy>0){
        reversed=reversed*10+copy%10;
        copy/=10;
    }
    return reversed==n;
}

//Calculates and returns the sum of digits of a given integer.
//// Works with negative numbers using absolute value.
int sumDigits(int n){
     n=abs(n);
    if(n==0) return 0;

    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

// Checks whether a number is an Armstrong number.
// An Armstrong number is equal to the sum of its digits each raised
// to the power of the number of digits.
bool isArmstrong(int n){
    if(n==0) return true;
    int original= abs(n);
    int k=0;
    while(original>0){
        k++;
        original/=10;
    }
    int sum=0;
    int copy= abs(n);
    while(copy>0){
        int digit=copy%10;
        sum+= (int)round(pow(digit,k));
        copy/=10;
    }
    return sum== abs(n);
}

// Determines whether a number contains more even digits than odd digits.
// Returns true if even digits are more than odd digits.
bool moreEvenDigits(int n){
    if(n==0) return true; // 0 has one even digit
    n= abs(n);
    int count_odd=0,count_even=0;
    while(n>0){
        int last=n%10;
        if(last%2==0) {
            count_even++;
        }
        else {
            count_odd++;
        }
        n/=10;
    }
    return (count_even>count_odd);
}

int main() {
   int n;
   cin>>n;
   int numbers[100];
   for(int i=0;i<n;i++){
       cin>>numbers[i];
   }
   int counter_palindromes=0;
   int counter_armstrong=0;
   int counter_even=0;
   int maxSumDigits=-1;
   int max_digit_number=numbers[0];
   double sum=0;
   for(int i=0;i<n;i++){
       sum+=numbers[i];
       if(isPalindrome(numbers[i])){
           counter_palindromes++;}
       if (isArmstrong(numbers[i])){
          counter_armstrong++;
       }
       if(moreEvenDigits(numbers[i])){
        counter_even++;
       }
       int s_digits= sumDigits(numbers[i]);
       if(s_digits>maxSumDigits){
           maxSumDigits=s_digits;
           max_digit_number=numbers[i];


       }


   }
    cout<<"Palindromes: "<<counter_palindromes<<endl;
   cout<<"Armstrong numbers: "<<counter_armstrong<<endl;
   cout<<"Number with max digit sum: "<<max_digit_number<<endl;
   cout<<"Numbers with more even digits: "<<counter_even<<endl;
   cout<<fixed<<setprecision(2);
   cout<<"Average: "<<sum/n<<endl;

    return 0;
}