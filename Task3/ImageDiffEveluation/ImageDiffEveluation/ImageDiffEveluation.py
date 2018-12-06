#The program return an RMS value, which depends on the images, the more different they are, the higher the value; 
from PIL import Image
from PIL import ImageChops
import math
#from skimage.measure import compare_ssim

import glob


im1 = Image.open("../../test_data/diff_test/test_image_1.png")
im2 = Image.open("../../test_data/diff_test/test_image_2.png")

#Root-Mean-Squere https://en.wikipedia.org/wiki/Root-mean-square_deviation
diff = ImageChops.difference(im2, im1)
h = diff.histogram()
sq = (value*((idx%256)**2) for idx, value in enumerate(h))
sum_of_squares = sum(sq)
rms = math.sqrt(sum_of_squares / float(im1.size[0] * im1.size[1]))
print(rms)