import sys
import os.path
from os import path

class CodeGenerator:
	
	folder_path = "test"
	def __init__(self, path, fd):
		self.path = path
		self.fd = fd

	@staticmethod	
	def writeHeader(fd, name):
		fd.write("/* ************************************************************************** */\n")
		fd.write("/*                                                                            */\n")
		fd.write("/*                                                        :::      ::::::::   */\n")
		fd.write("/*   "+ name)
		for i in range(51 - len(name)):
			fd.write(" ")
		fd.write(":+:      :+:    :+:   */\n")
		fd.write("/*                                                    +:+ +:+         +:+     */\n")
		fd.write("/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */\n")
		fd.write("/*                                                +#+#+#+#+#+   +#+           */\n")
		fd.write("/*   Created: 2019/03/28 11:02:58 by ldedier           #+#    #+#             */\n")
		fd.write("/*   Updated: 2019/03/28 11:02:58 by ldedier          ###   ########.fr       */\n")
		fd.write("/*                                                                            */\n")
		fd.write("/* ************************************************************************** */\n\n")

	@classmethod
	def generateCode(self):
		for line in fd:
			split = line.rstrip().split("\t")
			split = filter(None, split)
			filename = CodeGenerator.folder_path + "/" + split[1] + ".c"
	#		print "\t\t\t\t" + filename.split("/")[1];
			if (not os.path.exists(filename)):
				wfd = open(filename, 'w')
				CodeGenerator.writeHeader(wfd, split[1] + ".c")
				wfd.write("#include \"libftasm_checker.h\"\n\n")
				wfd.write(line.strip('\n') + "(void)\n{\n\treturn (0);\n}\n")
			else:
				print filename + " already exists."

if (len(sys.argv) > 1):
	path = sys.argv[1]
else:
	sys.exit("you shall add a path")
try:
  	fd = open(path, "r")
except:
	sys.exit("could not open %s" % path)

gen = CodeGenerator(path, fd)
gen.generateCode()
