OBJS = ui.o userinput.o tokenizer.o history.o

CFLAGS=-g -O3

all: uiTest

uiTest: $(OBJS)
	cc -o uiTest $(CFLAGS) $(OBJS)

$(OBJS): user.h src/tokenizer.h src/history.h

clean:
	rm -f *.o uiTest

run:uiTest
	./uiTest
