from Tkinter import *
import random
import tkMessageBox   
 
root = Tk(className = "2048")
root.geometry("320x360")
 
str_data=[]
B_list = []
frame2 = Frame(root,borderwidth = 10)
dic_color = {0:'GhostWhite', 2:'AliceBlue', 4:'LightCyan', 8:'Khaki',16:'SandyBrown', 32:'Goldenrod',64:'Orange',128:'Maroon',256:'Tomato',512:'OrangeRed',1024:'FireBrick',2048:'Red'}
list_data=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
left=0
up=1
right=2
down=3
derection_index=[   [[0,1,2,3],[4,5,6,7],[8,9,10,11],[12,13,14,15]], 
                    [[0,4,8,12],[1,5,9,13],[2,6,10,14],[3,7,11,15]],
                    [[3,2,1,0],[7,6,5,4],[11,10,9,8],[15,14,13,12]],
                    [[12,8,4,0],[13,9,5,1],[14,10,6,2],[15,11,7,3]]   ]
 
for i in range(16):
    str_data.append(StringVar())
    B_list.append(Button(frame2, width=4, height=2, textvariable = str_data[i]  ,font = ("Courier 20 bold roman"),bg=dic_color[0]))
    B_list[i].grid(row=i/4,column=i%4)
 
def CanMove(derection, index):
    for i in range(1, 4):
        if list_data[derection_index[derection][index][i]] == list_data[derection_index[derection][index][i-1]]:
            return True
        if list_data[derection_index[derection][index][i]] != 0 and list_data[derection_index[derection][index][i-1]] == 0:
            return True
    return False
 
def DealSpace(derection, index):
    for i in [3,2,1]:
        if list_data[derection_index[derection][index][i]] == 0:
            continue
        if list_data[derection_index[derection][index][i-1]] == 0:
            j = i
            while (j < 4):
                list_data[derection_index[derection][index][j-1]] = list_data[derection_index[derection][index][j]]
                list_data[derection_index[derection][index][j]] = 0
                j=j+1
 
def DealEqualNum(derection, index):
    for i in [0,1,2]:
        if list_data[derection_index[derection][index][i]] == list_data[derection_index[derection][index][i+1]]:
            list_data[derection_index[derection][index][i]] = list_data[derection_index[derection][index][i]] * 2
            list_data[derection_index[derection][index][i+1]] = 0
 
def Move(derection, index):
    DealSpace(derection, index)
    DealEqualNum(derection, index)
    DealSpace(derection, index)
 
def Refresh():
    for i in range(16):
        B_list[i].configure(bg=dic_color[list_data[i]])
        if list_data[i] == 0:
            str_data[i].set("")
            continue
        str_data[i].set(str(list_data[i]))
         
def key_event(event):
    canmovelist = []
    derection_code = 9
    global list_data
 
    if event.keycode == 37:
        derection_code = left
    if event.keycode == 39:
        derection_code = right
    if event.keycode == 38:
        derection_code = up
    if event.keycode == 40:
        derection_code = down
 
    for i in range(4):
        if CanMove(derection_code, i):
            Move(derection_code, i)
            canmovelist.append(i)
 
    if len(canmovelist) == 0:
        return
    list_data[derection_index[derection_code][canmovelist[random.randint(0,len(canmovelist)-1)]][3]] = 2
    Refresh()
    for i_derection in range(4):
        for i_index in range(4):
            if CanMove(i_derection, i_index):
                return
    tkMessageBox.showinfo('Game Over','Your score is %u.\n' % sum(list_data))
    list_data=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    Refresh()
 
frame2.bind('<KeyRelease>', key_event)
frame2.pack()
frame2.focus_set()
root.mainloop()
