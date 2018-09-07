#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

std::string addStr(std::string a, std::string b){
    std::string sum = "";
    long long int length = std::max(a.length(), b.length());

    while (a.size() < length){
        a = "0" + a;
    }
    while (b.size() < length){
        b = "0" + b;
    }
    int carry = 0;
    int digitsum = 0;

    for (long long int i = length-1; i > -1; i--){
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
std::string subStr(std::string n1, std::string n2){
    long long int length = std::max(n1.size(), n2.size());

     while (n1.size() < length){
        n1 = "0" + n1;
    }
    while (n2.size() < length){
        n2 = "0" + n2;
    }

    std::string diff = "";
    int a = 0;
    for (long long int i = length-1; i > -1; i--) {
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


int main(){
    int n;
    std::cin >> n;
    std::string c [n];

    for (int j = 0; j < n; j++){
        std::string a = "",b = "";
        std::cin >> a >> b;
        //std::cout << a[0] - '0' << b[0] - '0';

        if ((a[0] - '0' < 0) && (b[0] - '0' < 0)){
            a.erase(0, std::min(a.find_first_not_of('-'), a.size()-1));
            b.erase(0, std::min(b.find_first_not_of('-'), b.size()-1));

            c[j] = "-" + addStr(a,b);
        }

        else if (((a[0] - '0')) < 0){
            a.erase(0, std::min(a.find_first_not_of('-'), a.size()-1));
            if (a.size() > b.size()){
                c[j] = "-" + subStr(a,b);
            }
            else if (a.size() < b.size()){
                c[j] = subStr(b,a);
            }
            else if (a.size() == b.size()){
                for(int i = 0; i < a.length(); ++i){
                    if ((a[i] - '0') != (b[i] - '0'))
                    {
                        if ((a[i] - '0') > (b[i] - '0')){
                            c[j] = "-" + subStr(a,b);
                            break;
                        }
                        else{
                            c[j] = subStr(b,a);
                            break;
                        }

                    }
                }
            }
            else{
                c[j] = subStr(b,a);
            }
        }

        else if (((b[0] - '0')) < 0){
            b.erase(0, std::min(b.find_first_not_of('-'), b.size()-1));

            if (a.size() > b.size()){
                c[j] = subStr(a,b);
            }
            else if (a.size() < b.size()){
                c[j] = "-" +  subStr(b,a);
            }
            else if (a.size() == b.size()){
                for(int i = 0; i < a.length(); ++i){
                    if ((a[i] - '0') != (b[i] - '0'))
                    {
                        if ((a[i] - '0') > (b[i] - '0')){
                            c[j] =  subStr(a,b);
                            break;
                        }
                        else{
                            c[j] = "-" + subStr(b,a);
                            break;
                        }

                    }
                }
            }
            else{
                c[j] = subStr(a,b);
            }
        }

        else{
            c[j] = addStr(a,b);
        }
    }
    for (int i = 0; i < n; i++){
        if ((c[i]) == "")
        {
            std::cout << 0;
        }
        else
            std::cout << c[i];
            if (i!= n-1){
                std::cout << "\n";
            }

    }

}

