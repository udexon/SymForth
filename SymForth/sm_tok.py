def sm_tok(T):
    global skk
    print len(T)
    i=0
    L=len(T)
    while (i<L):
        print i
        if (T[i]=='f'):
            print 'forward', skk.forward(float(S.pop()))
        elif (T[i]=='r'):
            skk.right(float(S.pop()))
        else:
            S.append(T[i])
            print S[-1]
        i += 1

def sm(mystring):
    mystring=re.sub('\s+', ' ', mystring).strip()        
    T=mystring.split()
    sm_tok(T)

mystring="90 r 100 f"
mystring=re.sub('\s+', ' ', mystring).strip()        
T=mystring.split()
sm_tok(T)
