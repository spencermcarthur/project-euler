#!/bin/python3

from os import access, X_OK, system
from pathlib import Path


def main():
    script = Path(__file__)
    bin_dir = script.parent.parent / "bin"
    problems = list()
    for f in bin_dir.iterdir():
        if f.is_file() and access(f, X_OK):
            problems.append(f)

    for f in sorted(problems, key=lambda f: int(f.name)):
        system(f)


if __name__ == "__main__":
    main()
