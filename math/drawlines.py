import sys
from PIL import Image, ImageDraw
from random import randint

def drawlines(l):
    with Image.open("blank.png") as im:
        draw = ImageDraw.Draw(im)
        for i in range(0,len(l),4):
            e = l[i:i+4]
            c = ["#ff0000", "#00ff00", "#0000ff", "#ffff00", "#ff00ff", "#00ffff"][randint(0,5)]
            #print(e,c)
            draw.line(e, fill=c)
        with open("out.png", "wb") as imo:
            im.save(imo, "PNG")

if __name__ == "__main__":
    l = [int(float(s)*100) for s in input(">").split(',')]
    #print(l)
    if (len(l)%4==0):
        drawlines(l)
