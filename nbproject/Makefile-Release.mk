#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU_4.8.2-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/analyze.o \
	${OBJECTDIR}/src/application.o \
	${OBJECTDIR}/src/command.o \
	${OBJECTDIR}/src/externalFunctionsDouble.o \
	${OBJECTDIR}/src/externalFunctionsMpfr.o \
	${OBJECTDIR}/src/function.o \
	${OBJECTDIR}/src/lexer.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/mpfrInterface.o \
	${OBJECTDIR}/src/parserExec.o \
	${OBJECTDIR}/src/token.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wzero-as-null-pointer-constant -Wuseless-cast
CXXFLAGS=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wzero-as-null-pointer-constant -Wuseless-cast

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk calculator

calculator: ${OBJECTFILES}
	${LINK.cc} -o calculator ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/analyze.o: src/analyze.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/analyze.o src/analyze.cc

${OBJECTDIR}/src/application.o: src/application.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/application.o src/application.cc

${OBJECTDIR}/src/command.o: src/command.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/command.o src/command.cc

${OBJECTDIR}/src/externalFunctionsDouble.o: src/externalFunctionsDouble.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/externalFunctionsDouble.o src/externalFunctionsDouble.cc

${OBJECTDIR}/src/externalFunctionsMpfr.o: src/externalFunctionsMpfr.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/externalFunctionsMpfr.o src/externalFunctionsMpfr.cc

${OBJECTDIR}/src/function.o: src/function.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/function.o src/function.cc

${OBJECTDIR}/src/lexer.o: src/lexer.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/lexer.o src/lexer.cc

${OBJECTDIR}/src/main.o: src/main.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cc

${OBJECTDIR}/src/mpfrInterface.o: src/mpfrInterface.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/mpfrInterface.o src/mpfrInterface.cc

${OBJECTDIR}/src/parserExec.o: src/parserExec.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/parserExec.o src/parserExec.cc

${OBJECTDIR}/src/token.o: src/token.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/token.o src/token.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} calculator

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
