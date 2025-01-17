import subprocess

# Define the full path to the VLC executable
vlc_path = r"C:\Program Files\VideoLAN\VLC\vlc.exe"

# Define the path to the video file
video_file_path = r"D:\Videos\Movies\[MM] Neymar (2023) MultiAudio 1080p HS WEBDL HEVC x265.mkv"

# Specify the command to open the video using VLC
vlc_command = f'"{vlc_path}" "{video_file_path}"'

# Use subprocess to execute the VLC command
subprocess.Popen(vlc_command, shell=True)
