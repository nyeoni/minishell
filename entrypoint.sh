#!/usr/bin/env bash

LDPATH=`find / -name "libreadline.a"`

LDPATH=`dirname ${LDPATH}`

CPPPATH=`find / -name "readline.h"`

CPPPATH=`dirname ${CPPPATH}`

export LDFLAGS=-L${LDPATH}
export CPPFLAGS=-I${CPPPATH}

# build minishell
make fclean >/dev/null 
make -j >/dev/null &

# function for progress message
sp="/-\|"
sc=0
spin() {
   printf "%s\b${sp:sc++:1}"
   ((sc==${#sp})) && sc=0
}

echo -en "\033[38;5;175m"
echo -n "Build minishell ... "

# display progress message until background jobs done
while [[ -n $(jobs -r) ]]
do
	spin 
	sleep .3
done
echo -en "\033[1K\033[0m"

# check the minishell works well or not
echo "exit" | ./minishell 1>/dev/null 2>&1

if [ $? -gt 0 ]; then
	echo "Fail to build Minishell..."
	exit 1
fi

# execute minishell
exec "$@"
