#MAKEFILE FOR PROJECT 'RepairQ'
PROG = repairq.exe
CC = g++
INC = -Iinc
OUT = lib/lib.a
LDFLAGS =
ODIR = obj
SDIR = src

_OBJS = main.o ascii.o repair.o QueryU.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $<
$(PROG): $(OBJS)
	$(CC) -o $@ $< $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(OUT) $(PROG)
