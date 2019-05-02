import serial
import subprocess

PORT = '/dev/ttyUSB0'
MSG_PROCEED = b''
VLC_PATH = ""
VIDEO_PATH = r""

if __name__ == "__main__":
    with serial.Serial(PORT) as ser:
        msg_from_arduino = ser.readline().strip()
        if msg_from_arduino == MSG_PROCEED:
            print("Executing vlc...")
            subprocess.run([VLC_PATH, "--fullscreen", VIDEO_PATH])
