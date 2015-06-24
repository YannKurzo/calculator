# Executable
bin_PROGRAMS = calculator

# Source files
calculator_SOURCES = main.cc
calculator_SOURCES += analyze.cc
calculator_SOURCES += application.cc
calculator_SOURCES += command.cc
calculator_SOURCES += externalFunctionsDouble.cc
calculator_SOURCES += externalFunctionsMpfr.cc
calculator_SOURCES += function.cc
calculator_SOURCES += lexer.cc
calculator_SOURCES += mpfrInterface.cc
calculator_SOURCES += parserExec.cc
calculator_SOURCES += token.cc
calculator_SOURCES += util.cc

# Include files
AM_CPPFLAGS = -I$(srcdir)/include

# C++11 standard
AM_CPPFLAGS += -std=c++11

# Warning and errors
AM_CPPFLAGS += -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy
AM_CPPFLAGS += -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations
AM_CPPFLAGS += -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual
AM_CPPFLAGS += -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel
AM_CPPFLAGS += -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
AM_CPPFLAGS += -Wzero-as-null-pointer-constant -Wuseless-cast

# Check mpfr library
if MPFRINSTALLED
    AM_LDFLAGS = -lmpfr -lgmp
endif
