

import numpy as np
import imageio

#Comparison with original image usin the Root mean square error
def error(img, output):
  MSE = np.square(np.subtract(img,output)).mean() 
  RMSE = np.sqrt(np.square(np.subtract(img,output)).mean())
  print(f'{RMSE:.4f}')

#Normalization Values to int[0,255]
def normalization(img):
  min = np.min(img)
  max = np.max(img)
  img_new = np.asarray(((img - min)/(max-min))*255)
  return img_new

#Normalization Values to int[0,1]
def normalization_b(img):
  min = np.min(img)
  max = np.max(img)
  img_new = np.asarray(((img - min)/(max-min)))
  return img_new

filename_image = str(input()).rstrip()
filename_filter = str(input()).rstrip()
filename_refimg = str(input()).rstrip()

img = imageio.imread(filename_image)
filter_ = imageio.imread(filename_filter)
refimg = imageio.imread(filename_refimg)

img_F = np.fft.fft2(img)
#img_F its Frequency Domain of IMG, the F(I)

transf = normalization(img_F)
#the F(I) between [0,255]

filtro = normalization_b(filter_)
#The filter between [0,1]

img_F = np.fft.fftshift(img_F)
#shiftting the image

result = np.multiply(transf, filtro)
#Applying the filter M on Frequency Domain

result = np.fft.ifft2(result)
#Backing the IMG with the inverse of F, IF(I) = I

result = np.fft.ifftshift(result)
#re-shiffting the image

result = normalization(result)
result = np.abs(result).astype(np.uint8)

error(result, refimg)