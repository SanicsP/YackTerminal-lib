#coding:utf-8

#deploiment script for YackTerminal Library 

import pathlib
import shutil
import subprocess


#=========names================================================

destination_dir_name = "YT_LIB_TEST"
destination_licence_dir_name = "Licence"
readme_file_name = "readme.md"


#=============================================================

#=========================source paths================================

YackTerminal_lib_path = pathlib.Path("../YT_Library")
YackTerminal_doc_path = pathlib.Path("../Doc")
YackTerminal_readme_path = pathlib.Path("..") / readme_file_name

#===============================================================


#============dest directories===================================================
destination_directory = pathlib.Path("../")/destination_dir_name
destination_directory_src = destination_directory / "src"
destination_directory_doc = destination_directory / "documentation"
destination_directory_readme = destination_directory / readme_file_name
#========================================================================================







def init_destination_dir() : 
	if destination_directory.exists() : 
		print("rebuilding lib in directory" , destination_directory)
		shutil.rmtree(destination_directory)
	else : 
		print("building library in : " , destination_directory)

	shutil.copytree(YackTerminal_lib_path , destination_directory)
	shutil.copytree(YackTerminal_doc_path , destination_directory_doc)
	shutil.copyfile(YackTerminal_readme_path , destination_directory_readme)

	#shutil.rmtree(destination_directory_src)


try :
	init_destination_dir()
except FileExistsError :
	print("if you want rebuild the library you must remove the folder :" , destination_directory)
finally : 
	print("build terminated")

