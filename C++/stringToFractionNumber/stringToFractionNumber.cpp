/*
Given a string, convert it into a number. If string is for fraction number
then return fraction number.
Example: string = "123", output = 123
    string = "123.5" output = 123.5
    string = ".123" output = 0.123
    strint = "123....5"  output = -1
*/


#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int stringToNumber(string s){
    double value =0;
    int l = s.size()-1;
    for(auto c :s){
        int n = int(c);
        if(n < 48 || n > 57){
            return -1;
        }
        value += ((n-48) * pow(10, l));
        l --;
    }
    return value;
}
double stringToFractionNumber(string s){
    int index = s.find(".");
    if(index < 0){
        return stringToNumber(s);
    }
    string str1 = s.substr(0, index);
    string str2 = s.substr(index+1);

    index = str2.find(".");
    if(index >= 0){
        return -1;
    }

    int n1 = stringToNumber(str1);
    int n2 = stringToNumber(str2);
    int l = str2.size();
    return (n1+ n2/(pow(10, l)));

}
int main(){

    string s = "123.5";
    double retVal = stringToFractionNumber(s);
    cout << retVal;
    return 1;
}