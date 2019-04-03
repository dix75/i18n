#!/usr/bin/python3
# -*-coding: UTF-8 -*-

import os
import shutil

cmake="cmake"
compiler="Visual Studio 15 2017 Win64"
msbuild="c:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Professional\\MSBuild\\15.0\\Bin\\msbuild.exe"
mode="debug"  # debug or release



class Lib():
    def __init__(self, name):
        self.name_ = name
        self.path_ = name + "/build"
    def createTree(self):
        if(os.path.exists(self.path_) is True):
            shutil.rmtree(self.path_)
        os.makedirs(self.path_)
    def exec(self):
        self.createTree()
        os.system(f"{cmake} -G\"{compiler}\" -B{self.path_} -H{self.name_}")
        if(mode == "debug"):
            os.system(f"cd {self.path_} && \"{msbuild}\" {self.name_}.sln /m")
        else:
            os.system(f"cd {self.path_} && \"{msbuild}\" {self.name_}.sln /p:Configuration=Release")

def createLib(name):
    lib = Lib(name)
    lib.exec()


if (__name__ == "__main__"):
    print("=== Begin ===")
    print("=== Build Snappy ===")
    createLib("snappy")
    print("=== End Snappy ===")
    print("=== End ===")

