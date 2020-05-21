#! /usr/bin/env python3

import sys
import json

def calculate_frames(x: int, y: int, nbr_frames: int, w: int, h: int):

    frames = []
    for j in range(nbr_frames):
        frame = dict()
        frame["x"] = (x + j * w)
        frame["y"] = 0
        frame["w"] = w
        frame["h"] = h
        frames.append(frame)
    return frames


def create_animation():

    animation = dict()
    animation["name"] = input("enter name: ")
    print(animation["name"])
    animation["total_time"] = int(input("enter total_time: "))
    print(animation["total_time"])
    animation["switch_to"] = input("enter switch to: ")
    print(animation["switch_to"])
    animation["loop"] = input("false or true: ")
    if (animation["loop"] == "false") : animation["loop"] = False
    else : animation["loop"] = True
    return animation

if __name__ == "__main__": 

    if (len(sys.argv) < 6):
        print("usage: you have to write 4 arguments:)\n follow the ex: python3 anim_enemy_cutter.py x y nbr_frames w h")
        sys.exit(84)

    x = int(sys.argv[1])
    y = int(sys.argv[2])
    nbr_frames = int(sys.argv[3])
    w = int(sys.argv[4])
    h = int(sys.argv[5])

    animation = create_animation()
    animation["frames"] = calculate_frames(x, y, nbr_frames, w, h)

    print(json.dumps(animation))
