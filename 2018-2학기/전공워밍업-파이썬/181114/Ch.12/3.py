#메뉴 만들기
from PIL import Image, ImageTk, ImageFilter

import tkinter as tk
from tkinter import filedialog as fd

img = None
tk_img = None

rotate = 0

def open():
    global img, tk_img
    fname = fd.askopenfilename()
    img = Image.open(fname)
    tk_img = ImageTk.PhotoImage(img)
    canvas.create_image(250, 250, image=tk_img)
    window.update()

def quit():
    window.quit()

def image_rotate():
    global img, tk_img, rotate
    rotate += 45
    out = img.rotate(rotate)
    tk_img = ImageTk.PhotoImage(out)
    canvas.create_image(250, 250, image=tk_img)
    window.update()

def image_blue():
    global img, tk_img
    out = img.filter(ImageFilter.BLUR)
    tk_img = ImageTk.PhotoImage(out)
    canvas.create_image(250, 250, image=tk_img)
    window.update()

def image_emboss():
    global img, tk_img
    out = img.filter(ImageFilter.EMBOSS)
    tk_img = ImageTk.PhotoImage(out)
    canvas.create_image(250, 250, image=tk_img)
    window.update()

window = tk.Tk()
canvas = tk.Canvas(window, width=500, height=500)
canvas.pack()

menubar = tk.Menu(window)
filemenu = tk.Menu(menubar)
ipmenu = tk.Menu(menubar)

filemenu.add_command(label="열기", command=open)
filemenu.add_command(label="종료", command=quit)

ipmenu.add_command(label="영상회전", command=image_rotate)
ipmenu.add_command(label="영상흐리게", command=image_blue)
ipmenu.add_command(label="엠보싱", command=image_emboss)

menubar.add_cascade(label="파일", menu=filemenu)
menubar.add_cascade(label="영상처리", menu=ipmenu)

window.config(menu=menubar)
window.mainloop()