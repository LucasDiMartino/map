CC=gcc
CFLAGS=-W -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include/ -I/usr/include/gtk-2.0/gtk/ `pkg-config --cflags --libs gtk+-2.0` 
LDFLAGS=-lm `pkg-config --cflags --libs gtk+-2.0`
EXEC=map

.PHONY: clean, mrproper

SRCDIR=src
INCDIR=inc
OBJDIR=obj
BINDIR=bin

SRC=$(wildcard src/*.c)
OBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(BINDIR)/$@ $^ $(CLFLAGS) $(LDFLAGS)


$(OBJDIR)/main.o: $(INCDIR)/gui.h $(SRCDIR)/gui.c $(INCDIR)/menu.h $(SRCDIR)/menu.c
$(OBJDIR)/gui.o: $(INCDIR)/callback.h $(SRCDIR)/callback.c $(INCDIR)/widget.h $(SRCDIR)/widget.c $(INCDIR)/struct_widget.h
$(OBJDIR)/callback.o: $(INCDIR)/widget.h $(SRCDIR)/widget.c $(INCDIR)/gui.h $(SRCDIR)/gui.c
$(OBJDIR)/menu.o: $(INCDIR)/callback.h $(SRCDIR)/callback.c


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
	
clean:
	rm -f $(OBJDIR)/*.o

mrproper: clean
	rm -f $(BINDIR)/$(EXEC)
