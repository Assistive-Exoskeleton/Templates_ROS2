import re
import os

def rename_files(dirName,project_name,allFiles):
    # create a list of file and sub directories 
    # names in the given directory 
	listOfFile = os.listdir(dirName)
    # Iterate over all the entries
	for entry in listOfFile:
        # Create full path
		fullPath = os.path.join(dirName, entry)
		# If entry is a directory then get the list of files in this directory 
		if os.path.isdir(fullPath):
			new_name = re.sub(r"#dir#", project_name , fullPath)
			os.rename(fullPath,new_name)
			rename_files(new_name,project_name,allFiles)
		else:
			new_name = re.sub(r"##", project_name , fullPath)
			os.rename(fullPath,new_name)
			allFiles.append(new_name)
                
	return allFiles
        

def changePlaceholders(param_dict,file_list):
	for file in file_list:
		with open(file, "r+") as f:
			text = f.read()
			f.seek(0)
			for key,value in param_dict.items():
				text = re.sub("#"+key+"#", value, text)
			f.write(text)
			f.truncate()
		f.close()

def getNames():
	P_name = input("Please provide Project name:\n")
	param_dict = {"Pname" : P_name}
	return param_dict



def main():
	print("\n    #################################################\n\
    #### Welcome to ROS2 Control template script ####\n\
    #################################################\n ")
	param_dict = getNames()	
	
	file_list = list()
	file_list = rename_files(os.getcwd(), param_dict["Pname"], file_list)
	changePlaceholders(param_dict, file_list)

if __name__ == "__main__":
	main()
