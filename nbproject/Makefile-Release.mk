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
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/src/analyse.o \
	${OBJECTDIR}/src/binTree.o \
	${OBJECTDIR}/src/exec.o \
	${OBJECTDIR}/src/externalFunctions.o \
	${OBJECTDIR}/src/function.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/token.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/calculator

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/calculator: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/calculator ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/analyse.o: src/analyse.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/analyse.o src/analyse.cc

${OBJECTDIR}/src/binTree.o: src/binTree.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/binTree.o src/binTree.cc

${OBJECTDIR}/src/exec.o: src/exec.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/exec.o src/exec.cc

${OBJECTDIR}/src/externalFunctions.o: src/externalFunctions.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/externalFunctions.o src/externalFunctions.cc

${OBJECTDIR}/src/function.o: src/function.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/function.o src/function.cc

${OBJECTDIR}/src/main.o: src/main.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cc

${OBJECTDIR}/src/token.o: src/token.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Isrc/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/token.o src/token.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/calculator

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
