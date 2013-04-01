#!/bin/sh
/opt/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -c -o pcm.o pcm.c -I/`pwd`/include
/opt/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -c -o mixer.o mixer.c -I/`pwd`/include
/opt/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -c -o tinyplay.o tinyplay.c -I`pwd`/include
/opt/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -c -o tinymix.o tinymix.c -I`pwd`/include
/opt/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -o tinyplay tinyplay.o pcm.o
/opt/arm-2009q3/bin/arm-none-linux-gnueabi-gcc -o tinymix tinymix.o mixer.o 
