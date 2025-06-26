COMPILE_FILE_NAME ?= game.out
COMPILE_BASH_FILE ?= ./cmd/compile.sh
HELP_BASH_FILE ?= ./cmd/help.sh
B ?= bash

compile:
	${B} ${COMPILE_BASH_FILE} ${COMPILE_FILE_NAME}

help:
	${B} ${HELP_BASH_FILE}

	