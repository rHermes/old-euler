




/*
     FILE ARCHIVED ON 19:32:19 Jun 13, 2007 AND RETRIEVED FROM THE
     INTERNET ARCHIVE ON 12:41:48 Mar 21, 2015.
     JAVASCRIPT APPENDED BY WAYBACK MACHINE, COPYRIGHT INTERNET ARCHIVE.

     ALL OTHER CONTENT MAY ALSO BE PROTECTED BY COPYRIGHT (17 U.S.C.
     SECTION 108(a)(3)).
*/
(function(){
function n(c){return c!=null?'"'+c+'"':'""'}function J(c){if(typeof encodeURIComponent=="function"){return encodeURIComponent(c)}else{return escape(c)}}function d(c,a){if(a){window.google_ad_url+="&"+c+"="+a}}function i(c,a){if(a){d(c,J(a))}}function m(c,a,b){if(a&&typeof a=="object"){a=a[b%a.length]}d("color_"+c,a)}function N(c,a){var b=c.screen,e=navigator.javaEnabled(),f=-a.getTimezoneOffset();if(b){d("u_h",b.height);d("u_w",b.width);d("u_ah",b.availHeight);d("u_aw",b.availWidth);d("u_cd",b.colorDepth)}d("u_tz",
f);d("u_his",history.length);d("u_java",e);if(navigator.plugins){d("u_nplug",navigator.plugins.length)}if(navigator.mimeTypes){d("u_nmime",navigator.mimeTypes.length)}}function E(c){c=c.toLowerCase();if(c.substring(0,3)!="ca-"){c="ca-"+c}return c}function V(c,a,b,e){b=b.substring(0,2000);b=b.replace(/%\w?$/,"");if(c.google_ad_output=="js"&&(c.google_ad_request_done||c.google_radlink_request_done)){a.write('<script language="JavaScript1.1" src='+n(b)+"><\/script>")}else if(c.google_ad_output=="html"){if(c.name!=
"google_ads_frame"){if(e!=null){a.write('<div id="'+e+'">')}a.write('<iframe name="google_ads_frame" width='+n(c.google_ad_width)+" height="+n(c.google_ad_height)+" frameborder="+n(c.google_ad_frameborder)+" src="+n(b)+' marginwidth="0" marginheight="0" vspace="0" hspace="0" allowtransparency="true" scrolling="no">');a.write("</iframe>");if(e!=null){a.write("</div>")}}}else if(c.google_ad_output=="textlink"){a.write('<script language="JavaScript1.1" src='+n(b)+"><\/script>")}}function T(c){var a=
null;c.google_ad_frameborder=a;c.google_ad_format=a;c.google_page_url=a;c.google_language=a;c.google_gl=a;c.google_country=a;c.google_region=a;c.google_city=a;c.google_hints=a;c.google_safe=a;c.google_encoding=a;c.google_ad_output=a;c.google_max_num_ads=a;c.google_ad_channel=a;c.google_contents=a;c.google_alternate_ad_url=a;c.google_alternate_color=a;c.google_color_bg=a;c.google_color_text=a;c.google_color_link=a;c.google_color_url=a;c.google_color_border=a;c.google_color_line=a;c.google_reuse_colors=
a;c.google_adtest=a;c.google_kw_type=a;c.google_kw=a;c.google_num_radlinks=a;c.google_max_radlink_len=a;c.google_rl_filtering=a;c.google_rl_mode=a;c.google_rt=a;c.google_rl_dest_url=a;c.google_num_radlinks_per_unit=a;c.google_ad_type=a;c.google_image_size=a;c.google_feedback=a;c.google_skip=a;c.google_page_location=a;c.google_referrer_url=a;c.google_ad_region=a;c.google_ad_section=a;c.google_bid=a;c.google_cpa_choice=a;c.google_cust_age=a;c.google_cust_gender=a;c.google_cust_interests=a;c.google_cust_id=
a;c.google_cust_job=a;c.google_cust_u_url=a;c.google_cust_l=a;c.google_cust_lh=a;c.google_cust_ch=a;c.google_ed=a;c.google_targeting=a;c.google_ad_host=a;c.google_ad_slot=a;c.google_ad_override=a;c.google_ui_features=a}function H(c){var a=null,b=window,e=document,f=new Date,g=f.getTime(),h=b.google_ad_format;if(b.google_cpa_choice){b.google_ad_url="/web/20070613193219/http://pagead2.googlesyndication.com/cpa/ads?";b.google_ad_url+="client="+escape(E(b.google_ad_client));b.google_ad_region="_google_cpa_region_";d("cpa_choice",
b.google_cpa_choice);if(typeof e.characterSet!="undefined"){i("oe",e.characterSet)}else if(typeof e.charset!="undefined"){i("oe",e.charset)}}else{b.google_ad_url="/web/20070613193219/http://pagead2.googlesyndication.com/pagead/ads?";b.google_ad_url+="client="+escape(E(b.google_ad_client))}d("host",b.google_ad_host);var j=b.google_num_slots_by_client,C=b.google_num_slots_by_channel,l=b.google_prev_ad_formats_by_region;if(b.google_ad_region==a&&b.google_ad_section!=a){b.google_ad_region=b.google_ad_section}var k=b.google_ad_region==
a?"":b.google_ad_region,w=false;if(h){w=h.indexOf("_0ads")>0}if(w){if(b.google_num_0ad_slots){b.google_num_0ad_slots=b.google_num_0ad_slots+1}else{b.google_num_0ad_slots=1}if(b.google_num_0ad_slots>3){return false}}else if(!b.google_cpa_choice){if(b.google_num_ad_slots){b.google_num_ad_slots=b.google_num_ad_slots+1}else{b.google_num_ad_slots=1}if(b.google_num_slots_to_rotate){l[k]=a;if(b.google_num_slot_to_show==a){b.google_num_slot_to_show=g%b.google_num_slots_to_rotate+1}if(b.google_num_slot_to_show!=
b.google_num_ad_slots){return false}}else if(b.google_num_ad_slots>3&&k==""){return false}}d("dt",f.getTime());d("hl",b.google_language);if(b.google_country){d("gl",b.google_country)}else{d("gl",b.google_gl)}d("gr",b.google_region);i("gcs",b.google_city);i("hints",b.google_hints);d("adsafe",b.google_safe);d("oe",b.google_encoding);d("lmt",b.google_last_modified_time);i("alternate_ad_url",b.google_alternate_ad_url);d("alt_color",b.google_alternate_color);d("skip",b.google_skip);d("targeting",b.google_targeting);
var p=b.google_ad_client;if(!j[p]){j[p]=1;j.length+=1}else{j[p]+=1}if(l[k]){i("prev_fmts",l[k].toLowerCase());if(j.length>1){d("slot",j[p])}}if(h&&!b.google_ad_slot){i("format",h.toLowerCase());if(l[k]){l[k]=l[k]+","+h}else{l[k]=h}}d("num_ads",b.google_max_num_ads);d("output",c!=a?c:b.google_ad_output);d("adtest",b.google_adtest);if(b.google_ad_slot){d("slotname",b.google_ad_slot)}i("correlator",b.google_correlator);if(b.google_ad_channel){var x=b.google_ad_channel;i("channel",x);var y="",z=x.split("+");
for(var s=0;s<z.length;s++){var t=z[s];if(!C[t]){C[t]=1}else{y+=t+"+"}}i("pv_ch",y)}i("url",b.google_page_url);m("bg",b.google_color_bg,g);m("text",b.google_color_text,g);m("link",b.google_color_link,g);m("url",b.google_color_url,g);m("border",b.google_color_border,g);m("line",b.google_color_line,g);if(b.google_reuse_colors)d("reuse_colors",1);else d("reuse_colors",0);d("kw_type",b.google_kw_type);i("kw",b.google_kw);i("contents",b.google_contents);d("num_radlinks",b.google_num_radlinks);d("max_radlink_len",
b.google_max_radlink_len);d("rl_filtering",b.google_rl_filtering);d("rl_mode",b.google_rl_mode);d("rt",b.google_rt);i("rl_dest_url",b.google_rl_dest_url);d("num_radlinks_per_unit",b.google_num_radlinks_per_unit);d("ad_type",b.google_ad_type);d("image_size",b.google_image_size);d("region",b.google_ad_region);d("feedback_link",b.google_feedback);i("ref",b.google_referrer_url);i("loc",b.google_page_location);d("bid",b.google_bid);d("cust_age",b.google_cust_age);d("cust_gender",b.google_cust_gender);
d("cust_interests",b.google_cust_interests);d("cust_id",b.google_cust_id);d("cust_job",b.google_cust_job);d("cust_u_url",b.google_cust_u_url);d("cust_l",b.google_cust_l);d("cust_lh",b.google_cust_lh);d("cust_ch",b.google_cust_ch);d("ed",b.google_ed);i("ui",b.google_ui_features);if(F(b,e)&&e.body){var A=e.body.scrollHeight,B=e.body.clientHeight;if(B&&A){i("cc",Math.round(B*100/A))}}d("google_ad_override",b.google_ad_override);d("flash",b.google_flash_version);N(b,f);return true}function G(){var c=
window,a=document,b=false;if(O(c.google_ad_output,c.google_ad_client)&&!U()){b=true}var e=b?"json_html":null;if(!H(e)){return}if(!b){V(c,a,c.google_ad_url,null)}else{S()}T(c)}function K(c,a,b){G();return true}function F(c,a){return c.top.location==a.location}function D(c,a){var b=a.documentElement;if(F(c,a))return false;if(c.google_ad_width&&c.google_ad_height){var e=1,f=1;if(c.innerHeight){e=c.innerWidth;f=c.innerHeight}else if(b&&b.clientHeight){e=b.clientWidth;f=b.clientHeight}else if(a.body){e=
a.body.clientWidth;f=a.body.clientHeight}if(f>2*c.google_ad_height||e>2*c.google_ad_width){return false}}return true}function P(c){var a=window,b=document,e=b.location,f=b.referrer,g=null,h=a.onerror;a.onerror=c;if(a.google_ad_frameborder==g){a.google_ad_frameborder=0}if(a.google_ad_output==g){a.google_ad_output="html"}if(a.google_ad_format==g&&a.google_ad_output=="html"){a.google_ad_format=a.google_ad_width+"x"+a.google_ad_height}if(a.google_page_url==g){a.google_page_url=f;if(!D(a,b)){a.google_page_url=
e;a.google_last_modified_time=Date.parse(b.lastModified)/1000;a.google_referrer_url=f}}else{a.google_page_location=f;if(!D(a,b)){a.google_page_location=e}}if(a.google_num_slots_by_channel==g){a.google_num_slots_by_channel=[]}if(a.google_num_slots_by_client==g){a.google_num_slots_by_client=[]}if(a.google_prev_ad_formats_by_region==g){a.google_prev_ad_formats_by_region=[]}if(a.google_correlator==g){a.google_correlator=(new Date).getTime()}if(a.google_adslot_loaded==g){a.google_adslot_loaded={}}if(a.google_adContentsBySlot==
g){a.google_adContentsBySlot={}}if(a.google_flash_version==g){a.google_flash_version=I().toString()}a.onerror=h}function o(c){if(c in q){return q[c]}return q[c]=navigator.userAgent.toLowerCase().indexOf(c)!=-1}var q={};function r(){return o("msie")&&!window.opera}function u(){return o("safari")}function L(){var c=navigator.userAgent,a=c.indexOf("MSIE ");if(a==-1){return 0}else{return parseFloat(c.substring(a+5,c.indexOf(";",a)))}}function U(){if(r()){var c=L();return c<=5}else if(o("firefox")){var a=
navigator.userAgent.indexOf("Firefox")+8,b=parseInt(navigator.userAgent.charAt(a)),e=navigator.userAgent.slice(a);return b<1}else if(u()){var a=navigator.userAgent.indexOf("Safari")+7,e=navigator.userAgent.slice(a),f=parseInt(e);return f<412}else if(window.opera!=null){var a=navigator.userAgent.indexOf("Opera")+6,e=navigator.userAgent.slice(a),b=parseInt(e);return b<9}else if(!r()&&!u()&&o("mozilla")){var a=navigator.userAgent.indexOf("Netscape")+9,e=navigator.userAgent.slice(a),b=parseInt(e);return b<
7}else{return true}}function O(c,a){if(c!="html"){return false}var b={};b["ca-pub-8954402009499768"]=true;return b[a]!=null}function S(){var c=window;d("impl","s");d("callback","_google_setAdContentsBySlotForSync");document.write("<script src = '"+c.google_ad_url+"'><\/script>")}window.google_createDivWithContent=function(c){var a=window,b="google_ads_div_"+c,e="<div id="+b+">",f=a.google_adContentsBySlot[c];if(f==null){return}e+=f._html_;e+="\n</div>\n";document.write(e)};window.google_createDOMIframe=
function(c,a,b,e){var f=document.getElementsByTagName("script"),g=f[f.length-1],h=document.createElement("iframe");h.id="google_ads_iframe_"+c;h.width=a;h.height=b;h.vspace=0;h.hspace=0;h.allowTransparency="true";h.scrolling="no";h.marginWidth=0;h.marginHeight=0;h.frameBorder=0;h.style.border=0;g.parentNode.appendChild(h);h.contentWindow.document.write(e);h.contentWindow.document.close()};window.google_createiframe=function(c,a,b,e,f){var g="google_ads_div_"+c,h="google_ads_iframe_"+c,j="<div id="+
g+">";j+="<iframe id="+h+' width="'+e+'" height="'+f+'" vspace="0" hspace="0" allowtransparency="true" scrolling="no" marginwidth="0" marginheight="0" frameborder="0" style="border:0px;" src="'+a.replace(/&/g,"&amp;").replace(/</g,"&lt;").replace(/>/g,"&gt;").replace(/\"/g,"&quot;")+'"';j+=' onload="'+b+'"';j+="></iframe></div>";document.write(j)};var v="google_ads_iframe_".length;function M(c){var a=c.getAttribute("id"),b=a.substr(v,a.length-v);return b}window._google_syncAdSlotLoaded=function(c){var a=
M(c);window.google_loadiframe(c)};window._google_setAdContentsBySlotForSync=function(c){var a=window;for(var b in c){var e=c[b];a.google_adContentsBySlot[b]=e;if(e==null||e._empty_){}else if(e._expandable_){a.google_createDivWithContent(b)}else{if(navigator.userAgent.indexOf("MSIE ")>0){a.google_adslot_loaded[b]=false;var f="window._google_syncAdSlotLoaded(this);";a.google_createiframe(b,"about:blank",f,e._width_,e._height_)}else{a.google_createDOMIframe(b,e._width_,e._height_,e._html_)}}}};function R(c){var a=
{},b=c.split("?"),e=b[b.length-1].split("&");for(var f=0;f<e.length;f++){var g=e[f].split("=");if(g[0]){try{a[g[0].toLowerCase()]=g.length>1?(window.decodeURIComponent?decodeURIComponent(g[1].replace(/\+/g," ")):unescape(g[1])):""}catch(h){}}}return a}function Q(){var c=window,a=R(document.URL);if(a["google_ad_override"]){c.google_ad_override=a["google_ad_override"]}}function I(){var c=0;if(navigator.plugins&&navigator.mimeTypes.length){var a=navigator.plugins["Shockwave Flash"];if(a&&a.description){c=
a.description.replace(/([a-zA-Z]|\s)+/,"").split(".")[0]}}else if(navigator.userAgent&&navigator.userAgent.indexOf("Windows CE")>=0){c=3;var b=1;while(b){try{b=new ActiveXObject("ShockwaveFlash.ShockwaveFlash."+(c+1));c++}catch(e){b=null}}}else if(r()){try{var b=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.7")}catch(e){try{var b=new ActiveXObject("ShockwaveFlash.ShockwaveFlash.6");c=6;b.AllowScriptAccess="always"}catch(e){if(c==6){return c}}try{b=new ActiveXObject("ShockwaveFlash.ShockwaveFlash")}catch(e){}}if(b!=
null){c=b.GetVariable("$version").split(" ")[1].split(",")[0]}}return c}Q();P(K);G();
})()