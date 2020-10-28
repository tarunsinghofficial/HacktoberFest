#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: Juan Emilio Martinez Manjon
"""

from math import sqrt

cateto1 = float(input("Introduzca el primer cateto dle triangulo:"))
cateto2 = float(input("Introduzca el segundo cateto dle triangulo:"))

hipotenusa = sqrt(cateto1*cateto1 + cateto2*cateto2)

print("La hipotenusa es:",hipotenusa)
