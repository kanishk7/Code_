from sys import argv
import os

name = str(argv[1])
output = open(name,"w")
print """We are going to write over filename %s. Do you want that? 
Press CTRL+C to abort. Press RETURN to continue. """ %(name)
raw_input("?")

print "Now enter any three lines."
line1 = raw_input("Line 1:")
line2 = raw_input("Line 2:")
line3 = raw_input("Line 3:")
print "Writing to file"

output.write(line1)
output.write("\n")
output.write(line2)
output.write("\n")
output.write(line3)
output.write("\n")

print "Closing file."
output.close()
