import tkinter as tk

root = tk.Tk()

start = tk.Label(root, text="press 's' to start the game.")
start.pack()
quitGame = tk.Label(root, text="press 'q' to quit the game.")
quitGame.pack()

def key_pressed(event):
    if event.char == 's':
        print("Start")
    if event.char == 'q':
        root.quit()

frame = tk.Frame(root, width=800, height=600)
root.bind('<Key>', key_pressed)
frame.pack()

root.mainloop()