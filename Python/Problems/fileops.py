# merging 2 files
with open('file1.txt','r') as f1, open('file2.txt') as f2, open('merged.txt','w') as out:
    out.write(f1.read()+'\n'+f2.read())

with open('merged.txt') as out:
    print(out.read())

# ---------------------------------------------
print()
# reading file line by line and omitting line if start symbol is $
with open('file2.txt') as f:
    for line in f:
        if(line[0] == '$'):
            continue
        print(line.strip())