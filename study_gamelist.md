---
layout: study_gamelist
title : backjoon
---

<div class="box alt">
	<div class="row gtr-50 gtr-uniform">
		{%- for list in site.imitationlist -%}
			<div class="col-4"><span class="image fit"><a href="{{ list.url }}"><img src="{{ list.img }}" alt="" /></a><h5>{{ list.description }}</h5></span></div>
		{% endfor %}
	</div>
</div>