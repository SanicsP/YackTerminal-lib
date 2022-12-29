#coding:utf-8

#deploiment script for YackTerminal Library 

import pathlib
import shutil

destination_dir_name = "YT_LIB"
YackTerminal_lib_path = pathlib.Path("../YT_Library")
destination_directory = pathlib.Path("../")/destination_dir_name
destination_directory_src = destination_directory / "src"




print(YackTerminal_lib_path , pathlib.Path.exists(YackTerminal_lib_path))

def init_destination_dir() : 
	shutil.copytree(YackTerminal_lib_path , destination_directory)
	shutil.rmtree(destination_directory_src)




