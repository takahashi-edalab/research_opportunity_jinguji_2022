CC = g++
CFLAGS = -Wall -Wextra
BUILDDIR = build

.PHONY: run

run: $(BUILDDIR)/sample
	   ./$<

$(BUILDDIR)/sample: sample.cpp $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILDDIR):
	mkdir -p $@
