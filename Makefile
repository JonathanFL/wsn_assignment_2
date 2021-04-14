MAKE_NET = MAKE_NET_NULLNET
CONTIKI_PROJECT = assignment_2
all: $(CONTIKI_PROJECT)

CONTIKI = ../../contiki-ng

TARGET_LIBFILES += -lm

include $(CONTIKI)/Makefile.include