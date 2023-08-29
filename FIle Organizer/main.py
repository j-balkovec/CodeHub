"""_File Organizer_
@author:
    Jakob Balkovec

@date:
    August 28, 2023

@version:
    1.0

@license:
    This code is licensed under the MIT License.

@file:
    main.py

@description:
    This script implements a sentiment analysis algorithm that determines the sentiment 
    polarity (positive, negative, or neutral) of textual data. 
    It utilizes the TextBlob library for sentiment analysis.
    
@usage:
    Run this script with the necessary dependencies installed and provide the name of the folder
    you would like to organized. The script will organize the files in that folder.
    
    
@example:
    $ python main.py
"""

"""_imports_"""
import os
import shutil
import sys
from typing import List
from tqdm import tqdm

from constants import *

#---
# Imported for testing purposes only
#---
from test import run_test, delete_dir

"""_summary_
_desc_: returns the extension of a file name.

_param_: file_name (str): The name of the file.

_returns_: str: The extension of the file name.
"""
def get_extension(file_name: str) -> str:
    return "." + file_name.split(".")[-1].lower()            

def move_file(subcategory_dir: str, file: str) -> None:
    if not os.path.exists(os.path.join(TARGET_DIR_, subcategory_dir)):
        os.makedirs(os.path.join(TARGET_DIR_, subcategory_dir))
 
    source_path = os.path.join(TARGET_DIR_, file)
    destination_path = os.path.join(TARGET_DIR_, subcategory_dir, os.path.basename(file))
    shutil.move(source_path, destination_path)
    
"""_summary_
_desc_: organizes files into different categories based on their file extensions.

_param_: files (List[str]): A list of file paths.
    
_returns_: None: This function does not return anything.
"""          
def organize_files(files: List[str]) -> None:
    #for file in files:
    for file in tqdm(files, desc="\n[organizing files]", unit="file"):
        if file.lower() != MAKEFILE_:
            extension = get_extension(file)
        else:
            extension = "Makefile"
        
        for extensions, category in file_extensions.items():
            if extension in extensions:
                category_dir = category
                if extension in [".cpp", ".hpp", ".asm", "Makefile"]:
                    subdir_name = "Cpp"
                elif extension in [".c", ".h", ".pch", ".o", ".a"]:
                    subdir_name = "C"
                elif extension in [".java"]:
                    subdir_name = "Java"
                elif extension in [".py", ".pyw", ".ipynb"]:
                    subdir_name = "Python"
                elif extension in [".js", ".html", ".css", ".scss", ".sass", ".php", ".ts"]:
                    subdir_name = "Web"
                elif extension in [".rb"]:
                    subdir_name = "Ruby"
                elif extension in [".cs", ".vs"]:
                    subdir_name = "CSharp"
                elif extension in [".rs"]:
                    subdir_name = "Rust"
                elif extension in [".xlsx", ".xls"]:
                    subdir_name = "Spreadsheets"
                elif extension in [".pptx", ".ppt"]:
                    subdir_name = "Presentations"
                elif extension in [".csv", ".dat", ".db", ".dbf", ".log", ".mdb", ".sav", ".sql", ".json", ".xml"]:
                    subdir_name = "Data-Sets"
                elif extension in [".git"]:
                    subdir_name = "Git"
                elif extension in [".exe"]:
                    subdir_name = "Executables"
                else:
                    #check if no subdirs are present
                    subdir_name = OTHER_STR_
                    
                move_file(os.path.join(category_dir, subdir_name), file)
                break
        else:
            move_file(os.path.join(OTHER_STR_), file)

"""_summary_
    _desc_: exits the program.
    _returns_: None
    _param_: exit_code: int corresponding to the exit code
"""
def quit(exit_code: int) -> None:
    sys.exit(exit_code)

"""_summary_
    _desc_: establishes the current directory and returns a list of files in the directory.

    _returns_: List[str]: A list of file names in the current directory.

    _raises_: FileNotFoundError: If the target directory is not found.
"""
def establish_current_dir() -> List[str]:
    try:
        with os.scandir(TARGET_DIR_) as entries:
            files = [entry.name for entry in entries] # if entry.is_file()
            return files
        
    except FileNotFoundError:
        print(ERROR_MSG_)   
        quit(exit_code=1)
    
def main() -> None:
    run_test()
    #files = establish_current_dir()
    #organize_files(files)
    #input("\nPress [Enter] to continue...")
    #delete_dir()
    

if __name__ == "__main__":
  main()