# g_log Logging Library

## Introduction

**g_log** is a logging library implemented in Python that provides functionality for logging messages with different severity levels. It also includes a filter function for filtering log entries based on log levels.

## Author

Jakob Balkovec

## Date

July 7, 2023

## Version

1.0

## License

This library is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## File

[g_log.py](g_log.py)

## Description

The **g_log** library is implemented in the `g_log` class, which allows you to log messages with different severity levels. It provides the following features:

- Logging messages with different severity levels (DEBUG, INFO, WARNING, ERROR, CRITICAL).
- Logging messages with an optional condition and function name.
- Providing more detailed information about exceptions and tracebacks when an error occurs.
- Filtering log entries based on log levels.
- Rotating log files to prevent them from growing too large.

## Usage

To use the **g_log** library, follow these steps:

1. Import the `g_log` class from the `g_log` module:
   ```python
   from g_log import g_log
   ```
2. Create an instance of the `g_log` class:
   ```python
   logger = g_log()
   ```
3. Log messages using the `log()` method:
   ```python
   logger.log(condition'''[optional]''', message, level, func'''[optional]''')
   ```
- `condition` (optional): A string representing the condition for the log message.
- `message`: The log message to be logged.
- `level`: An integer representing the severity level of the log message (0: DEBUG, 1: INFO, 2: WARNING, 3: ERROR, 4: CRITICAL).
- `func` (optional): A function to be logged along with the log message.

Add filters to the logger (optional) through a `lambda`:
You can add filters to the logger to filter log entries based on log levels. For example, to filter log entries to include only INFO, DEBUG, and WARNING levels, you can use the following code:
```python
logger.add_filter(lambda log_entry: g_log.filter_by_log_level(log_entry, ['INFO', 'DEBUG', 'WARNING']))
```

This will add a filter function that checks if the log level of each log entry is in the specified list of levels.

## Example
Here's an example that demonstrates how to use the **`g_log`** library:

```python
from g_log import g_log

def raise_error():
    raise Exception("This is an error raised in TEST")

def main():
    logger = g_log()
    logger.add_filter(lambda log_entry: g_log.filter_by_log_level(log_entry, ['INFO', 'DEBUG', 'WARNING']))
    logger.log(None, "message", 0, raise_error)  # logged
    logger.log(None, "message", 1, raise_error)  # logged
    logger.log(None, "message", 3, raise_error)  # not logged

if __name__ == "__main__":
    main()
```

In this example, we create an instance of the g_log class and add a filter to include only log entries with INFO, DEBUG, and WARNING levels. We then log three messages with different severity levels and an error-raising function. The first two log messages will be logged, but the third one will not be logged due to the filter.

## Customization

The `g_log` library provides some customization options that you can modify according to your needs:

`_exc_info`: A boolean value (True or False) that determines whether to provide more detailed information about exceptions when an error occurs.
`_traceback`: A boolean value (True or False) that determines whether to provide more detailed information about the traceback when an error occurs.
`_accurate`: A boolean value (True or False) that determines whether to use a more detailed date/time format in the log entries.
You can modify these variables in the g_log.py file to customize the behavior of the library.

## Logging Levels

The severity levels in `g_log` increase in severity in the following manner:

**DEBUG**: For debug information.
**INFO**: For informal messages.
**WARNING**: For non-important warnings.
**ERROR**: For severe and important errors.
**CRITICAL**: For critical errors.
You can use these levels when logging messages to indicate the severity of the message.

## Logging Output

The log entries are written to log files with a unique filename generated based on the current timestamp. By default, the maximum number of log files to keep is set to 10, and the maximum size of a log file is set to 1024 bytes. When a log file reaches the maximum size, it is rotated by renaming the current file, creating a backup with a timestamp, and deleting excess backups if the maximum file count is reached.

## Additional Information

For additional information, please refer to the source code and comments in the `g_log.py` file.

Feel free to explore and modify the `g_log` library according to your needs. Happy logging!
