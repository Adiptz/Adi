if (self.CavalryLogger) { CavalryLogger.start_js(["Om3gq"]); }

__d("XLtgPostTranslationController",["XController"],(function(a,b,c,d,e,f){e.exports=b("XController").create("/intl/see_translation/",{ftid:{type:"String",required:!0},text_size:{type:"Enum",defaultValue:"medium",enumType:1},data_ft:{type:"String"},tn:{type:"String"}})}),null);
__d("highlight",["Animation","Style"],(function(a,b,c,d,e,f){function a(a,c,d,e){d===void 0&&(d="#fff9d7"),e===void 0&&(e="#fff"),new(b("Animation"))(a).from("background",e).to("background",d).ease(b("Animation").ease.both).duration(2e3).ondone(function(){b("Style").set(a,"background",""),c&&c()}).go()}e.exports=a}),null);
__d("LtgPostTranslation",["cx","Arbiter","AsyncRequest","ContentTranslationStrings","DOM","Event","LoadingIndicator.react","React","ReactDOM","XLtgPostTranslationController","collectDataAttributes","ge","highlight"],(function(a,b,c,d,e,f,g){"use strict";var h=b("React");a={_renderTranslation:function(a,c){if(!a||!a.parentNode)return;var d=b("DOM").create("div",{className:"_63tb"},c||b("ContentTranslationStrings").NO_TRANSLATION_AVAILABLE);b("DOM").replace(a,d);c&&b("highlight")(d)},bindListener:function(a,c){var d=this;b("Event").listen(a,"click",function(e){e.prevent();var f=b("ge")("translationSpinnerPlaceholder_"+c);f&&b("ReactDOM").render(h.jsx(b("LoadingIndicator.react"),{size:"small",color:"white"}),f);f=e.getTarget();e=b("collectDataAttributes")(f,["ft"]);f=b("XLtgPostTranslationController").getURIBuilder().setString("ftid",c).setString("data_ft",JSON.stringify(e.ft)).getURI();new(b("AsyncRequest"))().setURI(f).setHandler(function(c){c=c.getPayload();d._renderTranslation(a,c&&c.text);b("Arbiter").inform("ufi/translationRendered")}).setErrorHandler(function(){d._renderTranslation(a,null)}).send()})}};e.exports=a}),null);
__d("FormDisableOnSubmit",[],(function(a,b,c,d,e,f){a=function(){"use strict";function a(a){this._form=a}var b=a.prototype;b.enable=function(){this._subscription=this._form.subscribe(["submit","reset"],this._handle.bind(this))};b.disable=function(){this._form.unsubscribe(this._subscription),this._subscription=null};b._handle=function(a,b){if(a=="submit"){if(this._disabled)return!1;this._disabled=!0;return!0}this._disabled=!1};return a}();Object.assign(a.prototype,{_subscription:null,_disabled:!1});e.exports=a}),null);
__d("UIForm",["ArbiterMixin","BehaviorsMixin","DOM","Event","Form","Run","areJSONRepresentationsEqual","mixin"],(function(a,b,c,d,e,f){c=function(a){"use strict";babelHelpers.inheritsLoose(c,a);function c(c,d,e,f,g){var h;h=a.call(this)||this;h._root=c;h.controller=c;h._message=d;f&&(h._confirm_dialog=f,f.subscribe("confirm",h._handleDialogConfirm.bind(babelHelpers.assertThisInitialized(h))),b("DOM").prependContent(h._root,b("DOM").create("input",{type:"hidden",name:"confirmed",value:"true"})));b("Run").onAfterLoad(function(){this._originalState=b("Form").serialize(this._root)}.bind(babelHelpers.assertThisInitialized(h)));h._forceDirty=e;h._confirmed=!1;h._submitted=!1;b("Event").listen(h._root,"submit",h._handleSubmit.bind(babelHelpers.assertThisInitialized(h)));g&&g.length&&h.enableBehaviors(g);c=!0;b("Run").onBeforeUnload(h.checkUnsaved.bind(babelHelpers.assertThisInitialized(h)),c);return h}var d=c.prototype;d.getRoot=function(){return this._root};d._handleSubmit=function(){if(this._confirm_dialog&&!this._confirmed){this._confirm_dialog.show();return!1}if(this.inform("submit")===!1)return!1;this._submitted=!0;return!0};d._handleDialogConfirm=function(){this._confirmed=!0,this._confirm_dialog.hide(),this._root.getAttribute("ajaxify")?b("Event").fire(this._root,"submit"):this._handleSubmit()&&this._root.submit()};d.reset=function(){this.inform("reset"),this._submitted=!1,this._confirmed=!1};d.isDirty=function(){if(this._submitted||!b("DOM").contains(document.body,this._root))return!1;if(this._forceDirty)return!0;if(!this._originalState)return!1;var a=b("Form").serialize(this._root);return!b("areJSONRepresentationsEqual")(a,this._originalState)};d.checkUnsaved=function(){return this.isDirty()?this._message:null};return c}(b("mixin")(b("ArbiterMixin"),b("BehaviorsMixin")));e.exports=a.UIForm||c}),null);
__d("getNormalizedClientRect",["getDocumentScrollElement"],(function(a,b,c,d,e,f){"use strict";function a(a){var c=a.getBoundingClientRect(),d=0,e=0;a=b("getDocumentScrollElement")(a.ownerDocument);var f=a.getBoundingClientRect();if(f.left>0)d=-f.left;else{a=a.scrollWidth+f.left;var g=f.width;g>a&&(d=g-a)}f.top>0&&(e=-f.top);return{bottom:c.bottom+e,height:c.height,left:c.left+d,right:c.right+d,top:c.top+e,width:c.width}}e.exports=a}),null);
__d("StickyArea",["cx","CSS","DOM","DOMQuery","Event","Run","Style","ViewportBounds","getNormalizedClientRect","getOverlayZIndex","getStyleProperty","removeFromArray","throttle"],(function(a,b,c,d,e,f,g){var h=[],i=null,j=null,k=b("throttle").acrossTransitions(n,1e3),l="$$StickyArea_scrollListener",m="$$StickyArea_scrollListenerCount";function n(){h.sort(function(a,b){a=a.getNode();b=b.getNode();if(a.compareDocumentPosition)return 3-(a.compareDocumentPosition(b)&6);else return a.sourceIndex-b.sourceIndex})}function o(a,c,d){var e=a.getPlaceholder(),f=a.getNode(),g=b("Style").get(f,"float");a=a.getData();(a.placeholderWidth!==c||a.placeholderHeight!==d||a.placeholderFloat!==g)&&(b("Style").apply(e,{"float":g,height:d+"px",width:c+"px"}),a.placeholderHeight=d,a.placeholderWidth=c);f.nextSibling!==e&&b("DOM").insertAfter(f,e)}function p(a,c){var d=a.getData();d.fixed!==c&&(b("Style").apply(a.getNode(),d.styles),b("CSS").conditionShow(a.getPlaceholder(),c),b("CSS").conditionClass(a.getNode(),"_1a1e",c),b("Event").fire(a.getNode(),"change"),d.fixed=c)}function q(a,b){if(!a)return 0;else if(b.right<=a.rect.left||b.left>=a.rect.right)return q(a.prev,b);else return a.bottom}function r(){var a=0,c=h.length,d=100,e=null;function f(g,i){var j=d;while(a<c){var k=h[a],l=k.getNode(),m=k._scrollTarget;if(i&&!b("DOMQuery").contains(i,l))break;d=Math.max(j,k.getZIndex());var n=k.getData(),r=l.parentNode,s=n.styles;if(r==null){a++;continue}for(var t in s)s[t]="";p(k,!1);var u=l.offsetHeight,v=parseFloat(b("getStyleProperty")(l,"width"))||l.offsetWidth,w=m!==window?m.getBoundingClientRect().top:0,x=b("getNormalizedClientRect")(l);m=q(g||(m===window?e:null),x)+k.getOffset();var y=x.top-w;if(y<=m){s.width=v+"px";y=parseInt(b("Style").get(r,"padding-bottom"),10);var z=b("getNormalizedClientRect")(r);if(z.bottom-y>m+u||!k.getIsBoundToContainer()){var A=parseInt(b("Style").get(l,"margin-left"),10);s.position="fixed";s.bottom="auto";s.top=m+w+"px";s.left=x.left-A+"px"}else{(!n.parent||r!==n.parent)&&(b("Style").get(r,"position")==="static"&&b("Style").set(r,"position","relative"),n.parent=r);s.position="absolute";s.top="auto";s.bottom=y+"px";w=parseInt(b("Style").get(r,"border-left-width"),10);s.left=x.left-z.left-w+"px"}o(k,v,u);p(k,!0)}a++;A={bottom:m+u,prev:g,rect:x};n=0;k.getIsBoundToContainer()||(e=A,n=100);f(A,r);y=k.getZIndexOverride()||d+++n;b("Style").set(l,"z-index",y)}}f(null,null)}a=function(){"use strict";function a(c,d,e,f){f===void 0&&(f={}),this._isDestroyed=!1,this._node=c,this._data={fixed:!1,placeholderFloat:null,placeholderHeight:null,placeholderWidth:null,styles:{}},this._offset=e,this._boundToContainer=f.boundToContainer!==!1,f.stickTo===a.stickTo.SCROLL_PARENT?this._scrollTarget=b("Style").getScrollParent(c.parentNode)||window:this._scrollTarget=window,this._zIndexOverride=f.zIndexOverride,b("CSS").addClass(c,"_k"),d||b("Run").onLeave(this.destroy.bind(this)),!this._scrollTarget[l]?(this._scrollTarget[l]=b("Event").listen(this._scrollTarget,"scroll",function(){k(),r()}),this._scrollTarget[m]=1):this._scrollTarget[m]++,h.length||(i=b("Event").listen(window,"resize",function(){k(),r()}),j=b("ViewportBounds").subscribe("change",function(){k(),r()})),h.push(this),a.reflow()}var c=a.prototype;c.destroy=function(){if(this._isDestroyed)return;b("removeFromArray")(h,this);this._scrollTarget[m]--;this._scrollTarget[m]===0&&(this._scrollTarget[l].remove(),this._scrollTarget[l]=null);h.length||(i.remove(),i=null,j.unsubscribe(),j=null);this._placeholder&&b("DOM").remove(this._placeholder);var a=0;for(var c in this._data.styles)this._data.styles[c]="",a++;a&&b("Style").apply(this._node,this._data.styles);this._isDestroyed=!0};c.getData=function(){return this._data};c.getNode=function(){return this._node};c.getOffset=function(){return this._offset||0};c.getPlaceholder=function(){this._placeholder||(this._placeholder=b("DOM").create("div"));return this._placeholder};c.getIsBoundToContainer=function(){return this._boundToContainer};c.getZIndexOverride=function(){return this._zIndexOverride};c.getZIndex=function(){this._zIndex||(this._zIndex=b("getOverlayZIndex")(this._node));return this._zIndex};c.setOffset=function(a){this._offset=a};return a}();a.reflow=b("throttle").acrossTransitions(function(){n(),r()},100);a.stickTo={SCROLL_PARENT:"SCROLL_PARENT",WINDOW:"WINDOW"};e.exports=a}),null);