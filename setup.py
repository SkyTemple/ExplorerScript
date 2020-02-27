from setuptools import setup, find_packages

# README read-in
from os import path
this_directory = path.abspath(path.dirname(__file__))
with open(path.join(this_directory, 'README.rst'), encoding='utf-8') as f:
    long_description = f.read()
# END README read-in

setup(
    name='explorerscript',
    version='0.0.1',
    packages=find_packages(),
    # TODO:
    description='',
    long_description=long_description,
    long_description_content_type='text/x-rst',
    url='https://github.com/SkyTemple/ExplorerScript/',
    install_requires=[
        # TODO
    ],
    classifiers=[
        # TODO
    ],
)
