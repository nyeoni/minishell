#!/usr/bin/env bash

LABEL ghcr.io/chloekkk/blackholeshell:1.0.0

LDPATH=`find / -name "libreadline.a"`

LDPATH=`dirname ${LDPATH}`

CPPPATH=`find / -name "readline.h"`

CPPPATH=`dirname ${CPPPATH}`

export LDFLAGS=-L${LDPATH}
export CPPFLAGS=-I${CPPPATH}

make re

exec "$@"