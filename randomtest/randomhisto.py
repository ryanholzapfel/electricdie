#randomhisto.py

def dictPrintHoriz(dd):
    kk = dd.keys()
    outputTop = "count: |"
    outputMid = "--------"
    outputBot = "roll:  |"
    for key in kk:
        outputTop += str(dd[key])+"|"
        outputMid += "--"
        outputBot += str(key)+"|"
    print(outputTop)
    print(outputMid)
    print(outputBot)


def dictPrintVert(dd):
    kk = dd.keys()
    print("rr : cc")
    for key in kk:
        print(str(key)+" : "+str(dd[key]))


#save serial output of arduino to a text file with comma separated "dice rolls" in one line with no whitespace
with open("./random20-1000") as fileIn:
    #read the file, split it on the commas into a list, convert to int
    ln = fileIn.readline()
    ll = ln.split(",")
    for i in range(len(ll)):
        txt = ll[i]
        ll[i] = int(txt)
    
    #make empty dict, total count, find min and max possible roll
    dd = {}
    total = 0
    maxRoll = max(ll)+1 #add one for the range of the for loop
    minRoll = min(ll)

    #loop through list, counting each instance of any possible roll
    for j in range(minRoll, maxRoll):
        dd[j] = ll.count(j)
        total += dd[j]
    dictPrintVert(dd)
    print("Total Rolls: ",total)