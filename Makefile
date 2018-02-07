CXX=gcc
OUT_DIR=dist

MKDIR_P=mkdir -p

.PHONY: directories clean

all: directories memory-allocation large-memory-allocation bad-memory-allocation

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}

memory-allocation: memory-allocation.c
	$(CXX) -o $(OUT_DIR)/memory-allocation memory-allocation.c

large-memory-allocation: large-memory-allocation.c
	$(CXX) -o $(OUT_DIR)/large-memory-allocation large-memory-allocation.c

bad-memory-allocation: bad-memory-allocation.c
	$(CXX) -o $(OUT_DIR)/bad-memory-allocation bad-memory-allocation.c

clean:
	rm -rf dist
