#!/usr/bin/env python

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=['#Package_name#'],
    package_dir={'': 'src'},
    scripts=['scripts/#Executable_name#']
)

setup(**d)
