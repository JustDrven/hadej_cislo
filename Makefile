COMPILE_FILE_NAME ?= game.out
COMPILE_BASH_FILE ?= ./cmd/compile.sh
HELP_BASH_FILE ?= ./cmd/help.sh

compile:
	bash ${COMPILE_BASH_FILE} ${COMPILE_FILE_NAME}

help:
	bash ${HELP_BASH_FILE} ${COMPILE_FILE_NAME}
