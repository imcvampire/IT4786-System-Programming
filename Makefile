CXX=gcc
OUT_DIR=dist

MKDIR_P=mkdir -p

.PHONY: directories clean

all: directories memory

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}

memory: memory-allocation large-memory-allocation bad-memory-allocation free-memory

memory-allocation: memory-allocation.c
	$(CXX) -o $(OUT_DIR)/memory-allocation memory-allocation.c

large-memory-allocation: large-memory-allocation.c
	$(CXX) -o $(OUT_DIR)/large-memory-allocation large-memory-allocation.c

bad-memory-allocation: bad-memory-allocation.c
	$(CXX) -o $(OUT_DIR)/bad-memory-allocation bad-memory-allocation.c

free-memory: free-memory.c
	$(CXX) -o $(OUT_DIR)/free-memory free-memory.c

clean:
	rm -rf dist
