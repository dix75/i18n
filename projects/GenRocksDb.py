#!/usr/bin/python3
# -*-coding: UTF-8 -*-

import os
import shutil

out="rocksdb/build/"
snappy_out="snappy/build/"
project_dir="rocksdb"
cmake="cmake"
compiler="Visual Studio 15 2017 Win64"
msbuild="c:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Professional\\MSBuild\\15.0\\Bin\\msbuild.exe"
mode="debug"

if (__name__ == "__main__"):
    print("--- Begin ---")
    print("--- Build Snappy ---")
    if(os.path.exists(snappy_out) is True):
        shutil.rmtree(snappy_out)
    os.makedirs(snappy_out)
    os.system(f"{cmake} -G\"{compiler}\" -B{out} -H{project_dir} -DWITH_GFLAGS=1 -DWITH_SNAPPY=1 -DWITH_JEMALLOC=1 -DWITH_JNI=1")
    print("--- End Snappy ---")
    #if(os.path.exists(out) is True):
        #shutil.rmtree(out)
    #os.makedirs(out)
    #os.system(f"{cmake} -G\"{compiler}\" -B{out} -H{project_dir} -DWITH_GFLAGS=1 -DWITH_SNAPPY=1 -DWITH_JEMALLOC=1 -DWITH_JNI=1")
    if(mode == "debug"):
        os.system(f"cd {project_dir} && \"{msbuild}\" rocksdb.sln /m")
    else:
        os.system(f"cd {project_dir} && \"{msbuild}\" rocksdb.sln /p:Configuration=Release")
    print("--- End ---")

