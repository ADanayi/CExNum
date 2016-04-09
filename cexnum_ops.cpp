#include "cexnum.h"

CExNum& CExNum::operator = (const CExNum &b)
{
    this->data_len = b.data_len;
    this->data_sign = b.data_sign;
    for (int i{0}; i < this->data_len; i++)
        this->data_num[i] = b.data_num[i];
    for (int i{data_len}; i < MAXDIG; i++)
        this->data_num[i] = '0';
    return *this;
}

CExNum& CExNum::operator = (const int &a)
{
    func_int2data(a
                  ,data_sign
                  ,data_len
                  ,data_num);
    return *this;
}

CExNum& CExNum::operator = (CExNum &&b)
{
    this->data_len = b.data_len;
    this->data_sign = b.data_sign;
    this->data_num = b.data_num;
    b.data_num = nullptr;
    return *this;
}

CExNum  CExNum::operator + (const CExNum& b) const
{
    if ( (this->data_len == 0) )
    {
        CExNum a {b};
        return std::move(a);
    }

    if ( (b.data_len == 0) )
    {
        CExNum a {*this};
        return std::move(a);
    }

    CExNum a {b};
    if ( (this->data_sign == 0) && (b.data_sign == 0) )
    {
        func_posOps_add(a.data_num,this->data_num,
                        a.data_len,this->data_len);
        return std::move(a);
    }

    if ( (this->data_sign == 1) && (b.data_sign == 1) )
    {
        func_posOps_add(a.data_num,this->data_num,
                        a.data_len,this->data_len);
        return std::move(a);
    }

    if ( (this->data_sign == 0) && (b.data_sign == 1) )
    {
        a.negate();
        if (*this == a)
        {
            a = predef::zero;
            return std::move(a);
        }
        a.negate();
        a.comp10();
        if (func_posOps_add(a.data_num,this->data_num,
                            a.data_len,this->data_len))
        {
            a.negate();
            return std::move(a);
        }
        else
        {
            a.comp10();
            return std::move(a);
        }
    }

    if ( (this->data_sign == 1) && (b.data_sign == 0) )
    {
        a.negate();
        if (*this == a)
        {
            CExNum a{predef::zero};
            return std::move(a);
        }
        a.negate();
        CExNum temp{*this};
        temp.comp10();
        if (func_posOps_add(a.data_num,temp.data_num,
                            a.data_len,temp.data_len))
        {;
            return std::move(a);
        }
        else
        {
            a.negate();
            a.comp10();
            return std::move(a);
        }
    }
    return std::move(a);
}

CExNum  CExNum::operator + (const int &a) const
{
    CExNum temp{a};
    return std::move( (*this + temp) );
}

CExNum  CExNum::operator - (const CExNum& b) const
{
    CExNum ans{b};
    ans.negate();
    ans = *this + ans;
    return std::move(ans);
}

CExNum  CExNum::operator - (const int &a) const
{
    CExNum temp(-a);
    return std::move ( (*this + temp) );
}

CExNum  CExNum::operator * (const CExNum& b) const
{
    if (*this == predef::one)   //1*n
    {
        CExNum a{b};
        return std::move(a);
    }

    if (*this == predef::onem)  //-1*n
    {
        CExNum ans{b};
        ans.negate();
        return std::move(ans);
    }

    if (b == predef::one)       //n*1
    {
        CExNum ans{*this};
        return std::move(ans);
    }

    if (b == predef::onem)      //n*-1
    {
        CExNum ans{*this};
        ans.negate();
        return std::move(ans);
    }

    CExNum ans {*this};
    CExNum b2  {b};
    if ( (ans.data_sign == b.data_sign) )
    {
        b2.data_sign = false;
        ans.data_sign = false;
        func_posOps_humanMul(ans, b2);
    }
    else
    {
        ans.data_sign = false;
        b2.data_sign = false;
        func_posOps_humanMul(ans, b2);
        ans.negate();
    }

    return std::move(ans);
}

