
//  ==========================================================================
/// @file   mpfrInterface.cc
/// @author Yann Kurzo
/// @date   June 17, 2015, 8:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  Create a class for interfacing the mpfr library
//  ==========================================================================

#include "mpfrInterface.h"

#if(USE_MPFR_LIBRARY == 1)

#include "util.h"

#include <string>

using namespace std;

namespace MPFR
{
    static mpfr_rnd_t roundingMethod_m = MPFR_RNDN;

    mpfr_rnd_t getRoundingMethod(void)
    {
        return roundingMethod_m;
    }

    void setRoundingMethod(mpfr_rnd_t roundingMethod)
    {
        roundingMethod_m = roundingMethod;
    }
    
    unsigned int getPrecision(void)
    {
        return mpfr_get_default_prec();
    }
    
    void setPrecision(unsigned int precision)
    {
        mpfr_set_default_prec(precision);
    }
}

Mpfr::Mpfr(void)
{
    init("0");
}

Mpfr::Mpfr(const char *str)
{
    init(str);
}

Mpfr::Mpfr(const std::string& str)
{
    init(str.c_str());
}

Mpfr::Mpfr(double n)
{
    init(to_string(n).c_str());
}

Mpfr::~Mpfr(void)
{
    mpfr_clear(n_m);
}

Mpfr::Mpfr(Mpfr const& mpfr)
{
    mpfr_init_set(n_m, mpfr.n_m, MPFR::roundingMethod_m);
}

void Mpfr::init(const char *str)
{
    mpfr_init(n_m);
    mpfr_set_str(n_m, str, 10, MPFR::roundingMethod_m);
}

Mpfr& Mpfr::operator=(Mpfr const& mpfr)
{
    if(this != &mpfr)
    {
        mpfr_set(n_m, mpfr.n_m, MPFR::roundingMethod_m);
    }
    return *this;
}

Mpfr& Mpfr::operator=(double n)
{
    mpfr_set_str(n_m, to_string(n).c_str(), 10, MPFR::roundingMethod_m);
    return *this;
}

Mpfr& Mpfr::operator+=(const Mpfr& mpfr)
{
    mpfr_add(n_m, n_m, mpfr.n_m, MPFR::roundingMethod_m);
    return *this;
}

Mpfr operator+(Mpfr const& mpfr1, Mpfr const& mpfr2)
{
    Mpfr result(mpfr1);
    result += mpfr2;
    return result;
}

Mpfr& Mpfr::operator-=(const Mpfr& mpfr)
{
    mpfr_sub(n_m, n_m, mpfr.n_m, MPFR::roundingMethod_m);
    return *this;
}

Mpfr operator-(Mpfr const& mpfr1, Mpfr const& mpfr2)
{
    Mpfr result(mpfr1);
    result -= mpfr2;
    return result;
}

Mpfr& Mpfr::operator*=(const Mpfr& mpfr)
{
    mpfr_mul(n_m, n_m, mpfr.n_m, MPFR::roundingMethod_m);
    return *this;
}

Mpfr operator*(Mpfr const& mpfr1, Mpfr const& mpfr2)
{
    Mpfr result(mpfr1);
    result *= mpfr2;
    return result;
}

Mpfr& Mpfr::operator/=(const Mpfr& mpfr)
{
    mpfr_div(n_m, n_m, mpfr.n_m, MPFR::roundingMethod_m);
    return *this;
}

Mpfr operator/(Mpfr const& mpfr1, Mpfr const& mpfr2)
{
    Mpfr result(mpfr1);
    result /= mpfr2;
    return result;
}

Mpfr& Mpfr::operator^=(const Mpfr& mpfr)
{
    mpfr_pow(n_m, n_m, mpfr.n_m, MPFR::roundingMethod_m);
    return *this;
}

Mpfr operator^(Mpfr const& mpfr1, Mpfr const& mpfr2)
{
    Mpfr result(mpfr1);
    result ^= mpfr2;
    return result;
}

Mpfr& Mpfr::operator%=(const Mpfr& mpfr)
{
    mpfr_remainder(n_m, n_m, mpfr.n_m, MPFR::roundingMethod_m);
    return *this;
}

Mpfr operator%(Mpfr const& mpfr1, Mpfr const& mpfr2)
{
    Mpfr result(mpfr1);
    result %= mpfr2;
    return result;
}
#include <iostream>
void Mpfr::display(std::ostream& flow) const
{
    // Basic checks
    if(mpfr_inf_p(n_m) != 0)
    {
        if(mpfr_signbit(n_m) != 0)
        {
            flow << "-";
        }
        flow << "inf";
    }
    else if(mpfr_nan_p(n_m) != 0)
    {
        flow << "nan";
    }
    else
    {
        // Get number from mpfr library
        char *s = NULL;
        mpfr_exp_t exp;
        s = mpfr_get_str(s, &exp, 10, 0, n_m, MPFR::roundingMethod_m);

        // Create string and clear
        string digits(s);
        mpfr_free_str(s);

        // Check sign
        unsigned long int sign = (digits.at(0) == '-');
        if(sign != 0)
        {
            flow << "-";
        }
        
        // If bigger than 1
        if(exp > 0)
        {
            unsigned long int comma = static_cast<unsigned long int>(exp) + sign;
            
            // Check ending zeroes
            unsigned long int end = digits.size()-1;
            while(digits.at(end) == '0' && end >= comma)
                --end;
            
            // If there is nothing after the comma
            if(comma > end)
                flow << digits.substr(sign, comma-sign);
            else
                flow << digits.substr(sign, comma-sign) << "." << digits.substr(comma, end-sign);
        }
        // Otherwise
        else
        {
            flow << "0.";
            for(unsigned long int i=0; i<static_cast<unsigned long int>(-exp); ++i)
                flow << "0";
            
            // Check ending zeroes
            unsigned long int end = digits.size()-1;
            while(digits.at(end) == '0' && end > 0)
                --end;

            // Print after the comma
            flow << digits.substr(sign, end-sign+1);
        }
    }
}

std::ostream& operator<<(std::ostream& flow, Mpfr const& n)
{
    n.display(flow);
    return flow;
}

#endif


