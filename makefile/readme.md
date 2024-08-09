# Makefile

This readme explain why makefile is useful, and how to create it.

## Introduction

Imagine you develop a program called `foo`, who is composed with 5 header files `1.h, 2.h, 3.h, 4.h, 5.h`, 6 files of source code in C language, `1.c to 5.c` and one main file called `main.c`.

*⚠️Note: Is not recommanded to naming file like this ! Is just for example.*

Supposed we find a bug in the file `2.c`, and we have to fix this bug. To get the new program foo, we should re-compile all the files, headers and sources code, even if we have changed one file.

So what can we doing ? Is there a solution to this problem ?

Computer scientist have been confronted by this problem a mont of years ago. There are developped a program called make. Instead of compile all the source code, this program build only the source code who have changed. If you you make change in `2.c`, then make will build only this.

Here two reasons to why we need makefile:
* A software project composed by several source code files, might have a longer and complex compiler command. Wtih `make`, we can reduce them.
* A project of programming needs sometimes several special options for the compilations, usualy rarely used then is difficult to remember. With `make`, we don't need to do remember all of this.
* The need of maintains a consistens development environment.
* Automatisation of build process because  we can call `make` easily with a shell script or a cron task. (cron task ?)

## Why we need `Makefile` ?

Even the command `make` are useful, it cannot work without instructions we given to it.  This instructions `make` are stored in text file, usualy called `makefile` and contains all commands `make` should execute.

This files is normaly named `makefile` or `Makefile`. By conventions, GNU programs named `makefile` or `Makefile` because it's easy to see (if you make `ls`, this file is in principle at begiging of the list). If you given another name to the file, be aware to add inclusion options `-f` after the command `make` to let know at make the command you used.

For instance, if we have a `makefile` called `bejo`, then the command we use to give the order at make to use this file is:
```
make -f bejo
```

## Structure of `Makefile`

A `makefile` is composed by sections:
* target
* dependencies
* rules

The dependencies are elements where the source code is needed to create a target. The target is commonly a name of executable or object file. The rules are the necessary commands to create the target.

A simple smple description of make file:
```
target: dependencies
		command
		command
		...
```

## Example of `Makefile`

```
1 client: conn.o 
2	g++ client.cpp conn.o -o client
# dependencies to create the target conn.o
3 conn.o: conn.cpp conn.h 
# rules to create the target conn.o
4	g++ -c conn.cpp -o conn.o 
```

In this `makefile` above, the dependencies are in the `conn.o`, and the rules in the line with `g++ client.cpp conn.o -o client`. Notice which each lines of rules start by tabulation, not by spaces. Forgive tabulation at the begin of the line of rules are a common error when we build makefiles. Fortunately, this kind of errors are easy to see because the make program will tell to us.

Detailed description of `makefile` above:
* Create a exectuable file called `client` as target, who depend of the file `conn.o`
* The rules allows to create the target are in the third line
* In the third line, to create the target conn.o. The `make` program need files `conn.cpp` and `conn.h`
* The rules allowing to create the target `conn.o` are in the fourth line

## Comments

To add comments in the `makefile`, put # symbol in the first line commented.

Example:
```
# Create a executable file "client" 
1 client: conn.o
2	g++ client.cppp conn.o -o client
# Create object file "conn.o"
3 conn.o: conn.cpp conn.h
4	g++ conn.cpp -o conn.o
```

## Specific target (*phony target*)

A specific target (phony target) is just a name of fictionnal file for command will be executed when we lanch an explicit request. We have two reasons to use a phony target:
* To avoid conflict with a file who have the same name
* To improve the performance of `makefile`

If you write rules where the command is not supposed to create a target file, these command will be excuted for each re-execution of the target. For instance:
```
clean: 
	rm *.o temp
```
Due to the fact the command `rm` don't create file named `clean` this file will never exist. The command `rm` is always executed each time we write:
```
make clean
```
Because `make` assumes that the clean file is always new.

The target below stop working if a file named `clean` exist in the actual directory. As it does not require dependencies, the `clean` file will be considered like is up to date, and the `rm *.o temp` command will not be executed. To resolve this issue, you can declared explicitly a target is "specific" with the help of the command `.PHONY`. For instance:
```
.PHONY : clean
```
In the `makefile` above, we indicate the instruction `make clean` on the command line, the command `rm *.o temp` will be always executed, even if the file named `clean` exist or not in the directory.

## Variable

To define a variable in `makefile`, we can use the following command:
```
$VAR_NAME=value
```

By convention, a variable name is writing in majuscule, for instance:
```
$OBJECTS=main.o test.o
```

To get the value of a variable, put the symbol `$` before the variable as follows:
```
$(VAR_NAME)
```

In a `makefile`, we found two type of variables:
* recursively extended variable
* simply extended variable

In a recursively extended variable, `make` will continue to extend this variable until it cannot be extended, for instance:
```
TOPDIR=/home/tedi/project
SRCDIR=$(TOPDIR)/src
```
The variable *SRCDIR* will be extended, at first by extended the variable *TOPDIR* The final result is `/home/tedi/project/src`
But the recursively extended variable will not be suitable for this following command:
```
CC = gcc -o
CC = $(CC) -02
```
Using the recursevly extended variable in this case will cause an infinite loop. To avoid this, we can use simple extended variable instead:
```
CC := gcc -o
CC += $(CC) -02
```
The symbol `:=` create the variable *CC* and is aaigned this value `gcc -o`. The symbol `+=` is placed at the end of the value `-02` of *CC*

source: https://ftp.traduc.org/doc-vf/gazette-linux/html/2002/083/lg83-B.html
