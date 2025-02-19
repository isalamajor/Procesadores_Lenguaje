\ envos.fs set os-specific environmental queries 	07jul97jaw

\ Copyright (C) 1997,1999,2000,2003,2006,2007,2008 Free Software Foundation, Inc.

\ This file is part of Gforth.

\ Gforth is free software; you can redistribute it and/or
\ modify it under the terms of the GNU General Public License
\ as published by the Free Software Foundation, either version 3
\ of the License, or (at your option) any later version.

\ This program is distributed in the hope that it will be useful,
\ but WITHOUT ANY WARRANTY; without even the implied warranty of
\ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
\ GNU General Public License for more details.

\ You should have received a copy of the GNU General Public License
\ along with this program. If not, see http://www.gnu.org/licenses/.

get-current environment-wordlist set-current
: os-class ( -- c-addr u ) \ gforth-environment
    \G Counted string representing a description of the host operating system.
    s" unix" ;
: os-type ( -- c-addr u ) \ gforth-environment
    \G Counted string equal to "$host_os"
    s" linux-gnu" ;
set-current

: libtool-command ( -- c-addr u ) \ gforth
\G name of the GNU libtool command
    s" " ;

: libtool-cc ( -- c-addr u ) \ gforth
\G invocation string of the C compiler used for libtool
    s" gcc" ;

: libtool-flags ( -- c-addr u ) \ gforth
\G force no undefined for cygwin
    [ s" linux-gnu" s" cygwin" str= ] [IF]  s"  -no-undefined "
    [ELSE]  s" "  [THEN] ;

\ test for the presence of libffi or ffcall
false constant ffcall-present \ libffi present (on building)
false constant libffi-present \ ffcall libs present (on building)

: include-ffi.h-string ( -- c-addr u )
  s" #include <>" ;

