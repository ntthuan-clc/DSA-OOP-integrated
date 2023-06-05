SRC_DIR = source # Source code directory
SRC_DIR += source/sort
SRC_DIR += source/search
SRC_DIR += source/error
SRC_DIR += source/hash
SRC_DIR += source/tree

SRC_FILES := $(foreach SRC_DIR, $(SRC_DIR), $(wildcard $(SRC_DIR)/*.cpp)) # Get all .cpp file in SRC_DIR

run:
	@g++ $(SRC_FILES) -o output/main
	@./output/main

print:
	@echo $(SRC_FILES)

clean:
	rm output/*