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

CC := gcc
LDFLAGS_PATH := -L./
LDFLAGS := $(LDFLAGS_PATH) -ladd -lsub
CFLAGS_INC := -I./lib 
CFLAGS := -g -Wall $(CFLAGS_INC)


SRCS := $(wildcard *.c )
OBJS := $(addprefix , $(SRCS:.c=.o))
BINS := demo
#$(info $$SRCS is [$(SRCS)])
#$(info $$OBJS is [$(OBJS)])
#$(info $$BINS is [$(BINS)])

.PHONY : clean all check sub

all: check sub $(BINS)
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

sub:
	make -C ./lib/
	@cp ./lib/lib*.a ./
# ------------------------------------------------
# Clean
# ------------------------------------------------
clean:
	make -C ./lib/ clean
	@rm -f $(OBJS) $(BINS) ./lib*.a
