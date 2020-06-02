
<!-- jinja2 template extends `full` to include cell tags in the html rendering of notebooks -->
{% extends 'full.tpl'%}
{% block any_cell %}
{% if cell['metadata'].get('tags', []) %}
    <div style="background-color:white; border:thin solid grey; margin-left:95px; margin-right:6px">
    {% for tag in cell['metadata'].get('tags', []) %}
        &nbsp; <a href="https://{github_user_name}.github.io/{github_repo_name}/tag_index.html#{{ tag }}">{{ tag }}</a>
    {% endfor %}
    </div>
    {{ super() }}
{% else %}
    {{ super() }}
{% endif %}
{% endblock any_cell %}

