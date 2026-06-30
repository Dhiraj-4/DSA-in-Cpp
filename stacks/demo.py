import mss
import keyboard
import time
import os

# Create folder to save images
folder_name = "screenshots"
if not os.path.exists(folder_name):
    os.makedirs(folder_name)

def take_screenshot():
    with mss.mss() as sct:
        # Capture all monitors
        timestamp = int(time.time())
        output = f"{folder_name}/shot_{timestamp}.png"
        sct.shot(output=output)
        print(f"Screenshot saved: {output}")

# Set shortcut key (e.g., Ctrl+Shift+S)
print("Press Ctrl+Shift+S to take a screenshot. Press ESC to exit.")
keyboard.add_hotkey('ctrl+shift+s', take_screenshot)

keyboard.wait('esc')
