import os
import re
import nbformat

NOTEBOOK_DIR = os.path.join(os.path.dirname(__file__), '..', 'notebooks')

INDEX_FILE = os.path.join(NOTEBOOK_DIR, 'index.md')

INDEX_NB = os.path.join(NOTEBOOK_DIR, 'index.ipynb')

INDEX_HEADER = """
# CBE 30338 Chemical Process Control

## Table of Contents
"""

README_FILE = os.path.join(os.path.dirname(__file__), '..', 'README.md')

README_HEADER = """
# Chemical Process Control

This repository comprises a collection of Jupyter/Python 
notebooks in support of **CBE 30338 Chemical Process Control** taught at the 
University of Notre Dame. These materials have been developed over a period 
time, earlier versions having been created in Matlab/Simulink and available 
[here](REAME_DEPRECATED.md).

The links below display the notebooks as regular HTML web pages or, where 
indicated, as presentation slides. From there you can download the notebooks 
to execute on your laptop. To execute you will need to install a distributions 
of Jupyter and Python 3, such as the excellent [Anaconda distribution available
 from Continuum Analytics](https://www.continuum.io/downloads).

Please me know if you any thoughts or suggestions on how these notebooks could
 be improved for the purposes of teaching and learning the principles of 
 Chemical Process Control.

## Table of Contents
"""

REG = re.compile(r'(\d\d|[A-Z])\.(\d\d)-(.*)\.ipynb')

def iter_notebooks():
    """Return list of notebooks that match regular expression"""
    return sorted(nb_file for nb_file in os.listdir(NOTEBOOK_DIR)
                  if REG.match(nb_file))

def get_notebook_title(nb_file):
    nb = nbformat.read(os.path.join(NOTEBOOK_DIR, nb_file), as_version=4)
    for cell in nb.cells:
        if cell.source.startswith('#'):
            return cell.source[1:].splitlines()[0].strip()

def gen_contents(directory=None):
    for nb_file in iter_notebooks():
        if directory:
            nb_url = os.path.join(directory, nb_file)
        else:
            nb_url = nb_file
        chapter, section, title = REG.match(nb_file).groups()
        title = get_notebook_title(nb_file)
        if section == '00':
            if chapter in ['00']:
                yield '\n### [{0}]({1})'.format(title, nb_url)
            else:
                yield '\n### [{0}. {1}]({2})'.format(chapter,
                                                     title, nb_url)
        else:
            yield "- [{0}]({1})".format(title, nb_url)


def write_contents(FILE, HEADER, directory=None):
    f = open(FILE, 'w')
    f.write(HEADER)
    f.write('\n'.join(gen_contents(directory)))
    f.close()


if __name__ == '__main__':
    write_contents(
        INDEX_FILE,
        INDEX_HEADER,
        'http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/')
    write_contents(
        README_FILE,
        README_HEADER,
        'http://nbviewer.jupyter.org/github/jckantor/CBE30338/blob/master/notebooks/')

