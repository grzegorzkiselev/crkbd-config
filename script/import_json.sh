#!/bin/zsh -euo pipefail
cd `dirname $0`/..

qmk json2c -o grzegorzkiselev.c grzegorzkiselev.json
