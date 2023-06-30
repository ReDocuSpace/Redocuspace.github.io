---
layout: hobby
title: hobby
index : 0
---

### **본 내용은 책을 참고하여 개인학습한 내용을 담고 있습니다. 더욱 자세한 내용을 보시고 싶으신 분은 직접 구매하는 것을 추천드립니다.**

<div class="swiper-container">
	<div class="swiper-wrapper">
        {%- for list in site.hobby_novel_list -%}
            <div class="swiper-slide"><a class="collapse-item" class="slider_item" href="{{list.url}}"><img src="{{list.img}}"></a></div>
        {% endfor %}
	</div>
	<div class="swiper-button-next"></div><!-- 다음 버튼 -->
	<div class="swiper-button-prev"></div><!-- 이전 버튼 -->
</div>

<div class="card shadow mb-4">
    <div class="card-header py-3">
        <h4 class="m-0 font-weight-bold text-primary">자작 소설</h4>
    </div>
</div>

<script src="/assets/document/js/slider.js"></script>
		