#! /usr/bin/env python3

import sys
import json

LARGEUR_FRAME = 48
HAUTEUR_FRAME = 72

ANIMATION_NAMES = ["down", "left", "right", "up"]
IDLE_ANIM_NAME  = ["idle_down", "idle_left", "idle_right", "idle_up"]

def calculate_frames(x: int, y: int):
    animations = []
    for i in range(4):
        animation = dict()
        animation["name"] = ANIMATION_NAMES[i]
        frames = []
        for j in range(3):
            frame = dict()
            frame["x"] = (x + j * LARGEUR_FRAME)
            frame["y"] = (y + i * HAUTEUR_FRAME)
            frame["w"] = LARGEUR_FRAME
            frame["h"] = HAUTEUR_FRAME
            frames.append(frame)
        animation["frames"] = frames
        animation["total_time"] = 500
        animation["loop"] = False
        animations.append(animation)

    for i in range(4):
        animation = dict()
        animation["name"] = IDLE_ANIM_NAME[i]
        frames = []
        frames.append({
            "x" : x + 1 * LARGEUR_FRAME,
            "y" : y + i * HAUTEUR_FRAME,
            "w" : LARGEUR_FRAME,
            "h" : HAUTEUR_FRAME
        })
        animation["frames"] = frames
        animation["total_time"] = 100
        animation["loop"] = True
        animations.append(animation)
    return animations

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Error parameters: ./anim_perso_cutter.py x y")
        exit(1)
    animations = calculate_frames(int(sys.argv[1]), int(sys.argv[2]))
    print(json.dumps(animations))