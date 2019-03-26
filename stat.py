#!/usr/bin/python3
# -*-coding: UTF-8 -*-
#
# @file      stats.py
# @brief     The main file creates statistics from current project
# @author    S.Panin <dix75@mail.ru>
# @copyright S.Panin, 2015 - 2019
# @version   v.1.8
# @created   September (the) 15(th), 2012, 19:47 MSK
# @updated   January   (the) 08(th), 2019, 11:59 MSK
# @TODO
#
import os
import time


def countLines(file):
    try:
        return len(open(file, encoding="UTF-8").read().split('\n'))
    except UnicodeDecodeError as e:
        print(f" - Error occurs in file '{file}'. More info\n - {e}")


class Data:
    Tests = ('assertTrue', 'assertFalse', 'assertEquals', 'assertNotEquals', 'assertNullptr', 'assertNotNullptr', 'assertMaybeException', 'assertMaybeExceptionTrue', 'TPS_VERIFY', 'TPS_ASSERT', 'TPS_COMPARE', 'TPS_DCOMPARE')
    PassFolder = ('lime', 'Ld')
    PassFiles = ('~*.*')
    Folder = "stats"

    def __init__(self):
        self.m_lines = 0          # all lines in the project
        self.m_qml_lines = 0      # all qml lines in the project
        self.m_characters = 0     # all symbols in the project
        self.m_files = 0          # all files in the project
        self.m_files_h = 0        # all files *.h in the project
        self.m_files_qml = 0      # all files *.qml in the project
        self.m_files_cpp = 0      # all files *.cpp in the project
        self.tests = 0            # all files with tests in the project
        self.m_tests = 0          # max tests in the project

    def findTest(self, line):
        for item in self.Tests:
            if (line.find(item) != -1):
                return 1
        return 0

    def passFolder(self, root):
        for path in self.PassFolder:
            if root.find(path) != -1:
                return True
        return False

    def createOutputFile(self):
        tm = time.localtime()
        return f"{self.Folder}/{tm.tm_mon}_{tm.tm_year}.st"

    def createData(self):
        str =  f"{'':-^42}\n"
        str += f"Current Day is   {time.ctime()}\n"
        str += f"{'Max header files in the Project':<32}-{self.m_files_h:>8}\n"
        str += f"{'Max cpp files in the Project':<32}-{self.m_files_cpp:>8}\n"
        str += f"{'Max qml files in the Project':<32}-{self.m_files_qml:>8}\n"
        str += f"{'Max tests files in the Project':<32}-{self.tests-1:>8}\n"
        str += f"{'Max files in the Project':<32}-{self.m_files:>8}\n"
        str += f"{'Max qml lines in the Project':<32}-{self.m_qml_lines:>8}\n"
        str += f"{'Max tests in the Project':<32}-{self.m_tests:>8}\n"
        str += f"{'Max lines in the Project':<32}-{self.m_lines:>8}\n"
        str += f"{'Max symbols in the Project':<32}-{self.m_characters:>8}\n"
        return str

    def fileQml(self, file):
        self.m_files_qml += 1
        self.m_qml_lines += countLines(file)

    def fileHeader(self, file):
        self.m_files_h += 1
        self.tests += 1 if file.endswith("_test.h") else 0

    def fileCpp(self, file):
        self.m_files_cpp += 1

    def collect(self, file):
        self.m_files += 1
        try:
            for line in open(file, encoding="UTF-8"):
                self.m_lines += 1
                self.m_characters += len(line)
                self.m_tests += self.findTest(line)
        except UnicodeDecodeError as e:
            print(f" - Error occurs in file '{file}'. More info\n - {e}")

    def printData(self, start_time):
        str = self.createData()
        out = self.createOutputFile()

        print(str)
        print(f"Elapsed time: {time.time() - start_time}s")

        with open(out, "a+") as f:
            f.write(str)


if (__name__ == "__main__"):
    start_time = time.time()
    d = Data()
    for root, dirs, files in os.walk("projects"):
        if (d.passFolder(root)):
            continue
        for name in files:
            file = os.path.join(root, name)
            if(name.endswith(".qml")):
                d.fileQml(file)
            elif file.endswith(".h") or file.endswith(".hpp"):
                d.fileHeader(file)
            elif file.endswith(".cpp"):
                d.fileCpp(file)
            else:
                continue
            d.collect(file)
    d.printData(start_time)
