#!/bin/zsh -euo pipefail
cd `dirname $0`/..

qmk compile -kb crkbd/rev1 -km grzegorzkiselev
