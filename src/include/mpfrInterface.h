
//  ==========================================================================
/// @file   mpfrInterface.h
/// @author Yann Kurzo
/// @date   June 17, 2015, 8:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  Create a class for interfacing the mpfr library
//  ==========================================================================

#ifndef MPFRINTERFACE_H
#define	MPFRINTERFACE_H

#include "config.h"

#if(USE_DOUBLE_TYPE == 1)
    typedef double calculType_t;
#elif(USE_MPFR_LIBRARY == 1)

#include "mpfr.h"
#include <ostream>

/// @brief  
class Mpfr
{
    private:
        mpfr_t n_m;
        
    public:
        /// @brief  Default constructor
        Mpfr(void);
        
        /// @brief  Constructor from a string
        Mpfr(const char *str);
        
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
        
        /// @brief  Set mpfr default precision
        static void setPrecision(unsigned int precision);
        
        /// @brief  Used to display the number on standard output
        void display(std::ostream& flow) const;
        
    private:
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

// Set the type
typedef Mpfr calculType_t;

#endif

#endif	/* MPFRINTERFACE_H */

