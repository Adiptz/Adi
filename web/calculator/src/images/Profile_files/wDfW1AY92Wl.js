if (self.CavalryLogger) { CavalryLogger.start_js(["jUhiI"]); }

__d("CometVideoHomeLiveUpNextOverlay_query.graphql",[],(function(a,b,c,d,e,f){"use strict";a={argumentDefinitions:[],kind:"Fragment",metadata:null,name:"CometVideoHomeLiveUpNextOverlay_query",selections:[{alias:null,args:[{kind:"Literal",name:"section_type",value:"WWW_LIVE_HERO"}],concreteType:"VideoHomeSection",kind:"LinkedField",name:"video_home_section",plural:!1,selections:[{alias:null,args:null,concreteType:"VideoHomeSectionComponentsConnection",kind:"LinkedField",name:"section_components",plural:!1,selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"nodes",plural:!0,selections:[{kind:"InlineFragment",selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"feed_unit",plural:!1,selections:[{kind:"InlineFragment",selections:[{alias:null,args:null,concreteType:"StoryAttachment",kind:"LinkedField",name:"attachments",plural:!0,selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"media",plural:!1,selections:[{kind:"InlineFragment",selections:[{alias:null,args:null,kind:"ScalarField",name:"id",storageKey:null},{args:null,kind:"FragmentSpread",name:"CometTahoeUpNextOverlay_video"}],type:"Video",abstractKey:null}],storageKey:null}],storageKey:null}],type:"Story",abstractKey:null}],storageKey:null}],type:"VideoHomeFeedUnitSectionComponent",abstractKey:null}],storageKey:null}],storageKey:null}],storageKey:'video_home_section(section_type:"WWW_LIVE_HERO")'}],type:"Query",abstractKey:null};e.exports=a}),null);
__d("VideoHomeLiveComponentWithUpNextQuery.graphql",[],(function(a,b,c,d,e,f){"use strict";a=function(){var a={alias:null,args:null,kind:"ScalarField",name:"__typename",storageKey:null},b={alias:null,args:null,kind:"ScalarField",name:"id",storageKey:null},c={alias:null,args:null,kind:"ScalarField",name:"uri",storageKey:null},d={alias:null,args:null,kind:"ScalarField",name:"length",storageKey:null},e={alias:null,args:null,kind:"ScalarField",name:"offset",storageKey:null},f=[b],g={kind:"InlineFragment",selections:f,type:"Node",abstractKey:"__isNode"},h={alias:null,args:null,kind:"ScalarField",name:"name",storageKey:null},i={alias:null,args:null,kind:"ScalarField",name:"verification_status",storageKey:null},j={alias:null,args:null,kind:"ScalarField",name:"is_verified",storageKey:null},k={alias:null,args:null,concreteType:"WorkForeignEntityInfo",kind:"LinkedField",name:"work_foreign_entity_info",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"type",storageKey:null}],storageKey:null};return{fragment:{argumentDefinitions:[],kind:"Fragment",metadata:null,name:"VideoHomeLiveComponentWithUpNextQuery",selections:[{args:null,kind:"FragmentSpread",name:"CometVideoHomeLiveUpNextOverlay_query"}],type:"Query",abstractKey:null},kind:"Request",operation:{argumentDefinitions:[],kind:"Operation",name:"VideoHomeLiveComponentWithUpNextQuery",selections:[{alias:null,args:[{kind:"Literal",name:"section_type",value:"WWW_LIVE_HERO"}],concreteType:"VideoHomeSection",kind:"LinkedField",name:"video_home_section",plural:!1,selections:[{alias:null,args:null,concreteType:"VideoHomeSectionComponentsConnection",kind:"LinkedField",name:"section_components",plural:!1,selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"nodes",plural:!0,selections:[a,{kind:"InlineFragment",selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"feed_unit",plural:!1,selections:[a,{kind:"InlineFragment",selections:[{alias:null,args:null,concreteType:"StoryAttachment",kind:"LinkedField",name:"attachments",plural:!0,selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"media",plural:!1,selections:[a,{kind:"InlineFragment",selections:[b,{alias:null,args:null,kind:"ScalarField",name:"is_live_streaming",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"playable_duration",storageKey:null},{alias:null,args:null,concreteType:"VideoThumbnail",kind:"LinkedField",name:"preferred_thumbnail",plural:!1,selections:[{alias:null,args:[{kind:"Literal",name:"height",value:145},{kind:"Literal",name:"sizing",value:"cover-fill-cropped"},{kind:"Literal",name:"width",value:257}],concreteType:"Image",kind:"LinkedField",name:"image",plural:!1,selections:[c],storageKey:'image(height:145,sizing:"cover-fill-cropped",width:257)'},b],storageKey:null},{alias:null,args:null,concreteType:"TextWithEntities",kind:"LinkedField",name:"title",plural:!1,selections:[{alias:null,args:null,concreteType:"ImageAtRange",kind:"LinkedField",name:"image_ranges",plural:!0,selections:[d,e,{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"entity_with_image",plural:!1,selections:[a,{alias:null,args:null,concreteType:"Image",kind:"LinkedField",name:"image",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"height",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"scale",storageKey:null},c,{alias:null,args:null,kind:"ScalarField",name:"width",storageKey:null}],storageKey:null},g],storageKey:null}],storageKey:null},{alias:null,args:null,concreteType:"InlineStyleAtRange",kind:"LinkedField",name:"inline_style_ranges",plural:!0,selections:[d,e,{alias:null,args:null,kind:"ScalarField",name:"inline_style",storageKey:null}],storageKey:null},{alias:null,args:null,concreteType:"AggregatedEntitiesAtRange",kind:"LinkedField",name:"aggregated_ranges",plural:!0,selections:[d,e,{alias:null,args:null,kind:"ScalarField",name:"count",storageKey:null},{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"sample_entities",plural:!0,selections:[a,{kind:"InlineFragment",selections:[b,h],type:"User",abstractKey:null},g],storageKey:null}],storageKey:null},{alias:null,args:null,concreteType:"EntityAtRange",kind:"LinkedField",name:"ranges",plural:!0,selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"entity",plural:!1,selections:[a,{kind:"TypeDiscriminator",abstractKey:"__isEntity"},{alias:null,args:[{kind:"Literal",name:"site",value:"www"}],kind:"ScalarField",name:"url",storageKey:'url(site:"www")'},{kind:"InlineFragment",selections:[b,{kind:"InlineFragment",selections:[{alias:"profile_url",args:null,kind:"ScalarField",name:"url",storageKey:null}],type:"Entity",abstractKey:"__isEntity"}],type:"Actor",abstractKey:"__isActor"},{kind:"InlineFragment",selections:[{alias:null,args:null,kind:"ScalarField",name:"external_url",storageKey:null}],type:"ExternalUrl",abstractKey:null},{kind:"InlineFragment",selections:[{alias:null,args:null,kind:"ScalarField",name:"time_index",storageKey:null}],type:"VideoTimeIndex",abstractKey:null},{kind:"InlineFragment",selections:[{alias:null,args:null,kind:"ScalarField",name:"category_type",storageKey:null},i,b,j],type:"Page",abstractKey:null},{kind:"InlineFragment",selections:[k,{alias:null,args:null,concreteType:"WorkUserInfo",kind:"LinkedField",name:"work_info",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"is_active_account",storageKey:null}],storageKey:null}],type:"User",abstractKey:null},{kind:"InlineFragment",selections:[k,{alias:null,args:null,kind:"ScalarField",name:"work_official_status",storageKey:null}],type:"Group",abstractKey:null},g],storageKey:null},d,e],storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"text",storageKey:null}],storageKey:null},{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"owner",plural:!1,selections:[a,h,{kind:"TypeDiscriminator",abstractKey:"__isActor"},b,{kind:"InlineFragment",selections:[i],type:"Page",abstractKey:null},{kind:"InlineFragment",selections:[j],type:"User",abstractKey:null}],storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"breaking_status",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"is_premiere",storageKey:null}],type:"Video",abstractKey:null},g,{kind:"InlineFragment",selections:f,type:"GenericAttachmentMedia",abstractKey:null},{kind:"InlineFragment",selections:f,type:"MontageImage",abstractKey:null},{kind:"InlineFragment",selections:f,type:"MontageVideo",abstractKey:null}],storageKey:null}],storageKey:null}],type:"Story",abstractKey:null},g],storageKey:null}],type:"VideoHomeFeedUnitSectionComponent",abstractKey:null},g],storageKey:null}],storageKey:null},b],storageKey:'video_home_section(section_type:"WWW_LIVE_HERO")'}]},params:{id:"2970289099751415",metadata:{},name:"VideoHomeLiveComponentWithUpNextQuery",operationKind:"query",text:null}}}();e.exports=a}),null);
__d("VideoHomeLiveHeroPlayerOverlay_video.graphql",[],(function(a,b,c,d,e,f){"use strict";a=function(){var a={alias:null,args:null,kind:"ScalarField",name:"name",storageKey:null};return{argumentDefinitions:[],kind:"Fragment",metadata:null,name:"VideoHomeLiveHeroPlayerOverlay_video",selections:[{alias:null,args:null,kind:"ScalarField",name:"broadcast_status",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"is_video_broadcast",storageKey:null},a,{alias:null,args:null,concreteType:"TextWithEntities",kind:"LinkedField",name:"savable_description",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"text",storageKey:null}],storageKey:null},{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"owner",plural:!1,selections:[a,{alias:null,args:null,concreteType:"Image",kind:"LinkedField",name:"profile_picture",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"uri",storageKey:null}],storageKey:null},{kind:"InlineFragment",selections:[{alias:null,args:null,kind:"ScalarField",name:"is_verified",storageKey:null}],type:"Page",abstractKey:null}],storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"live_rewind_enabled",storageKey:null},{args:null,kind:"FragmentSpread",name:"VideoHomeVideoOwnerLink_video"},{args:null,kind:"FragmentSpread",name:"CometVideoHomeThreeDotContextMenuWrapper_video"}],type:"Video",abstractKey:null}}();e.exports=a}),null);
__d("VideoHomeLiveHeroPlayer_video.graphql",[],(function(a,b,c,d,e,f){"use strict";a=function(){var a={alias:null,args:null,kind:"ScalarField",name:"id",storageKey:null};return{argumentDefinitions:[],kind:"Fragment",metadata:null,name:"VideoHomeLiveHeroPlayer_video",selections:[a,{alias:null,args:null,kind:"ScalarField",name:"url",storageKey:null},{alias:null,args:null,concreteType:"Image",kind:"LinkedField",name:"image",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"uri",storageKey:null}],storageKey:null},{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"video_channel",plural:!1,selections:[a],storageKey:null},{alias:null,args:null,concreteType:"LiveVideoConfig",kind:"LinkedField",name:"live_video_config",plural:!1,selections:[{alias:null,args:[{kind:"Literal",name:"params_to_expose",value:["is_enabled","creation_source"]}],concreteType:"LiveVideoClippingConfig",kind:"LinkedField",name:"clipping_config",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"is_enabled",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"creation_source",storageKey:null}],storageKey:'clipping_config(params_to_expose:["is_enabled","creation_source"])'}],storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"live_rewind_enabled",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"broadcast_status",storageKey:null},{args:null,kind:"FragmentSpread",name:"VideoHomeLiveHeroPlayerOverlay_video"}],type:"Video",abstractKey:null}}();e.exports=a}),null);
__d("VideoHomeVideoOwnerLink_video.graphql",[],(function(a,b,c,d,e,f){"use strict";a={argumentDefinitions:[],kind:"Fragment",metadata:null,name:"VideoHomeVideoOwnerLink_video",selections:[{alias:null,args:null,concreteType:null,kind:"LinkedField",name:"owner",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"id",storageKey:null},{kind:"InlineFragment",selections:[{alias:null,args:null,kind:"ScalarField",name:"uri_token",storageKey:null}],type:"Page",abstractKey:null}],storageKey:null}],type:"Video",abstractKey:null};e.exports=a}),null);
__d("CometVideoHomeLiveUpNextOverlay.react",["requireDeferred","CometRelay","CometTahoeUpNextOverlay.react","CometVideoHomeLiveContext","React","XCometVideoHomeLiveControllerRouteBuilder","stylex","CometVideoHomeLiveUpNextOverlay_query.graphql"],(function(a,b,c,d,e,f){"use strict";var g;b("CometRelay").graphql;var h=b("CometRelay").useFragment,i=b("React");c=b("React");var j=c.useContext,k=c.useState,l=b("requireDeferred")("VideoHomeTypedLoggerLite"),m=5;function a(a){var b=k(!1),c=b[0];b=b[1];return c?null:i.jsx(n,babelHelpers["extends"]({},a,{setCancelled:b}))}function n(a){var c=a.query,d=a.setCancelled;a=h(g!==void 0?g:g=b("CometVideoHomeLiveUpNextOverlay_query.graphql"),c);c=a.video_home_section;a=j(b("CometVideoHomeLiveContext"));var e=a.setHotswapVideoID,f=c==null?void 0:(a=c.section_components)==null?void 0:(c=a.nodes)==null?void 0:(a=c[0])==null?void 0:(c=a.feed_unit)==null?void 0:(a=c.attachments)==null?void 0:(c=a[0])==null?void 0:c.media;if(f==null)return null;a={};f.id!=null&&(a.v=f.id);c=b("XCometVideoHomeLiveControllerRouteBuilder").buildURL(a);a=function(){e(f.id),l.onReady(function(a){a.log({event:"www_live_hero_up_next_chain",event_target:"video",event_target_id:f.id})})};return i.jsx("div",{className:"kr520xx4 j9ispegn pmk7jnqg mrt03zmi n7fi1qx3 i09qtzwb qqguqgly",children:i.jsx(b("CometTahoeUpNextOverlay.react"),{isMakingProgress:!0,navigateToNextVideo:a,nextVideoURL:c,onCancelCallback:function(){return d(!0)},onProgressDone:a,timeoutSec:m,video:f,visible:!0})})}e.exports=a}),null);
__d("VideoHomeLiveComponentWithClickToTahoeOrScrollTop.react",["requireCond","React","cr:1279507","VideoComponent","cr:1289297","cr:1289298","cr:1289299","cr:1289300","cr:1279508","VideoWithClickToTahoe"],(function(a,b,c,d,e,f){"use strict";a=b("React");c=function(a){babelHelpers.inheritsLoose(c,a);function c(){return a.apply(this,arguments)||this}var d=c.prototype;d.enable=function(a){var c=new(b("VideoWithClickToTahoe"))(a,this.props.videoPermalink,this.props.videoChannelID,this.props.caller,this.props.isOfferVideo,a.getPlayerOrigin(),a.getPlayerSuborigin(),this.props.storyIdentifier,this.props.feedLocation,this.props.reactionVideoChannelType,null,this.props.externalLogID);if(b("cr:1279507")!=null&&b("cr:1279508")!=null){var d=new(b("cr:1279508"))(a,this.$1);d.disable();this.subscriptionsHandler=new(b("cr:1279507"))();this.subscriptionsHandler.addSubscriptions(a.addListener("enterWatchAndScroll",function(){c.disable(),d.enable()}),a.addListener("exitWatchAndScroll",function(){c.enable(),d.disable()}))}};d.disable=function(){var a;(a=this.subscriptionsHandler)==null?void 0:a.release()};d.$1=function(){if(!b("cr:1289300")||!b("cr:1289299")||!b("cr:1289297")||!b("cr:1289298"))return;b("cr:1289300").log({event:b("cr:1289299").CLICK,click_point:b("cr:1289297").LIVE_WNS,click_target:b("cr:1289298").VIDEO})};d.shouldComponentUpdate=function(){return!1};d.render=function(){return null};return c}(a.Component);e.exports=b("VideoComponent").createContainer(c)}),null);
__d("VideoHomeLiveComponentWithMuteObserver.react",["CometVideoHomeLiveContext","React","SubscriptionsHandler"],(function(a,b,c,d,e,f){"use strict";a=b("React");c=function(a){babelHelpers.inheritsLoose(c,a);function c(){var c,d;for(var e=arguments.length,f=new Array(e),g=0;g<e;g++)f[g]=arguments[g];return(c=d=a.call.apply(a,[this].concat(f))||this,d.subscriptions=new(b("SubscriptionsHandler"))(),c)||babelHelpers.assertThisInitialized(d)}var d=c.prototype;d.enable=function(a){var b=this;this.subscriptions.addSubscriptions(a.addListener("muteVideo",function(){b.context.setVideoMuted(!0)}),a.addListener("unmuteVideo",function(){b.context.setVideoMuted(!1)}))};d.disable=function(){};d.componentWillUnmount=function(){this.subscriptions.release()};d.render=function(){return null};return c}(a.Component);c.contextType=b("CometVideoHomeLiveContext");e.exports=c}),null);
__d("VideoHomeLiveComponentWithUpNext.react",["CometVideoHomeLiveUpNextOverlay.react","React","RelayFBEnvironment","RelayModern","SubscriptionsHandler","VideoHomeVisibilityUtils","requestIdleCallback","VideoHomeLiveComponentWithUpNextQuery.graphql"],(function(a,b,c,d,e,f){"use strict";var g,h=b("React"),i=b("RelayModern").QueryRenderer;b("RelayModern").graphql;a=function(a){babelHelpers.inheritsLoose(c,a);function c(){var c,d;for(var e=arguments.length,f=new Array(e),g=0;g<e;g++)f[g]=arguments[g];return(c=d=a.call.apply(a,[this].concat(f))||this,d.state={hidden:!0,playerFinished:!1},d.subscriptions=new(b("SubscriptionsHandler"))(),d.$1=function(){d.vpc&&b("VideoHomeVisibilityUtils").isVisible(d.vpc)?d.setState({hidden:!1}):b("requestIdleCallback")(d.$1)},c)||babelHelpers.assertThisInitialized(d)}var d=c.prototype;d.enable=function(a){var b=this;this.vpc=a;this.subscriptions.addSubscriptions(a.addListener("stateChange",function(){var c=a.getState()==="finished";b.setState({playerFinished:c});c&&b.$1()}))};d.disable=function(){};d.componentWillUnmount=function(){this.subscriptions.release()};d.render=function(){var a=this.state,c=a.hidden;a=a.playerFinished;return!this.vpc||c||!a?null:h.jsx(i,{environment:b("RelayFBEnvironment"),query:g!==void 0?g:g=b("VideoHomeLiveComponentWithUpNextQuery.graphql"),render:function(a){var c=a.error;a=a.props;return c||a==null?null:h.jsx(b("CometVideoHomeLiveUpNextOverlay.react"),{query:a})},variables:{}})};return c}(h.PureComponent);e.exports=a}),null);
__d("VideoCompnentWithFluentUFISupport.react",["React","UFIVideoPlayerRegistry","VideoComponent"],(function(a,b,c,d,e,f){"use strict";a=b("React");c=function(a){babelHelpers.inheritsLoose(c,a);function c(){return a.apply(this,arguments)||this}var d=c.prototype;d.enable=function(a){b("UFIVideoPlayerRegistry").registerVideoPlayerController(a)};d.disable=function(){};d.render=function(){return null};return c}(a.Component);e.exports=b("VideoComponent").createContainer(c)}),null);
__d("VideoHomeVideoOwnerLink.react",["Link.react","React","RelayHooks","XVideoHomeShowController","VideoHomeVideoOwnerLink_video.graphql"],(function(a,b,c,d,e,f){"use strict";var g,h=b("React");b("RelayHooks").graphql;var i=b("RelayHooks").useFragment;function a(a){var c,d=a.children,e=a.video;a=babelHelpers.objectWithoutPropertiesLoose(a,["children","video"]);e=i(g!==void 0?g:g=b("VideoHomeVideoOwnerLink_video.graphql"),e);e=(e==null?void 0:(c=e.owner)==null?void 0:c.uri_token)||(e==null?void 0:(c=e.owner)==null?void 0:c.id);if(e==null)return h.jsx(h.Fragment,{children:d});c=b("XVideoHomeShowController").getURIBuilder().setString("section_id",e).getURI();return h.jsx(b("Link.react"),babelHelpers["extends"]({},a,{href:c,children:d}))}e.exports=a}),null);
__d("VideoHomeLiveHeroPlayerOverlay.react",["cx","fbt","requireCond","Badge.react","cr:1427299","Image.react","LineClamp.react","React","RelayHooks","VideoBroadcastStatus","VideoHomeVerifiedPageTooltip.react","VideoHomeVideoOwnerLink.react","stylex","VideoHomeLiveHeroPlayerOverlay_video.graphql"],(function(a,b,c,d,e,f,g,h){"use strict";var i,j,k=b("React");b("RelayHooks").graphql;var l=b("RelayHooks").useFragment;(j||(j=b("stylex"))).inject(".ff05a22o{right:12px}",1,".ff05a22o{left:12px}");j.inject(".s8sjc6am{position:absolute}",1);j.inject(".facqkgn9{top:12px}",1);function a(a){var c,d,e;a=a.video;a=l(i!==void 0?i:i=b("VideoHomeLiveHeroPlayerOverlay_video.graphql"),a);c=a.name!=null&&a.name!==""?a.name:(c=a.savable_description)==null?void 0:c.text;d=(d=a.owner)==null?void 0:(d=d.profile_picture)==null?void 0:d.uri;e=(e=a.owner)==null?void 0:e.name;var f=a.broadcast_status===b("VideoBroadcastStatus").LIVE;return k.jsxs(k.Fragment,{children:[!f&&k.jsx("div",{className:"_8ts-"}),k.jsxs("div",{className:"_8nga"+(f?"":" _8ts_")+(f&&a.live_rewind_enabled?" _8y-i":""),children:[k.jsx(b("VideoHomeVideoOwnerLink.react"),{video:a,children:k.jsx(b("Image.react"),{className:"_8ngb",height:36,src:d,width:36})}),k.jsxs("div",{className:"_8ngc"+(f?" _91po":""),children:[k.jsxs("div",{className:"_91ol",children:[c!=null&&c!==""&&k.jsx(b("LineClamp.react"),{className:"_8ngd",lineHeight:20,lines:1,children:c}),!f&&a.is_video_broadcast===!0&&k.jsx("div",{className:"_91om",children:h._("Recorded Live")})]}),k.jsxs("div",{className:"_8tt0",children:[k.jsx(b("VideoHomeVideoOwnerLink.react"),{className:"_8nge",video:a,children:e}),((d=a.owner)==null?void 0:d.is_verified)===!0&&k.jsx(b("VideoHomeVerifiedPageTooltip.react"),{children:k.jsx(b("Badge.react"),{size:"xsmall",type:"verified"})})]})]})]}),b("cr:1427299")&&k.jsx("div",{className:"facqkgn9 s8sjc6am ff05a22o",children:k.jsx(b("cr:1427299"),{video:a,videoMenuLocation:"VIDEO_HOME_LIVE_TAB"})})]})}e.exports=a}),null);
__d("VideoHomeLiveHeroPlayer.react",["cx","requireCond","requireDeferred","CometVideoHomeLiveContext","cr:1338723","cr:1338724","Image.react","cr:1432591","React","RelayHooks","VideoCompnentWithFluentUFISupport.react","VideoComponentAutoPlayControl.react","VideoComponentContextMenu.react","VideoComponentDebugOverlay.react","VideoComponentEmbeddedControls.react","VideoComponentWithExternalLogger.react","cr:1430101","VideoHomeLiveComponentWithClickToTahoeOrScrollTop.react","VideoHomeLiveComponentWithMuteObserver.react","VideoHomeLoggingExternalLogIDContext","deferredLoadComponent","VideoComponentLiveVideoIndicator.react","VideoComponentPlayButton.react","VideoComponentStreamingReactionTray.react","VideoComponentWithLiveBroadcast.react","VideoComponentWithMetadataOverlay.react","VideoComponentWithTahoeExitAutoplay.react","VideoDataContainer.react","VideoHomeLiveComponentWithUpNext.react","VideoHomeLiveHeroPlayerOverlay.react","VideoPlayer.react","VideoHomeLiveHeroPlayer_video.graphql"],(function(a,b,c,d,e,f,g){"use strict";var h,i=b("React");c=b("React");var j=c.useContext,k=c.useEffect,l=c.useState;b("RelayHooks").graphql;var m=b("RelayHooks").useFragment,n=b("deferredLoadComponent")(b("requireDeferred")("VideoComponentLiveEndScreen.react")),o=b("deferredLoadComponent")(b("requireDeferred")("VideoComponentLiveInterruptedScreen.react")),p=b("requireDeferred")("VideoHomeTypedLoggerLite");function a(a){var c=a.reactionVideoChannelType,d=c===void 0?"video_home_www_live_hero":c;c=a.playerOrigin;c=c===void 0?"video_home":c;var e=a.playerSubOrigin;e=e===void 0?"topic_live":e;var f=m(h!==void 0?h:h=b("VideoHomeLiveHeroPlayer_video.graphql"),a.video);a=l(!0);var g=a[0],q=a[1];a=j(b("CometVideoHomeLiveContext"));var r=a.setHeroVideoID;a=a.videoMuted;var s=f.id;k(function(){r(s)},[r,s]);var t=j(b("VideoHomeLoggingExternalLogIDContext"));if(f==null||s==null||f.url==null)return null;var u=function(){p.onReady(function(a){a.log({event:"click",event_target:"video",event_target_id:s,event_target_info:f.url,section_video_channel_type:d})})},v="DEFAULT",w=["pages_live_tab"].includes(c),x=w;w=w;return i.jsx("div",{className:"_8n18",children:i.jsxs("div",{className:"_150c",children:[!g&&i.jsx(b("Image.react"),{className:"_3chq",src:(g=f.image)==null?void 0:g.uri}),i.jsx(b("VideoDataContainer.react"),{onVideoLoaded:function(){q(!1)},renderLoading:function(){return i.jsx("div",{className:"_53j5",style:{width:"100%",height:"100%"},children:i.jsx("i",{className:"_5l7x"})})},videoID:s,children:i.jsxs(b("VideoPlayer.react"),{disableClickPlayPause:!0,onVideoClick:u,playerOrigin:c,reactionVideoChannelType:d,startMuted:a,subOrigin:e,videoData:b("VideoDataContainer.react").VIDEO_DATA_PLACEHOLDER,children:[i.jsx(b("VideoComponentAutoPlayControl.react"),{}),i.jsx(b("VideoComponentLiveVideoIndicator.react"),{}),i.jsx(b("VideoComponentWithLiveBroadcast.react"),{}),i.jsx(o,{}),i.jsx(n,{}),i.jsx(b("VideoComponentDebugOverlay.react"),{}),i.jsx(b("VideoComponentContextMenu.react"),{}),i.jsx(b("VideoHomeLiveComponentWithClickToTahoeOrScrollTop.react"),{caller:"channel_view_from_video_home",externalLogID:t,reactionVideoChannelType:d,videoPermalink:f.url,videoChannelID:(g=f.video_channel)==null?void 0:g.id,isOfferVideo:!1}),i.jsx(b("VideoComponentEmbeddedControls.react"),{showFullscreenButton:b("cr:1430101")===null,unhideControlsOnHover:!0,gamesVideoCreatorClippingGK:((a=(u=f.live_video_config)==null?void 0:(c=u.clipping_config)==null?void 0:c.is_enabled)!=null?a:!1)&&((e=f.live_video_config)==null?void 0:(g=e.clipping_config)==null?void 0:g.creation_source)===v,isLiveRewindEnabled:f.live_rewind_enabled,forceVisibleOnMount:!0}),i.jsx(b("VideoComponentStreamingReactionTray.react"),{}),i.jsx(b("VideoComponentWithTahoeExitAutoplay.react"),{}),i.jsx(b("VideoComponentWithMetadataOverlay.react"),{overlay:i.jsx(b("VideoHomeLiveHeroPlayerOverlay.react"),{video:f})}),!w&&i.jsx(b("VideoHomeLiveComponentWithUpNext.react"),{}),i.jsx(b("VideoHomeLiveComponentWithMuteObserver.react"),{}),b("cr:1432591")!=null&&i.jsx(b("cr:1432591"),{videoID:s}),i.jsx(b("VideoComponentPlayButton.react"),{}),i.jsx(b("VideoComponentWithExternalLogger.react"),{externalLogID:t,playerOrigin:"video_home",playerSuborigin:"topic_live"}),!x&&b("cr:1430101")&&i.jsx(b("cr:1430101"),{closeButtonClickPoint:"live_wns",impressionEvent:"www_live_wns_impression",videoChainingCaller:"live_tab"}),b("cr:1338723")!=null?i.jsx(b("cr:1338723"),{broadcastStatus:f.broadcast_status}):null,b("cr:1338724")!=null?i.jsx(b("cr:1338724"),{broadcastStatus:f.broadcast_status}):null,i.jsx(b("VideoCompnentWithFluentUFISupport.react"),{})]})})]})})}e.exports=a}),null);