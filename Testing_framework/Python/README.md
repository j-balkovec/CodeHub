# Testing Framework in Python

![Build](https://img.shields.io/badge/build-passing-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue)

Created by Jakob Balkovec - Wed 5 Jul 2023

This project aims to rewrite the mock testing framework originally written in C++, into Python.

## Overview

This testing framework provides a set of assertion methods to facilitate testing in Python. It allows developers to write test cases and verify the expected behavior of their code.

## Features

- Assertion methods for various types of conditions
- Customizable failure messages
- Integration with existing testing frameworks
- Easy to use and understand
- Colored output
- Time Stamps

## Getting Started

To use this testing framework, follow these steps:

1. Clone the repository or copy the necessary files into your project directory.
2. Import the `test_` file into your project.
3. The methods are static so you can use them anywhere throughout your project
4. Conduct the documentation, Write test methods using the available assertion methods.
5. Run the test methods and observe the results.

## Usage

Here's an example of how to use the testing framework:

```python
# Import all of the methods
from Test_ import *

# Write a test case
def test_assert() -> None:
    ASSERT(True)  # pass
    ASSERT(False, "")  # fail
    return None

# Run tests
def main() -> int:
    test_assert()
    print()
    return 0
```


The above demonstration (also included in `main.py`) uses `ASSERT` to check whether the condition is `True` or `False`, 
it will then print a *timestamp* in **YELLOW**, a *green* message if the test **PASSED**, or a **RED** message if the test *FAILED*.

## [License]([https://img.shields.io/badge/license-MIT-blue](https://opensource.org/license/mit/))

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements

The testing framework is inspired by popular testing frameworks such as `unittest` and `pytest`.
Thanks to the Python community for providing excellent resources and support.

Feel free to customize the content and sections of the `README.md` file according to your specific needs.

