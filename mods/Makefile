PREFIX := /usr/local/bin
CC=gcc

all: bat cpu dat mem

bat: battery.c
	$(CC) battery.c -o ${PREFIX}/bat

cpu: cpu.c
	$(CC) cpu.c -o ${PREFIX}/cpu

dat: date.c
	$(CC) date.c -o ${PREFIX}/dat

mem: memory.c
	$(CC) memory.c -o ${PREFIX}/mem
