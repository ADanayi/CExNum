#include "cexnum.h"

void func_int2data (const int &a, bool& data_sign,
                    int &data_len, char* data_num)
{
    std::string temp;
    temp = std::to_string(a);
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


bool func_posOps_add(char* num1,
                     char* num2,
                     int& len1,
                     const int& len2)
{
    if (len1 == 0)
    {
        len1 = len2;
        for (int i{0}; i < len1; i++)
            num1[i] = num2[i];
        for (int i{len1}; i < MAXDIG ; i++)
            num1[i] = '0';
        return false;
    }
    if (len2 == 0)
    {
        return false;
    }
    if (len2 >= len1)
    {
        bool res{false};
        for (int i{}; i < len2; i++)
        {
            num1[i] = func_ch_add(num1[i], num2[i], res);
        }
        if (res)
        {
            if (len2 < MAXDIG)
            {
                num1[len2] = '1';
                len1 = len2 + 1;
                for (int i{len1}; i < MAXDIG; i++)
                    num1[i] = '0';
                return false;
            }
            else
            {
                len1 = func_num_calcLen(num1);
                return true;
            }
        }
        else
        {
            len1 = len2;
            for (int i{len1}; i < MAXDIG; i++)
                num1[i] = '0';
            return false;
        }
    }
    else
    {
        bool res{false};
        for (int i{}; i < len1; i++)
        {
            num1[i] = func_ch_add(num1[i], num2[i], res);
        }
        if (res)
        {
            if (len1 < MAXDIG)
            {
                num1[len1] = '1';
                len1 = len1 + 1;
                for (int i{len1}; i < MAXDIG; i++)
                    num1[i] = '0';
                return false;
            }
            else
            {
                len1 = func_num_calcLen(num1);
                return true;
            }
        }
        else
        {
            for (int i{len1}; i < MAXDIG; i++)
                num1[i] = '0';
            return false;
        }
    }
}

char func_ch_add(const char &a, const char &b,
                 bool &res)
{
    int t1{func_char2int(a)};
    int t2{func_char2int(b)};
    int t3{t1 + t2};
    if (res) t3++;
    if (t3 >= 10)
    {
        res = true;
        return (func_int2char(t3 - 10) );
    }
    else
    {
        res = false;
        return (func_int2char(t3) );
    }
}

char func_int2char(const int& num)
{
    return (num + '0');
}


int func_char2int(const char& ch)
{
    return (ch - '0');
}

void func_num_comp(char* num1, int& len, bool calclen)
{
    static const int nine_zero {'9' + '0'};
    for (int i{}; i < MAXDIG; i++)
        num1[i] = nine_zero - num1[i];
    if (calclen)
        len = func_num_calcLen(num1);
}

int  func_num_calcLen(char* num)
{
    int len{MAXDIG};
    while (num[len-1] == '0')
        len--;
    return len;
}

void func_posOps_seqMul(CExNum& a,CExNum& b)
{
    if (a == predef::zero)
    {
        a = predef::zero;
        return;
    }
    if (b == predef::zero)
    {
        a = predef::zero;
        return;
    }
    CExNum adder{a};
    b = b + predef::onem;
    while (b != predef::zero)
    {
        a = a + adder;
        b = b + predef::onem;
    }
}

char func_ch_mul(const char& ch1, const char&ch2, int &res)
{
int sum{ (ch1 - '0') * (ch2 - '0') + res};
if (sum >= 100)
    std::cout << "Error" << std::endl;
res = sum/10;
return (sum - res*10) + '0';
}

CExNum func_posOps_divide(CExNum& a, CExNum& b, CExNum& res)
{
    if ( (a == predef::zero) || (b == predef::zero) )   // 0
    {
        CExNum ans{predef::zero};
        return std::move(ans);
    }

    CExNum op_sum{b};
    CExNum op_ctr{predef::one};

    while (a > op_sum)
    {
        op_sum = op_sum + b;
        op_ctr.inc();
    }

    if (a == op_sum)
    {
        res = predef::zero;
        return std::move(op_ctr);
    }

    op_ctr--;
    op_sum = op_sum - b;
    res = a - op_sum;
    return std::move(op_ctr);
}

bool func_ch_MUL(char *num, int & len, char & ch)
{
    if (ch == '0')
    {
        for (int i{}; i < MAXDIG; i++)
            num[i] = '0';
        len = 0;
        return false;
    }
    if (ch == '1')
    {
        return false;
    }
    int res{0};
    for (int i{}; i < len; i++)
    {
        num[i] = func_ch_mul(num[i], ch, res);
    }
    if (res != 0)
    {
        if (len < MAXDIG)
        {
            len++;
            num[len - 1] = (res + '0');
            return false;
        }
        else
        {
            len = MAXDIG;
            return true;
        }
    }
    else
    {
        return false;
    }
}

bool CExNum::func_posOps_humanMul(CExNum& a, CExNum& b) const
{
    CExNum  sum   {};
    CExNum  adder {};
    bool    E{ false };
    for (int i{}; i < a.data_len; i++)
    {
        if (a.data_num[i] != '0')
        {
            adder = b;
            E = E || func_ch_MUL(adder.data_num , adder.data_len,
                                 a.data_num[i] ) ;
            adder = adder << i;
            sum   = sum   +  adder;
        }
    }
    a = sum;
    return E;
}

bool CExNum::func_posOps_humanDiv(CExNum& a, CExNum& b) const
{
    if (b == 0)
    {
        return false;
    }
    if (a == 0)
    {
        return true;
    }
    if (a == 1)
        return true;
    if (a == b)
    {
        a = predef::one;
        return true;
    }

    if (a < b)
    {
        a = predef::zero;
        return true;
    }

    CExNum temp{};
    CExNum ans{};
    int len{a.data_len};
    int divlen{b.data_len};
    int ctr{1};

    temp.data_len = 1;
    temp.data_num[0] = a.data_num[len -1];
    if (ctr < divlen)
        for (ctr = 2; ctr < divlen; ctr++)
        {
            temp << 1;
            temp.data_num[0] = a.data_num[len - ctr - 1];
        }

    if (temp < b)
    {
        ctr++;
        temp << 1;
        temp.data_num[0] = a.data_num[len - ctr];
    }

    int i{};
    for (; (b*i) < temp; i++);
    if ( (b*i) > temp)
    {
        i--;
    }
    if (i > 9)
        return false;
    ans.data_len = 1;
    ans.data_num[0] = i + '0';
    temp = temp - (i*b);

    while(ctr < len)
    {
        ctr++;
        if (temp != predef::zero)
            temp << 1;
        else
            temp.data_len = 1;
        temp.data_num[0] = a.data_num[len - ctr];

        while ( (temp < b)&&(ctr <= len) )
        {
            ans << 1;
            ans.data_num[0] = '0';
            temp << 1;
            temp.data_num[0] = a.data_num[len - ctr];
            ctr++;
        }

        temp.calcLen();

        if (temp >= b)
        {
            i = 0;
            for (; (b*i) < temp; i++);
            if ( (b*i) > temp) i--;
            if (i > 9)
                return false;
            ans << 1;
            ans.data_num[0] = i + '0';
            temp = temp - (i*b);;
        }
    }

    ans.calcLen();
    a.data_len = ans.data_len;
    a.data_num = ans.data_num;
    ans.data_num = nullptr;
    return true;
}
