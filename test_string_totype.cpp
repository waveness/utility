#include <stdio.h>
#include <string>
#include <sstream>
#include <limits>
#include <typeinfo>
#include <stdlib.h>
#include <iostream>

template<typename T>
static std::string toString(const T& t){
    std::ostringstream oss;

    if(typeid(t) == typeid(double)){
        printf("this is double\n");
        int prec = std::numeric_limits<long double>::digits10;
        oss.precision(prec);
    }

    oss << t;
    return oss.str();
}

template <typename T>
static T stringToNumber(const std::string& str){
    std::istringstream iss(str);

    T num;
    iss >> num;
    return num;
}

double stringToDouble(const std::string& str){
#if 1
    double value;
    printf("---> %s \n", str.c_str());
    value = atof(str.c_str());
    return value;
#else
    double value; 
    std::istringstream is(str);
    is >> value;
    return value;
#endif
}

std::string doubleToString(double value){
    int prec = std::numeric_limits<long double>::digits10;
    std::ostringstream out;
    out.precision(prec);
    out << value;
    std::string str = out.str();
    return str;
}

int main(){
    float a = 0.040035;
    double b = 0.03623262845891671;

    std::string str_a = toString(a);
    std::string str_b = toString(b);
    printf("--->string a = %s\n", str_a.c_str());
    printf("--->string b = %s\n", str_b.c_str());

    printf("--->cvt to float %f\n", stringToNumber<float>(str_a));
    printf("--->cvt to double %f\n", stringToNumber<double>(str_b));

    std::cout.precision(18);
    std::cout << "---->cvt to double:" << stringToNumber<double>(str_b) << std::endl;

    return 0;
}
