import serial
import sys
from sys import stdout
import threading
import tkinter as tk
from tkinter import *


root = tk.Tk()

start = tk.Label(root, text="press 's' to start the game.")
start.pack(pady=20)

def key_pressed(event):
    if event.char == 'q':
        root.quit()

frame = tk.Frame(root, width=400, height=100)

root.bind('<Key>', key_pressed)

menu = Menu(root)
root.config(menu=menu)
filemenu = Menu(menu)
menu.add_cascade(label="File", menu=filemenu)

menu = Menu(root)
root.config(menu=menu)

frame.pack(pady=20)

root.mainloop()

