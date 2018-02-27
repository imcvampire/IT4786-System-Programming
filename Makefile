CXX=gcc
OUT_DIR=bin

MKDIR_P=mkdir -p

all: directories memory lock-file

directories: ${OUT_DIR}

.PHONY: directories clean


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

.PHONY: memory memory-allocation large-memory-allocation bad-memory-allocation free-memory


lock-file: atomic-lock-file

atomic-lock-file: atomic-lock-file.c
	$(CXX) -o $(OUT_DIR)/atomic-lock-file atomic-lock-file.c

.PHONY: lock-file atomic-lock-file

clean:
	rm -rf dist
