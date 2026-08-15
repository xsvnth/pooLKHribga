#!/bin/sh

find . -name "*.sh" | xargs -n1 basename | sed 's/\.sh$//'
