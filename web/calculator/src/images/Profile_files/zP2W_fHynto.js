if (self.CavalryLogger) { CavalryLogger.start_js(["R0Mpn"]); }

__d("MoatNHTSignalTypes",[],(function(a,b,c,d,e,f){a=function(a){return{evaluate:function(){try{return a()}catch(a){return!1}},getName:function(){return a.toString()}}};b=function(a){return{evaluate:function(){try{return a()}catch(a){return-1}},getName:function(){return a.toString()}}};var g=10;c=function(a){return{evaluate:function(){try{var b=a();return Math.round(+b/g)*g}catch(a){return-1}},getName:function(){return a.toString()}}};d=function(a){return{evaluate:function(){try{return a()}catch(a){return""}},getName:function(){return a.toString()}}};e.exports={booleanSignal:a,continuousSignal:b,bucketizedSignal:c,stringSignal:d}}),null);
/**
 * Copyright 2004-present Facebook. All Rights Reserved.
 *
 * Two of the signals Moat wants are whether the 'webdriver-evaluate' and
 * 'webdriver-evauate-response' events were ever fired. Here we just set up
 * listeners for these events and remember if they ever fired. This is not
 * completely reliable as these events may have fired before this module ran.
 *
 * Defining these here rather than in the MoatNHTSignals module to keep that
 * one Moat-only code as much as possible.
 *
 * @format
 *  strict-local
 * @preserve-whitespace
 */__d("MoatNHTFacebookSpecificSignals",["EventListener","MoatNHTSignalTypes"],(function $module_MoatNHTFacebookSpecificSignals(global,require,requireDynamic,requireLazy,module,exports){




var booleanSignal=require('MoatNHTSignalTypes').booleanSignal;

var webdriverEvaluateFired=false;
var webdriverEvaluateResponseFired=false;

require("EventListener").listen(window,'webdriver-evaluate',function(){
webdriverEvaluateFired=true;
});

require("EventListener").listen(window,'webdriver-evaluate-response',function(){
webdriverEvaluateResponseFired=true;
});

var signals=[
booleanSignal(function(){return!!webdriverEvaluateFired;}),
booleanSignal(function(){return!!webdriverEvaluateResponseFired;})];


var MoatNHTFacebookSpecificSignals=


{
getSignals:function getSignals(){
return signals;
}};


module.exports=MoatNHTFacebookSpecificSignals;}),null);
/**
 * Copyright (c) 2011-2015 Moat Inc.  All Rights Reserved by Moat.
 * Confidential code, methods, and practices herein covered by Moat-Facebook
 * Non-Disclosure Agreement.
 *
 * This module contains proprietary code from Moat.
 *
 * This module implements various signals used for non-human traffic
 * detection by Moat, a third-party ads measurement company. Facebook is
 * partnering with Moat to provide third-party verification of
 * full-view impression logging.
 *
 * Each signal is a JavaScript fragment, provided by Moat. Facebook runs
 * these checks on full view ad impressions and sends Moat the results,
 * which they use to determine if the traffic came from a non-human
 * source (e.g. a bot).
 *
 * This module wraps Moat's JavaScript fragments in a form that can be
 * run on Facebook.
 *
 * @format
 * @preserve-whitespace
 * @nolint
 */__d("MoatNHTSignals",["MoatNHTSignalTypes"],(function $module_MoatNHTSignals(global,require,requireDynamic,requireLazy,module,exports){var MoatNHTSignalTypes;

var booleanSignal=(MoatNHTSignalTypes=require("MoatNHTSignalTypes")).booleanSignal;
var bucketizedSignal=MoatNHTSignalTypes.bucketizedSignal;
var continuousSignal=MoatNHTSignalTypes.continuousSignal;
var stringSignal=MoatNHTSignalTypes.stringSignal;




var docElemStyle=
document&&document.documentElement&&document.documentElement.style||
{};

var w=window,
d=w.document,
e=d.documentElement,
g=d.body,
p=w.navigator;

var inApp=
!!navigator.userAgent.match(/iPhone|iPod|iPad/)&&
!navigator.userAgent.match(/Safari|CriOS/i)||
!!new RegExp('Android').exec(navigator.userAgent)&&
!!navigator.userAgent.match(/Version/);

var isNativeFunction=function isNativeFunction(suspect){
if(!suspect||typeof suspect!=='function'){
return false;
}
if(String(Function.prototype.toString).indexOf('[native code]')<0){
if(suspect===Function.prototype.toString){
return false;
}else{
return null;
}
}
var isFnNative=String(suspect).indexOf('[native code]')>=0;
return isFnNative&&true||false;
};

var doesToStringOutputContain=function doesToStringOutputContain(fn,string){
return Object.prototype.toString.call(fn).indexOf(string)>0;
};

var isToStringNative=
String(Function.prototype.toString).indexOf('[native code]')>=0;








var signals=[

booleanSignal(function(){return!!(window.chrome&&window.chrome.webstore);}),
booleanSignal(function(){return!!document.documentMode;}),
booleanSignal(function(){return!!document.fonts.ready;}),
booleanSignal(function(){return!!window.ActiveXObject;}),
booleanSignal(function(){return!!window.chrome;}),
booleanSignal(function(){return!!window.navigator.serviceWorker;}),
booleanSignal(function(){return!!window.opera;}),
booleanSignal(function(){return!!window.sidebar;}),
booleanSignal(function(){return!+'\v1';}),
booleanSignal(function(){return!window.ActiveXObject;}),
booleanSignal(function(){return'-ms-ime-align'in docElemStyle;}),
booleanSignal(function(){return'-ms-scroll-limit'in docElemStyle;}),
booleanSignal(function(){return'-webkit-font-feature-settings'in document.body.style;}),
booleanSignal(function(){return'ActiveXObject'in window;}),
booleanSignal(function(){return'MozAppearance'in docElemStyle;}),
booleanSignal(function(){return'_phantom'in window;}),
booleanSignal(function(){return'callPhantom'in window;}),
booleanSignal(function(){return'content'in document.createElement('template');}),
booleanSignal(function(){return'getEntriesByType'in window.performance;}),
booleanSignal(function(){return'image-rendering'in document.body.style;}),
booleanSignal(function(){return'object-fit'in document.body.style;}),
booleanSignal(function(){return'open'in document.createElement('details');}),
booleanSignal(function(){return'orientation'in window.screen;}),
booleanSignal(function(){return'performance'in window;}),
booleanSignal(function(){return'shape-image-threshold'in document.body.style;}),
booleanSignal(function(){return'srcset'in document.createElement('img');}),
booleanSignal(function(){return window.CSS.supports('--fake-var','0');}),
booleanSignal(function(){return window.CSS.supports('cursor','grab');}),
booleanSignal(function(){return window.CSS.supports('cursor','zoom-in');}),
booleanSignal(function(){return window.CSS.supports('image-orientation','270deg');}),
booleanSignal(function(){return window.CSS.supports('position','sticky');}),
booleanSignal(function(){return CSS.supports('image-rendering','pixelated');}),
booleanSignal(function(){return CSS.supports('object-fit','contain');}),
booleanSignal(function(){return CSS.supports('object-fit','inherit');}),
booleanSignal(function(){return CSS.supports('shape-image-threshold','0.9');}),
booleanSignal(function(){return CSS.supports('word-break','keep-all');}),
booleanSignal(
function(){return window.document.createElement('style').scoped===undefined;}),

booleanSignal(
function(){return window.performance.getEntriesByType('resource')instanceof Array;}),

booleanSignal(function(){return typeof InstallTrigger==='undefined';}),
booleanSignal(function(){return typeof Intl.Collator().resolvedOptions()==='object';}),
booleanSignal(function(){return typeof window.navigator.onLine==='boolean';}),
booleanSignal(function(){return typeof window.navigator.webkitGamepads==='undefined';}),
booleanSignal(function(){return typeof window.performance.now()==='number';}),
booleanSignal(function(){return window.ActiveXObject.toString().indexOf('native')==-1;}),
booleanSignal(
function(){return(
Object.prototype.toString.
call(window.HTMLElement).
indexOf('Constructor')==-1);}),

booleanSignal(
function(){return'webkitWirelessVideoPlaybackDisabled'in w.HTMLVideoElement.prototype;}),

booleanSignal(function(){return p.appVersion.search(/Edge\/\d*.\d*/);}),
booleanSignal(
function(){return(
p.appVersion.search(/Edge\/\d*.\d*/)&&
!document.documentMode&&
!!w.StyleMedia);}),

booleanSignal(function(){return inApp;}),
booleanSignal(function(){return isNativeFunction(document.createElement('dialog').show);}),
booleanSignal(function(){return isNativeFunction(navigator.getBattery);}),
booleanSignal(function(){return isNativeFunction(navigator.permissions.query);}),
booleanSignal(function(){return isNativeFunction(new AudioContext().createBuffer);}),
booleanSignal(function(){return isNativeFunction(webkitRequestAnimationFrame);}),
booleanSignal(function(){return isNativeFunction(window.BroadcastChannel.call);}),
booleanSignal(function(){return isNativeFunction(window.FontFace);}),
booleanSignal(function(){return isNativeFunction(window.Gamepad);}),
booleanSignal(function(){return isNativeFunction(window.MutationEvent);}),
booleanSignal(function(){return isNativeFunction(window.MutationObserver);}),
booleanSignal(function(){return isNativeFunction(window.crypto.getRandomValues);}),
booleanSignal(function(){return isNativeFunction(window.document.body.createShadowRoot);}),
booleanSignal(function(){return(
isNativeFunction(window.document.body.webkitCreateShadowRoot));}),

booleanSignal(function(){return isNativeFunction(window.fetch);}),
booleanSignal(function(){return(
isNativeFunction(window.navigator.serviceWorker.register));}),

booleanSignal(function(){return isNativeFunction(window.navigator.webkitGetGamepads);}),
booleanSignal(function(){return isNativeFunction(window.speechSynthesis.speak);}),
booleanSignal(function(){return isNativeFunction(window.webkitRTCPeerConnection);}),
booleanSignal(function(){return isNativeFunction(document.elementsFromPoint);}),
booleanSignal(function(){return isNativeFunction(CSS.supports);}),
booleanSignal(function(){return isNativeFunction(Proxy);}),
booleanSignal(function(){return isNativeFunction(createImageBitmap);}),
booleanSignal(function(){return isNativeFunction(document.createElement('div').animate);}),
booleanSignal(function(){return(
isNativeFunction(document.documentElement.webkitRequestFullScreen));}),

booleanSignal(function(){return isNativeFunction(Intl.Collator);}),
booleanSignal(function(){return(
isNativeFunction(
document.createElement('div').animate(
[
{transform:'scale(1)',easing:'ease-in'},
{transform:'scale(1.3)',easing:'ease-in'}],

{duration:1300,iterations:1}).
reverse));}),


booleanSignal(
function(){return(
(doesToStringOutputContain(w.HTMLElement,'Constructor')||
!!(
'webkitWirelessVideoPlaybackDisabled'in w.HTMLVideoElement.prototype))&&

!inApp&&
isToStringNative&&
!isNativeFunction(w.alert)&&
!isNativeFunction(w.confirm)&&
!isNativeFunction(w.prompt));}),

booleanSignal(
function(){return(
typeof w.chrome!=='undefined'&&
isNativeFunction(w.chrome.csi)&&
!!w.chrome.webstore&&
!w.chrome.runtime.connect);}),

booleanSignal(
function(){return(
(typeof InstallTrigger==='undefined'||
'MozAppearance'in docElemStyle)&&
!!w.navigator.webdriver);}),

booleanSignal(
function(){return(
doesToStringOutputContain(w.HTMLElement,'Constructor')||
!!('webkitWirelessVideoPlaybackDisabled'in w.HTMLVideoElement.prototype));}),

booleanSignal(function(){return doesToStringOutputContain(w.HTMLElement,'Constructor');}),
booleanSignal(
function(){return(
'opr'in window&&
'addons'in window.opr&&
isNativeFunction(window.DetachedViewControlEvent));}),

booleanSignal(function(){return new Uint16Array(1)[0]==0;}),
booleanSignal(function(){return eval('1 == [for (item of [1,2,3]) item][0]');}),


continuousSignal(function(){return Date.now();}),
continuousSignal(function(){return new Date().getTimezoneOffset();}),



bucketizedSignal(
function(){return(
(w.innerWidth||d.documentElement.clientWidth||g.clientWidth)/(
w.innerHeight||d.documentElement.clientHeight||g.clientHeight));}),

bucketizedSignal(
function(){return(
(w.outerWidth||
w.document&&w.document.body&&w.document.body.offsetWidth)/(
w.outerHeight||
w.document&&w.document.body&&w.document.body.offsetHeight));}),

bucketizedSignal(function(){return w.screen.availWidth/w.screen.availHeight;}),
bucketizedSignal(function(){return w.screen.width/w.screen.height;}),
bucketizedSignal(function(){return w.screenX||w.screenLeft||w.screenX;}),
bucketizedSignal(function(){return w.screenY||w.screenTop||w.screenY;}),


stringSignal(function(){return w.navigator.platform;}),
stringSignal(function(){return w.navigator.vendor;})];


var MoatNHTSignals={
getSignals:function getSignals(){
return signals;
}};


module.exports=MoatNHTSignals;}),null);
__d("MoatNHTDetection",["Banzai","MoatNHTFacebookSpecificSignals","MoatNHTSignals","URI"],(function(a,b,c,d,e,f){var g,h=(b("MoatNHTSignals").getSignals()||[]).concat(b("MoatNHTFacebookSpecificSignals").getSignals()||[]),i=0,j=function(){var a={};h.forEach(function(b){a[b.getName()]=b.evaluate()});return a};a={evaluateAndLogSignals:function(a){var c=j();a={token:a,results:c};b("Banzai").post("xtrackable:moat_nht",a);i}};e.exports=a}),null);