# File Organizer

**Author:** Jakob Balkovec  
**Date:** August 28, 2023  
**Version:** 1.0  
**License:** This code is licensed under the MIT License.

## File

- `main.py`

## Description

This script implements a sentiment analysis algorithm that determines the sentiment polarity (positive, negative, or neutral) of textual data. It utilizes the TextBlob library for sentiment analysis.

## Usage

Run this script with the necessary dependencies installed and provide the name of the folder you would like to organize. The script will organize the files in that folder.

## Example

```sh
$ python main.py
```

## Imports
- `os`
- `shutil`
- `sys`
- `List from typing`
- `tqdm`
- `constants`

## Functions

### `get_extension(file_name: str) -> str`
Returns the extension of a file name.

### `move_file(subcategory_dir: str, file: str) -> None`
Moves a file to a specified subcategory directory.

### `organize_files(files: List[str]) -> None`
Organizes files into different categories based on their file extensions.

### `quit(exit_code: int) -> None`
Exits the program with a specified exit code.

### `establish_current_dir() -> List[str]`
Establishes the current directory and returns a list of files in the directory.

### `main() -> None`
Main function of the script.

## Testing

The script includes testing functionalities. Run tests using the run_test() function.

Note: This README provides a summary of the code. For the complete code and details, refer to the main.py file.
