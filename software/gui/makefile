# Application name
TARGET = can2usb

# Source files
SRCS = src/main.c src/ui.c

# Object files
OBJST = main.o ui.o

# Compiler
CC = gcc
# Debug
DEBUG = -g
# Optimization
OPT = -O0
# GTK specific
GTK_SPEC = -rdynamic
# Warnings
WARN = -Wall

PTHREAD = -pthread

CCFLAGS = $(DEBUG) $(GTK_SPEC) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB = `pkg-config --cflags --libs gtk+-3.0`

# Linker
LD = gcc
LDFLAGS = $(PTHREAD) $(GTKLIB) -export-dynamic

OBJS = $(SRCS:%.c=%.o)

app: $(OBJS)
	$(CC) $(CCFLAGS) $(OBJST) -o $(TARGET) $(GTKLIB)
	rm -f *.o

.c.o:
	$(CC) -c $(CCFLAGS) $*.c $(GTKLIB)

clean:
	rm -f *.o
	rm -f $(TARGET)

remake: clean bms
