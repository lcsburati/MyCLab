TARGET = main

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

CC = gcc
CFLAGS = -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces

RAYLIB_INCLUDE = -I/opt/homebrew/include
MY_INCLUDE = -I$(INCDIR)
ALL_INCLUDES = $(RAYLIB_INCLUDE) $(MY_INCLUDE)

RAYLIB_LIBS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo

SOURCES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(INCDIR)/*.c)

OBJECTS = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

vpath %.c $(SRCDIR) $(INCDIR)

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) -o $@ $^ $(RAYLIB_LIBS)


$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(ALL_INCLUDES) -c $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

help:
	@echo "Comandos:"
	@echo "  make   -> Compile All"
	@echo "  clean  -> Clean bin and obj files"