---
layout: document
title: Document
index : 0
---

<!-- 클래스명은 변경하면 안 됨 -->

<div class="swiper-container">
	<div class="swiper-wrapper">
        {%- for list in site.programming_basic_list -%}
            <div class="swiper-slide"><a class="collapse-item" class="slider_item" href="{{list.url}}"><img src="{{list.img}}"></a></div>
        {% endfor %}
	</div>
	<div class="swiper-button-next"></div><!-- 다음 버튼 -->
	<div class="swiper-button-prev"></div><!-- 이전 버튼 -->
</div>

<div class="card shadow mb-4">
    <div class="card-header py-3">
        <h4 class="m-0 font-weight-bold text-primary">프로그래밍 기본</h4>
    </div>
</div>

<div class="swiper-container">
	<div class="swiper-wrapper">
        {%- for list in site.programming_unity_list -%}
            <div class="swiper-slide"><a class="collapse-item" class="slider_item" href="{{list.url}}"><img src="{{list.img}}"></a></div>
        {% endfor %}
	</div>
	<div class="swiper-button-next"></div><!-- 다음 버튼 -->
	<div class="swiper-button-prev"></div><!-- 이전 버튼 -->
</div>

<div class="card shadow mb-4">
    <div class="card-header py-3">
        <h4 class="m-0 font-weight-bold text-primary">프로그래밍 심화</h4>
    </div>
</div>

<div class="swiper-container">
	<div class="swiper-wrapper">
        {%- for list in site.etc_book_list -%}
            <div class="swiper-slide"><a class="collapse-item" class="slider_item" href="{{list.url}}"><img src="{{list.img}}"></a></div>
        {% endfor %}
	</div>
	<div class="swiper-button-next"></div><!-- 다음 버튼 -->
	<div class="swiper-button-prev"></div><!-- 이전 버튼 -->
</div>
<div class="card shadow mb-4">
    <div class="card-header py-3">
        <h4 class="m-0 font-weight-bold text-primary">기획 및 기타</h4>
    </div>
</div>

<script src="/assets/document/js/slider.js"></script>
		