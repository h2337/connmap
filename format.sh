#!/usr/bin/env bash

clang-format -i -style=Google sources/*.c includes/*.h
clang-format -i -style=Google cpp/src/*.cpp cpp/include/*.hpp
