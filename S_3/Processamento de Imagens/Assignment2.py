
#Eduardo Barroso Ribeiro Fernandes
#N_USP: 12681733
import numpy as np
import imageio
import matplotlib.pyplot as plt
import math

def filtering_1d(array_img, array_w, w_size):
    a_size = int(array_img.size)
    array = np.asarray(array_img).flatten()
    arr = np.zeros(a_size)
    for i in range(a_size):
        for j in range(w_size):
            if i+j >= a_size:
                arr[i] += array[j-1]*array_w[j]
            else:
                arr[i] += array[i+j]*array_w[j]
    arr = np.insert(arr, 0, arr[a_size-1], axis = 0)
    arr = arr[:a_size]
    arr = np.reshape(arr,(int(np.sqrt(a_size)),int(np.sqrt(a_size))))
    return arr

def arr_dot(array1, array2):
  return np.sum(np.multiply(array1,array2))

def binarize(img, img_size, threshold):
  for i in range (img_size):
    for j in range (img_size):
      if img[i][j] > threshold:
        img[i][j] = 255
      else:
        img[i][j] = 0
  return img

def limiarization(img,img_size, threshold):
  avg1 = np.average(img[np.where(img > threshold)])
  avg2 = np.average(img[np.where(img <= threshold)])
  t = (avg1+avg2)/2
  if np.abs(t - threshold) > 0.5:
    return limiarization(img, img_size, t)
  else:
    return binarize(img, img_size, t)

def filtering_2d(img, img_size, weights, w_size, threshold):
  pad = w_size//2
  img = np.pad(img, pad_width=pad, mode='symmetric')
  arr = np.zeros((img_size,img_size))
  for i in range(pad,img_size+pad):
    for j in range(pad,img_size+pad):
      arr[i-pad][j-pad] = arr_dot(weights, img[i-pad:i+pad+1,j-pad:j+pad+1])
  return limiarization(arr, img_size, threshold)

def median_filter(img, img_size, size_filter):
  pad = size_filter//2
  img = np.pad(img, pad_width=pad, mode='constant', constant_values = 0)
  arr = np.zeros((img_size,img_size))
  for i in range(pad, img_size+pad):
    for j in range(pad, img_size+pad):
        arr[i-pad][j-pad] = np.median(np.asarray(img[i-pad:i+pad+1,j-pad:j+pad+1]).flatten())
  return arr

#Normalization Values to int[0,255]
def normalization(img):
  img_size = int(math.sqrt(np.size(img)))
  min = np.min(img)
  max = np.max(img)
  img = np.asarray(((img - min)/(max-min))*255)
  return img

#Comparison with original image
def error(img, output):
  MSE = np.square(np.subtract(img,output)).mean() 
  RMSE = math.sqrt(MSE)
  print(RMSE)

#Choosing method
def method_img(img, method):
    img_size = int(math.sqrt(np.size(img)))
    if method == 1:
        threshold = int(input())
        return limiarization(img,img_size,threshold)
    elif method == 2:
        n = int(input())
        weights = np.asarray(list(map(int,input().split())))
        return filtering_1d(np.asarray(img).flatten(), weights, n)
    elif method == 3:
        n = int(input())
        weights = np.zeros((n,n))
        for i in range(n):
          weights[i] = np.asarray(list(map(int,input().split())))
        threshold = int(input())
        return filtering_2d(img, img_size,weights,n, threshold)
    else:
        n = int(input())
        return median_filter(img, img_size, n)
filename = str(input()).rstrip()
method = int(input())
img = imageio.imread(filename)

output = method_img(img, method)
output = normalization(output)
img = imageio.imread(filename)
error(img, output)
