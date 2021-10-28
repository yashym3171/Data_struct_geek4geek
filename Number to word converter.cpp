#include <iostream>

#include <string>

#include <vector>

#include <cctype>

#include <utility>

#include <algorithm>

#include <stdexcept>





bool isDigit(const std::string &num);

auto numberDecomposer(const std::string &num) -> std::pair<std::string, std::vector<std::string>>;

std::string hundredParser(const std::string &num, const std::vector<std::string> &wordDic);

auto parseWord(const std::string &num, const std::vector<std::string> &wordDic) -> std::pair<std::string, std::string>;





const std::vector<std::string> wordsDic{

    "Zero", "One", "Two", "Three", "Four", "Five", "Six", 

    "Seven", "Eight", "Nine", "Ten", "Eleven", 

    "Twelve", "Thirteen", "Fourteen", "Fifteen", 

    "Sixteen", "SevenTeen", "Eighteen", "Nineteen","Twenty",

    "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",

    "Ninety", "Hundred", "Thousand", "Million", "Billion", 

    "Trillion", "Quadrillion", "Quintillion"

};





int main()

{

    std::string sNumber;

    std::cin >> sNumber;

    if (sNumber.empty()) sNumber = "1000";

    if (!isDigit(sNumber)) {

        std::cout << "Invalid Number format....\n";

        std::cout << "Program expect format: 212727812772\n";

        std::cout << "\n\n\nAuthor: Mirielle";

        return -1;

    };

    auto parsed = parseWord(sNumber, wordsDic);

    std::cout << "Your Input: " << sNumber << std::endl;

    std::cout << "Splitted: " << parsed.first << std::endl;

    std::cout << std::endl;

    std::cout << parsed.second;

    

    std::cout << std::endl;

    return 0;

}



// make accept whitespace and dot

bool isDigit(const std::string &num) {

    bool res{ true };

    auto begin{ num.cbegin() };

    while (begin != num.end()) {

        if (!isdigit(*begin)) {

            res = false;

            break;

        }

        begin++;

    };

    return res;

};





// filter whitespace

auto numberDecomposer(const std::string &num) -> std::pair<std::string, std::vector<std::string>> {

    int i, j;

    std::string res;

    std::pair<std::string, std::vector<std::string>> pair{ "", {} };

    auto length{ num.size() };

    const int DIVISOR{ 3 };

    int divLen = length / DIVISOR;

    int divRem = length % DIVISOR;

    for (i = 0; i < divRem; i++)

        res += num[i];

    pair.second.push_back(res);

    for (i = 0; i < divLen; i++) {

        if(divRem) res += ',';

        pair.second.push_back("");

        for (j = 0; j < DIVISOR; j++) {

            res += num[divRem];

            pair.second[i + 1] += num[divRem];

            divRem++;

        }

    };

    pair.first = res;

    return pair;

};







std::string hundredParser(const std::string &num, const std::vector<std::string> &wordDic) {

    std::string res;

    int _num = std::stoi(num);

    auto length = num.size();

    switch (length) {

    case 1:

        res += wordDic[_num];

        break;

    case 2:

        if (_num <= 20)

            res = wordDic[_num];

        else {

            if (!(_num % 10)) {

                res = wordDic[18 + (_num / 10)];

            }

            else {

                int div = _num;

                int rem = _num % 10;

                res += wordDic[20 + (div / 10 - 2)];

                res += " ";

                res += wordDic[rem];

            }

        }

        break;

    case 3:

        if(_num == 0) return "";

        if(_num <= 19) {

            std::string tmp = std::to_string(_num);

            return hundredParser(tmp, wordsDic);

        }

        if (!(_num % 100)) {

            int div = _num / 100;

            res += wordDic[div];

            res += " Hundred";

        }

        else {

            int hundred = _num / 100;

            std::string splitted = hundredParser(num.substr(1), wordDic);

            if(num[0] != '0')
{

                res += wordDic[hundred];

                res += " Hundred and ";

            } 

                

           // res += " Hundred and ";

            res += splitted;

        }

        break;

    }

    return res;

};





auto parseWord(const std::string &num, const std::vector<std::string> &wordDic) -> std::pair<std::string, std::string> 

{

    std::string res, hundreds;

    std::pair<std::string, std::string> pair;

    std::vector<std::string> splittedBuffer;

    auto decomposed = numberDecomposer(num);

    std::string splitted = decomposed.first;

    int divLen = std::count(splitted.begin(), splitted.end(), ',');

    if (!divLen)

        res += hundredParser(num, wordDic);

    else {

        int counter = divLen - 1;

        try {

            wordDic.at(29 + counter);

        }catch(std::exception &s) {

            std::cout << "Buffer Overflow: Index out of range\n\n";

            return {splitted, ""};

        }

        for (const auto &i : decomposed.second) {

            if (!i.empty()) {

                auto f = hundredParser(i, wordDic);

                res += f;

                if (29 - counter <= 29) {

                    res += " ";

                    res += wordDic[29 + counter];

                    res += ", ";

                };

                counter--;

            }

        }

    };

    pair.first = splitted;

    pair.second = res;

    return pair;

};
