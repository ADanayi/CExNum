#include "cexnum.h"

bool CExNum::operator == (const CExNum& b) const
{
    bool zero_check {true};
    if (this->data_len != b.data_len)
        return 0;
    int i{};
    for (;i < MAXDIG; i++)
    {
        if (this->data_num[i] != b.data_num[i])
            return 0;
        if (this->data_num[i] != '0')
        {
            zero_check = false;
            break;
        }
    }
    for (;i < MAXDIG; i++)
    {
        if (this->data_num[i] != b.data_num[i])
            return 0;
    }
    if (zero_check) return true;
    else
        if (this->data_sign == b.data_sign)
            return true;
        else
            return false;
}

bool CExNum::operator != (const CExNum& b) const
{
    return !(*this == b);
}

bool CExNum::operator < (const CExNum& b) const
{
    CExNum temp{*this - b};
    if (temp.data_len == 0) return false;
    return temp.data_sign;
}

bool CExNum::operator > (const CExNum& b) const
{
    CExNum temp{*this - b};
    if (temp.data_len == 0) return false;
    return !temp.data_sign;
}

bool CExNum::operator <= (const CExNum& b) const
{
    return ( !(*this > b) );
}

bool CExNum::operator >= (const CExNum &b) const
{
    return !(*this < b);
}

bool CExNum::operator < (const int& b) const
{
    CExNum temp{b};
    return (*this < temp);
}

bool CExNum::operator == (const int& b) const
{
    CExNum temp{b};
    return (*this == temp);
}

bool CExNum::operator != (const int& b) const
{
    CExNum temp{b};
    return (*this != temp);
}

bool CExNum::operator > (const int& b) const
{
    CExNum temp{b};
    return (*this > temp);
}

bool CExNum::operator <= (const int& b) const
{
    CExNum temp{b};
    return (*this <= temp);
}

bool CExNum::operator >= (const int& b) const
{
    CExNum temp{b};
    return (*this >= temp);
}

bool CExNum::operator <  (CExNum&& b) const
{
    CExNum temp{b};
    return (*this < temp );
}

bool CExNum::operator >  (CExNum&& b) const
{
    CExNum temp{b};
    return (*this > temp );
}

bool CExNum::operator ==  (CExNum&& b) const
{
    CExNum temp{b};
    return (*this == temp );
}

bool CExNum::operator !=  (CExNum&& b) const
{
    CExNum temp{b};
    return (*this != temp );
}

bool CExNum::operator <=  (CExNum&& b) const
{
    CExNum temp{b};
    return (*this <= temp );
}

bool CExNum::operator >=  (CExNum&& b) const
{
    CExNum temp{b};
    return (*this >= temp );
}
