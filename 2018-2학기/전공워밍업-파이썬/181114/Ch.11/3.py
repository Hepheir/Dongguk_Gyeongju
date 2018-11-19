file = open("a.txt", "r")
for line in file:
    line = line.rstrip()
    print(line)
file.close()