
import time
import keyboard

TIME = 1.2
def pressKey():
    print("Press key at 2 sec\n")

    while True:
        if keyboard.is_pressed('q'):  # if key 'q' is pressed 
            print('You Pressed q!')
            break  # finishing the loop

        print("press down\n")
        for i in range(2):
            keyboard.press_and_release('page up')
            time.sleep(TIME)

        for i in range(2):
            keyboard.press_and_release('page down')
            time.sleep(TIME)
        time.sleep(1.5)



def main():
    print("Hello World!")
    time.sleep(2)
    pressKey()
  

if __name__ == "__main__":
    main()