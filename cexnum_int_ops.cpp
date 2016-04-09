#include "cexnum.h"

bool    operator <  (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp < b);
}

bool    operator <  (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp < b);
}


bool    operator == (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp == b);
}

bool    operator != (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp != b);
}

bool    operator >  (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp > b);
}

bool    operator <= (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp <= b);
}

bool    operator >= (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp >= b);
}



bool    operator == (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp == b);
}

bool    operator != (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp != b);
}

bool    operator >  (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp > b);
}

bool    operator <= (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp <= b);
}

bool    operator >= (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp >= b);
}


CExNum  operator + (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp + b);
}

CExNum  operator - (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp - b);
}

CExNum  operator * (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp * b);
}

/*CExNum  operator / (const int & a, const CExNum& b)//not done
{
    CExNum temp{a};
    return (temp / b);
}

CExNum  operator % (const int & a, const CExNum& b) //not done
{
    CExNum temp{a};
    return (temp % b);
}*/

CExNum  operator ^ (const int & a, const CExNum& b)
{
    CExNum temp{a};
    return (temp ^ b);
}

CExNum  operator + (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp + b);
}

CExNum  operator - (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp - b);
}

CExNum  operator * (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp * b);
}

/* CExNum  operator / (const int & a, CExNum&& b) //not done
{
    CExNum temp{a};
    return (temp / b);
}

CExNum  operator % (const int & a, CExNum&& b) //not done
{
    CExNum temp{a};
    return (temp % b);
}*/

CExNum  operator ^ (const int & a, CExNum&& b)
{
    CExNum temp{a};
    return (temp ^ b);
}


