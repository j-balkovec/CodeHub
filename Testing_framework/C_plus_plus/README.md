# Test File in C++

![Build](https://img.shields.io/badge/build-passing-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue)

This repository contains a test file written in C++. The purpose of this file is to provide a set of test functions and assertion methods to facilitate testing in C++ projects.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [License](#license)
- [Contributing](#contributing)
- [Contact](#contact)

## Introduction

The `test_file.h` is a C++ header file that provides a testing framework for writing and running tests in C++ projects. It includes various assertion methods to validate the expected behavior of functions and classes.

## Features

- Assertion methods for different types of conditions
- Colored output for better readability
- Time Stamps
- Customizable failure messages
- Support for different types of exceptions
- Easy to use and integrate with existing codebases

## Usage

To use the `test_.h` in your C++ project, follow these steps:

1. Copy the `test_file.h` file into your project directory.
2. Include the `test_.h` header in your test source file with `#include "test_.h`.
3. Write test functions using the available assertion methods.
4. Compile and run your tests using a C++ compiler.
5. Analyze the test results to ensure the correctness of your code.

Here's an example of how to use the `test_.h`:

```cpp
#include <iostream>
#include <string>
#include "test_.h"

void func() {
  // Test case 1
  bool condition1 = true;
  TEST::ASSERT(condition1, "Test case 1 failed", "test_function"); //pass

  // Test case 2
  bool condition2 = false;
  TEST::ASSERT(condition2, "Test case 2 failed", "test_function"); //fail
}

int main() {

  func();
  return 0;
}
```

The above demonstration (also included in main.cpp) uses ASSERT to check whether the condition is True or False, it will then print a timestamp in YELLOW, a green message if the test PASSED, or a RED message if the test FAILED.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements

The testing framework is inspired by popular testing frameworks such as `gtest` and `boost`.
Thanks to the C++ community for providing excellent resources and support.

Feel free to customize the content and sections of the `README.md` file according to your specific needs.
