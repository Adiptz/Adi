if (self.CavalryLogger) { CavalryLogger.start_js(["+MRdg"]); }

__d("DynamicPageHovercardTypedLogger",["Banzai","GeneratedLoggerUtils","nullthrows"],(function(a,b,c,d,e,f){"use strict";a=function(){function a(){this.$1={}}var c=a.prototype;c.log=function(){b("GeneratedLoggerUtils").log("logger:DynamicPageHovercardLoggerConfig",this.$1,b("Banzai").BASIC)};c.logVital=function(){b("GeneratedLoggerUtils").log("logger:DynamicPageHovercardLoggerConfig",this.$1,b("Banzai").VITAL)};c.logImmediately=function(){b("GeneratedLoggerUtils").log("logger:DynamicPageHovercardLoggerConfig",this.$1,{signal:!0})};c.clear=function(){this.$1={};return this};c.getData=function(){return babelHelpers["extends"]({},this.$1)};c.updateData=function(a){this.$1=babelHelpers["extends"]({},this.$1,a);return this};c.setContentType=function(a){this.$1.content_type=a;return this};c.setContentTypeList=function(a){this.$1.content_type_list=a;return this};c.setEvent=function(a){this.$1.event=a;return this};c.setExtraInfo=function(a){this.$1.extra_info=a;return this};c.setPageid=function(a){this.$1.pageid=a;return this};c.setReferrer=function(a){this.$1.referrer=a;return this};c.setTime=function(a){this.$1.time=a;return this};c.setTimeSpent=function(a){this.$1.time_spent=a;return this};c.setTrackingNodeName=function(a){this.$1.tracking_node_name=a;return this};c.setTrackingNodeType=function(a){this.$1.tracking_node_type=a;return this};c.setUIID=function(a){this.$1.ui_id=a;return this};c.setWeight=function(a){this.$1.weight=a;return this};return a}();c={content_type:!0,content_type_list:!0,event:!0,extra_info:!0,pageid:!0,referrer:!0,time:!0,time_spent:!0,tracking_node_name:!0,tracking_node_type:!0,ui_id:!0,weight:!0};e.exports=a}),null);
__d("PagesHovercardFooter.react",["cx","DynamicPageHovercardTypedLogger","Layout.react","PageCTAViewerUnitContainer.react","PagesHeaderFollowButtonContainer.react","PagesHeaderLikeButtonContainer.react","PagesMessageButton.react","React"],(function(a,b,c,d,e,f,g){"use strict";var h=b("React"),i=b("Layout.react").Column;a=function(a){babelHelpers.inheritsLoose(c,a);function c(){return a.apply(this,arguments)||this}var d=c.prototype;d.render=function(){var a=this.$1(),c=this.$2(),d=this.$3(),e=(a!==null?1:0)+(c!==null?1:0)+(d!==null?1:0);e=e===3?"_1wcx":e===2?"_1wcy":"_1wcz";a!==null&&(a=h.jsx(i,{className:e,children:a}));c!==null&&(c=h.jsx(i,{className:e,children:c}));d!==null&&(d=h.jsx(i,{className:e,children:d}));return h.jsxs("div",{className:"_54ay",children:[this.$4(),h.jsx("div",{className:"_1wc-",children:h.jsxs(b("Layout.react"),{children:[a,c,d]})})]})};d.$4=function(){return!this.props.callToActionUnitData?null:h.jsx("div",{className:"callToActionButton",onClick:this.$5.bind(this),role:"presentation",children:h.jsx(b("PageCTAViewerUnitContainer.react"),babelHelpers["extends"]({},this.props.callToActionUnitData))})};d.$1=function(){return!this.props.likeFollowData||this.props.shouldDisableLikeButton?null:h.jsx("div",{onClick:this.$6.bind(this),role:"presentation",children:h.jsx(b("PagesHeaderLikeButtonContainer.react"),babelHelpers["extends"]({},this.props.likeFollowData))})};d.$2=function(){return!this.props.likeFollowData||!this.props.likeFollowData.followAllowed?null:h.jsx("div",{onClick:this.$7.bind(this),role:"presentation",children:h.jsx(b("PagesHeaderFollowButtonContainer.react"),babelHelpers["extends"]({},this.props.likeFollowData,{asPrimaryButton:"false"}))})};d.$3=function(){var a=this.props.messageData;return!a?null:h.jsx("div",{onClick:this.$8.bind(this),role:"presentation",children:h.jsx(b("PagesMessageButton.react"),{isInHovercard:!0,pageID:String(this.props.pageID),settings:a})})};d.$5=function(a){this.$9("cta_click")};d.$6=function(a){this.$9("like_click")};d.$7=function(a){this.$9("follow_click")};d.$8=function(a){this.$9("message_click")};d.$9=function(a){new(b("DynamicPageHovercardTypedLogger"))().setPageid(Number(this.props.pageID)).setEvent("header_footer_engagement").setContentType(99).setTrackingNodeType(0).setTrackingNodeName(a).setReferrer(this.props.referrer).setUIID(this.props.UIID).log()};return c}(h.Component);e.exports=a}),null);
__d("XSaveAddToSaveListController",["XController"],(function(a,b,c,d,e,f){e.exports=b("XController").create("/save/list/add/",{})}),null);
__d("XSavedListsFromSaverController",["XController"],(function(a,b,c,d,e,f){e.exports=b("XController").create("/save/lists/get/",{})}),null);
__d("PlacesSaveButton.react",["ix","cx","fbt","AsyncRequest","Image.react","MenuSeparator.react","MenuStaticItem.react","PlacesSearchClickTypeEnums.react","PlacesSearchResults.react","PopoverMenu.react","React","ReactXUIMenu","SimpleXUIDialog","XSaveAddToSaveListController","XSaveController","XSaveListCreateDialogController","XSavedListsFromSaverController","XUIButton.react","XUIPopoverButton.react","XUISpinner.react","fbglyph"],(function(a,b,c,d,e,f,g,h,i){"use strict";var j=b("React"),k=b("ReactXUIMenu").Item;a=function(a){babelHelpers.inheritsLoose(c,a);function c(b,c){b=a.call(this,b,c)||this;b.state={isLoading:!1,saveState:b.props.actionInfo.saveState==="SAVED"?"saved":"save",savedListMap:new Map()};return b}var d=c.prototype;d.render=function(){if(this.props.savedListsGk)return this.$1();else return this.$2()};d.$2=function(){var a=this,c=this.props.withoutLabel?"":this.state.saveState==="saved"?i._("Saved"):i._("Save"),d=this.props.withoutLabel?"_w0u":"_44h8",e=this.state.saveState==="saved"?g("136872"):g("125658"),f=this.state.saveState==="saving"||this.state.saveState==="unsaving",h=this.state.saveState==="saved"?"saved":"save",k=this.state.saveState==="saved"?b("PlacesSearchClickTypeEnums.react").SAVED:b("PlacesSearchClickTypeEnums.react").SAVE;return j.jsx(b("XUIButton.react"),babelHelpers["extends"]({className:d,size:this.props.size,"data-et":JSON.stringify({click_point:h,data:JSON.stringify({entity_id:this.props.entityID})})},b("PlacesSearchResults.react").getLoggingData({resultID:this.props.entityID,clickType:k}),{label:c,disabled:f,image:j.jsx(b("Image.react"),{src:e}),onClick:function(){return a.$3()}}))};d.$1=function(){return this.state.saveState==="save"||this.state.saveState==="saving"?this.$2():this.$4()};d.$5=function(a){var c=a.target.getAttribute("name");new(b("AsyncRequest"))().setURI(b("XSaveAddToSaveListController").getURIBuilder().getURI()).setData({object_id:this.props.entityID,list_id:a.target.getAttribute("value")}).setHandler(function(a){a=a.getPayload().response;a==="SAVED_IN_LIST"?b("SimpleXUIDialog").show(j.jsxs("div",{children:[i._("Successfully added to list"),'\xa0"',c,'"']})):a==="SAVE_ALREADY_IN_LIST"?b("SimpleXUIDialog").show(j.jsxs("div",{children:[i._("Already in list"),'\xa0"',c,'"']})):b("SimpleXUIDialog").show(j.jsx("div",{children:i._("Something went wrong, please try again.")}))}).send()};d.$6=function(){return!this.state.isLoading?null:j.jsx(k,{children:j.jsx(b("XUISpinner.react"),{size:"small"})})};d.$7=function(){var a=this;if(this.state.savedListMap===null||this.state.isLoading)return null;var c=[],d=this.state.savedListMap;for(var e in d){var f=d[e].name,h=d[e].icon,i=null;d[e].inList&&(i=j.jsx(b("Image.react"),{className:"_4jse",src:g("128986")}));c.push(j.jsx(k,{children:j.jsxs("div",{className:"_4jsf",name:f,onClick:function(b){return a.$5(b)},role:"presentation",value:e,children:[i,j.jsxs("span",{value:e,name:f,children:[j.jsx(b("Image.react"),{src:h}),f]})]})},e))}return c};d.$8=function(){if(this.state.isLoading)return null;if(Object.keys(this.state.savedListMap).length===0)return j.jsx(b("MenuStaticItem.react"),{children:i._("You have no saved lists yet.")});else return j.jsx(b("MenuStaticItem.react"),{children:i._("Add to...")})};d.$4=function(){var a=this,c=this.state.saveState==="unsaving",d=j.jsxs(b("ReactXUIMenu"),{children:[this.$8(),this.$6(),this.$7(),j.jsx(b("MenuSeparator.react"),{}),j.jsx(k,{onclick:function(b){return a.$9(b)},children:i._("Add to new list...")}),j.jsx(b("MenuSeparator.react"),{}),j.jsx(k,{onclick:function(b){return a.$3(b)},children:i._("Unsave")})]});return j.jsx("div",{children:j.jsx(b("PopoverMenu.react"),{menu:d,disabled:c,children:this.$10()})})};d.$10=function(){var a=this,c=this.props.withoutLabel?"":i._("Saved"),d=this.props.withoutLabel?"_w0u":"_44h8",e=g("136872"),f=this.state.saveState==="unsaving";return j.jsx(b("XUIPopoverButton.react"),babelHelpers["extends"]({className:d,size:this.props.size,"data-et":JSON.stringify({click_point:"saved",data:JSON.stringify({entity_id:this.props.entityID})})},b("PlacesSearchResults.react").getLoggingData({resultID:this.props.entityID,clickType:b("PlacesSearchClickTypeEnums.react").SAVED}),{label:c,disabled:f,image:j.jsx(b("Image.react"),{src:e}),onClick:function(){return a.$11()}}))};d.$3=function(){var a=this,c=this.state.saveState;this.setState({saveState:this.$12()});new(b("AsyncRequest"))().setURI(b("XSaveController").getURIBuilder().getURI()).setData({object_id:this.props.entityID,action:c==="saved"?"UNSAVE":"SAVE",surface:"search",mechanism:"search_result"}).setHandler(function(b){a.setState({saveState:b.error===0?a.$12():c})}).send()};d.$12=function(){if(this.state.saveState==="save")return"saving";if(this.state.saveState==="saving")return"saved";return this.state.saveState==="saved"?"unsaving":"save"};d.$11=function(){var a=this;this.setState({isLoading:!0});new(b("AsyncRequest"))().setURI(b("XSavedListsFromSaverController").getURIBuilder().getURI()).setData({object_id:this.props.entityID}).setHandler(function(b){a.setState({savedListMap:b.payload.savedListMap,isLoading:!1})}).send()};d.$9=function(){new(b("AsyncRequest"))().setURI(b("XSaveListCreateDialogController").getURIBuilder().getURI()).setData({object_id:this.props.entityID}).send()};return c}(j.Component);e.exports=a}),null);