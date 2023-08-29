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
    contants.py

@description:
    This file contains the constants used throughout the program
    
@usage:
    Chnage the value of the TARGET_DIR_ variable to the folder you would like organized.
"""

"""_imports_"""
import os
import shutil
from typing import List
import random
import string

from constants import *

_MAX_ = 100

"""_summary_
_desc_: creates a new directory and moves a randomly generated file into it.

_param_: None

_returns_: None
"""
def make_dir() -> None:
    random_sequence = ''.join(random.choice(string.ascii_lowercase) for _ in range(4))
    
    all_extensions = (
        IMAGES_ + TEXT_ + VIDEO_ + AUDIO_ + APPLICATIONS_ + CODE_ +
        INSTALL_ + COMPRESSED_ + DOCUMENTS_ + OTHER_
    )
    random_extension = random.choice(all_extensions)
    
    file_name = random_sequence + random_extension
    
    with open(file_name, "w") as f:
        pass
    
    shutil.move(file_name, os.path.join(TARGET_DIR_, file_name))

"""_summary_
_desc_: create a directory if it doesn't exist.

_param_: None

_returns_: None
"""
def establish() -> None: 
    if not os.path.exists(TARGET_DIR_):
        os.makedirs(TARGET_DIR_)

"""_summary_
_desc_: deletes the directory specified by the constant TARGET_DIR_.

_param_: None

_returns_: None
"""
def delete_dir():
    shutil.rmtree(TARGET_DIR_)

"""_summary_
_desc_: run the test by establishing a connection and creating directories.

_param_: None

_returns_:
    None
"""
def run_test():
    establish()
    for i in range(_MAX_):
        make_dir()
        
        