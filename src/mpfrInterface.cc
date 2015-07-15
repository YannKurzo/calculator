
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
#include <cstdlib>

using namespace std;

namespace MPFR
{
    // Rounding
    static mpfr_rnd_t roundingMethod_m = MPFR_RNDN;

    mpfr_rnd_t getRoundingMethod(void)
    {
        return roundingMethod_m;
    }

    void setRoundingMethod(mpfr_rnd_t roundingMethod)
    {
        roundingMethod_m = roundingMethod;
    }
    
    // Precision
    unsigned int getPrecision(void)
    {
        return mpfr_get_default_prec();
    }
    
    void setPrecision(unsigned int precision)
    {
        mpfr_set_default_prec(precision);
    }
    
    // Display mode
    static bool scientificDisplayMode_m = false;
    
    bool getDisplayMode(void)
    {
        return scientificDisplayMode_m;
    }
    
    void setDisplayMode(bool scientific)
    {
        scientificDisplayMode_m = scientific;
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
        unsigned int sign = (digits.at(0) == '-');
        
        // Erase zeros
        while(digits.size()-1 != 0 && digits.at(digits.size()-1) == '0')
        {
            digits.erase(digits.end()-1);
        }
        
        // Print 0
        if(digits == "0")
        {
            flow << "0";
        }
        else
        {
            // Print in exponential format
            if(MPFR::scientificDisplayMode_m)
            {
                // Check if number needs a point
                if(digits.size() > sign + 1)
                {
                    digits.insert(sign + 1, ".");
                }
                // Check if the exponent is needed
                if(exp != 1)
                {
                    digits.insert(digits.size(), "e" + to_string(exp - 1));
                }
                // Print
                flow << digits;
            }
            // Print in normal format
            else
            {
                // Few variables
                int signedSize = digits.size();
                int signedSign = static_cast<int>(sign);
                
                // Check if number is below 1
                if(exp < 1)
                {
                    // Print minus if necessary
                    if(digits.at(0) == '-')
                    {
                        flow << "-";
                        digits.erase(0, 1);
                    }
                    
                    // Print beggining
                    flow << "0.";
                    
                    // Add zeroes at the beginning
                    for(int i=exp; i < 0; ++i)
                    {
                        flow << "0";
                    }
                }
                // Check if number needs a point
                else if(signedSize > exp)
                {
                    digits.insert(static_cast<unsigned int>(exp + signedSign), ".");
                }
                
                // Print digits
                flow << digits;
                
                // Add zeroes at the end
                for(unsigned int i=digits.size(); i < exp + sign; ++i)
                {
                    flow << "0";
                }
            }
        }
    }
}

std::ostream& operator<<(std::ostream& flow, Mpfr const& n)
{
    n.display(flow);
    return flow;
}

#endif


