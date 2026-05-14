#!/bin/zsh -euo pipefail
cd `dirname $0`/..

qmk flash -kb crkbd/rev1 -km grzegorzkiselev
