if (self.CavalryLogger) { CavalryLogger.start_js(["uVeuh"]); }

__d("MessengerCreateVideoMeetupLinkMutation.graphql",[],(function(a,b,c,d,e,f){"use strict";a=function(){var a=[{defaultValue:null,kind:"LocalArgument",name:"input"}],b=[{alias:null,args:[{kind:"Variable",name:"data",variableName:"input"}],concreteType:"CreateVideoMeetupLinkResponsePayload",kind:"LinkedField",name:"create_video_meetup_link",plural:!1,selections:[{alias:null,args:null,concreteType:"MessengerCallInviteLink",kind:"LinkedField",name:"meetup_link",plural:!1,selections:[{alias:null,args:null,kind:"ScalarField",name:"id",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"link_url",storageKey:null},{alias:null,args:null,kind:"ScalarField",name:"link_hash",storageKey:null}],storageKey:null}],storageKey:null}];return{fragment:{argumentDefinitions:a,kind:"Fragment",metadata:null,name:"MessengerCreateVideoMeetupLinkMutation",selections:b,type:"Mutation",abstractKey:null},kind:"Request",operation:{argumentDefinitions:a,kind:"Operation",name:"MessengerCreateVideoMeetupLinkMutation",selections:b},params:{id:"3346221745407746",metadata:{},name:"MessengerCreateVideoMeetupLinkMutation",operationKind:"mutation",text:null}}}();e.exports=a}),null);
__d("MessengerCreateVideoMeetupLinkMutation",["Promise","requireCond","cr:1012418","MessengerCreateVideoMeetupLinkMutation.graphql"],(function(a,b,c,d,e,f){"use strict";var g,h=b("cr:1012418").commitMutation;b("cr:1012418").graphql;function a(a,c,d){d===void 0&&(d=!0);return new(b("Promise"))(function(e,f){h(a,{mutation:g!==void 0?g:g=b("MessengerCreateVideoMeetupLinkMutation.graphql"),onCompleted:function(a){var b;b=a==null?void 0:(b=a.create_video_meetup_link)==null?void 0:(b=b.meetup_link)==null?void 0:b.link_url;a=a==null?void 0:(a=a.create_video_meetup_link)==null?void 0:(a=a.meetup_link)==null?void 0:a.link_hash;return b!=null&&a!=null?e({linkHash:a,linkUrl:b}):f({error:"Failed to create linkurl."})},onError:function(a){f(a)},optimisticUpdater:null,variables:{input:{client_mutation_id:"",link_options:{link_surface:c,should_allow_anonymous_guests:d}}}})})}e.exports=a}),null);
__d("ZenonPreCallHookBuilderHelper",["regeneratorRuntime","Promise","ConstUriUtils","MessengerCreateVideoMeetupLinkMutation","VideoChatLinksUserActionsMultiplexLogger","ZenonCallWindowErrors","gkx","randomZenonCallID","randomZenonNonce"],(function(a,b,c,d,e,f){"use strict";var g=b("ZenonCallWindowErrors").CannotAcceptInviteError,h=b("ZenonCallWindowErrors").InviteNotFoundError,i=b("ZenonCallWindowErrors").UninitializedError;a={acceptCall:function(a,c){if(a===null)throw new i();var d=a.callInviteModel;a=a.callWindowController;var e=d.getCurrentInvite();if(e===null)throw new h();if(e.type!=="ringing"||e.context.type!=="thread")throw new g();var f=b("randomZenonNonce")();a=a.initCall({context:{controllerParams:e.controllerParams,intent:"accept invite"},joinContext:{thread:e.context.type==="thread"?e.context.thread:{id:"0",type:2},type:"thread"},mediaType:e.requestingVideo?"video":"audio",nonce:f});e=a[0];a=a[1];d.accept(f,{isPopupBlocked:e===null,trigger:c});return a},createMeetup:function(a,c,d,e){var f,g;return b("regeneratorRuntime").async(function(h){while(1)switch(h.prev=h.next){case 0:if(!(a===null)){h.next=2;break}throw new i();case 2:j(d,e).setEvent("meetup_attempt_create_meetup").log();h.prev=3;h.next=6;return b("regeneratorRuntime").awrap(b("MessengerCreateVideoMeetupLinkMutation")(c,b("gkx")("1224637")?"WORKPLACE":void 0,!b("gkx")("1224637")));case 6:f=h.sent;g=f.linkUrl;g!=null?j(d,e).setEvent("meetup_create_success").log():j(d,e).setEvent("meetup_create_failed").log();return h.abrupt("return",g);case 12:h.prev=12;h.t0=h["catch"](3);j(d,e).setEvent("meetup_create_failed").log();j(d,e).setEvent("error").setErrorType("LinkCreationError "+h.t0.name).setErrorDetails(h.t0.description).log();throw h.t0;case 17:case"end":return h.stop()}},null,this,[[3,12]])},joinMeetup:function(a,c,d,e){if(a===null)throw new i();var f=a.callInviteModel;a=a.callWindowController;var g=b("randomZenonNonce")();c=b("ConstUriUtils").getUri(c);e&&c&&(c=c.addQueryParam("users_to_ring",e));if(!c)return b("Promise").reject("An invalid URI was provided");e=a.initCall({context:{callID:b("randomZenonCallID")(),existingCall:null,intent:"start or join",invitees:[]},joinContext:{linkUrl:c.toString(),type:"link"},mediaType:"video",nonce:g});e[0];a=e[1];c=f.getCurrentInvite();c!=null&&d!=null&&f.accept(g,{isPopupBlocked:!1,trigger:d});return a},startCall:function(a,c){var d=c.existingCall,e=c.extra,f=c.invitees,g=c.mediaType,h=c.thread;c=c.trigger;if(a===null)throw new i();var j=a.callWindowController;a=a.incomingRingSDK;var k=b("randomZenonCallID")(),l=b("randomZenonNonce")();j=j.initCall({context:{callID:k,existingCall:d,intent:"start or join",invitees:f},extra:e,joinContext:{thread:h,type:"thread"},mediaType:g,nonce:l});d=j[0];f=j[1];a.startCallIntent(l,{callID:k,callTrigger:c,isPopupBlocked:d===null,isVideo:g==="video",peerID:h.type===1?h.id:"MW_PEER_ID",protocol:h.type===1?"p2p":"mw"});return f}};function j(a,c){return new(b("VideoChatLinksUserActionsMultiplexLogger"))().setSurface(a).setComponent(c)}e.exports=a}),null);
__d("QpActionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","qp_action");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("QpImpressionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","qp_impression");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomCardImpressionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_card_impression");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomCardTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_card_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomCreateTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_create_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomGroupRoomListViewImpressionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_group_room_list_view_impression");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomGroupRoomListViewItemTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_group_room_list_view_item_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomGroupRoomRhcImpressionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_group_room_rhc_impression");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomInterestTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_interest_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomJoinTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_join_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomPromotionUnitImpressionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_promotion_unit_impression");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomPromotionUnitTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_promotion_unit_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomSelfCardButtonTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_self_card_button_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomSelfCardTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_self_card_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomSettingSheetImpressionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_setting_sheet_impression");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomTrayImpressionFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_tray_impression");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);
__d("RoomUpdateTapFalcoEvent",["FalcoLoggerInternal","getSamplingPolicyConfig_DO_NOT_USE"],(function(a,b,c,d,e,f){"use strict";a=b("getSamplingPolicyConfig_DO_NOT_USE")("falco","room_update_tap");c=b("FalcoLoggerInternal").create(a);e.exports=c}),null);