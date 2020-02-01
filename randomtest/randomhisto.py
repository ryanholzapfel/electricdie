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



with open("/Users/ryan/Documents/Arduino/randomtest/random20-1000") as fileIn:
    ln = fileIn.readline()
    ll = ln.split(",")
#    for i in ll:
#        ll[i] = int(ll[i])
    dd = {}
    total = 0
    for j in range(1,21):
        dd[j] = ll.count(str(j))
        total += dd[j]
    dictPrintVert(dd)
    print("Total Rolls: ",total)