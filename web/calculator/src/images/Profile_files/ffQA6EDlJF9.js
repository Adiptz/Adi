if (self.CavalryLogger) { CavalryLogger.start_js(["LqAgb"]); }

__d("ReactComposerFunFactTaggerComponent.react",["cx","FlexLayout.react","React","TextWithEmoticons.react","XUICloseButton.react","XUIText.react","cxMargin"],(function(a,b,c,d,e,f,g){"use strict";var h=b("React");a=function(a){babelHelpers.inheritsLoose(c,a);function c(){return a.apply(this,arguments)||this}var d=c.prototype;d.render=function(){return h.jsxs(b("FlexLayout.react"),{align:"center",className:"_mot _3-8j",direction:"vertical",children:[h.jsx(b("TextWithEmoticons.react"),{size:24,text:this.props.emoji}),h.jsx(b("XUIText.react"),{className:"_2er3 _3-8w",display:"block",size:"header3",children:this.props.title}),this.props.attribution&&h.jsx(b("XUIText.react"),{className:"_3-8w",color:"secondary",children:this.props.attribution}),this.props.showCloseButton&&h.jsx(b("XUICloseButton.react"),{className:"_2er4",onClick:this.props.onClose})]})};return c}(h.Component);e.exports=a}),null);
__d("ReactComposerEditDialog.react",["cx","fbt","Arbiter","Bootloader","DialogExpansion","DOMContainer.react","FBConfirmDialog.react","LayerFadeOnShow","React","ReactComponentWithPureRenderMixin","ReactComposerEvents","ReactComposerHandleUnsavedChanges","ReactComposerMediaUtils","SubscriptionsHandler","XUICloseButton.react","XUIDialog.react","XUIDialogBody.react","XUIDialogTitle.react","createReactClass_DEPRECATED","prop-types","throttle"],(function(a,b,c,d,e,f,g,h){"use strict";var i=b("React"),j=600,k=500,l=500;c=b("createReactClass_DEPRECATED")({displayName:"ReactComposerEditDialog",_subscriptions:b("SubscriptionsHandler"),mixins:[b("ReactComponentWithPureRenderMixin")],propTypes:{causalElementRef:(a=b("prop-types")).func.isRequired,composerDOM:a.any.isRequired,composerID:a.string.isRequired,postID:a.any,onDismiss:a.func.isRequired,isSproutsComposer:a.oneOf([null,!0,!1])},getInitialState:function(){return{shown:!0,showConfirmDialog:!1}},UNSAFE_componentWillMount:function(){this._subscriptions=new(b("SubscriptionsHandler"))(),this._subscriptions.addSubscriptions(b("Arbiter").subscribe(b("ReactComposerEvents").POST_SUCCEEDED+this.props.composerID,b("throttle")(this._dismiss,l)))},componentWillUnmount:function(){this._subscriptions.release()},componentDidMount:function(){},render:function(){var a=this.state.showConfirmDialog?this._renderDismissConfirmation():null;return i.jsxs("div",{children:[a,i.jsxs(b("XUIDialog.react"),{behaviors:{DialogExpansion:b("DialogExpansion"),LayerFadeOnShow:b("LayerFadeOnShow")},"data-testid":void 0,causalElementRef:this.props.causalElementRef,className:"_51ly"+(this.props.isSproutsComposer?"":" _3v1e"),shown:this.state.shown,width:this.props.isSproutsComposer?k:j,layerHideOnBlur:!1,children:[i.jsxs(b("XUIDialogTitle.react"),{showCloseButton:!1,children:[h._("Edit Post"),i.jsx(b("XUICloseButton.react"),{className:"_51-t",label:h._("Close"),onClick:this._showConfirmDialog})]}),i.jsx(b("XUIDialogBody.react"),{className:"_51lz",children:i.jsx(b("DOMContainer.react"),{children:this.props.composerDOM})})]})]})},_renderDismissConfirmation:function(){return i.jsx(b("FBConfirmDialog.react"),{content:b("ReactComposerHandleUnsavedChanges").getUnsavedChangesMessage(this.props.composerID),onCancel:this._cancelDismiss,onConfirm:this._dismiss,onToggle:this._cancelDismiss,shown:!0,title:h._("Discard Changes?"),cancelButtonText:h._("Keep Editing"),confirmButtonText:h._("Discard")})},_showConfirmDialog:function(){this.setState({showConfirmDialog:!0})},_cancelDismiss:function(){this.setState({showConfirmDialog:!1})},_dismiss:function(){var a=this;this.setState({shown:!1,showConfirmDialog:!1});b("Bootloader").loadModules(["TextDelightInComposerLogger"],function(b){b.endFunnel(a.props.composerID)},"ReactComposerEditDialog.react");var c=b("ReactComposerMediaUtils").tryGetVideoXUploader(this.props.composerID);c&&c.cancelUploads();this.props.onDismiss&&this.props.onDismiss()}});e.exports=c}),null);
__d("ReactComposerEditPostUtils",["invariant","ActorURI","ComposerPublisher","ReactComposerAsyncRequest","ReactComposerAttachmentStore","ReactComposerAttachmentType","ReactComposerMediaUploadStore","ReactComposerPostDataUtils","ReactComposerTaggerStore","ReactComposerTaggerType","ReactComposerVideoUploadStore","getMentionsTextForContentState","ifRequired"],(function(a,b,c,d,e,f,g){a={save:function(a){!a.composerID&&g(0,93);!a.composerConfig.contextInfo&&g(0,94);!a.targetID&&g(0,95);var c=a.composerID,d=this._isOnMediaEligibleAttachment(c),e=b("ReactComposerPostDataUtils").getPostData(a),f=b("ReactComposerVideoUploadStore").getVideo(c);if(d&&!!f){var h=b("ReactComposerVideoUploadStore").getUploader(c);h&&h.uploadFromFile(f.file,e);return}h=b("ReactComposerMediaUploadStore").getUploads(c);d&&h.size>0&&Object.assign(e,b("ReactComposerPostDataUtils").getMediaUploadsData(c,h));f=b("ReactComposerAttachmentStore").getIsAttachmentSelectedOrProxied(c,b("ReactComposerAttachmentType").GROUP_MEET_UP);f&&Object.assign(e,b("ReactComposerPostDataUtils").getGroupMeetupData(c));d=b("ReactComposerAttachmentStore").getIsAttachmentSelectedOrProxied(c,b("ReactComposerAttachmentType").SHIFT_SWAP);d&&b("ifRequired")("ReactComposerShiftSwapStore",function(a){Object.assign(e,{work_shift_swap_data:{job_position:a.getPosition(),description:a.getShiftDescription(),start_time:a.getShiftStartTime(),end_time:a.getShiftEndTime()!==null?a.getShiftEndTime():void 0}})});h=b("ReactComposerTaggerStore").getTaggerData(c,b("ReactComposerTaggerType").WORK_CHECKLIST);f=h.hasChecklist;f&&b("ifRequired")("ReactComposerWorkChecklistStore",function(a){var d=a.getTitle(c).getCurrentContent();d=d.hasText()?d.getPlainText():null;a=a.getListItems(c);var f=[];a.forEach(function(a){var c=a.editorState;a=a.id;var d=c.getCurrentContent().getPlainText();d.trim().length>0&&f.push({id:a,text:b("getMentionsTextForContentState")(c.getCurrentContent())})});Object.assign(e,{work_checklist_metadata:{title:d,items:f}})});b("ifRequired")("ReactComposerWorkContentAppAttachmentStore",function(a){Object.assign(e,{multi_share_attachments:Array.from(a.getScrapedAttachments(c).map(function(a){return{type:a.attachmentConfig.type,params:a.attachmentConfig.params}}))})});b("ifRequired")("ReactComposerWorkContentFileUploadStore",function(a){Object.assign(e,{attached_files_data:{files:Array.from(a.getCompletedUploads(c).map(function(a){return{id:a.fileID,handle:a.handleID}}))}})});if(b("ComposerPublisher").getShouldUseGraphQLForEdit(a.actorID,e)){b("ComposerPublisher").publishFromEditDialog(a,e);return}e.delight_ranges&&Object.assign(e,{delight_ranges:JSON.stringify(e.delight_ranges)});d="/composer/edit/"+a.composerConfig.contextInfo.postID;a.actorID&&(d=b("ActorURI").create(d,a.actorID));h=new(b("ReactComposerAsyncRequest"))(a.composerID,d).setData(e).setHandler(a.onPostSuccess).setErrorHandler(a.onPostFailure);h.send()},_isOnMediaEligibleAttachment:function(a){a=b("ReactComposerAttachmentStore").getSelectedAttachmentID(a);return a===b("ReactComposerAttachmentType").MEDIA||a==b("ReactComposerAttachmentType").FIND_PLAYERS}};e.exports=a}),null);
__d("ReactComposerEditStore",["ReactComposerActionStore","ReactComposerEditPostUtils","ReactComposerMediaConfig","ReactComposerPostUtils"],(function(a,b,c,d,e,f){a=function(a){"use strict";babelHelpers.inheritsLoose(c,a);function c(){return a.apply(this,arguments)||this}var d=c.prototype;d.__onPostStarted=function(a){b("ReactComposerEditPostUtils").save({actorID:a.actorID,composerConfig:a.config,composerID:a.composerID,targetID:a.targetID})};d.__canPost=function(a){return!b("ReactComposerPostUtils").isPostButtonDisabled(a.composerID,b("ReactComposerMediaConfig").photo.limit)};return c}(b("ReactComposerActionStore"));e.exports=new a()}),null);
__d("ReactComposerEditMediaSaveButtonContainer.react",["fbt","ReactComposerContextTypes","ReactComposerEditStore","ReactComposerMediaPostButtonContainerMixin","createReactClass_DEPRECATED","prop-types"],(function(a,b,c,d,e,f,g){a=b("createReactClass_DEPRECATED")({displayName:"ReactComposerEditMediaSaveButtonContainer",contextTypes:b("ReactComposerContextTypes"),mixins:[b("ReactComposerMediaPostButtonContainerMixin")],propTypes:{label:b("prop-types").string},getDefaultProps:function(){return{label:g._("Save")}},componentDidMount:function(){b("ReactComposerEditStore").registerComposerID(this.context.composerID)}});e.exports=a}),null);
__d("ReactComposerEditSaveButtonContainer.react",["fbt","React","ReactComposerContextTypes","ReactComposerEditStore","ReactComposerPostButtonContainerMixin","createReactClass_DEPRECATED","prop-types"],(function(a,b,c,d,e,f,g){b("React");a=b("createReactClass_DEPRECATED")({displayName:"ReactComposerEditSaveButtonContainer",contextTypes:b("ReactComposerContextTypes"),mixins:[b("ReactComposerPostButtonContainerMixin")],propTypes:{label:b("prop-types").string},getDefaultProps:function(){return{label:g._("Save")}},componentDidMount:function(){b("ReactComposerEditStore").registerComposerID(this.context.composerID)}});e.exports=a}),null);
__d("ReactEditComposer.react",["cx","Arbiter","JSResource","React","ReactComposer.react","ReactComposerAsset3dEagerAttachment.react","ReactComposerAttachmentActions","ReactComposerAttachmentType","ReactComposerBodyContainer.react","ReactComposerConfig","ReactComposerContextConfig","ReactComposerContextProviderMixin","ReactComposerEditMediaSaveButtonContainer.react","ReactComposerEditSaveButtonContainer.react","ReactComposerEvents","ReactComposerFunFactTaggerComponent.react","ReactComposerLoggingName","ReactComposerMarkdownTaggerButton.react","ReactComposerMarkdownTaggerContainer.react","ReactComposerMediaEagerAttachment.react","ReactComposerPrefillConfig","ReactComposerPrefillUtils","ReactComposerStatusEagerAttachment.react","ReactComposerTaggerType","ReactComposerWithSprouts.react","createReactClass_DEPRECATED","lazyLoadComponent","prop-types"],(function(a,b,c,d,e,f,g){var h=b("React"),i=b("lazyLoadComponent")(b("JSResource")("ReactComposerBreakingNewsButtonContainer.react").__setRef("ReactEditComposer.react")),j=b("lazyLoadComponent")(b("JSResource")("ReactComposerBreakingNewsContainer.react").__setRef("ReactEditComposer.react"));a=b("createReactClass_DEPRECATED")({displayName:"ReactEditComposer",mixins:[b("ReactComposerContextProviderMixin")],propTypes:{children:b("prop-types").arrayOf(b("prop-types").element),contextConfig:b("ReactComposerContextConfig").isRequired,config:b("ReactComposerConfig").isRequired,prefillConfig:b("ReactComposerPrefillConfig").isRequired,triggeredFrom:b("prop-types").oneOf(Object.values(b("ReactComposerLoggingName")))},UNSAFE_componentWillMount:function(){b("ReactComposerPrefillUtils").prefill(this.props.contextConfig.composerID,this.props.prefillConfig,this.props.contextConfig.gks)},componentDidMount:function(){var a=this.props.prefillConfig;a&&a.selectedAttachment&&(b("ReactComposerAttachmentActions").selectAttachment(this.props.contextConfig.composerID,a.selectedAttachment,a.shouldActivateSelectedAttachment),a.shouldActivateSelectedAttachment&&b("Arbiter").inform(b("ReactComposerEvents").ACTIVATE_ATTACHMENT+this.props.contextConfig.composerID))},render:function(){var a=this.props.prefillConfig.selectedAttachment;a=this._getAttachments(a);var c=this._getFunFactTagger();return this.props.contextConfig.gks&&this.props.contextConfig.gks.isSproutsComposer?h.jsx(b("ReactComposerWithSprouts.react"),{defaultAttachmentOnExpand:b("ReactComposerAttachmentType").STATUS,innerProps:{className:"_1nby",loggingConfig:this.props.config.loggingConfig,activateOnInit:!0,activateOnInitEntryPoint:this.props.config.triggeredFrom,sproutsConfig:this.props.config.sproutsConfig},ref:"root",children:h.jsxs(b("ReactComposerBodyContainer.react"),{expanded:this.props.config.showExpandedComposer,children:[c,a,this.props.children]})}):h.jsx(b("ReactComposer.react"),{className:"_1nby",loggingConfig:this.props.config.loggingConfig,activateOnInit:!0,activateOnInitEntryPoint:this.props.config.triggeredFrom,children:h.jsxs(b("ReactComposerBodyContainer.react"),{expanded:this.props.config.showExpandedComposer,children:[c,a,this.props.children]})})},_getFunFactTagger:function(){var a;a=(a=this.props.config)!=null?(a=a.taggersConfig)!=null?a[b("ReactComposerTaggerType").FUN_FACT]:a:a;return a&&a.emoji&&a.title?h.jsx(b("ReactComposerFunFactTaggerComponent.react"),{emoji:a.emoji,showCloseButton:!1,title:a.title}):null},_getAdditionalTaggersForMediaAttachment:function(){var a=[];this.props.config.taggersConfig&&this.props.config.taggersConfig[b("ReactComposerTaggerType").MARKDOWN]&&this.props.config.taggersConfig[b("ReactComposerTaggerType").MARKDOWN].enabled&&a.push({button:h.jsx(b("ReactComposerMarkdownTaggerButton.react"),{},"markdown_button"),container:h.jsx(b("ReactComposerMarkdownTaggerContainer.react"),{},"markdown_container")});return a},_getAdditionalTaggersForStatusAttachment:function(){var a=[];this.props.config.taggersConfig&&this.props.config.taggersConfig[b("ReactComposerTaggerType").MARKDOWN]&&this.props.config.taggersConfig[b("ReactComposerTaggerType").MARKDOWN].enabled&&a.push({button:h.jsx(b("ReactComposerMarkdownTaggerButton.react"),{},"markdown_button"),container:h.jsx(b("ReactComposerMarkdownTaggerContainer.react"),{},"markdown_container")});var c=this._getBreakingNewsTagger();c&&a.push(c);return a},_getBreakingNewsTagger:function(){var a;a=(a=this.props.config)!=null?(a=a.taggersConfig)!=null?a[b("ReactComposerTaggerType").BREAKING_NEWS]:a:a;return!a||!a.enabled?null:{button:h.jsx(h.Suspense,{fallback:h.jsx("div",{}),children:h.jsx(i,{breakingTaggerConfig:a},"breaking_news_button")}),container:h.jsx(h.Suspense,{fallback:h.jsx("div",{}),children:h.jsx(j,{pageID:this.props.config.targetData.targetID},"breaking_news_container")})}},_getAttachments:function(a){var c,d=[];d.push(h.jsx(b("ReactComposerStatusEagerAttachment.react"),{additionalTaggers:this._getAdditionalTaggersForStatusAttachment(),config:this.props.config,prefillConfig:this.props.prefillConfig,postButtonModule:b("ReactComposerEditSaveButtonContainer.react"),selected:a===(c=b("ReactComposerAttachmentType")).STATUS,scrapeLinkOnInit:!1},"status"));d.push(h.jsx(b("ReactComposerMediaEagerAttachment.react"),{additionalTaggers:this._getAdditionalTaggersForMediaAttachment(),config:this.props.config,prefillConfig:this.props.prefillConfig,postButtonModule:b("ReactComposerEditMediaSaveButtonContainer.react"),selected:a===c.MEDIA},"media"));d.push(h.jsx(b("ReactComposerAsset3dEagerAttachment.react"),{config:this.props.config,postButtonModule:b("ReactComposerEditSaveButtonContainer.react"),selected:a===c.ASSET_3D},"asset3d"));c=this.props.config.attachmentsConfig[c.FIND_PLAYERS];if(c){c=c.module;c!==null&&d.push(h.jsx(c,{config:this.props.config,prefillConfig:this.props.prefillConfig,postButtonModule:b("ReactComposerEditSaveButtonContainer.react"),selected:a===b("ReactComposerAttachmentType").FIND_PLAYERS},"find_players"))}c=this.props.prefillConfig&&this.props.prefillConfig.selectedAttachment===b("ReactComposerAttachmentType").GROUP_MEET_UP;if(c){c=this.props.prefillConfig&&this.props.prefillConfig.groupMeetUpAttachment;var e;c&&(e=c.module);e&&d.push(h.jsx(e,{config:this.props.config,prefillConfig:this.props.prefillConfig,selected:a===b("ReactComposerAttachmentType").GROUP_MEET_UP},"group_meetup"))}c=this.props.config.attachmentsConfig[b("ReactComposerAttachmentType").SHIFT_SWAP];if(c){c=c.module;c!==null&&d.push(h.jsx(c,{config:this.props.config,prefillConfig:this.props.prefillConfig,selected:a===b("ReactComposerAttachmentType").SHIFT_SWAP},"shift_swap"))}return d}});e.exports=a}),null);
__d("ReactEditComposerInit",["requireCond","DOM","React","ReactComposerEditDialog.react","cr:1508587","ReactComposerInit","ReactDOM","ReactEditComposer.react","Run","cr:1093979"],(function(a,b,c,d,e,f){"use strict";var g=b("React");function h(a){a=document.getElementById(a);return a?a.firstElementChild:null}a={_composerDOM:null,_mountContainer:null,init:function(a,c){var d,e;this._composerDOM=b("DOM").create("div");this._mountContainer=b("DOM").create("div");e=(e=a)!=null?(e=e.config)!=null?(e=e.contextInfo)!=null?e.postID:e:e:e;d=(d=b("cr:1093979"))!=null?d:g.Fragment;b("ReactDOM").render(g.jsx(d,{children:g.jsx(b("ReactComposerEditDialog.react"),{causalElementRef:function(){return h(c.causalContainerID)},composerDOM:this._composerDOM,composerID:a.contextConfig.composerID,postID:e,onDismiss:this._cleanup.bind(this),isSproutsComposer:(d=a)!=null?(d=d.contextConfig)!=null?(d=d.gks)!=null?d.isSproutsComposer:d:d:d})}),this._mountContainer);b("DOM").appendContent(document.body,this._mountContainer);b("ReactComposerInit").init(b("ReactEditComposer.react"),a,this._composerDOM);b("cr:1508587")&&b("cr:1508587").notifyFocusAcquired(a.contextConfig.composerID);b("Run").onUnload(this._cleanup.bind(this));b("Run").onLeave(this._cleanup.bind(this))},_cleanup:function(){var a=this;window.setTimeout(function(){a._composerDOM&&b("ReactDOM").unmountComponentAtNode(a._composerDOM),a._mountContainer&&b("ReactDOM").unmountComponentAtNode(a._mountContainer)},0)}};e.exports=a}),null);