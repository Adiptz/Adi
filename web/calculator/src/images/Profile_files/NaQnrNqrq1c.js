if (self.CavalryLogger) { CavalryLogger.start_js(["jghzE"]); }

__d("XCometStoriesCreateControllerRouteBuilder",["cometRouteBuilder"],(function(a,b,c,d,e,f){a=b("cometRouteBuilder")("/stories/create/",Object.freeze({}),void 0);e.exports=a}),null);
__d("CometDensityAwarenessContext",["React"],(function(a,b,c,d,e,f){"use strict";a=b("React");c=!1;e.exports=a.createContext(c)}),null);
__d("CometBase.react",["BaseView.react"],(function(a,b,c,d,e,f){"use strict";e.exports=b("BaseView.react")}),null);
__d("CometProgressSkittleIndeterminate.react",["CometProgressRingIndeterminate.react","React","stylex"],(function(a,b,c,d,e,f){"use strict";var g=b("React");function a(){return g.jsx("div",{className:"spb7xbtv bkmhp75w emlxlaya s45kfl79 l9j0dhe7 taijpn5t pq6dq46d rq0escxv sk4xxmp2 agehan2d n8ej3o3l rt8b4zig bp9cbjyn tdjehn4e thwo4zme tv7at329",children:g.jsx(b("CometProgressRingIndeterminate.react"),{color:"disabled",size:20})})}e.exports=a}),null);
__d("getTetraListCellAddOn.react",["ix","fbt","CometToggle.react","Locale","React","TetraButton.react","TetraIcon.react","fbicon"],(function(a,b,c,d,e,f,g,h){"use strict";var i=b("React"),j=b("Locale").isRTL(),k=function(a,c){var d=a.on,e=a.onPress,f=a.testOnly_pressed;a.type;var h=babelHelpers.objectWithoutPropertiesLoose(a,["on","onPress","testOnly_pressed","type"]);return i.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},h,{"aria-checked":e!=null?d:void 0,color:c?"disabled":d?"highlight":"secondary",disabled:c,hideHoverOverlay:!0,icon:a.on?b("fbicon")._(g("484757"),20):b("fbicon")._(g("659288"),20),onPress:e,role:e!=null?"checkbox":void 0,testOnly_pressed:f}))},l=function(a,c){var d=a.on,e=a.onPress,f=a.testOnly_pressed;a.type;a=babelHelpers.objectWithoutPropertiesLoose(a,["on","onPress","testOnly_pressed","type"]);return i.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},a,{"aria-checked":e!=null?d:void 0,color:c?"disabled":d?"highlight":"secondary",disabled:c,hideHoverOverlay:!0,icon:d?b("fbicon")._(g("621399"),20):b("fbicon")._(g("545517"),20),onPress:e,role:e!=null?"radio":void 0,testOnly_pressed:f}))},m=function(a,c,d){a.text;a.type;a=babelHelpers.objectWithoutPropertiesLoose(a,["text","type"]);d===3?d=j?b("fbicon")._(g("492521"),24):b("fbicon")._(g("492575"),24):d=j?b("fbicon")._(g("492518"),20):b("fbicon")._(g("492572"),20);return i.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},a,{color:c?"disabled":"secondary",disabled:c,icon:d}))},n=function(a,c,d){a.children;d=a.onPress;var e=a.open;a.type;a=babelHelpers.objectWithoutPropertiesLoose(a,["children","onPress","open","type"]);return i.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},a,{color:c?"disabled":"secondary",disabled:c,icon:e?b("fbicon")._(g("505565"),20):b("fbicon")._(g("492454"),20),onPress:d}))},o=function(a,c){var d=a.color,e=a.icon,f=a.onHoverIn,g=a.onHoverOut,h=a.onPress,j=a.onPressIn,k=a.testOnly_pressed;a.type;a=babelHelpers.objectWithoutPropertiesLoose(a,["color","icon","onHoverIn","onHoverOut","onPress","onPressIn","testOnly_pressed","type"]);d=(d=d)!=null?d:"primary";return i.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},a,{color:c?"disabled":d,disabled:c,hideHoverOverlay:!0,icon:e,onHoverIn:f,onHoverOut:g,onPress:h,onPressIn:j,testOnly_pressed:k}))},p=function(a,c){var d=a.labelIsHidden;d=d===void 0?!1:d;var e=a.type;a=babelHelpers.objectWithoutPropertiesLoose(a,["labelIsHidden","type"]);e=e==="primary-button"?"primary":"secondary";return i.createElement(b("TetraButton.react"),d?babelHelpers["extends"]({disabled:c,labelIsHidden:!0,type:e},a):babelHelpers["extends"]({disabled:c,type:e},a))},q=function(a,c){var d=a.onChange,e=a.size;a.type;var f=a.value;a=babelHelpers.objectWithoutPropertiesLoose(a,["onChange","size","type","value"]);return i.jsx(b("CometToggle.react"),babelHelpers["extends"]({disabled:c,onClick:d!=null?d:function(){},size:e,tabIndex:-1,value:f},a,{children:a.disabled===!0?h._("Disabled"):h._("Enabled")}))},r=function(a,c){var d=a.onPress,e=a.type;a=babelHelpers.objectWithoutPropertiesLoose(a,["onPress","type"]);return i.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},a,{color:c?"disabled":"secondary",disabled:c,icon:e==="more"?b("fbicon")._(g("484391"),24):b("fbicon")._(g("478237"),16),onPress:d}))};a=function(a,b,c){switch(a.type){case"checkbox":return k(a,b);case"radio":return l(a,b);case"disclosure":return m(a,b,c);case"expander":return n(a,b,c);case"icon":return o(a,b);case"primary-button":return p(a,b);case"secondary-button":return p(a,b);case"switch":return q(a,b);case"more":return r(a,b);case"close":return r(a,b);case"body":return a.addOn;default:a.type}};e.exports={getSecondaryAddOn:a}}),null);
__d("TetraListCell.react",["CometDensityAwarenessContext","CometPressable.react","CometProgressSkittleIndeterminate.react","CometVisualCompletionAttributes","MWJewelThreadFacepile.react","React","TetraIcon.react","TetraishSkittleEmoji.react","TetraishSkittleIcon.react","TetraProfilePhoto.react","TetraProfilePhotoForActor.react","TetraText.react","TetraTextPairing.react","getTetraListCellAddOn.react","gkx","mergeRefs","qex","stylex","useCometAriaID"],(function(a,b,c,d,e,f){"use strict";var g,h=b("React");c=b("React");var i=c.useContext,j=c.useMemo,k=b("getTetraListCellAddOn.react").getSecondaryAddOn,l={addOn:{alignItems:"bp9cbjyn",display:"j83agx80",flexDirection:"btwxx1t3"},addOnWithExpander:{marginEnd:"oi9244e8"},addOnWithIcon:{display:"j83agx80"},addOnWithText:{marginStart:"kkf49tns"},bottomAddOn:{display:"j83agx80",flexDirection:"cbu4d94t",marginEnd:"a9txdygg",marginStart:"fnu23jab"},bottomAddOnInner:{maxWidth:"d2edcug0"},bottomAddOnWithFacepile:{marginStart:"ocgrx2df"},bottomDivider:{backgroundColor:"pwoa4pd7",bottom:"i09qtzwb",end:"n7fi1qx3",height:"ay7djpcl",position:"pmk7jnqg",start:"j9ispegn"},content:{alignItems:"gs1a9yip",borderStyle:"ow4ym5g4",borderWidth:"auili1gw",boxSizing:"rq0escxv",display:"j83agx80",flexDirection:"cbu4d94t",flexGrow:"buofh1pr",flexShrink:"g5gj957u",justifyContent:"i1fnvgqd",marginBottom:"oygrvhab",marginEnd:"cxmmr5t8",marginStart:"hcukyx3x",marginTop:"kvgmc6g5",minHeight:"tgvbjcpo",minWidth:"hpfvmrgz",paddingEnd:"rz4wbd8a",paddingStart:"a8nywdso",position:"l9j0dhe7",zIndex:"du4w35lb",flexBasis:"rj1gh0hx",paddingBottom:"f10w8fjw",paddingTop:"pybr56ya"},contentContainer:{borderStyle:"ow4ym5g4",borderWidth:"auili1gw",boxSizing:"rq0escxv",display:"j83agx80",flexGrow:"buofh1pr",flexShrink:"g5gj957u",justifyContent:"i1fnvgqd",marginBottom:"oygrvhab",marginEnd:"cxmmr5t8",marginStart:"hcukyx3x",marginTop:"kvgmc6g5",minHeight:"tgvbjcpo",minWidth:"hpfvmrgz",paddingBottom:"qt6c0cv9",paddingEnd:"rz4wbd8a",paddingStart:"a8nywdso",paddingTop:"jb3vyjys",zIndex:"du4w35lb",alignItems:"bp9cbjyn",flexDirection:"btwxx1t3",position:"l9j0dhe7"},contentWithMoreSpacing:{paddingBottom:"ihqw7lf3",paddingTop:"discj3wi"},densityMode:{"@media (max-height: 700px)":{marginEnd:"m6uieof3",marginStart:"icc0peqn",marginTop:"hx8drtub",marginBottom:"j13r6fgp",transform:"nddp3pr2"}},disabled:{cursor:"rj84mg9z",pointerEvents:"hzruof5a"},listCellMinHeight:{minHeight:"nnctdnn4"},pressable:{borderTopStartRadius:"ue3kfks5",borderTopEndRadius:"pw54ja7n",borderBottomEndRadius:"uo3d90p7",borderBottomStartRadius:"l82x9zwi",display:"a8c37x1j"},primaryAddOn:{alignSelf:"nqmvxvec",display:"j83agx80",flexDirection:"cbu4d94t",marginBottom:"bi6gxh9e",marginEnd:"tvfksri0",marginTop:"aov4n071",position:"l9j0dhe7"},responsiveButtons:{flexGrow:"buofh1pr",paddingBottom:"iuny7tx3",paddingTop:"ipjc6fyt"},responsiveContent:{alignItems:"bp9cbjyn",flexDirection:"btwxx1t3",flexWrap:"lhclo0ds",marginBottom:"mysgfdmx",marginTop:"hddg9phg"},responsiveText:{boxSizing:"rq0escxv",flexBasis:"hkbzh7o3",flexGrow:"buofh1pr",flexShrink:"g5gj957u",maxWidth:"d2edcug0",minWidth:"ptc67a42",paddingBottom:"iuny7tx3",paddingEnd:"hv4rvrfc",paddingTop:"ipjc6fyt"},root:{borderStyle:"ow4ym5g4",borderWidth:"auili1gw",boxSizing:"rq0escxv",display:"j83agx80",flexGrow:"buofh1pr",flexShrink:"g5gj957u",justifyContent:"i1fnvgqd",marginBottom:"oygrvhab",marginEnd:"cxmmr5t8",marginStart:"hcukyx3x",marginTop:"kvgmc6g5",minHeight:"tgvbjcpo",minWidth:"hpfvmrgz",paddingBottom:"qt6c0cv9",paddingTop:"jb3vyjys",position:"l9j0dhe7",zIndex:"du4w35lb",alignItems:"bp9cbjyn",flexDirection:"btwxx1t3",paddingEnd:"dflh9lhu",paddingStart:"scb9dxdr"},rootWithIncreasedHeight:{minHeight:"e170dy2k"},secondaryAddOn:{marginBottom:"n851cfcs",marginStart:"ozuftl9m",marginTop:"n1l5q3vz",position:"l9j0dhe7"},secondaryAddOnCenter:{marginBottom:"bi6gxh9e",marginTop:"aov4n071"},secondaryAddOnSmall:{marginBottom:"bi6gxh9e",marginStart:"ozuftl9m",marginTop:"aov4n071",position:"l9j0dhe7"},selected:{backgroundColor:"i224opu6"},textRight:{flexShrink:"pfnyh3mw"}},m={center:{alignSelf:"o8rfisnq"},start:{alignSelf:"nqmvxvec"}},n={center:{alignSelf:"o8rfisnq"},start:{alignSelf:"nqmvxvec"}};function a(a,c){var d=a.addOnBottom,e=a.addOnPrimary,f=a.addOnPrimaryCssSelectionId,k=a.addOnPrimaryOverrideVerticalStyle,r=a.addOnPrimaryTestId;r=a.addOnPrimaryVerticalAlign;r=r===void 0?"start":r;var s=a.addOnSecondary,t=a.addOnSecondaryRef,u=a.addOnSecondaryTestId;u=a.addOnSecondaryVerticalAlign;u=u===void 0?"start":u;var v=a.body,w=a.bodyColor;w=w===void 0?"secondary":w;var x=a.bodyLineLimit,y=a.contentHorizontalPadding,z=a.dataAttributes,A=a.disabled;A=A===void 0?!1:A;var B=a.emphasized;B=B===void 0?!1:B;var C=a.focusable,D=a.hasBottomDivider,E=a.headline,F=a.headlineAddOn,G=a.headlineColor;G=G===void 0?"primary":G;var H=a.headlineLineLimit,I=a.level;I=I===void 0?3:I;var J=a.linkProps,K=a.meta,L=a.metaColor;L=L===void 0?"tertiary":L;var M=a.metaLineLimit,aa=a.metaLocation,ba=a.onHoverIn,ca=a.onHoverOut,N=a.onPress,da=a.onPressIn,ea=a.onPressOut,O=a.paddingHorizontal,fa=a.role,P=a.selected;P=P===void 0?!1:P;var Q=a.size;Q=Q===void 0?"default":Q;var R=a.testid;R=a.testOnly_pressed;a=i(b("CometDensityAwarenessContext"));var S=b("useCometAriaID")("aria-labelledby"),T=S[0],ga=T[0];T=T[1];S=S[1];var ha=S[0],U=S[1];S=j(function(){return b("mergeRefs")(U,t)},[U,t]);var V=E!=null&&v==null&&K==null,W=E==null&&v!=null&&K==null,X=E==null&&v==null&&K!=null,Y=V&&H!=null&&H===1||W&&x!=null&&x===1||X&&M!=null&&M===1;V=V&&H!=null&&H>1||W&&x!=null&&x>1||X&&M!=null&&M>1;W=s!=null&&(s.type==="primary-button"||s.type==="secondary-button"||s.type==="body");X=s!=null&&s.type==="expander";u=W||X?"center":u;r=Y?"center":r;var Z=d!=null&&d.type==="buttons",$=b("gkx")("1500018")||b("qex")._("1497433");a=a&&$;$=z!=null?Object.keys(z).reduce(function(a,b){a!=null&&b!=null&&(a["data-"+b]=z[b]);return a},{}):null;k=h.jsxs("div",{className:(g||(g=b("stylex")))(l.root,X&&Q!=="small"?l.rootWithIncreasedHeight:null,Q!=="small"?l.listCellMinHeight:null),style:y==null?void 0:{paddingLeft:y,paddingRight:y},children:[e!=null?h.jsx("div",{className:(g||(g=b("stylex")))(l.primaryAddOn,k,m[r],a===!0&&l.densityMode),"data-testid":void 0,id:f,children:h.jsx(o,{addOnPrimary:e,disabled:A})}):null,h.jsxs("div",{className:g(l.contentContainer),children:[h.jsxs("div",{className:g(l.content,e==null&&(V||Y&&(W||X))?l.contentWithMoreSpacing:null,Z?l.responsiveContent:null),children:[h.jsx("div",babelHelpers["extends"]({className:g(Z&&l.responsiveText)},ga,{ref:T,children:h.jsx(b("TetraTextPairing.react"),{body:v,bodyColor:A?"disabled":w,bodyLineLimit:x,headline:E,headlineAddOn:F,headlineColor:A?"disabled":G,headlineLineLimit:H,level:I,meta:K,metaColor:A?"disabled":L,metaLineLimit:M,metaLocation:aa,reduceEmphasis:B===!1})})),d!=null&&h.jsx("div",{className:(g||(g=b("stylex")))(l.bottomAddOn,d.type==="facepile"?l.bottomAddOnWithFacepile:null,Z?l.responsiveButtons:null),children:h.jsx("div",{className:(g||(g=b("stylex")))(l.bottomAddOnInner),children:h.jsx(p,{addOnBottom:d})})})]}),s!=null?h.jsx("div",babelHelpers["extends"]({className:(g||(g=b("stylex")))(Q!=="small"&&l.secondaryAddOn,Q==="small"&&l.secondaryAddOnSmall,(W||X)&&l.secondaryAddOnCenter,n[u])},ha,{"data-testid":void 0,ref:S,children:h.jsx(q,{addOn:s,disabled:A,level:I})})):null,((y=D)!=null?y:!1)?h.jsx("div",{className:(g||(g=b("stylex")))(l.bottomDivider)}):null]})]});r=s!=null&&s.type==="expander"&&s.open===!0&&s.children!=null?s.children:null;a=void 0;f=void 0;if(s!=null)switch(s.type){case"checkbox":f=s.on;a="checkbox";break;case"radio":f=s.on;a="radio";break;case"switch":f=s.value;a="switch";break}return h.jsxs(h.Fragment,{children:[h.jsx("div",babelHelpers["extends"]({},b("CometVisualCompletionAttributes").IGNORE_DYNAMIC,{role:fa,style:{paddingLeft:(e=O)!=null?e:8,paddingRight:(V=O)!=null?V:8}},$,{children:N!=null||J!=null?h.jsx(b("CometPressable.react"),{"aria-checked":f,"aria-pressed":P?"true":void 0,disabled:A,display:"block",focusable:C,linkProps:J,onHoverIn:ba,onHoverOut:ca,onPress:N,onPressIn:da,onPressOut:ea,overlayDisabled:P,ref:c,role:a,testOnly_pressed:R,testid:void 0,xstyle:[l.pressable,P&&l.selected,A&&l.disabled],children:k}):h.jsx("div",{className:(g||(g=b("stylex")))(l.pressable,P?l.selected:null,A?l.disabled:null),"data-testid":void 0,ref:c,children:k})})),r]})}function o(a){var c=a.addOnPrimary;a=a.disabled;switch(c.type){case"icon":c.type;var d=babelHelpers.objectWithoutPropertiesLoose(c,["type"]);return h.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},d,{disabled:a}));case"profile-photo":c.type;d=babelHelpers.objectWithoutPropertiesLoose(c,["type"]);return h.jsx(b("TetraProfilePhoto.react"),babelHelpers["extends"]({},d));case"profile-photo-for-actor":c.type;d=babelHelpers.objectWithoutPropertiesLoose(c,["type"]);return h.jsx(b("TetraProfilePhotoForActor.react"),babelHelpers["extends"]({},d));case"contained-icon":d=c.color;d=d===void 0?"gray":d;c.type;var e=babelHelpers.objectWithoutPropertiesLoose(c,["color","type"]);return h.jsx(b("TetraishSkittleIcon.react"),babelHelpers["extends"]({color:d},e,{disabled:a}));case"contained-progress-ring-indeterminate":return h.jsx(b("CometProgressSkittleIndeterminate.react"),{});case"messenger-facepile":c.type;d=babelHelpers.objectWithoutPropertiesLoose(c,["type"]);return h.jsx(b("MWJewelThreadFacepile.react"),babelHelpers["extends"]({},d));case"group_member_profile_primary_addon":return c.component;case"save_collection_initial":return c.component;case"emoji":e=c.color;a=e===void 0?"gray":e;d=c.emoji;e=c.emojiSize;e=e===void 0?20:e;c=c.size;c=c===void 0?40:c;return h.jsx(b("TetraishSkittleEmoji.react"),{color:a,emoji:d,emojiSize:e,size:c});default:return null}}var p=function(a){a=a.addOnBottom;switch(a.type){case"buttons":return a.component;case"facepile":return a.facepile;case"designOverride_Notifications_bottomAddOn":return a.override_component;default:return null}},q=function(a){var c=a.addOn,d=a.disabled;a=a.level;var e=k(c,d,a),f=c.type==="disclosure"&&c.text!=null?c.text:null;return h.jsxs("div",{className:(g||(g=b("stylex")))(l.addOn),children:[f!=null&&h.jsx("div",{className:(g||(g=b("stylex")))(l.textRight),children:h.jsx(b("TetraText.react"),{color:d?"disabled":"secondary",numberOfLines:1,type:a===3?"body2":"body3",children:f})}),h.jsx("div",{className:g(c.type==="expander"?l.addOnWithExpander:null,f!=null?l.addOnWithText:null,c.type==="icon"?l.addOnWithIcon:null),children:e})]})};e.exports=h.forwardRef(a)}),null);
__d("TetraAccessoryListCell.react",["React","TetraListCell.react"],(function(a,b,c,d,e,f){"use strict";var g=b("React");function a(a,c){return g.jsx(b("TetraListCell.react"),babelHelpers["extends"]({},a,{ref:c}))}e.exports=g.forwardRef(a)}),null);
__d("TetraUnitHeader.react",["CometBase.react","CometColumn.react","CometColumnItem.react","CometPressable.react","IconSource","React","TetraIcon.react","TetraText.react","TetraTextPairing.react","stylex"],(function(a,b,c,d,e,f){"use strict";var g,h=b("React");c=b("React");var i=c.useState,j=8,k={action:{backgroundColor:"b0kwm4yp",borderTop:"gcieejh5",borderEnd:"bn081pho",borderBottom:"humdl8nn",borderStart:"izx4hr6d",borderTopStartRadius:"jk6sbkaj",borderTopEndRadius:"kdgqqoy6",borderBottomEndRadius:"ihh4hy1g",borderBottomStartRadius:"qttc61fc",display:"q9uorilb",marginTop:"kvgmc6g5",marginEnd:"cxmmr5t8",marginBottom:"oygrvhab",marginStart:"hcukyx3x",paddingTop:"jb3vyjys",paddingEnd:"rz4wbd8a",paddingBottom:"qt6c0cv9",paddingStart:"a8nywdso",position:"l9j0dhe7",verticalAlign:"pzggbiyp"},actionButton:{color:"py34i1dx",cursor:"nhd2j8a9",textDecoration:"owjl8umy"},actionHidden:{opacity:"b5wmifdl"},hairline:{backgroundColor:"pwoa4pd7",height:"ay7djpcl",marginBottom:"mkjtxrlb"},root:{paddingBottom:"e5nlhep0"}},l={8:{paddingTop:"cxgpxx05"},12:{paddingTop:"pybr56ya"},16:{paddingTop:"discj3wi"},20:{paddingTop:"aodizinl"}};function a(a){var c=a.action,d=a.actionAccessibilityLabel,e=a.actionHidden;e=e===void 0?!1:e;var f=a.actionLinkProps,m=a.actionRef,n=a.actiontestid,o=a.actionWrapper,p=a.addOn_DEPRECATED,q=a.body,r=a.bodyColor;r=r===void 0?"secondary":r;var s=a.disabled,t=a.hasTopDivider;t=t===void 0?!1:t;var u=a.headline,v=a.headlineColor;v=v===void 0?"primary":v;var w=a.iconColor;w=w===void 0?"primary":w;var x=a.level,y=a.linkProps,z=a.meta,A=a.metaColor;A=A===void 0?"secondary":A;var B=a.metaLocation,C=a.onActionHoverIn,D=a.onActionHoverOut,E=a.onActionPress,F=a.onActionPressIn,G=a.onActionPressOut,H=a.onPress,I=a.onPressIn,J=a.onPressOut,K=a.paddingHorizontal;K=K===void 0?16:K;var L=a.paddingTop;L=L===void 0?20:L;var M=a.testOnly_actionPressed,N=a.testOnly_pressed;a=babelHelpers.objectWithoutPropertiesLoose(a,["action","actionAccessibilityLabel","actionHidden","actionLinkProps","actionRef","actiontestid","actionWrapper","addOn_DEPRECATED","body","bodyColor","disabled","hasTopDivider","headline","headlineColor","iconColor","level","linkProps","meta","metaColor","metaLocation","onActionHoverIn","onActionHoverOut","onActionPress","onActionPressIn","onActionPressOut","onPress","onPressIn","onPressOut","paddingHorizontal","paddingTop","testOnly_actionPressed","testOnly_pressed"]);var O=i(!1),P=O[0];O=O[1];var Q;if(c!=null){f={"aria-label":d,linkProps:f,onHoverIn:C,onHoverOut:D,onPress:E,onPressIn:F,onPressOut:G,testOnly_pressed:(d=M)!=null?d:!1,testid:n};c instanceof b("IconSource")?Q=h.jsx(b("TetraIcon.react"),babelHelpers["extends"]({},f,{color:w,icon:c,ref:m})):Q=h.jsx(b("CometPressable.react"),babelHelpers["extends"]({},f,{onFocusVisibleChange:O,overlayOffset:j,overlayRadius:4,ref:m,xstyle:[k.actionButton,k.action,e&&!P&&k.actionHidden],children:h.jsx(b("TetraText.react"),{color:"highlight",numberOfLines:1,type:x===2?"body2":"body3",children:c})}))}else p!=null&&(Q=h.jsx("div",{className:(g||(g=b("stylex")))(k.action),children:p}));if(o!=null){C=o.component;Q=h.jsx(C,babelHelpers["extends"]({},o.props,{children:Q}))}E=h.jsx(b("TetraTextPairing.react"),{body:q,bodyColor:r,bodyLineLimit:3,headline:u,headlineAddOn:Q,headlineColor:v,headlineLineLimit:2,isSemanticHeading:!0,level:x,meta:z,metaColor:A,metaLineLimit:1,metaLocation:(D=B)!=null?D:"below"});G=h.jsx(b("CometColumn.react"),babelHelpers["extends"]({},a,{paddingHorizontal:t?0:K,xstyle:[k.root,l[L]],children:h.jsx(b("CometColumnItem.react"),{children:H!=null?h.jsx(b("CometPressable.react"),{disabled:s,linkProps:y,onPress:H,onPressIn:I,onPressOut:J,overlayDisabled:!0,ref:m,testOnly_pressed:(F=N)!=null?F:!1,children:E}):E})}));return t?h.jsxs(b("CometColumn.react"),{paddingHorizontal:K,children:[h.jsx(b("CometColumnItem.react"),{children:h.jsx(b("CometBase.react"),{xstyle:k.hairline})}),G]}):G}e.exports=a}),null);
__d("StoriesEnums",[],(function(a,b,c,d,e,f){"use strict";a={BACKGROUND_STYLE:{BLACK:"black",DEFAULT:"default"},EMPTY_BUCKET_TYPES:{FRIEND_BUCKET:"FRIEND_BUCKET",SELF_BUCKET:"SELF_BUCKET",UNSELECTED:"UNSELECTED"},END_CARD:{AVATAR_WIDTH:44,COUNT_DOWN_SECONDS:5,MAX_AVATAR_NUMBER:4,MAX_TILE_NUMBER:6,MS_PER_INTERVAL:200,MS_PER_SECOND:1e3,PADDING_HORIZONTAL:12,PADDING_VERTICAL:16,PADDING_WIDTH:32},GRADIENT_DIRECTION:{BL_TR:"BL_TR",BOTTOM_TOP:"BOTTOM_TOP",BR_TL:"BR_TL",LEFT_RIGHT:"LEFT_RIGHT",RIGHT_LEFT:"RIGHT_LEFT",TL_BR:"TL_BR",TOP_BOTTOM:"TOP_BOTTOM",TR_BL:"TR_BL"},LIGHTWEIGHT_REACTION_UNICODES:{ANGER:"\ud83d\ude21",HAHA:"\ud83d\ude06",LIKE:"\ud83d\udc4d",LOVE:"\u2764\ufe0f",SORRY:"\ud83d\ude22",SUPPORT:"\ud83e\udd17",WOW:"\ud83d\ude2e"},NAV_DIRECTIONS:{NEXT_BUCKET:"next-bucket",NEXT_CARD:"next-card",PREV_BUCKET:"prev-bucket",PREV_CARD:"prev-card",STAY_HERE:"stay_here"},POLL_STICKER:{AVAILABLE_WIDTH_RATIO:(240-2*12)/240,BACKGROUND_COLOR_BLUE:"#79A6FF",BACOGROUND_COLOR_SLATE:"#EAEFF2",CHILD_PADDING_RATIO:.05,DEFAULT_OPTION_WIDTH_RATIO:.5,FIVE_OPTION_STAR_RATING:"FIVE_OPTION_STAR_RATING",IG_LEFT_TEXT_COLOR:"#13bda6",IG_RIGHT_TEXT_COLOR:"#F36B7F",IG_TWO_OPTION_COMBINED:"IG_TWO_OPTION_COMBINED",MINIMUM_LABEL_WIDTH_RATIO:.31,OVERFLOW_CHILD_PADDING_RATIO:20/240,TEXT_BIG_HEIGHT_RATIO:40/72,TEXT_BIG_MAX_FONT_SIZE_RATIO:30/240,TEXT_BIG_MIN_FONT_SIZE_RATIO:20/240,TEXT_BIG_RATIO:40/240,TEXT_COLOR_GREY:"#5F6673",TEXT_ONLY_FONT_SIZE_RATIO:20/240,TEXT_SMALL_HEIGHT_RATIO:25/72,TEXT_SMALL_MAX_FONT_SIZE_RATIO:20/240,TEXT_SMALL_MIN_FONT_SIZE_RATIO:12/240,TEXT_SMALL_RATIO:25/240,TEXT_WITH_PERCENT_FONT_SIZE_RATIO:12/240,TWO_OPTION_COMBINED:"TWO_OPTION_COMBINED",VOTE_COUNT_FONT_SIZE_RATIO:32/240,VOTE_OPTION_MAX_WIDTH_RATIO:.75},PRONOUN:{FEMALE:"FEMALE",MALE:"MALE",NEUTRAL:"NEUTRAL"},RECTANGULAR_TILE_TYPES:{THREE_COLUMN:"THREE_COLUMN",TWO_COLUMN:"TWO_COLUMN"},STORIES_BUCKETS_INDEXER_TYPES:{BIRTHDAY:"BIRTHDAY",BIRTHDAY_SELF:"BIRTHDAY_SELF",OTHER:"OTHER",OWNED_SELF:"OWNED_SELF"},STORIES_OPTION_TYPES:{DELETE:"DELETE",DELETE_STORY_AND_BLOCK_MEMBER:"DELETE_STORY_AND_BLOCK_MEMBER",MUTE_CARD_OWNER:"MUTE_CARD_OWNER",REPORT_TO_GROUP_ADMINS:"REPORT_TO_GROUP_ADMINS"},STORY_CARD_TYPES:{ADMINED_ADDITIONAL_PROFILE_STORY:"ADMINED_ADDITIONAL_PROFILE_STORY",ARCHIVED_STORY:"ARCHIVED_STORY",BIRTHDAY_STORY:"BIRTHDAY_STORY",CREW_STORY:"CREW_STORY",EVENT_STORY:"EVENT_STORY",GOODWILL_GENERATED_STORY:"GOODWILL_GENERATED_STORY",GOODWILL_STORY:"GOODWILL_STORY",GROUP_STORY:"GROUP_STORY",HIGHLIGHTED_STORY:"HIGHLIGHTED_STORY",LIVE_STORY:"LIVE_STORY",M_GROUP_STORY:"M_GROUP_STORY",NULL_STATE_STORY:"NULL_STATE_STORY",PAGE_STORY:"PAGE_STORY",PROFILE_PLUS_STORY:"PROFILE_PLUS_STORY",PROMOTION_STORY:"PROMOTION_STORY",SHARED_PAGE_STORY:"SHARED_PAGE_STORY",STORY:"STORY",TOPIC_STORY:"TOPIC_STORY",UNKNOWN:"UNKNOWN",WAS_LIVE:"WAS_LIVE"},STORY_MEDIA_TYPES:{PHOTO:"Photo",VIDEO:"Video"},STORY_OVERLAY_TYPES:{EXTERNAL_SONG:"StoryOverlayExternalSong",INTERACTIVE_STICKER:"StoryOverlayReactionSticker",LINK_STICKER:"StoryOverlayLinkSticker",POLL_STICKER:"StoryOverlayPollSticker",RESHARED_CONTENT:"StoryOverlayResharedContent",RESHARED_POST:"StoryOverlayResharedPost",TAG_STICKER:"StoryOverlayTagSticker"},STORY_REACTION_STICKERS_CONSTANTS:{ANIMATIONS_INTERVAL_THROTTLE:300,HOLD_DELAY:1e3},TAG_STICKER_TYPES:{LOCATION:"LOCATION",PAGE:"PAGE",PEOPLE:"PEOPLE",PRODUCT:"PRODUCT"},VIEWER_THEME:{DARK_MODE:"dark_mode",DARK15:"dark_15",DARK30:"dark_30",DEFAULT:"default"},VIEWERSHEET_ANIMATION:{DEFAULT:"default",SLIDE_UP:"slide_up"},VIEWERSHEET_STYLE:{PAGE_TRANSITION:"PAGE_TRANSITION",USER:"USER",USER_TRANSITION:"USER_TRANSITION"},VOTING_PHASES:{JUST_VOTED:"JUST_VOTED",RESULTS:"RESULTS",VOTING:"VOTING"}};e.exports=a}),null);
__d("StoriesUniqueID",[],(function(a,b,c,d,e,f){"use strict";var g="js_",h=36,i=0;function a(){return g+(i++).toString(h)}e.exports=a}),null);
__d("StoriesUtils",["ExecutionEnvironment"],(function(a,b,c,d,e,f){"use strict";var g=500,h={};a={cardID2ThreadID:function(a){h[a]==null&&(h[a]=window.atob(a).split(":")[2]);return h[a]},shouldResizeToViewStories:function(a){return!b("ExecutionEnvironment").canUseDOM?!1:a<g}};e.exports=a}),null);
__d("FBStoriesLoggingConstants",[],(function(a,b,c,d,e,f){"use strict";a={EVENT_STORY:"event",FOLLOWEE_STORY:"followee",FRIEND_STORY:"friend",GROUP_STORY:"group",MISSING_STORY_DATA:"missingStoryData",PAGE_STORY:"page",SELF_STORY:"self",STORY_PROMOTION:"promotion",ACTION_OPEN_MEDIA:"open_media",ACTION_DELETE_MEDIA:"delete_media_attempted",ACTION_SEND_REPLY_ATTEMPT:"attempt_to_send_reply",ACTION_SEND_REACTION_STICKER_INTERACTED:"reaction_sticker_interacted",ACTION_OPEN_SEEN_SUMMARY:"open_seen_summary",ACTION_OPEN_STORY:"open_story",ACTION_CLOSE_STORY:"close_story",ACTION_TRAY_LOAD:"story_tray_load",ACTION_SEND_STORY_FAILED:"send_story_failed",ACTION_SEND_STORY_SUCCEEDED:"send_story_succeed",ACTION_REPLY_ATTEMPT_COMPLETED:"reply_attempt_completed",ACTION_STORY_NAVIGATION:"story_navigation",INTERACTION_TAP_RESHARED_STORY:"reshared_story_tap",INTERACTION_TAP_RESHARED_TOOLTIP:"reshared_story_view_story_tap",GESTURES:{CLOSE_STORY:{CLICK_RIGHT:"click_right",CLICK_LEFT:"click_left",AUTO_JUMP:"auto_jump",AUTO_EXIT:"auto_exit",CLICK_EXIT:"click_exit",SWIPE_RIGHT:"swipe_right",SWIPE_LEFT:"swipe_left",SWIPE_EXIT:"swipe_exit",SWIPE_DOWN_EXIT:"swipe_down_exit",CLOSE_BUTTON_EXIT:"close_button_exit",BACK_BUTTON_EXIT:"back_button_exit"}},SOURCE_CLOSE_FROM_MODAL:"closeFromClickingOnModal",SOURCE_CLOSE_FROM_MODAL_CLOSE_BUTTON:"closeFromClickingOnModalCloseButton",SOURCE_CLOSE_FROM_LAST_STORY_FINISHING:"closeFromLastStoryFinishing",SOURCES:{ARCHIVE:"archive",POST_HEADER:"post_header_actor_photo",STORY_TRAY:"story_tray",IN_FEED:"in_feed",UNKNOWN:"unknown"}};e.exports=a}),null);
__d("XFBStoriesSingleStoryAsyncController",["XController"],(function(a,b,c,d,e,f){e.exports=b("XController").create("/stories/view/async/",{card_id:{type:"FBID"},story_id:{type:"FBID"},auto_open_viewersheet:{type:"Bool",defaultValue:!1},story_action_source:{type:"String"}})}),null);
__d("FBStoriesRing",["csx","cx","Arbiter","CSS","DOM","FBStoriesLoggingConstants","XFBStoriesSingleStoryAsyncController"],(function(a,b,c,d,e,f,g,h){"use strict";a=function(){function a(a){this.$1=a.element;this.$2=a.profileId;this.$3=a.storyId;this.$4=!1;a=b("DOM").scry(this.$1,"._6_ut");a.length>0&&(this.$4=!0);this.$5()}var c=a.prototype;c.$5=function(){var a=this;b("Arbiter").subscribe("has_story_bucket_been_seen",function(c,d){if(a.$2===d){c=b("DOM").scry(a.$1,"._6_ut");c.length>0&&(b("CSS").removeClass(c[0],"_6_ut"),a.$4=!1)}});b("Arbiter").subscribe("update_next_thread_to_view",function(c,d){c=d.bucketOwnerId;d=d.threadId;if(a.$2===c&&a.$4){c=b("XFBStoriesSingleStoryAsyncController").getURIBuilder().setFBID("story_id",a.$3).setFBID("card_id",d).setBool("auto_open_viewersheet",!1).setString("story_action_source",b("FBStoriesLoggingConstants").SOURCES.POST_HEADER).getURI();a.$1.setAttribute("ajaxify",c)}})};return a}();e.exports=a}),null);