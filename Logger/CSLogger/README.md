# Logging Library for C#

**Author:** Jakob Balkovec

**Date:** July 7, 2023

**Version:** 1.0

**File:** Logger.cs

## Overview

This C# script contains a logging library implemented through the `GLog` class. It provides functionality for logging messages with different severity levels. The script also includes a filter function for filtering log entries based on log levels.

## Constants

- `MaxFiles`: The maximum number of log files to keep.
- `MaxSizeOf`: The maximum size of a log file in bytes.

## Severity Levels

Levels increase with severity in the following manner:

- DEBUG
- INFO
- WARNING
- ERROR
- CRITICAL

## Flags

- `_exc_info`: Provides more detailed information about the exception.
- `_traceback`: Provides more detailed information about the traceback.
- `_accurate`: Provides a more detailed date/time format of the log entry.

   - `_accurate` = true: `{yyyy-MM-dd HH:mm:ss}`
   - `_accurate` = false: `{HH:mm:ss}`

## Constructor

- Initializes a new instance of the `GLog` class.

## Methods

- `GetUniqueFilename(string baseFilename, string extension)`: Generates a unique filename by combining the base filename and an extension.

- `GetLineNumber(Delegate func)`: Retrieves the line number of a method represented by a delegate.

- `AddFilter(Func<string, bool> filterFunc)`: Adds a filter function to the list of log entry filters.

- `ShouldLog(string logEntry)`: Determines whether a log entry should be logged based on the registered filters.

- `Log(string condition, string message, int level, Delegate? func = null)`: Logs an event with a specified condition, message, log level, and an optional delegate for execution.

- `GetTimestamp()`: Gets the current timestamp in an accurate or simplified format.

- `WriteToFile(string logEntry)`: Writes a log entry to the log file.

- `RotateFiles()`: Rotates log files by moving the current log to a backup and removing excess backups.

## Filtering by Log Level

- `FilterByLogLevel(string logEntry, List<string> levels)`: Filters log entries by log level based on a list of log levels.

