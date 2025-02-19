#Makefile for the C part of Gforth

#Copyright (C) 1995,1996,1997,1998,2000,2003,2006,2007,2008 Free Software Foundation, Inc.

#This file is part of Gforth.

#Gforth is free software; you can redistribute it and/or
#modify it under the terms of the GNU General Public License
#as published by the Free Software Foundation, either version 3
#of the License, or (at your option) any later version.

#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.#See the
#GNU General Public License for more details.

#You should have received a copy of the GNU General Public License
#along with this program. If not, see http://www.gnu.org/licenses/.

# ------------- gforth version

VERSION =0.7.3
DOSVERSION=`echo $VERSION|sed 's/\.//g'`
EXE=

# ------------- System specific variables

machine=amd64
kernel_fi = kernl64l.fi
include_fi = kernl64l.fi
# this is the type of machine
# used to extend the include path with ./arch/$machine
# so we could include a machine specific
# machine.h file

PATHSEP = :

osclass = @OSCLASS@

EC = 

# ------------- Utility programs

SHELL	= /bin/sh
RM	= rm
RMTREE	= rm -rf
CP	= cp -p
TAR	= tar cf -
GCC	= gcc
BOOTFORTH	= ../preforth
CC	= $(GCC)
LD	= $(GCC:gcc=ld)
AS	= $(GCC:gcc=as)
STRIP	= strip
GCCLD	= $(GCC)

FORTHPATH = .$(PATHSEP)$(libdir)/gforth/site-forth$(PATHSEP)$(datadir)/gforth/site-forth$(PATHSEP)$(libdir)/gforth/$(VERSION)$(PATHSEP)$(datadir)/gforth/$(VERSION)

# ------------  Source and Build directories

top_srcdir = ..
top_builddir = ..

# ------------	Install directories


prefix = /usr/local
exec_prefix = ${prefix}
srcdir = .
bindir = ${exec_prefix}/bin
#read-only architecture-independent files
datadir = ${prefix}/share
#read-only architecture-dependent non-ascii files
libdir = ${exec_prefix}/lib
infodir = ${prefix}/share/info
mandir = ${prefix}/share/man
man1dir= $(mandir)/man1
man1ext= .1

# ------------- ltdl variables

LTDLDEPS = 
LTDLINCL = 
LIBLTDL  = 

# ------------- Compiler Flags

XCFLAGS	= -O2
XDEFINES = -DHAVE_CONFIG_H
SWITCHES = $(XCFLAGS) $(XDEFINES) $(OPTDEFINES)
#use -fno-inline to avoid register problems with asinh, atanh on gcc-3.3 on 386
ENGINE_FLAGS =  -fno-gcse -fno-strict-aliasing -fno-crossjumping -fno-reorder-blocks -falign-labels=1 -falign-loops=1 -falign-jumps=1 -fno-defer-pop -fcaller-saves -fno-inline -fno-reorder-blocks
DEBUGFLAG = 
CFLAGS	= $(DEBUGFLAG) -I$(srcdir)/../arch/$(machine) -I. -Wall $(SWITCHES) -DDEFAULTPATH='"$(FORTHPATH)"' $(LTDLINCL)
CFLAGS2	= $(DEBUGFLAG) -I$(srcdir)/../arch/$(machine) -I. -Wall $(SWITCHES) -DDEFAULTPATH='"$(FORTHPATH)"' $(LTDLINCL)
CPPFLAGS=
FORTHKFLAGS= --die-on-signal -p "..$(PATHSEP)$(srcdir)" -i ../$(kernel_fi)
FORTHK	= ../gforth $(FORTHKFLAGS)
FORTH	= $(BOOTFORTH) --die-on-signal

#John Wavrik should use -Xlinker -N to get a writable text (executable)
XLDFLAGS =  -export-dynamic
LDFLAGS =  $(DEBUGFLAG) $(XLDFLAGS)
LDLIBS  = -lm  

AOBJECTS = io.o signals.o support$(OPT).o  ${LIBOBJDIR}pow10$U.o $(OPTOBJECTS)



