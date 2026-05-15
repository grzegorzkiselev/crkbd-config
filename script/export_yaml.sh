#!/bin/zsh -euo pipefail
cd `dirname $0`/..

qmk c2json -kb crkbd/rev1 -km grzegorzkiselev | keymap parse -c 10 -q - >sweep_keymap.yaml