import os
import platform
import sys
from setuptools import setup, find_packages


this_directory = os.path.abspath (os.path.dirname (__file__))
with open (os.path.join (this_directory, 'README.md')) as f:
    long_description = f.read ()

setup (
    name = 'brainflow',
    version = os.environ.get('BRAINFLOW_VERSION', '1.0.8'),
    description = 'Library to get data from OpenBCI boards',
    long_description = long_description,
    long_description_content_type = 'text/markdown',
    url = 'https://github.com/Andrey1994/brainflow',
    author = 'Andrey Parfenov',
    author_email = 'a1994ndrey@gmail.com',
    packages = find_packages (),
    install_requires = [
        'numpy'
    ],
    package_data = {
        'brainflow': [
            os.path.join ('lib', 'BoardController.dll'),
            os.path.join ('lib', 'BoardController32.dll'),
            os.path.join ('lib', 'libBoardController.so'),
            os.path.join ('lib', 'libBoardController.dylib'),
            os.path.join ('lib', 'brainflow_boards.json'),
            os.path.join ('lib', 'DataHandler.dll'),
            os.path.join ('lib', 'DataHandler32.dll'),
            os.path.join ('lib', 'libDataHandler.so'),
            os.path.join ('lib', 'libDataHandler.dylib')
        ]
    },
    zip_safe = True,
    python_requires = '>=3.0'
)
