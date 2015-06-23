bin_PROGRAMS = calculator

AM_CPPFLAGS = -I$(srcdir)/include
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wzero-as-null-pointer-constant -Wuseless-cast

#if MPFRINSTALLED
 #   AM_LDFLAGS = -lmpfr -lgmp
#endif

calculator_SOURCES = main.cc analyze.cc application.cc command.cc externalFunctionsDouble.cc externalFunctionsMpfr.cc function.cc lexer.cc mpfrInterface.cc parserExec.cc token.cc
