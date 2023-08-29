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
    This script is a Python program designed to organize files 
    within a specified directory into different categories 
    based on their file extensions. It aims to enhance file 
    organization and grouping for better management. The script 
    achieves this by moving files into subdirectories that correspond
    to specific categories such as programming languages, file types, and data formats.
    
@usage:
    Run the executable with the necessary dependencies installed and provide the name of the folder
    you would like to organized. The script will organize the files in that folder.
    
@example:
    $ python main.py
"""

"""_imports_"""
from tkinter import *
import os
from ttkthemes import ThemedTk
from tkinter import filedialog, messagebox, ttk
from constants import *
from main import establish_current_dir, organize_files

"""_constants_"""
BG_COLOR_ = "#252629" 

"""_summary_
_desc_: opens a file dialog to browse a folder and update the label with the selected folder name.

_param_: folder_label (str): The label to update with the selected folder name.

_returns_: None
"""
def browse_folder(folder_label: str):
    global target_folder
    target_folder = filedialog.askdirectory()
    folder_name = os.path.basename(target_folder)
    folder_label.config(text=f"Selected Folder: {folder_name}")

"""_summary_
_desc_: organizes files in the target folder usinq the gui.

_param_: None

_returns_: None
"""
def organize_files_gui():
    if not target_folder:
        messagebox.showerror("Error", "Please select a folder.")
        return

    files = establish_current_dir()
    organize_files(files)
    messagebox.showinfo("Success", "Files organized.")

"""_summary_
_desc_: initializes the main GUI window for the File Organizer application.

_param_: None
    
_returns_: None
"""
def main():
    root = ThemedTk(theme="Adapta")
    root.title("File Organizer")
    
    root.geometry("400x200")
    root.configure(bg=BG_COLOR_)

    folder_label_frame = Frame(root) 
    folder_label_frame.pack(side="top", fill="x", pady=0) 
    
    folder_label = Label(folder_label_frame, text="Selected Folder: ")
    folder_label = Label(folder_label_frame, text="Selected Folder: ", foreground="#FFFFFF")
    folder_label.pack(side="top", anchor="center")
    
    made_by_label = Label(root, text="Made by Jakob™", fg = "#9d9ea3", bg = BG_COLOR_, font=("Helvetica", 32))
    made_by_label.place(relx=0.5, rely=0.5, anchor="center")
    
    style = ttk.Style()
    style.configure("Custom.TButton", foreground="#FFFFFF", background="#FFFDD0",
                    borderwidth=0, relief="groove")

    button_frame = Frame(root, bg= BG_COLOR_) 
    button_frame.pack(side="bottom")

    select_folder_button = ttk.Button(button_frame, text="Select Folder", command=lambda: browse_folder(folder_label), style="Custom.TButton")
    select_folder_button.pack(side="left", padx=10, pady=20)

    organize_button = ttk.Button(button_frame, text="Organize Files", command=organize_files_gui, style="Custom.TButton")
    organize_button.pack(side="right", padx=10, pady=20)
    
    root.mainloop()

if __name__ == "__main__":
    target_folder = ""
    main()
