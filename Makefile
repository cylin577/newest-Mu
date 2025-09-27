# Unified Makefile for Mu

# Variables
MAKE := make

.PHONY: all qt clean

# Default target
all: qt

# Build the Qt standalone version
qt:
	@echo "Building QtMu..."
	(mkdir -p qtBuildSystem/Mu/build && cd qtBuildSystem/Mu/build && qmake6 .. && $(MAKE))

# Clean the build directory
clean:
	@echo "Cleaning build directory..."
	rm -rf qtBuildSystem/Mu/build
	rm -rf build
