#!/usr/bin/python
import sys

# 
# INSERT DESCRIPTION HERE
#
def justify(file_name, justify_length):
    # COMPLETE ME
    file = open(file_name, 'r')
    letters = 0

    for line in file:
	handle_line(line, justify_length)

def handle_line(line, justify_length):
	if (len(line) > justify_length):
		#line needs to be split
		arr = line.split()
		length = 0;
		prev = 0;
		string = ""
		for i in range(0, len(arr)):
			length += len(arr[i])
			length += 1
			string += arr[i] + " "
			if (length >= justify_length):
				if (prev == i):
					handle_line(arr[i][:justify_length],
					  justify_length)
					handle_line(arr[i][justify_length:], 
					  justify_length)
					string = ""
					length = 0
				else:
					handle_line(string[:(-1 -
					  len(arr[i]))], justify_length)
					string = arr[i] + " "
					length = len(string)
					prev = i;
			#Handle the leftover, if any
		if (len(string) > 0):
			handle_line(string[:-1], justify_length)
	else:
		arr = line.split()
		letters = 0
		for word in arr:
			letters += len(word)
		subtract = justify_length - letters
		if (len(arr) > 1):
		    inc = subtract / (len(arr) - 1)
		    whitespaces = []
		    for i in range(0, len(arr) - 1):
			whitespaces.append(inc)
		    remainder = subtract - inc * (len(arr) - 1)
		#for w in whitespaces:
		#    if (remainder > 0):
		#	w = w + 1
		#	remainder--
		for i in range(0, len(arr)):
		    sys.stdout.write(arr[i])
		    if (i < len(arr) - 1):
			sys.stdout.write(" " * inc)
			if (remainder > 0):
			    sys.stdout.write(" ")
			    remainder -= 1
		sys.stdout.write("\n")
		#print arr[0] + subt



# Program justifies text contents of a given file
# This is the actual code that gets run when the
# program is run. 
#
# DO NOT EDIT BELOW HERE.
if __name__ == "__main__":

    file_name = ''
    length = -1

    # Parse command line arguments
    try:
        for i in range(len(sys.argv)):
            if sys.argv[i] == '-f':
                file_name = sys.argv[i+1]
            elif sys.argv[i] == '-l':
                length = int(sys.argv[i+1])
    except:
        exit('Input error. Example input: justifytext -f mytextfile -l 80')

    if file_name == '' or length < 1:
        exit('Input error. Example input: justifytext -f mytextfile -l 80')
        
    justify(file_name, length)
