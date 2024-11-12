COLLEEN_NAME = Colleen
GRACE_NAME = Grace
SULLY_NAME = Sully

COLLEEN_SRCS = Colleen.cpp
GRACE_SRCS = Grace.cpp
SULLY_SRCS = Sully.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

$(COLLEEN_NAME): $(COLLEEN_SRCS)
	@echo "\033[0;34mCompiling $(COLLEEN_NAME)...\033[0m"
	$(CXX) $(CXXFLAGS) $(COLLEEN_SRCS) -o $(COLLEEN_NAME)
	@echo "\033[0;32mCompilation of $(COLLEEN_NAME) done.\033[0m"

$(GRACE_NAME): $(GRACE_SRCS)
	@echo "\033[0;34mCompiling $(GRACE_NAME)...\033[0m"
	$(CXX) $(CXXFLAGS) $(GRACE_SRCS) -o $(GRACE_NAME)
	@echo "\033[0;32mCompilation of $(GRACE_NAME) done.\033[0m"

$(SULLY_NAME): $(SULLY_SRCS)
	@echo "\033[0;34mCompiling $(SULLY_NAME)...\033[0m"
	$(CXX) $(CXXFLAGS) $(SULLY_SRCS) -o $(SULLY_NAME)
	@echo "\033[0;32mCompilation of $(SULLY_NAME) done.\033[0m"

all: $(COLLEEN_NAME) $(GRACE_NAME) $(SULLY_NAME)

fclean:
	@echo "\033[0;34mCleaning all executables and generated files...\033[0m"
	rm -f $(COLLEEN_NAME) $(GRACE_NAME) $(SULLY_NAME) Sully_*.cpp Sully_* Grace_kid.cpp tmp_Colleen
	@echo "\033[0;32mFull clean done.\033[0m"

re: fclean all

.PHONY: all fclean re
