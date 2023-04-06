#!/usr/bin/env bash

# Desativa o modo de depuração
PS4='+ $(date "+%Y-%m-%d %T") $BASH_SOURCE:$LINENO: '
set -x

# main
git status
git add --all
git commit -m "./push.sh"
git push --all

# Desativa o modo de depuração
set +x

