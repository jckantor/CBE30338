<!-- jinja2 template to adds cell tags to the html rendering of notebooks -->
{% extends 'full.tpl'%}
{% block any_cell %}
{% if cell['metadata'].get('tags', []) %}
    <div style="background-color:white; border:thin solid grey; margin-left:95px; margin-right:6px">
    {% for tag in cell['metadata'].get('tags', []) %}
        &nbsp; <a href="https://jckantor.github.io/CBE30338/tag_index.html#{{ tag }}">{{ tag }}</a>
    {% endfor %}
    </div>
    {{ super() }}
{% else %}
    {{ super() }}
{% endif %}
{% endblock any_cell %}