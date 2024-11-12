COLLEEN_NAME = Colleen
GRACE_NAME = Grace
SULLY_NAME = Sully

COLLEEN_SRCS = Colleen.s
GRACE_SRCS = Grace.s
SULLY_SRCS = Sully.s

CC = nasm
CFLAGS = -f elf64 -g -F dwarf -DPIC

LINKER = ld
LDFLAGS = -lc -I /lib64/ld-linux-x86-64.so.2

$(COLLEEN_NAME): $(COLLEEN_SRCS)
	@echo "\033[0;34mCompiling $(COLLEEN_NAME)...\033[0m"
	$(CC) $(CFLAGS) $(COLLEEN_SRCS) -o $(COLLEEN_NAME).o
	@echo "\033[0;32mCompilation of $(COLLEEN_NAME) done.\033[0m"
	@echo "\033[0;34mLinking $(COLLEEN_NAME)...\033[0m"
	$(LINKER) $(COLLEEN_NAME).o -o $(COLLEEN_NAME) $(LDFLAGS)
	@echo "\033[0;32mLinking of $(COLLEEN_NAME) done.\033[0m"

$(GRACE_NAME): $(GRACE_SRCS)
	@echo "\033[0;34mCompiling $(GRACE_NAME)...\033[0m"
	$(CC) $(CFLAGS) $(GRACE_SRCS) -o $(GRACE_NAME).o
	@echo "\033[0;32mCompilation of $(GRACE_NAME) done.\033[0m"
	@echo "\033[0;34mLinking $(GRACE_NAME)...\033[0m"
	$(LINKER) $(GRACE_NAME).o -o $(GRACE_NAME) $(LDFLAGS)
	@echo "\033[0;32mLinking of $(GRACE_NAME) done.\033[0m"

$(SULLY_NAME): $(SULLY_SRCS)
	@echo "\033[0;34mCompiling $(SULLY_NAME)...\033[0m"
	$(CC) $(CFLAGS) $(SULLY_SRCS) -o $(SULLY_NAME).o
	@echo "\033[0;32mCompilation of $(SULLY_NAME) done.\033[0m"
	@echo "\033[0;34mLinking $(SULLY_NAME)...\033[0m"
	$(LINKER) $(SULLY_NAME).o -o $(SULLY_NAME) $(LDFLAGS)
	@echo "\033[0;32mLinking of $(SULLY_NAME) done.\033[0m"

all: $(COLLEEN_NAME) $(GRACE_NAME) $(SULLY_NAME)

fclean:
	@echo "\033[0;34mCleaning all executables and generated files...\033[0m"
	rm -f $(COLLEEN_NAME) $(GRACE_NAME) $(SULLY_NAME) $(COLLEEN_NAME).o $(GRACE_NAME).o $(SULLY_NAME).o Sully_*.s Sully_* Grace_kid.s tmp_Colleen
	@echo "\033[0;32mFull clean done.\033[0m"

re: fclean all

.PHONY: all fclean re
