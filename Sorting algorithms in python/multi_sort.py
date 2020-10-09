

# Q3 Sorts


def i_sort(li):
    for x in range (1,len(li)):
        
        for y in range(x,0,-1):
            if( li[y] < li[y-1]):
                li[y],li[y-1] = li[y-1],li[y]
            else:
                break   
    return li



def b_sort(li):
    for x in range(len(li)):
        for y in range(len(li)-x-1):
            if(li[y] > li[y+1]):
                li[y],li[y+1] = li[y+1],li[y]
    return li


def s_sort(li):
    for x in range(len(li)):
        for y in range(x,len(li)):
            if (li[x] > li[y]):
                hold = li[x]
                li[x] = li[y]
                li[y] = hold
    return li



def m_sort(li):
    mid = len(li)//2
    left=[]
    right=[]

    for x in range(0,mid):
        left.append(li[x])
    i_sort(left)
    
    for x in range(mid,len(li)):
        right.append(li[x])
    i_sort(right)

    i=0
    for x in range(0,len(li),2):
        if (left[i]<right[i]):
            li[x]=left[i]
            li[x+1]=right[i]
        else:
            li[x]=right[i]
            li[x+1]=left[i]
        i=i+1

    return li


def main():


    listed = [10,2,25,15,5,3] #assumed

    while True:
        li=listed.copy()
        x = int(input("Enter Sorting Algorithm\n1.Insertion Sort\n2.Bubble Sort\n3.Selection Sort\n4.Merge Sort\n>>"))

        if(x==1):
            print("Insertion Sort:",i_sort(li))
        elif(x==2):
            print("Bubble Sort:",b_sort(li))
        elif(x==3):
            print("Selection Sort:",s_sort(li))
        elif(x==4): 
            print("Merge Sort",m_sort(li))
        else:
            break




if __name__ == '__main__':main()
