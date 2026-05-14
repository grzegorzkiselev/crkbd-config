#!/bin/zsh -euo pipefail
cd `dirname $0`/..

qmk c2json -kb crkbd/rev1 -km grzegorzkiselev -o grzegorzkiselev.json keymap.c
