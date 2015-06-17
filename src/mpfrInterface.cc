
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

#include <string>

using namespace std;

Mpfr::Mpfr(void)
{
    init("0");
}

Mpfr::Mpfr(const char *str)
{
    init(str);
}

Mpfr::~Mpfr(void)
{
    mpfr_clear(n_m);
}

Mpfr::Mpfr(Mpfr const& mpfr)
{
    mpfr_init_set(n_m, mpfr.n_m, MPFR_RNDN);
}

void Mpfr::init(const char *str)
{
    mpfr_init(n_m);
    mpfr_set_str(n_m, str, 10, MPFR_RNDN);
}

Mpfr& Mpfr::operator=(Mpfr const& mpfr)
{
    if(this != &mpfr)
    {
        mpfr_set(n_m, mpfr.n_m, MPFR_RNDN);
    }
    return *this;
}

Mpfr& Mpfr::operator+=(const Mpfr& mpfr)
{
    mpfr_add(n_m, n_m, mpfr.n_m, MPFR_RNDN);
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
    mpfr_sub(n_m, n_m, mpfr.n_m, MPFR_RNDN);
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
    mpfr_mul(n_m, n_m, mpfr.n_m, MPFR_RNDN);
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
    mpfr_div(n_m, n_m, mpfr.n_m, MPFR_RNDN);
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
    mpfr_pow(n_m, n_m, mpfr.n_m, MPFR_RNDN);
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
    mpfr_remainder(n_m, n_m, mpfr.n_m, MPFR_RNDN);
    return *this;
}

Mpfr operator%(Mpfr const& mpfr1, Mpfr const& mpfr2)
{
    Mpfr result(mpfr1);
    result %= mpfr2;
    return result;
}

void Mpfr::setPrecision(unsigned int precision)
{
    mpfr_set_default_prec(precision);
}

void Mpfr::display(std::ostream& flow) const
{
    // Get number from mpfr library
    char *s = NULL;
    mpfr_exp_t exp;
    s = mpfr_get_str(s, &exp, 10, 0, n_m, MPFR_RNDN);
    
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
        flow << digits.substr(sign, comma-sign) << "." << digits.substr(comma, digits.size());
    }
    // Otherwise
    else
    {
        flow << "0.";
        for(unsigned long int i=0; i<static_cast<unsigned long int>(-exp); ++i)
            flow << "0";
        
        flow << digits.substr(sign, digits.size());
    }
    
}

std::ostream& operator<<(std::ostream& flow, Mpfr const& n)
{
    n.display(flow);
    return flow;
}

#endif