OBJECTS = engine$(OPT).o engine2$(OPT).o main$(OPT).o
OBJECTS_NATIVE = engine-native$(OPT).o engine-native2$(OPT).o engine-native3$(OPT).o main-native$(OPT).o
OBJECTS_FAST = engine-fast$(OPT).o engine-fast2$(OPT).o main-fast$(OPT).o
OBJECTS_ITC = engine-itc$(OPT).o main-itc$(OPT).o
OBJECTS_DITC = engine-ditc$(OPT).o main-ditc$(OPT).o
OBJECTS_PROF = engine-prof$(OPT).o main-prof$(OPT).o
OBJECTS_FI =  engine$(OPT).o main-fi$(OPT).o

# In engine subdirectory there are (or should be) only files that belong to
# our engine, so we can make life easy
DEPS =  config.h forth.h io.h $(srcdir)/../arch/$(machine)/*.[h]
ENGINE_DEPS = engine.c $(DEPS) prim_lab.i prim.i  fnmatch.h threaded.h
MAIN_DEPS = main.c $(DEPS) prim_superend.i prim_num.i prim_grp.i costs.i super2.i
ENGINE_FAST_DEPS = engine.c $(DEPS) prim_lab-fast.i prim-fast.i fnmatch.h threaded.h
MAIN_FAST_DEPS = main.c $(DEPS) prim_superend-fast.i prim_num-fast.i prim_grp-fast.i costs-fast.i super2-fast.i

#some makes don't do the -o $@ correctly, so we help them
.c.o:
	$(GCC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.s.o:
	$(GCC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

support$(OPT).o: support.c config.h forth.h longlong.h
	$(GCC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $(srcdir)/support.c

strtol.o: strtol.c ansidecl.h

fnmatch.o: fnmatch.c fnmatch.h

getopt1.o: getopt1.c getopt.h

getopt.o: getopt.c getopt.h

gforth$(OPT)$(EC)$(EXE):	$(OBJECTS) $(AOBJECTS) $(LTDLDEPS)
	$(GCCLD) $(LDFLAGS) $(OBJECTS) $(AOBJECTS) $(LDLIBS) -o $@

gforth-native$(OPT)$(EC)$(EXE):	$(OBJECTS_NATIVE) $(AOBJECTS) $(LTDLDEPS)
	$(GCCLD) $(LDFLAGS) $(OBJECTS_NATIVE) $(AOBJECTS) $(LDLIBS) -o $@

gforth-fast$(OPT)$(EC)$(EXE):	$(OBJECTS_FAST) $(AOBJECTS) $(LTDLDEPS)
	$(GCCLD) $(LDFLAGS) $(OBJECTS_FAST) $(AOBJECTS) $(LDLIBS) -o $@

gforth-itc$(OPT)$(EC)$(EXE):	$(OBJECTS_ITC) $(AOBJECTS) $(LTDLDEPS)
	$(GCCLD) $(LDFLAGS) $(OBJECTS_ITC) $(AOBJECTS) $(LDLIBS) -o $@

gforth-ditc$(OPT)$(EC)$(EXE): $(OBJECTS_DITC) $(AOBJECTS) $(LTDLDEPS)
	$(GCCLD) $(LDFLAGS) $(OBJECTS_DITC) $(AOBJECTS) $(LDLIBS) -o $@

gforth-prof$(OPT)$(EC)$(EXE): $(OBJECTS_PROF) $(AOBJECTS) $(LTDLDEPS) profile$(OPT).o
	$(GCCLD) $(LDFLAGS) $(OBJECTS_PROF) $(AOBJECTS) profile$(OPT).o $(LDLIBS) -o $@

gforth-fi$(OPT)$(EC)$(EXE):	$(OBJECTS_FI) $(AOBJECTS) $(LTDLDEPS)
	$(GCCLD) $(LDFLAGS) $(OBJECTS_FI) $(AOBJECTS) $(LDLIBS) -o $@

engine.s:	$(ENGINE_FAST_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -S $(srcdir)/engine.c

engine$(OPT).o:	$(ENGINE_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DGFORTH_DEBUGGING -o $@ -c $(srcdir)/engine.c

engine2$(OPT).o:	$(ENGINE_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DGFORTH_DEBUGGING -DENGINE=2 -o $@ -c $(srcdir)/engine.c

engine-native$(OPT).o:$(ENGINE_FAST_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DNO_IP -o $@ -c $(srcdir)/engine.c

engine-native2$(OPT).o:$(ENGINE_FAST_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DNO_IP -DENGINE=2 -o $@ -c $(srcdir)/engine.c

engine-native3$(OPT).o:$(ENGINE_FAST_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DNO_IP -DENGINE=3 -o $@ -c $(srcdir)/engine.c

engine-fast$(OPT).o:	$(ENGINE_FAST_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -o $@ -c $(srcdir)/engine.c

engine-fast2$(OPT).o:	$(ENGINE_FAST_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DENGINE=2 -o $@ -c $(srcdir)/engine.c

engine-itc$(OPT).o:	$(ENGINE_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DINDIRECT_THREADED -DGFORTH_DEBUGGING -o $@ -c $(srcdir)/engine.c

engine-ditc$(OPT).o:	$(ENGINE_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DDOUBLY_INDIRECT -o $@ -c $(srcdir)/engine.c

engine-prof$(OPT).o:	$(ENGINE_DEPS)
		$(GCC) $(CFLAGS2) $(CPPFLAGS) $(ENGINE_FLAGS) -DVM_PROFILING -o $@ -c $(srcdir)/engine.c

main$(OPT).o:		$(MAIN_DEPS) 
		$(GCC) $(CFLAGS) $(CPPFLAGS) -DGFORTH_DEBUGGING  -o $@ -c $(srcdir)/main.c

main-native$(OPT).o:	$(MAIN_FAST_DEPS) 
		$(GCC) $(CFLAGS) $(CPPFLAGS) -DNO_IP -o $@ -c $(srcdir)/main.c

main-fast$(OPT).o:	$(MAIN_FAST_DEPS) 
		$(GCC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $(srcdir)/main.c

main-itc$(OPT).o:	$(MAIN_DEPS) 
		$(GCC) $(CFLAGS) $(CPPFLAGS) -DINDIRECT_THREADED -DGFORTH_DEBUGGING -o $@ -c $(srcdir)/main.c

main-ditc$(OPT).o:	$(MAIN_DEPS)
		$(GCC) $(CFLAGS) $(CPPFLAGS) -DDOUBLY_INDIRECT -o $@ -c $(srcdir)/main.c

main-prof$(OPT).o:	$(MAIN_DEPS)
		$(GCC) $(CFLAGS) $(CPPFLAGS) -DVM_PROFILING -o $@ -c $(srcdir)/main.c

main-fi$(OPT).o:	$(MAIN_DEPS)
		$(GCC) $(CFLAGS) $(CPPFLAGS) -DINCLUDE_IMAGE -o $@ -c $(srcdir)/main.c

peephole$(OPT).o:	peephole.c peephole.i $(DEPS)
		$(GCC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $(srcdir)/peephole.c

profile$(OPT).o:	profile.c profile.i $(DEPS)
		$(GCC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $(srcdir)/profile.c

#The next two rules seem to be superfluous:

# engine:		$(OBJECTS) $(OBJECTS0) ;

# engine_ditc:	$(OBJECTS_DITC) $(OBJECTS0) ;

#NeXTstep hack

termios.o:	/usr/lib/libposix.a
	ar x /usr/lib/libposix.a termios.o

#duplicated rules to avoid too many recursive make invocations
# !! No any forth stuff should be done in ../Makefile.
# !! I added the dependencies on prim.i and prim_lab.i in the main Makefile, jens

#I commented out the following rules because they are no longer up-to-date. - anton

#prim.i:		../prim.b ../prims2x.fs
#		$(FORTHK) prims2x.fs -e "s\" ../prim.b\" ' output-c process-file bye" >$@-
#		$(CP) $@- $@
#		$(RM) $@-
#
#prim_lab.i:	../prim.b ../prims2x.fs
#		$(FORTHK) prims2x.fs -e "s\" ../prim.b\" ' output-label process-file bye" >$@-
#		$(CP) $@- $@
#		$(RM) $@-

config.h:	stamp-h
stamp-h:	config.h.in ../config.status ../stamp-h.in
		cd .. && CONFIG_FILES=$@ CONFIG_HEADERS=engine/config.h ./config.status
		echo timestamp > stamp-h

Makefile: Makefile.in ../config.status ../configure.in
	cd .. && $(MAKE) engine/Makefile.in

image.i:	../fi2c.fs ../$(include_fi)
		$(BOOTFORTH) ../fi2c.fs -e "s\" ../$(include_fi)\" fi2c bye" >$@

../$(include_fi):	FORCE
		cd .. && $(MAKE) $(include_fi)

#phony targets depend on FORCE; this is more portable than .PHONY
FORCE:

