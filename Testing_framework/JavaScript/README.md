# Testing Framework in JavaScript

This is a simple "assertion" library for JavaScript that provides functions for writing tests and making assertions.

## Usage

To use the assertion library, include the library code in your JavaScript file. You can then use the provided assertion functions in your tests to check conditions and validate results.

### Available Functions

The following functions are available:

- `ASSERT(condition, message = "", funcName = "")`: Asserts a condition and prints a pass or fail message.
- `ASSERT_EQUAL(expected, actual, message = "", funcName = "")`: Checks if the expected value is equal to the actual value.
- `ASSERT_NOT_EQUAL(notExpected, actual, message = "", funcName = "")`: Checks if the expected value is not equal to the actual value.
- `ASSERT_TRUE(condition, message = "", funcName = "")`: Asserts that a given condition is true.
- `ASSERT_FALSE(condition, message = "", funcName = "")`: Asserts that a given condition is false.
- `ASSERT_IN(expected, actual, message = "", funcName = "")`: Assertion function to check if the expected value is included in the actual value.
- `ASSERT_NOT_IN(notExpected, actual, message = "", funcName = "")`: Asserts that the given value is not in the actual value.
- `ASSERT_THROW(statement, expectedException, message = "", funcName = "")`: Asserts that a specific exception is thrown when executing a statement.
- `ASSERT_NO_THROW(statement, message = "", funcName = "")`: Executes a statement and checks if it throws an exception.

## Example

Here's an example of how to use the assertion library:

```javascript
function add(a, b) {
  return a + b;
}

function testAdd() {
  ASSERT_EQUAL(5, add(2, 3), "Addition of 2 and 3 should be 5", "add");
  ASSERT_TRUE(add(2, 3) > 0, "Sum should be positive", "add");
}

testAdd();
```

In the example above, we define a function add that adds two numbers. We then define a test function testAdd that uses the assertion functions to check if the addition is correct. Finally, we call testAdd to run the tests.

## License

This project is licensed under the MIT License. See the [LICENSE] file for details. Feel free to modify the content as needed to fit your requirements.
