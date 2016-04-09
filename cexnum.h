// In the name of God
// This class is made to hold all the difinitions
// and operational functions of the application.
// Created by ADanayi
// Advanced Programming 2016
// HW4 Q8

#define MAXDIG 1000
#include <iostream>
#include <string>

#ifndef CEXNUM_H
#define CEXNUM_H
#endif // CEXNUM_H

// C Extended Number = CExNum

class CExNum{
public:
    CExNum(const std::string);
    CExNum(int num);
    CExNum(const CExNum &b);
    CExNum(CExNum &&b);
    CExNum();
    ~CExNum();
    void    disp() const;
    void    inp();
    void    comp9();
    void    comp10();
    void    inc();
    void    dec();
    int     getLen() const;
    int     calcLen();
    bool    getSign() const;
    void    negate();
    char*   getNum() const;
    CExNum  fact(CExNum);
    CExNum  fib(CExNum);

    CExNum& operator = (const CExNum &b);
    CExNum& operator = (CExNum &&b);
    CExNum& operator = (const int &a);

    CExNum  operator + (const CExNum& b) const;
    CExNum  operator - (const CExNum& b) const;
    CExNum  operator * (const CExNum& b) const;
    CExNum  operator / (const CExNum& b) const; //not done
    CExNum  operator % (const CExNum& b) const; //not done
    CExNum  operator ^ (const CExNum& b) const;

    CExNum  operator + (CExNum&& b) const;
    CExNum  operator - (CExNum&& b) const;
    CExNum  operator * (CExNum&& b) const;
    CExNum  operator / (CExNum&& b) const; //not done
    CExNum  operator % (CExNum&& b) const; //not done
    CExNum  operator ^ (CExNum&& b) const;

    CExNum  operator - (const int &a) const;
    CExNum  operator + (const int &a) const;
    CExNum  operator ^ (const int b ) const;
    CExNum  operator / (const int &b) const; //not done
    CExNum  operator % (const int &b) const; //not done

    CExNum  operator -  ();
    CExNum& operator ++ ();
    CExNum& operator ++ (int);
    CExNum& operator -- ();
    CExNum& operator -- (int);

    CExNum& operator << (int a);
    CExNum& operator >> (int a);

    bool    operator <  (const CExNum& b) const;
    bool    operator == (const CExNum& b) const;
    bool    operator != (const CExNum& b) const;
    bool    operator >  (const CExNum& b) const;
    bool    operator <= (const CExNum& b) const;
    bool    operator >= (const CExNum& b) const;

    bool    operator <  (const int& b) const;
    bool    operator == (const int& b) const;
    bool    operator != (const int& b) const;
    bool    operator >  (const int& b) const;
    bool    operator <= (const int& b) const;
    bool    operator >= (const int& b) const;

    bool    operator <  (CExNum&& b) const;
    bool    operator == (CExNum&& b) const;
    bool    operator != (CExNum&& b) const;
    bool    operator >  (CExNum&& b) const;
    bool    operator <= (CExNum&& b) const;
    bool    operator >= (CExNum&& b) const;

    char    operator [] (const int& a) const;

    void    test(CExNum& a, CExNum& b)
    {
        CExNum t1{a};
        CExNum t2{b};
        func_posOps_humanDiv(t1,t2);
        t1.disp();
    }

private:
    char *data_num {nullptr};
    int  data_len;
    bool data_sign; // positive == false, negative == true

    bool   func_posOps_humanMul(CExNum& a, CExNum& b) const;
    bool   func_posOps_humanDiv(CExNum& a, CExNum& b) const;

    // bool data_zero
    // bool data_one (abs)

};

// Functions used in Class functions
char func_ch_add (const char &a, const char &b,
                  bool &res);
char func_ch_mul (const char &a, const char &b,
                   int &res);
bool func_ch_MUL(char *num, const int & len, char & ch);
int  func_char2int (const char& ch);
char func_int2char (const int& num);
void func_int2data (const int &a, bool& data_sign,
                    int &data_len, char* data_num = nullptr); // done
bool func_posOps_add(char* num1,
                     char* num2,
                     int& len1,
                     const int& len2);    // num 1 will be replaced with the ans
                                                // returns E
void func_posOps_seqMul(CExNum& a,CExNum& b);
   // returns E

CExNum  func_posOps_divide(CExNum& a, CExNum& b, CExNum& res);
// returns a/bx
// res = a%b

void func_num_comp(char* num1, int& len, bool calclen = false);
int  func_num_calcLen(char *num);

// Another operations: (first int)
bool    operator <  (const int & a, CExNum&& b);
bool    operator == (const int & a, CExNum&& b);
bool    operator != (const int & a, CExNum&& b);
bool    operator >  (const int & a, CExNum&& b);
bool    operator <= (const int & a, CExNum&& b);
bool    operator >= (const int & a, CExNum&& b);

bool    operator <  (const int & a, const CExNum& b);
bool    operator == (const int & a, const CExNum& b);
bool    operator != (const int & a, const CExNum& b);
bool    operator >  (const int & a, const CExNum& b);
bool    operator <= (const int & a, const CExNum& b);
bool    operator >= (const int & a, const CExNum& b);

CExNum  operator + (const int & a, const CExNum& b);
CExNum  operator - (const int & a, const CExNum& b);
CExNum  operator * (const int & a, const CExNum& b);
CExNum  operator / (const int & a, const CExNum& b); //not done
CExNum  operator % (const int & a, const CExNum& b); //not done
CExNum  operator ^ (const int & a, const CExNum& b);

CExNum  operator + (const int & a, CExNum&& b);
CExNum  operator - (const int & a, CExNum&& b);
CExNum  operator * (const int & a, CExNum&& b);
CExNum  operator / (const int & a, CExNum&& b); //not done
CExNum  operator % (const int & a, CExNum&& b); //not done
CExNum  operator ^ (const int & a, CExNum&& b);

//  Some special objects to be pre-processed:
#ifndef PREDEF
#define PREDEF

namespace predef
{
extern const CExNum one;
extern const CExNum onem;
extern const CExNum two;
extern const CExNum twom;
extern const CExNum ten;
extern const CExNum tenm;
extern const CExNum zero;
}

#endif
