#!/bin/python3

from os import X_OK, access, system
from pathlib import Path
from time import time


def main():
    script = Path(__file__)
    bin_dir = script.parent.parent / "bin"
    problems = list()
    for f in bin_dir.iterdir():
        if f.is_file() and access(f, X_OK):
            problems.append(f)

    count = 0
    start_time = time()
    for f in sorted(problems, key=lambda f: int(f.name)):
        if system(f) == 0:
            count += 1
        else:
            print(f"Problem {int(f.name)} failed")
    end_time = time()

    print(f"Ran {count} problems. Total runtime: {end_time - start_time:.2f}s")


if __name__ == "__main__":
    main()
