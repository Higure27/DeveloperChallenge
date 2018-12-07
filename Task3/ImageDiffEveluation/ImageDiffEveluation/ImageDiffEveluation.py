#The program return an RMS  and SSIM values.
# Dependending on the images, the more different they are, the higher the value for RMS.
# For SSIM the the more different they are the closer the value is to -1. The more similarties they have the closer the value is to 1. 
from PIL import Image
from PIL import ImageChops
import math
from skimage.measure import compare_ssim as ssim
import imageio
import glob


im1 = Image.open("../../test_data/diff_test/test_image_1.png")
im2 = Image.open("../../test_data/diff_test/test_image_2.png")

image_list = []
for filename in glob.glob('../../test_data/2D_registration/*.jpg'): #assuming gif
    im=imageio.imread(filename)
    image_list.append(im)

#Root-Mean-Squere https://en.wikipedia.org/wiki/Root-mean-square_deviation
diff = ImageChops.difference(im2, im1)
h = diff.histogram()
sq = (value*((idx%256)**2) for idx, value in enumerate(h))
sum_of_squares = sum(sq)
rms = math.sqrt(sum_of_squares / float(im1.size[0] * im1.size[1]))
print(rms)
#SSIM http://scikit-image.org/docs/dev/auto_examples/transform/plot_ssim.html
s = ssim(image_list[1], image_list[2],multichannel=True)
print(s)