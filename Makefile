MKFILE_PATH := $(abspath $(dir $(firstword $(MAKEFILE_LIST))))

PATH_TO_EMCC=/home/viral/emsdk/upstream/emscripten/emcc
HEADER_FILES = canvas.h ChartJS_handler.h html_canvas.h simulation.h statistics_handler.h subject.h Strategies/MovementStrategy.h Strategies/RegularMovement.h Strategies/LockdownMovement.h
SOURCE_FILES = ChartJS_handler.cpp html_canvas.cpp main.cpp simulation.cpp subject.cpp Strategies/RegularMovement.cpp Strategies/LockdownMovement.cpp

OUTPUT_PATH=$(MKFILE_PATH)/build/
OUTPUT_FILE_NAME=index.html

HTML_DEPENDENCIES_PATH=$(MKFILE_PATH)/dependencies/
HTML_DEPENDENCIES = Chart.min.js Chart.min.css

prod-build: clean copydeps $(HEADER_FILES) $(SOURCE_FILES)
	@echo Production build started...
	@$(PATH_TO_EMCC) $(SOURCE_FILES) -s ASYNCIFY -s EXTRA_EXPORTED_RUNTIME_METHODS='["AsciiToString"]' -s WASM=1 -o $(OUTPUT_PATH)$(OUTPUT_FILE_NAME) --shell-file shell_minimal.html
	@echo Production build complete.

debug-build: clean copydeps $(HEADER_FILES) $(SOURCE_FILES)
	@echo Debug build started...
	@$(PATH_TO_EMCC) $(SOURCE_FILES) -s ASYNCIFY -s EXTRA_EXPORTED_RUNTIME_METHODS='["AsciiToString"]' -s WASM=1 -s SAFE_HEAP=1 -g -o $(OUTPUT_PATH)$(OUTPUT_FILE_NAME) --shell-file shell_minimal.html
	@echo Debug build complete.

clean:
	@echo Cleaning build folder...
	@rm -rf $(OUTPUT_PATH)
	@mkdir -p $(OUTPUT_PATH)
	@echo Cleaning build folder done.

copydeps:
	@echo Copying dependencies...
	@cd $(HTML_DEPENDENCIES_PATH) && cp -t $(OUTPUT_PATH) $(HTML_DEPENDENCIES)
	@echo Copying dependencies done.

run-debug: debug-build
	@echo "Staring test server with debug ready code... (you can stop the server by pressing ctrl+C)"
	@cd $(OUTPUT_PATH) && python3 -m http.server

run-production: prod-build
	@echo "Staring test server with production code... (you can stop the server by pressing ctrl+C)"
	@cd $(OUTPUT_PATH) && python3 -m http.server