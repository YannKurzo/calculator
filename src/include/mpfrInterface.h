
//  ==========================================================================
/// @file   mpfrInterface.h
/// @author Yann Kurzo
/// @date   June 17, 2015, 8:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Mpfr class. This file defines with a typedef
///         either double or Mpfr depending on the config.h file for doing
///         the calculations.
//  ==========================================================================

#ifndef MPFRINTERFACE_H
#define	MPFRINTERFACE_H

#include "config.h"

#if(USE_DOUBLE_TYPE == 1)

/// @brief  Calculation type
typedef double calculType_t;

namespace MPFR
{
    #define UNUSED(x) (void)(x)

    /// @brief  Dummy function for compilation
    static int getRoundingMethod(void) {return 0;}
    
    /// @brief  Dummy function for compilation
    static void setRoundingMethod(unsigned int roundingMethod) {UNUSED(roundingMethod);}
    
    /// @brief  Get the double precision
    /// @return Actual precision in number of bits
    static unsigned int getPrecision(void) {return 53;}

    /// @brief  Dummy function for compilation
    static void setPrecision(unsigned int precision) {UNUSED(precision);}
}
    
#elif(USE_MPFR_LIBRARY == 1)

#include "mpfr.h"
#include <ostream>

namespace MPFR
{
    /// @brief  Get the actual rounding method
    /// @return Rounding method
    mpfr_rnd_t getRoundingMethod(void);

    /// @brief  Set the rounding method
    /// @param  roundingMethod Rounding Method
    void setRoundingMethod(mpfr_rnd_t roundingMethod);

    /// @brief  Get mpfr actual precision
    /// @return Actual precision in number of bits
    unsigned int getPrecision(void);

    /// @brief  Set mpfr default precision
    /// @param  precision Precision in number of bits
    void setPrecision(unsigned int precision);
}

/// @brief  This class interfaces the mpfr library
class Mpfr
{
    public:
        /// Used for calculation
        mpfr_t n_m;
        
    public:
        /// @brief  Default constructor
        Mpfr(void);
        
        /// @brief  Constructor from a string
        Mpfr(const char *str);
        
        /// @brief  Constructor from a string
        Mpfr(const std::string& str);
        
        /// @brief  Constructor from a double
        Mpfr(double n);
        
        /// @brief  Copy constructor
        Mpfr(Mpfr const& mpfr);
        
        /// @brief  Destructor
        ~Mpfr(void);
        
        /// @brief  Assignment operator
        Mpfr& operator=(Mpfr const& mpfr);

        /// @brief  Assignment operator
        Mpfr& operator=(double n);
        
        /// @brief  += operator
        Mpfr& operator+=(const Mpfr& mpfr);
        
        /// @brief  -= operator
        Mpfr& operator-=(const Mpfr& mpfr);
        
        /// @brief  *= operator
        Mpfr& operator*=(const Mpfr& mpfr);
        
        /// @brief  /= operator
        Mpfr& operator/=(const Mpfr& mpfr);
        
        /// @brief  ^= operator
        Mpfr& operator^=(const Mpfr& mpfr);
        
        /// @brief  %= operator
        Mpfr& operator%=(const Mpfr& mpfr);
        
        /// @brief  Used to display the number on standard output
        void display(std::ostream& flow) const;
        
    private:
        /// @brief  Initialize from a string
        /// @param  str String
        void init(const char *str);
};

/// @brief  += operator
Mpfr operator+(Mpfr const& mpfr1, Mpfr const& mpfr2);

/// @brief  -= operator
Mpfr operator-(Mpfr const& mpfr1, Mpfr const& mpfr2);

/// @brief  *= operator
Mpfr operator*(Mpfr const& mpfr1, Mpfr const& mpfr2);

/// @brief  /= operator
Mpfr operator/(Mpfr const& mpfr1, Mpfr const& mpfr2);

/// @brief  ^= operator
Mpfr operator^(Mpfr const& mpfr1, Mpfr const& mpfr2);

/// @brief  %= operator
Mpfr operator%(Mpfr const& mpfr1, Mpfr const& mpfr2);

/// @cond STANDARD_OUTPUT
std::ostream& operator<<(std::ostream& flow, Mpfr const& n);
/// @endcond STANDARD_OUTPUT

/// @brief  Calculation type
typedef Mpfr calculType_t;

#endif  /* USE_MPFR_LIBRARY */

#endif	/* MPFRINTERFACE_H */

