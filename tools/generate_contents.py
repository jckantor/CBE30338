import os
import re
import nbformat

# location of notebook directory in the local repository
NOTEBOOK_DIR = os.path.join(os.path.dirname(__file__), '..', 'notebooks')

# location of the index file in the local respository
INDEX_FILE = os.path.join(NOTEBOOK_DIR, 'index.md')

# location of the index notebook in the local repository
INDEX_NB = os.path.join(NOTEBOOK_DIR, 'index.ipynb')

# header for the index file and notebook
INDEX_HEADER = """
# [Chemical Process Control](http://jckantor.github.io/CBE30338/)

## Table of Contents
"""

# location of the README.md file in the local repository
README_FILE = os.path.join(os.path.dirname(__file__), '..', 'README.md')

# header for README.md
README_HEADER = """
# Chemical Process Control

This repository comprises a collection of Jupyter/Python notebooks in support of **CBE 30338 Chemical Process Control**
taught at the University of Notre Dame.

The links below display the notebooks as regular HTML web pages. From there you can run the notebook on 
[Google Colaboratory](https://colab.research.google.com) or download to run on your own laptop. To run on your own
laptop you will need to install Jupyter and Python 3, such as the excellent
[Anaconda distribution from Continuum Analytics](https://www.continuum.io/downloads).

Please let me know (jeff at nd.edu) if you any thoughts or suggestions on how these notebooks could be improved for 
teaching and learning the principles of Chemical Process Control.

## Contents
---
"""

# regular expression that matches notebook filenames to be included in the TOC
REG = re.compile(r'(\d\d|[A-Z])\.(\d\d)-(.*)\.ipynb')

def iter_notebooks():
    """Return list of notebooks matched by regular expression"""
    return sorted(nb_file for nb_file in os.listdir(NOTEBOOK_DIR) if REG.match(nb_file))

def get_notebook_title(nb_file):
    """Returns notebook title header if it exists, else None"""
    nb = nbformat.read(os.path.join(NOTEBOOK_DIR, nb_file), as_version=4)
    for cell in nb.cells:
        if cell.cell_type == "markdown":
            if cell.source.startswith('#'):
                return cell.source[1:].splitlines()[0].strip()

def gen_contents(directory=None):
    for nb_file in iter_notebooks():
        nb_url = os.path.join(directory, nb_file) if directory else nb_file
        chapter, section, name = REG.match(nb_file).groups()
        if chapter.isdigit():
            chapter = int(chapter)
            if chapter == 0:
                fmt = "\n### [{2}]({3})" if section in '00' else "- [{2}]({3})"
            else:
                fmt = "\n### [Chapter {0}. {2}]({3})" if section in '00' else "- [{0}.{1} {2}]({3})"
        else:
            fmt = "\n### [Appendix {0}. {2}]({3})" if section in '00' else "- [{0}.{1} {2}]({3})"

        yield fmt.format(chapter, int(section), get_notebook_title(nb_file), nb_url)


def write_contents(FILE, HEADER, directory=None):
    with open(FILE, 'w') as f:
        f.write(HEADER)
        f.write('\n'.join(gen_contents(directory)))


if __name__ == '__main__':
    directory = 'http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/'
    write_contents(INDEX_FILE, INDEX_HEADER, directory)
    os.system(' '.join(['notedown', INDEX_FILE, '>', INDEX_NB]))
    write_contents(README_FILE, README_HEADER,  directory)
