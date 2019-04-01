#!/usr/bin/python3
# -*-coding: UTF-8 -*-
import os
import shutil

out="build/cmake-projects/the/"
h="projects/perfect"
cmake="cmake"
s="Visual Studio 15 2017 Win64"

if (__name__ == "__main__"):
    print("--- Begin ---")
    if(os.path.exists(out) is True):
        shutil.rmtree(out)
    os.makedirs(out)
    os.system("{} -G\"{}\" -B{} -H{} -DWITH_GFLAGS=1 -DWITH_SNAPPY=1 -DWITH_JEMALLOC=1 -DWITH_JNI=1".format(cmake, s, out, h))
    print("--- End ---")

# sample command: cmake -G "Visual Studio 15 Win64" -DWITH_GFLAGS=1 -DWITH_SNAPPY=1 -DWITH_JEMALLOC=1 -DWITH_JNI=1 ..
