#!/bin/python
# -*- coding: utf-8 -*-

import numpy as np
from . import dft
from fractions import Fraction
from typeguard import typechecked

@typechecked
def singleDFTterm(signal: np.ndarray,f: int,sampling_rate: int = 32000000000) -> complex:
    fraction = Fraction(f,sampling_rate)
    return dft.singleDFTterm(signal,fraction.numerator,fraction.denominator)
