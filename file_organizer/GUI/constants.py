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
    constants.py

@description:
    This file contains the constants used throughout the program
    
@usage:
    Change the value of the TARGET_DIR_ variable to the folder you would like organized.
"""

'''_Could be changed to "Desktop" or any folder you would like organized_'''

TARGET_DIR_ = "__TEST__"

'''_List is unhashable, using tuples instead_'''

IMAGES_ = (".jpeg", ".png", ".jpg", ".gif", 
           ".bmp", ".svg", ".tiff", ".heic", ".webp")

TEXT_ = (".txt", ".rtf", ".md")

VIDEO_ = (".mp4", ".mkv", ".avi", ".mov", 
          ".wmv", ".flv", ".ogg", ".webm")

AUDIO_ = (".mp3", ".wav", ".m4a", ".flac")

APPLICATIONS_ = (".exe", ".lnk", ".msi", ".app")

CODE_ = (".cpp", ".hpp", ".asm", ".js", ".html", ".css", ".scss", 
        ".sass", ".php", ".ts", ".c", ".h", ".pch", ".o", ".a", 
        ".java", ".rb", ".rs", ".py", ".pyw", ".ipynb", ".cs", ".vs"
        ".xcodeproj")

INSTALL_ = (".dmg", ".pkg", ".deb", ".rpm")

COMPRESSED_ = (".zip", ".rar", ".tar", ".gz", ".7z")

DOCUMENTS_ = (".doc", ".pdf", ".docx", ".ppt", ".pptx", ".odt", ".ods",
              ".xls", ".xlsx", ".csv", ".dat", ".db", ".dbf", ".log", 
              ".mdb", ".sav", ".sql", ".json", ".xml")

OTHER_ = ("",)

'''_file categories used in organize_files()_'''
file_extensions = {
    IMAGES_: "Images",
    TEXT_: "Text",
    VIDEO_: "Video",
    AUDIO_: "Audio",
    APPLICATIONS_: "Applications",
    CODE_: "Code",
    INSTALL_: "Install",
    COMPRESSED_: "Compressed",
    DOCUMENTS_: "Documents",
    OTHER_: "Other"
}

'''_other constants defined for clarity_'''
MAKEFILE_ = "makefile"

OTHER_STR_ = "Other"

ERROR_MSG_ = f"[{TARGET_DIR_} directory not found]\n"
