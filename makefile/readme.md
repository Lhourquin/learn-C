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