CExNum  CExNum::operator - ()
{
    CExNum ans{*this};
    ans.negate();
    return std::move(ans);
}

CExNum CExNum::operator ^ (int b) const
{
    if (*this == predef::zero)  //0^n
    {
        CExNum ans{predef::zero};
        return std::move(ans);
    }
    if (b == 1)         //n^1
    {
        CExNum ans{*this};
        return std::move(ans);
    }
    if (b == 0)         //n^0
    {
        CExNum ans{predef::one};
        return std::move(ans);
    }
    if (*this == predef::one)   //1^n
    {
        CExNum ans{predef::one};
        return std::move(ans);
    }
    if (*this == predef::onem) // -1^n
    {
        CExNum one_m{predef::onem};
        if (b < 0) b = -b;
        for (int i{}; i < b; i++)
             one_m.negate();
        return std::move(one_m);
    }
    if (b < 0)
    {
        CExNum ans{predef::zero};
        return std::move(ans);
    }
    CExNum  c1{*this};
    for (int i{1}; i < b; i++)
        c1 = c1 * (*this);
    return std::move(c1);
}

CExNum  CExNum::operator ^ (const CExNum& b) const
{
    if (*this == predef::zero)  //0^n
    {
        CExNum ans{predef::zero};
        return std::move(ans);
    }
    if (b == predef::one)         //n^1
    {
        CExNum ans{*this};
        return std::move(ans);
    }
    if (b == predef::zero)         //n^0
    {
        CExNum ans{predef::one};
        return std::move(ans);
    }
    if (*this == predef::one)   //1^n
    {
        CExNum ans{predef::one};
        return std::move(ans);
    }
    if (*this == predef::onem) // -1^n
    {
        CExNum b2{b};
        CExNum one_m{predef::onem};
        if (b2.data_sign) b2.negate();
        for (CExNum i{0}; i < b2; ++i)
             one_m.negate();
        return std::move(one_m);
    }
    if (b < predef::zero)
    {
        CExNum ans{predef::zero};
        return std::move(ans);
    }
    CExNum  c1{*this};
    for (CExNum i{predef::one}; i < b; ++i)
        c1 = c1 * (*this);
    return std::move(c1);
}

CExNum& CExNum::operator++ ()
{
    this->inc();
    return *this;
}

CExNum& CExNum::operator++ (int)
{
    this->inc();
    return *this;
}

CExNum& CExNum::operator-- ()
{
    this->inc();
    return *this;
}

CExNum& CExNum::operator-- (int)
{
    this->dec();
    return *this;
}

CExNum& CExNum::operator >> (int a)
{
    if (data_len !=0)
    if (this->data_len >= a)
    {
        this-> data_len -= a;
        for (int i{}; i < data_len; i++)
            data_num[i] = data_num[i + a];
        for (int i{data_len}; i < data_len + a; i++)
            data_num[i] = '0';
    }
    return *this;
}

CExNum& CExNum::operator << (int a)
{
    if (this->data_len != 0)
    if (this->data_len + a <= MAXDIG)
    {
        this-> data_len += a;
        for (int i{data_len - 1}; a <= i; i--)
            data_num[i] = data_num[i - a];
        for (int i{}; i < a; i++)
            data_num[i] = '0';
    }
    return *this;
}

CExNum  CExNum::operator + (CExNum&& b) const
{
    CExNum temp{b};
    return std::move(*this + b);
}

CExNum  CExNum::operator - (CExNum&& b) const
{
    CExNum temp{b};
    return std::move(*this - temp);
}

CExNum  CExNum::operator * (CExNum&& b) const
{
    CExNum temp{b};
    return std::move(*this * temp);
}

/*CExNum  CExNum::operator / (CExNum&& b)
{
    CExNum temp{b};
    return std::move(*this / temp);
}

CExNum  CExNum::operator % (CExNum&& b)
{
    CExNum temp{b};
    return std::move(*this % temp);
}*/

CExNum  CExNum::operator ^ (CExNum&& b) const
{
    CExNum temp{b};
    return std::move(*this ^ temp);
}
