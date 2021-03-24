import PySimpleGUI as sg

menu_def = ['&File', ['&Open', '!&Save', 'E&xit', 'Properties']]
edit_def = ['Edit', ['&Edit', '&Menu', 'Items', 'Properties']]

layout = [   [sg.ButtonMenu('File', menu_def, key='_FILE_'),
             sg.ButtonMenu('Edit', menu_def,  key='_EDIT_'),],
             [sg.Text('The Menus are the same until you press Change button')],
             [sg.Text('Change button changes Edit Menu Button')],
            [sg.Button('Change Edit Menu'), sg.Button('Exit')]]

window = sg.Window('Window Title',
                   layout,
                   border_depth=0,
                   use_default_focus=False,
                   )

while True:             # Event Loop
    event, values = window.Read()
    if event in  (None, 'Exit'):
        break
    print(event, values)
    if event == '_FILE_':               # if a File menu item chosen
        if values[event] == 'Exit':    # test which item chosen
            break
    elif event.startswith('Change'):
        window.Element('_EDIT_').Update(edit_def)   # change the edit menu definition
    elif event == '_MINIMIZE_':
        window.Minimize()

window.Close()