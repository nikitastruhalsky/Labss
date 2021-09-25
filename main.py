import math

import numpy as np

N = 7


def GenerateMatrix():
    return np.random.uniform(-100, 101, (N, N))


def PrintMatrix(matrix):
    for arr in matrix:
        for elem in arr:
            print(elem, end="\t\t")
        print()


def PrintVector(vector):
    for elem in vector:
        print(elem, end='\t')
    print()


def FindF(matrix):
    count = 0
    f_vector = [0] * N
    for arr in matrix:
        vectorElem = 1
        for elem in arr:
            f_vector[count] += elem * vectorElem
            vectorElem += 1
        count += 1
    return f_vector


def GaussMethod(matrix, f_vector):
    k = 0
    while k <= N - 2:
        i = k + 1
        maximum = matrix[k][k]
        maximumIndex = k
        while i <= N - 1:
            if math.fabs(matrix[i][k]) > math.fabs(maximum):
                maximum = matrix[i][k]
                maximumIndex = i
            i += 1
        if maximumIndex != k:
            temp = f_vector[maximumIndex]
            f_vector[maximumIndex] = f_vector[k]
            f_vector[k] = temp
            temp = matrix[maximumIndex].copy()
            matrix[maximumIndex] = matrix[k]
            matrix[k] = temp
        i = k + 1
        while i <= N - 1:
            try:
                l_i = matrix[i][k] / matrix[k][k]
            except ZeroDivisionError as e:
                print(e)
                return

            f_vector[i] -= l_i * f[k]
            j = k
            while j <= N - 1:
                matrix[i][j] -= l_i * matrix[k][j]
                j += 1
            i += 1
        k += 1
    x = [0] * N
    x[N - 1] = f_vector[N - 1] / matrix[N - 1][N - 1]
    i = N - 2
    while i >= 0:
        s = 0
        j = i + 1
        while j <= N - 1:
            s += matrix[i][j] * x[j]
            j += 1
        x[i] = (f_vector[i] - s) / matrix[i][i]
        i -= 1
    return x


def FindMaxFabsInList(arr):
    maximum = arr[0]
    for elem in arr:
        if math.fabs(elem) > math.fabs(maximum):
            maximum = elem
    return maximum


def GilbertMatrix(matrix, n):
    i = 0
    while i < n:
        j = 0
        while j < n:
            matrix[i][j] = 1 / (i + 1 + j + 1 - 1)
            j += 1
        i += 1
    return matrix


if __name__ == '__main__':
    m = GenerateMatrix()
    PrintMatrix(m)
    print()
    v = [0] * N
    index = 0
    for element in v:
        v[index] = index + 1
        index += 1

    PrintVector(v)
    print()
    f = FindF(m)
    PrintVector(f)
    print()
    x = GaussMethod(m, f)
    print(x)
    v_max = FindMaxFabsInList(v)
    x_max = FindMaxFabsInList(x)
    print()
    print((math.fabs(v_max - x_max) * 100 / math.fabs(v_max)), '%')

    m = [[0] * N] * N
    gilbert = GilbertMatrix(m, N)
    f = FindF(gilbert)
    x = GaussMethod(gilbert, f)
    x_max = FindMaxFabsInList(x)
    print()
    print((math.fabs(v_max - x_max) * 100 / math.fabs(v_max)), '%')
