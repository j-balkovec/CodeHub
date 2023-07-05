# Testing Framework in C#

![Build](https://img.shields.io/badge/build-passing-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue)

This repository contains a test framework written in C#. The purpose of this framework is to provide assertion methods for testing C# code.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [License](#license)
- [Contributing](#contributing)
- [Contact](#contact)

## Introduction

The `TEST` class in the `Test_` namespace is a C# class that provides assertion methods for testing. It includes methods for asserting conditions, equality, exceptions, and more.

## Features

- Assertion methods for different types of conditions
- Colored output for better readability
- Customizable failure messages
- Support for different types of exceptions
- Easy to use and integrate with existing codebases

## Usage

To use the `TEST` class in your C# project, follow these steps:

1. Include the `Test_` namespace in your source file: `using Test_;`
2. Write test methods using the available assertion methods from the `TEST` class.
3. Compile and run your tests using a C# compiler or test runner.
4. Analyze the test results to ensure the correctness of your code.

Here's an example of how to use the `TEST` class:

```csharp
using System;
using Test_;

namespace Main
{
    class Program
    {
        static void Main(string[] args)
        {
            TEST.ASSERT(true, "");
            TEST.ASSERT(false, "");


            TEST.ASSERT_THROW<ArgumentNullException>(() => {
                string nullString = null;
                int length = nullString.Length;
            }, "");

            Console.ReadLine();
        }
    }
}
```

In the above example, we include the Test_ namespace and call the assertion methods from the TEST class to validate the expected results. The test methods can be customized with failure messages and additional parameters.

## [License]([https://img.shields.io/badge/license-MIT-blue](https://opensource.org/license/mit/))

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributing

Contributions are welcome! If you find any issues or want to enhance the functionality of the test framework, feel free to open an issue or submit a pull request.
