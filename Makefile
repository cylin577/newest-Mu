# Unified Makefile for Mu

# Variables
MAKE := make

.PHONY: all qt clean

# Default target
all: qt

# Build the Qt standalone version
qt:
	@echo "Building Mu..."
	(cd qtBuildSystem/Mu && qmake6 && $(MAKE))

# Clean the build directory
clean:
	@echo "Cleaning build directory..."
	(cd qtBuildSystem/Mu && rm -rf *.o moc_* qrc_* ui_* Mu Makefile CMakeFiles)
	rm -rf build
