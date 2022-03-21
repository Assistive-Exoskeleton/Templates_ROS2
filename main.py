import re
import os
import shutil
from src.dictionaries import *

def rename_files(dirName,allFiles,param_dict):
    # create a list of file and sub directories 
    # names in the given directory 
	listOfFile = os.listdir(dirName)
    # Iterate over all the entries		
	for entry in listOfFile:

		if entry not in ignores: 
			# Create full path
			fullPath = os.path.join(dirName, entry)
			new_path = fullPath 
			for key,value in param_dict.items():
				new_path = re.sub("#"+key+"#", value, new_path)

			os.rename(fullPath,new_path)

			if os.path.isdir(new_path):
				rename_files(new_path,allFiles,param_dict)
			else:
				allFiles.append(new_path)
			
                
	return allFiles	#this function returns list of files in all subfolders
        

def rename_text(file_list,param_dict):
	for file in file_list:
		with open(file, "r+") as f:
			text = f.read()
			f.seek(0)
			for key,value in param_dict.items():
				text = re.sub("#"+key+"#", value, text)
			f.write(text)
			f.truncate()
		f.close()

def getNames(param_dict):
	for key in param_dict.keys():
		P_name = input(f"Please provide {key}:\n")
		if P_name!="":
			param_dict[key] = P_name

def choose_modality():
	while True:
		choose = int(input(banners[1]))
		if choose > len(param_dict)+1 or choose < 0: #minimal error filtering 
			continue
		break
	return choose
		

def main():
	print(banners[0])
	
	dict_n = choose_modality()

	if dict_n > 0:

		os.system("clear -x")
		
		#prepare final directory
		shutil.copytree(os.getcwd()+"/src/"+str(dict_n), os.getcwd()+"/result",dirs_exist_ok=True)

		print(banners[dict_n+1])

		getNames(param_dict[dict_n-1])	
		
		file_list = list()
		file_list = rename_files(os.getcwd()+"/result", file_list, param_dict[dict_n-1])
		rename_text(file_list, param_dict[dict_n-1])

		print("\nPackage created successfully\n")

if __name__ == "__main__":
	main()
