// The source for CExNum
// Created by ADanayi

#include "cexnum.h"
#include "iostream"
#include <string>

CExNum::CExNum(const std::string temp)
{
    this->data_num = new char [MAXDIG];
    if (temp.length() ==  0)
        (*this) = predef::zero;

    int i{};
    if (temp[0] == '-')
    {
        i = 1;
        data_sign = 1;
        data_len = temp.length() - 1;
    }
    else
    {
        i = 0;
        data_sign = 0;
        data_len = temp.length();
    }
    if (data_num != nullptr)
    {
        for (size_t j{}; j < temp.length() - i; j++)
            data_num[j] = temp[(temp.length() -1 ) -(j)];
        data_num[temp.length() - i] = '\0';
    for (int i{data_len}; i < MAXDIG; i++)
        data_num[i] = '0';
    }

}

CExNum::~CExNum()
{
    delete[] data_num;
}

int CExNum::getLen() const
{
    return data_len;
}

int CExNum::calcLen()
{
    this->data_len = func_num_calcLen(this->data_num);
    return this->data_len;
}

CExNum::CExNum()
{
    this->data_num = new char [MAXDIG];
    for (int i{}; i < MAXDIG; i++)
        this->data_num[i] = '0';
    this->data_sign = 0;
    this->data_len = 0;
}

CExNum::CExNum(int num)
{
    this->data_num = new char [MAXDIG];
    if (num == 0)
    {
        for (int i{}; i<MAXDIG; i++)
            this->data_num[i] = '0';
        this->data_len = 0;
        this->data_sign = 0;
    }
    else
        func_int2data(num, data_sign, data_len, data_num);
}

void CExNum::disp() const
{
    bool isZero {true};
    for (int i{}; i < MAXDIG; i++)
        if (data_num[i] != '0')
        {
            isZero = false;
            break;
        }
    if (isZero == 0)
    {
        if (data_sign)
            std::cout << "-";
        for (int i{}; (i < data_len) && (i < MAXDIG); i++)
        std::cout << data_num[data_len - i - 1];}
    else
        std::cout << "0";
}

CExNum::CExNum(const CExNum &b)
{
    if (this->data_num == nullptr)
        data_num = new char [MAXDIG];
    this->data_num = new char [MAXDIG];
    for (int i{}; i < b.data_len; i++)
        this->data_num[i] = b.data_num[i];
    for (int i{b.data_len}; i < MAXDIG; i++)
        this->data_num[i] = '0';
    this->data_len = b.data_len;
    this->data_sign = b.data_sign;
}

CExNum::CExNum(CExNum &&b)
{
    this->data_num = b.data_num;
    b.data_num = nullptr;
    this->data_len = b.data_len;
    this->data_sign = b.data_sign;
}

void CExNum::comp9()
{
    func_num_comp(data_num,data_len);
    this->calcLen();
}

void CExNum::comp10()
{
    CExNum one(1);
    func_num_comp(data_num,data_len, true);
    func_posOps_add(this->data_num,one.data_num,
                    this->data_len,one.data_len);
}

void CExNum::negate()
{
    this->data_sign = !this->data_sign;
}

void CExNum::inc()
{
    *this = *this + predef::one;
}

void CExNum::dec()
{
    *this = *this + predef::onem;
}

char CExNum::operator [] (const int& a) const
{
    if ( (0 <= a) && (a < MAXDIG) )
        return this->data_num[a];
    else
        return '\0';
}
