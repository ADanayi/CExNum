#include "cexnum.h"

CExNum  CExNum::fact(CExNum Num)
{
    CExNum ans{};
    if (Num == predef::zero)
    {
        ans = predef::zero;
        return std::move(ans);
    }
    if (Num.data_sign == 1)
    {
        ans = predef::onem;
        return std::move(ans);
    }
    while (predef::zero < Num)
    {
        ans = ans * Num;
        Num--;
    }
    return std::move(ans);
}

CExNum  CExNum::fib(CExNum Num)
{
    if (predef::zero >= Num)
    {
        CExNum ans{};
        return std::move(ans);
    }
    if ( (predef::one == Num) || (predef::two == Num) )
    {
        CExNum ans{predef::one};
        std::move(ans);
    }
    return std::move( fib(Num-1) +  fib(Num-2) );
}
