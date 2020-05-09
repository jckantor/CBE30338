import numpy as np
import matplotlib.pyplot as plt

def plotter(*titles, **kwargs):
    """Returns a list of axes corresponding to a given list of title strings."""
    fig, ax = plt.subplots(len(titles), figsize=(8, 1+2.5*len(titles)), **kwargs)
    if len(titles) > 1:
        for (a, title) in zip(ax, titles):
            a.set_xlabel("time / seconds")
            a.set_title(title)
            a.grid(True)
        fig.tight_layout()
    else:
        print(type(ax))
        ax.set_xlabel("time / seconds")
        ax.set_title(titles[0])
        ax.grid(True)
    return ax