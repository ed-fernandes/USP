# -*- coding: utf-8 -*-
"""Assignment4.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1zYIYQfFjLIS_D7wvFKnIfV6fdT0xO6RN
"""

import numpy as np
import matplotlib.pyplot as plt
import imageio
from numpy.fft import fftn, fftshift, ifftn

#Comparison with original image usin the Root mean square error
def error(img, output):
  RMSE = np.sqrt(np.square(np.subtract(img,output)).mean())
  print(f'{RMSE:.4f}')

#Degrading image
def gaussian_filter(k, sigma):
    arx = np.arange((-k // 2) + 1.0, (k // 2) + 1.0)
    x, y = np.meshgrid(arx, arx)
    filt = np.exp(-(1/2) * (np.square(x) + np.square(y)) / np.square(sigma))
    return filt / np.sum(filt)

def CLSQ(filename, k, sigma, gamma):
  f = imageio.imread(filename)
  #Computing the number of padding on one side

  #Gaussian
  h = gaussian_filter(k,sigma)
  a = int(f.shape[0]//2 - h.shape[0]//2)
  h_pad = np.pad(h, (a,a), 'constant', constant_values=(0))
  #Laplace
  p = np.asarray([[0, -1, 0],[-1,4,-1],[0,-1,0]])
  b = int(f.shape[0]//2 - p.shape[0]//2)
  p_pad = np.pad(p, (b,b), 'constant', constant_values=(0))


  # computing the Fourier transforms
  F = fftn(f)
  P = fftn(p_pad)
  H = fftn(h_pad)
  H_inv = np.conjugate(H)


  #Restoring the image
  R = H_inv/(H*H_inv + gamma*(np.abs(P)**2))

  #Convolution
  G = np.multiply(F,R)

  # Inverse Transform
  g = fftshift(ifftn(G).real)
  g = np.clip(g.astype(int), 0,255)

  
  #plt.imshow(g, cmap="gray"); plt.title("clsq")
  error(f,g)

filename = str(input()).rstrip()
method = int(input())
if method == 1:
  kernel = int(input())
  sigma = float(input())
  gamma = float(input())
  CLSQ(filename, kernel, sigma, gamma)