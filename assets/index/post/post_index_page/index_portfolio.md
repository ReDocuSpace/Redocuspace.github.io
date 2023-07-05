---
layout: default
---


{% for list in site.project_management_list %}

<div class="intro_document_main_{{list.index}}">
	<div class="wide_area">
	    <div class="local_area">
            <a href="{{list.url}}">
                <div class = "intro_contents">
	                <div class="image_setup">
                        <img src="{{list.img }}">
                    <div class="txt">{{ list.title }}</div>
                    </div>
                </div>
            </a>
        </div>
    </div>
</div>

{% endfor %}
