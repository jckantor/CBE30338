
# Edit the following string variables to customize tools to a new notebook repository
GITHUB_USER = "jckantor"
GITHUB_REPO = "CBE30338"
PAGE_TITLE = "CBE 30338 Chemical Process Control"

PAGE_URL = f"http://{GITHUB_USER}.github.io/{GITHUB_REPO}/"
GITHUB_URL = f"https://github.com/{GITHUB_USER}/{GITHUB_REPO}/"

# header to be inserted at the top of each notebook
NOTEBOOK_HEADER_CONTENT = f"""
*This notebook contains course material from [{PAGE_TITLE}]({PAGE_URL}) 
by Jeffrey Kantor (jeff at nd.edu); the content is available [on GitHub]({GITHUB_URL}).
The text is released under the [CC-BY-NC-ND-4.0 license](https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode), 
and code is released under the [MIT license](https://opensource.org/licenses/MIT).*
"""

# header for README.md
README_HEADER = f"""
# {PAGE_TITLE}

This repository comprises a collection of Jupyter/Python notebooks in support of **{PAGE_TITLE}**
taught at the University of Notre Dame.

The links below display the notebooks as regular HTML web pages. From there you can run the notebook on 
[Google Colaboratory](https://colab.research.google.com) or download to run on your own laptop. To run on your own
laptop you will need to install Jupyter and Python 3, such as the excellent
[Anaconda distribution from Continuum Analytics](https://www.continuum.io/downloads).

Please let me know (jeff at nd.edu) if you any thoughts or suggestions on how these notebooks could be improved for 
teaching and learning the principles of Chemical Process Control.
"""

README_FOOTER = f"""
**License Requirements.** The materials in this repository are available at 
[{GITHUB_URL}]({GITHUB_URL}) for noncommercial use under terms of the 
[Creative Commons Attribution Noncommericial ShareAlike License](http://creativecommons.org/licenses/by-nc-sa/4.0/). 
You are invited to fork this repository, and to use, adapt, remix these material for non-commericial purposes. The 
license terms require you to give attribution and share your work under the same terms. Pull requests for corrections 
and additions to these materials are most welcome.
"""
