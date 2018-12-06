import imageio
from PIL import Image
from PIL import ImageChops
import math
#from skimage.measure import compare_ssim

#im = imageio.imread('imageio:chelsea.png')
#print(im.shape)

#from PIL import Image
import glob
image_list = []
for filename in glob.glob('../../test_data/2D_registration/*.png'): #assuming gif
    #im=Image.open(filename)
    im=imageio.imread(filename)
    image_list.append(im)

#print(image_list[0].shape)
#print(image_list[1].shape)


#im1 = Image.open("../../test_data/2D_registration/foodtest0.jpg")
#im2 = Image.open("../../test_data/2D_registration/foodtest1.jpg")

im1 = Image.open("../../test_data/diff_test/test_image_1.png")
im2 = Image.open("../../test_data/diff_test/test_image_2.png")

#Root-Mean-Squere https://en.wikipedia.org/wiki/Root-mean-square_deviation
diff = ImageChops.difference(im2, im1)
h = diff.histogram()
sq = (value*((idx%256)**2) for idx, value in enumerate(h))
sum_of_squares = sum(sq)
rms = math.sqrt(sum_of_squares / float(im1.size[0] * im1.size[1]))
print(rms)