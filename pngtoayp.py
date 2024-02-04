from PIL import Image

def convertion(source_path : str, dest_path : str):
    assert source_path[-4:] == ".png" and dest_path[-4:] == ".ayp", "usage pngtoayp.py <source png file> <dest ayp file>"
    #open image
    im = Image.open(source_path)
    pxl = im.load()
    #write new one
    with open(dest_path, "wb") as dest:
        #header
        file_size = (22 + im.height * im.width * 3).to_bytes(4, 'little')
        height = im.height.to_bytes(4, 'little')
        width = im.width.to_bytes(4, 'little')
        dest.write(b"AY" + file_size + b"AYPIMANN" + height + width)
        #pixels
        for y in range(im.height):
            for x in range(im.width):
                p = pxl[x,y]
                b = p[0].to_bytes(1) + p[1].to_bytes(1) + p[2].to_bytes(1)
                dest.write(b)


if __name__ == "__main__":
    from sys import argv
    assert len(argv) == 3, "usage pngtoayp.py <source png file> <dest ayp file>"
    convertion(argv[1], argv[2])