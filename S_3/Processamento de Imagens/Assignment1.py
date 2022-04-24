
# Eduardo Barroso Ribeiro Fernandes
# N_USP 12681733

import numpy as np
import random
import imageio
import matplotlib.pyplot as plt
import math

# Entrada de dados
filename = str(input().rstrip())
ls_scene = int(input())
function = int(input())
q_param = int(input())
ls_image = int(input())
n_bits = int(input())
seed = int(input())
matriz_R = np.load(filename)


# Funções geradoras de imagens
def funcao(x, y, n, q):
    if n == 1:
        return (x*y + 2*y)
    elif n == 2:
        return np.abs(np.cos(x/q) + 2*np.sin(y/q))
    elif n == 3:
        return np.abs(3*x/q - math.pow(y/q, 1/3))
    elif n == 4:
        return random.random()
    else:  # RandomWalk
        matrix = np.zeros((ls_scene, ls_scene))
        x = 0
        y = 0
        step = 1+ls_scene**2
        matrix[x][y] = 1
        for k in range(0, step):
            dx = random.randint(-1, 1)
            dy = random.randint(-1, 1)
            x = int((x + dx) % ls_scene)
            y = int((y + dy) % ls_scene)
            matrix[x][y] = 1
        return matrix


# Geração de cena
random.seed(seed)
scene = np.ones((ls_scene, ls_scene), dtype=float)
if(function == 5):  # Caso específico do RandomWalk
    scene = funcao(0, 0, function, q_param)
else:
    for i in range(ls_scene):
        for j in range(ls_scene):
            scene[i][j] = float(funcao(i, j, function, q_param))

min = np.min(scene)
max = np.max(scene)


# Normalização da cena entre [0,(2**16)-1]
for i in range(ls_scene):
    for j in range(ls_scene):
        scene[i][j] = (scene[i][j] - min)/(max-min)*65535


# Normalização da imagem
step = int(ls_scene / ls_image)
image = np.ones((ls_image, ls_image), dtype=int)
i2 = 0
j2 = 0
min = np.min(scene)
max = np.max(scene)

for i in range(ls_image):
    for j in range(ls_image):
        image[i][j] = np.uint8(((scene[i2][j2] - min)/(max-min))*255)
        image[i][j] = image[i][j] >> 8 - n_bits
        j2 += step
    j2 = 0
    i2 += step

plt.imshow(image.astype(np.uint8), cmap="gray")


# Cálculo do erro
RSE = 0
for i in range(ls_image):
    for j in range(ls_image):
        RSE += math.pow(image[i][j] - matriz_R[i][j], 2)

RSE = math.pow(RSE, 0.5)
print(RSE)
