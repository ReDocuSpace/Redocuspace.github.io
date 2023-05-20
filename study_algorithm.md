---
layout: study_algorithm
title : backjoon
---

<h4> 알고리즘 </h4>

[![Solved.ac Profile](http://mazassumnida.wtf/api/v2/generate_badge?boj=eqmentstudio)](https://solved.ac/eqmentstudio/)
						
<hr/>
<!--
<div class="col-12">
    <select name="demo-category" id="demo-category">
	    <option value="">- Category -</option>
	    <option value="1">백준</option>
	    <option value="1">프로그래머스</option>
	    <option value="1">코드 포스</option>
	    <option value="1">기타</option>
	</select>
</div>
<hr/>
-->

이거 좀 되었으면 좋겠는데 왜 안될까

<h4>알고리즘 문제</h4>
<div class="table-wrapper">
	<table>
		<thead>
			<tr>
				<th>카테고리</th>
                <th>문제 번호</th>
				<th>문제 제목</th>
				<th>등급</th>
                <th>분류</th>
			</tr>
		</thead>
		<tbody>
			{% directory path: /백준 exclude: .md %}
			<tr>
				<td>{{ file.directory01}}</td>
                <td>{{ file.number}}</td>
				<td>{{ file.slug }}</td>
				<td>{{ file.directory02 }}</td>
                <td></td>
			</tr>
			{% enddirectory %}
		</tbody>
	</table>
</div>
