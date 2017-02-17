# ------------------------------------------------
# A Generic Makefile for Building Targets
#
# Author: yangsheng1107@gmail.com
# Date  : 2016-12-22
#
# Changelog :
#   0.01 - first version
# ------------------------------------------------
TOP_DIR := $(shell cd ../;pwd)
STYLE_TOOL := $(TOP_DIR)/tools/checksrc.pl

LDFLAGS_PATH :=
LDFLAGS := -ldl $(LDFLAGS_PATH)
CFLAGS_INC :=
CFLAGS := -g -Wall $(CFLAGS_INC)


SRCS := $(wildcard *.c )
OBJS := $(addprefix , $(SRCS:.c=.o))
BINS := demo
#$(info $$SRCS is [$(SRCS)])
#$(info $$OBJS is [$(OBJS)])
#$(info $$BINS is [$(BINS)])

.PHONY : clean all check

all: check $(BINS)
	make -C ./lib/
# ------------------------------------------------
# Generate binary files
# ------------------------------------------------
$(BINS): $(OBJS)
#	$(info $$OBJS is [$(OBJS)])
	$(CC) $(OBJS) $(LDFLAGS) -o $@ 

# ------------------------------------------------
# Build Object files
# ------------------------------------------------
$(OBJS): %.o: %.c
#	$(info $$@ is [$@], and $$< is [$<])
	$(CC) $(CFLAGS) -c $< $(LDFLAGS) -o $@

# ------------------------------------------------
# Style 
# ------------------------------------------------
check:
#	$(info $$SRCS is [$(SRCS)])
	$(STYLE_TOOL) $(SRCS)

# ------------------------------------------------
# Clean
# ------------------------------------------------
clean:
	make -C ./lib/ clean
	@rm -f $(OBJS) $(BINS)
