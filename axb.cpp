#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

std::string addStr(std::string a, std::string b){
    std::string sum = "";
    int length = std::max(a.length(), b.length());

    while (a.size() < length){
        a = "0" + a;
    }
    while (b.size() < length){
        b = "0" + b;
    }
    int carry = 0;
    int digitsum = 0;

    for (int i = length-1; i > -1; i--){
        digitsum = int(a[i] - '0') + int(b[i] - '0') + carry;
        carry = 0;
        if (digitsum > 9 ){
            digitsum -=10;
            carry = 1;
        }
        sum = (std::to_string(digitsum)) + sum;

    }
    if (carry == 1){
        sum = "1" + sum;
    }
    //std::cout<<sum;
    return sum;
}
std::string subtStr(std::string n1, std::string n2){
    int length = std::max(n1.size(), n2.size());

     while (n1.size() < length){
        n1 = "0" + n1;
    }
    while (n2.size() < length){
        n2 = "0" + n2;
    }

    std::string diff = "";
    int a = 0;
    for (int i = length-1; i > -1; i--) {
        a = (n1[i]-'0') - (n2[i]-'0');

        if (a>-1){
            diff = std::to_string(a) + diff;
        }
        else{
            int b = i-1;
            while (b > -1){
                n1[b] = ((n1[b]-'0') - 1) % 10 + '0';
                if (n1[b] == '9')
                    b--;
                else
                    break;
            }
                    diff = std::to_string(a+10) + diff;
        }

    }
        return diff.erase(0, std::min(diff.find_first_not_of('0'), diff.size()-1));
}

//int toInt(std::string f){
//    int g;
//    std::istringstream (f) >> g;
//    return g;
//}

std::string karatsuba(std::string num1, std::string num2){
    int length = std::max(num1.length(), num2.length());

    while (num1.size() < length){
        num1 = "0" + num1;
    }
    while (num2.size() < length){
        num2 = "0" + num2;
    }

 //   if (length == 1)
 //       return std::to_string((num1[0]-'0')*(num2[0]-'0'));
    if (length < 8){
        unsigned long long int f;
        f = ((unsigned long long)atoi((num1.c_str())) * ((unsigned long long)atoi(num2.c_str())));
        return std::to_string(f);
    }


    std::string x1 = num1.substr(0,length/2);
    std::string x2 = num1.substr(length/2,length-length/2);
    std::string y1 = num2.substr(0,length/2);
    std::string y2 = num2.substr(length/2,length-length/2);

    std::string z0 = karatsuba(x1, y1);
    std::string z1 = karatsuba(x2, y2);
    std::string z2 = karatsuba(addStr(x1,x2), addStr(y1,y2)); //cant add/sub strings
    std::string z3 = subtStr(z2,addStr(z0, z1)); //cant add/sub strings

    for (long long int i = 0; i < 2 * (length - length/2); i++){
        z0 += "0";
    }
    for (long long int i = 0; i < (length - length/2); i++){
        z3 += "0";
    }

    std::string product = addStr(addStr(z0, z1), z3);

    return product.erase(0, std::min(product.find_first_not_of('0'), product.size()-1));
}

int main(){
    //num1
    std::string nu1, nu2;
    std::cin>>nu1>>nu2;

    std::cout << karatsuba(nu1,nu2);

return 0;
}

