from setuptools import setup, find_packages

# README read-in
from os import path
this_directory = path.abspath(path.dirname(__file__))
with open(path.join(this_directory, 'README.rst'), encoding='utf-8') as f:
    long_description = f.read()
# END README read-in

setup(
    name='explorerscript',
    version='0.0.3',
    packages=find_packages(),
    description='ExplorerScript and SSBScript: Script languages for decompiled SSB (Pokémon Mystery Dungeon Explorers of Sky)',
    long_description=long_description,
    long_description_content_type='text/x-rst',
    url='https://github.com/SkyTemple/ExplorerScript/',
    install_requires=[
        'python-igraph >= 0.8.0',
        'antlr4-python3-runtime >= 4.8'
    ],
    classifiers=[
        'Development Status :: 2 - Pre-Alpha',
        'Programming Language :: Python',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8'
    ],
)
