//
//  MSDKProtocol.h
//  MSDK
//
//  Created by Hillson Song on 6/18/18.
//  Copyright © company. All rights reserved.
//
#ifndef MSDK_PROTOCOL_H
#define MSDK_PROTOCOL_H

#define MSDK_AUTH_PRECODE_ACTION		"auth/pcprecode"
#define MSDK_AUTH_LOGIN_ACTION          "auth/login"
#define MSDK_AUTH_AUTOLOGIN_ACTION      "auth/auto_login"
#define MSDK_AUTH_VERIFY_LOGIN_ACTION   "auth/verify_login"
#define MSDK_AUTH_LOGOUT_ACTION         "auth/logout"
#define MSDK_AUTH_SCAN_LOGIN_ACTION     "auth/scan_login"
#define MSDK_AUTH_GETBINDINFO_ACTION    "auth/get_bind_relation"
#define MSDK_AUTH_DECRYPT_ACTION        "auth/decrypt"
#define MSDK_AUTH_RESTORE_ACTION        "auth/restore"
#define MSDK_AUTH_CHECK_LOGIN           "auth/check_and_login"
#define MSDK_AUTH_CHECK                 "auth/check_login"
#define MSDK_AUTH_BIND_CONFIRM_CODE     "auth/bind_with_confirm_code"
#define MSDK_AUTH_LOGIN_CONFIRM_CODE    "auth/login_with_confirm_code"
#define MSDK_AUTH_WX_TICKET             "profile/jsticket_info"



#define MSDK_PRAJNA_REPORT_ACTION       "prajna/report"

#define MSDK_PROFILE_CANBIND_ACTION     "profile/can_bind"
#define MSDK_PROFILE_USERINFO_ACTION     "profile/userinfo"
#define MSDK_PROFILE_OPENID2UID          "profile/openid2uid"
#define MSDK_PROFILE_DEEPLINK_ACTION     "profile/createdeeplink"
#define MSDK_PROFILE_SHORTURL_ACTION     "url_shortener/shorten_url"
#define MSDK_PROFILE_RESETGUEST_ACTION   "profile/reset_guest"

#define MSDK_FRIEND_SHARE_ACTION             "friend/share"
#define MSDK_FRIEND_FRIENDLIST_ACTION        "friend/friend_list"

#define MSDK_TOOLS_FREEFLOW_ISFREE      "freeflow/isfree"

#define MSDK_GROUP_CREATE_ACTION    "group/create_bind_group"
#define MSDK_GROUP_RELATION_INFO          "group/get_group_rela_info"
#define MSDK_GROUP_JOIN_ACTION          "group/join_group"
#define MSDK_GROUP_UNBIND_ACTION        "group/unbind_group"
#define MSDK_GROUP_LIST_ACTION          "group/get_group_list"
#define MSDK_GROUP_BIND_ACTION  "group/bind_existing_group"
#define MSDK_GROUP_REMIND_LEADERBIND_ACTION   "group/remind_leader_bind"
#define MSDK_GROUP_INFO_ACTION          "group/get_group_info"
#define MSDK_GROUP_SEND_MSG_ACTION       "group/send_group_msg"

#define MSDK_NOTICE_GET_NOTICE_ACTION         "notice/get_notice"

#define MSDK_CONF_GETCONF_ACTION             "conf/get_conf"


#define MSDK_LBS_SET_LOCATION               "lbs/set_location"
#define MSDK_LBS_CLEAR_LOCATION               "lbs/clear_location"
#define MSDK_LBS_GET_NEARBY               "lbs/nearby"
#define MSDK_LBS_GET_IPINFO               "lbs/ip2country_ext"


// 文档未定义的
#define MSDK_AUTH_BIND_ACTION           "auth/bind"
#define MSDK_PROFILE_FIRSTREG_ACTION    "profile/get_first_reg"
#define MSDK_PROFILE_VIDEOVIP_ACTION    "profile/get_video_vip"
#define MSDK_PROFILE_XINYUESUPER_ACTION "profile/get_xinyue_super"
#define MSDK_GROUP_VIPRICHINFO_ACTION        "group/get_vip_rich_info"
#define MSDK_GROUP_GROUPMEMBERINFO_ACTION    "group/get_group_member_info"

// 自建账号
#define MSDK_ACCOUNT_REGISTER_ACTION            "account/register"
#define MSDK_ACCOUNT_VERIFY_CODE_ACTION         "account/sendcode"
#define MSDK_ACCOUNT_LOGIN_ACTION               "account/login"
#define MSDK_ACCOUNT_RESET_PASSWORD_ACTION      "account/changepassword"
#define MSDK_ACCOUNT_CHECK_TOKEN_ACTION         "account/check"
#define MSDK_ACCOUNT_LOGOUT_ACTION              "account/logout"
#define MSDK_ACCOUNT_MODIFY_ACTION              "account/modify"
#define MSDK_ACCOUNT_LOGIN_WITH_CODE_ACTION     "account/loginwithcode"
#define MSDK_ACCOUNT_REGISTER_STATUS_ACTION     "account/registerstatus"
#define MSDK_ACCOUNT_VERIFY_CODE_STATUS_ACTION  "account/codestatus"
#define MSDK_ACCOUNT_GET_RECEIVE_EMAIL_ACTION   "account/getreceiveemail"
#define MSDK_ACCOUNT_VERIFY_PASSWORD_ACTION     "account/verify_password"

#endif /* MSDK_PROTOCOL_H */
