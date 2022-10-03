a=int(input())
b=input()

if a==1:
    
    print(b)
else:
    
    b=list(b)
    c=0
    f=""


    for i in range(len(b)):
        if i == 0:
            
            c+=1
            d=i+c
            b.insert(d,"1")
        else:
            c+=1+i
            d=i+c
            b.insert(d,"1")


    for i in range(len(b)):
        if b[i] == "1":
            f+=b[i-1]
        else:
            pass

    g=f.find("1")
    print(f[:g])
