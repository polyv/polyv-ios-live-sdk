//
//  PLVSocketIOEventDef.h
//  PLVLiveSDK
//
//  Created by ftao on 10/11/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 1. 注明 NSDictionary、NSNumber 的表示该字段(参数)的值为 字典或 number 类型；未注明的为默认 String 类型
 2. 注明 optional 的为可选项，即可能不存在此字段；未注明的一般都为存在
 3. 如果注释或字段和实际数据存在出入，欢迎大家通过Github或易方的技术支持进行反馈。公司官网：http://www.polyv.net/
 */

#define PLV_EXPORT extern

#pragma mark - 聊天室事件键集合

/*!
 @constant    PLVSocketIOChatRoomUserKey
 @abstract    聊天室用户信息
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoomUserKey; /* NSDictionary */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserClientIpKey; /* 用户IP */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserNickKey; /* 用户昵称 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserPicKey; /* 用户头像，地址需要转换，返回的地址一般未带协议 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserRoomIdKey; /* 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserUidKey; /* socket 分配的id */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserUserIdKey; /* 用户唯一标识 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserUserTypeKey; /* 用户类型，目前有teacher(老师)、assistant(助教)、manager(管理员)、slice(云课堂学员) */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserActorKey; /* optional, 头衔 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoomUserCanAnswerKey; /* optional, 是否有回答提问的权限 */

#pragma mark 聊天室基本消息

/*!
 @constant    PLVSocketIOChatRoom_LOGIN_EVENT
 @abstract    登录消息，登录房间的时候服务器会广播这一消息
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_LOGIN_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_LOGIN_onlineUserNumber; /* NSNumber, 当前房间总在线人数 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_LOGIN_userKey; /* NSDictionary，等同 PLVSocketIOChatRoomUserKey */

/*!
 @constant    PLVSocketIOChatRoom_LOGOUT_EVENT
 @abstract    退出消息，断开连接服务器广播的消息
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_LOGOUT_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_LOGOUT_onlineUserNumber; /* NSNumber, 当前在线总人数 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_LOGOUT_uid; /* 离开人的uid */

/*!
 @constant    PLVSocketIOChatRoom_GONGGAO_EVENT
 @abstract    公告消息，如有公告，登录房间的时候服务器会广播这一消息，公告即为管理员的发言信息
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_GONGGAO_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_GONGGAO_content; /* 公告内容 */

/*!
 @constant    PLVSocketIOChatRoom_BULLETIN_EVENT
 @abstract    公告消息，POLYV 后台聊天室管理中，发布公告的内容
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_BULLETIN_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_BULLETIN_content; /* 公告内容 */

/*!
 @constant    PLVSocketIOChatRoom_SPEAK_EVENT
 @abstract    发言,接收别人的发言消息(不包括自己)
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_SPEAK_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_SPEAK_id; /* 消息唯一标志 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_SPEAK_time; /* NSNumber,时间戳 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_SPEAK_userKey; /* NSDictionary，等同 PLVSocketIOChatRoomUserKey，发言人 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_SPEAK_values; /* NSArray, 消息内容 */

#pragma mark 聊天室赞赏消息

/*!
 @constant    PLVSocketIOChatRoom_FLOWERS_EVENT
 @abstract    送花事件
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_FLOWERS_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_FLOWERS_nick; /* 送花人昵称 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_FLOWERS_uimg; /* 送花人头像 */

/*!
 @constant    PLVSocketIOChatRoom_LIKES_EVENT
 @abstract    点赞事件
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_LIKES_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_LIKES_count; /* NSNumber, 当前点赞总数，若发生消息的时候没传此属性，则不返回这个属性 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_LIKES_nick; /* 点赞人昵称 */

/*!
 @constant    PLVSocketIOChatRoom_REWARD_EVENT
 @abstract    打赏事件，目前需要通过HTTP接口进行支付后，由后台通知服务器
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_REWARD_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REWARD_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REWARD_contentKey; /* NSDictionary, 打赏的内容 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REWARD_content_gimg; /* 礼物的图片，若为空，则代表现金打赏 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REWARD_content_rewardContent; /* 礼物的名称,若gimg为空,此字段为打赏的金额 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REWARD_content_uimg; /* 打赏人的头像 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REWARD_content_unick; /* 打赏人的昵称 */

/*!
 @constant    PLVSocketIOChatRoom_REDPAPER_EVENT
 @abstract    发红包，和打赏的情况类似，也是通过HTTP接口支付后由后台通知服务器
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_msgSource; /* 消息类型 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_totalAmount; /* 红包总金额 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_number; /* 红包个数 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_content; /* 祝福语 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_redpackId; /* 红包ID */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_redCacheId; /* 红包缓存ID */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_userKey; /* NSDictionary, 发红包用户 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_user_roomId; /* 房间号 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_user_openId; /* 微信用户openId */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_user_nick; /* 用户昵称 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_user_pic; /* 用户头像 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_REDPAPER_user_userId; /* optional, 用户Id */

#pragma mark 聊天室管理及控制

/*!
 @constant    PLVSocketIOChatRoom_REMOVE_CONTENT_EVENT
 @abstract    删除某条聊天记录，目前需要通过HTTP接口调用
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_id; /* 删除内容对应的id */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_REMOVE_CONTENT_content; /* optional, 删除的内容 */

/*!
 @constant    PLVSocketIOChatRoom_REMOVE_HISTORY_EVENT
 @abstract    清空聊天记录
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_REMOVE_HISTORY_EVENT;

/*!
 @constant    PLVSocketIOChatRoom_CLOSEROOM_EVENT
 @abstract    关闭聊天室
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSEROOM_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSEROOM_valueKey; /* NSDictionary */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSEROOM_value_roomId; /* NSNumber, 房间号 */
        PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSEROOM_value_closed; /* NSNumber(BOOL)，true为关闭；false为开启 */

/*!
 @constant    PLVSocketIOChatRoom_CLOSE_DANMU_EVENT
 @abstract    关闭弹幕
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSE_DANMU_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSE_DANMU_isClose; /* NSNumber(BOOL)，true为关；false为开启 */


/*!
 @constant    PLVSocketIOChatRoom_BANIP_EVENT
 @abstract    禁言事件
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_BANIP_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_BANIP_userIds; /* NSArray<NSDictionary，内容可使用PLVSocketIOChatRoomUserKey内Key值>, 被禁用户 */

/*!
 @constant    PLVSocketIOChatRoom_UNSHIELD_EVENT
 @abstract    解禁言事件
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_UNSHIELD_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_UNSHIELD_userIds; /* NSArray<NSDictionary，内容可使用PLVSocketIOChatRoomUserKey内Key值>, 解禁用户 */

/*!
 @constant    PLVSocketIOChatRoom_KICK_EVENT
 @abstract    踢人事件
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_KICK_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_KICK_userKey; /* NSDictionary，等同 PLVSocketIOChatRoomUserKey，被踢用户对象 */


/*!
 @constant    PLVSocketIOChatRoom_DEBUG_EVENT
 @abstract    调试模式，调试模式的开关在助教页面
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_DEBUG_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_DEBUG_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_DEBUG_isdebug; /* NSNumber(BOOL)，true为开启调试模式；false为关闭 */

/*!
 @constant    PLVSocketIOChatRoom_CHATROOM_CONTROL_EVENT
 @abstract    聊天室管理操作事件（关闭欢迎语、关闭点赞语）
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_type; /* 控制类型：closeWelcome(关闭欢迎语)、closeLikes(关闭点赞语)等 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CHATROOM_CONTROL_value; /* NSNumber(BOOL)，YES 为开启；NO 为关闭 */

#pragma mark 聊天室问答消息

/*!
 @constant    PLVSocketIOChatRoom_S_QUESTION_EVENT
 @abstract    学生在观看端发起提问
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_S_QUESTION_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_S_QUESTION_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_S_QUESTION_content; /* 提问内容 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_S_QUESTION_userKey; /* NSDictionary，提问学生相关信息，可以参看 PLVSocketIOChatRoomUserKey 字典属性内容*/

/*!
 @constant    PLVSocketIOChatRoom_T_ANSWER_EVENT
 @abstract    老师回答学生的提问
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_T_ANSWER_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_T_ANSWER_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_T_ANSWER_content; /* 回答内容 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_T_ANSWER_sUserId; /* 提问学生userId */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_T_ANSWER_userKey; /* NSDictionary，讲师信息，可以参看 PLVSocketIOChatRoomUserKey 字典属性内容 */

/*!
 @constant    PLVSocketIOChatRoom_QUESTION_EVENT
 @abstract    老师提问，在客户端聊天室发起，可以了解下http://dev.polyv.net/2016/08/clientchat/ 2.3问答功能
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_QUESTION_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_QUESTION_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_QUESTION_question; /* 问题选项(单选题/判断题) */

/*!
 @constant    PLVSocketIOChatRoom_CLOSE_QUESTION_EVENT
 @abstract    关闭问答，老师发起问答后关闭问答
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSE_QUESTION_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CLOSE_QUESTION_roomId; /* NSNumber, 房间号 */

/*!
 @constant    PLVSocketIOChatRoom_ANSWER_EVENT
 @abstract    学员在观看端回答老师提出的问题
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_ANSWER_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_ANSWER_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_ANSWER_answer; /* 学员选择的答案 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_ANSWER_nick; /* 回答问题学员昵称 */

#pragma mark 聊天室自定义消息

/*!
 @constant    PLVSocketIOChatRoom_CUSTOMER_MESSAGE_EVENT
 @abstract    自定义消息接收事件，目前只能通过后台管理员调用HTTP接口发送消息，可参考http://dev.polyv.net/2016/12/send-chat/
 */
PLV_EXPORT NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_image; /* 消息图片(根据发送的消息是否有图片决定) */
    PLV_EXPORT NSString *const PLVSocketIOChatRoom_CUSTOMER_MESSAGE_content; /* 消息内容 */

#pragma mark - 连麦事件键集合

/*
 @constant    PLVSocketIOLinkMicUserkey
 @abstract    举手学员信息
 */
PLV_EXPORT NSString *const PLVSocketIOLinkMicUserkey;
    PLV_EXPORT NSString *const PLVSocketIOLinkMicUserNickkey; /* 用户昵称 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMicUserPickey; /* 用户头像 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMicUserUserIdkey; /* 用户userId */
    PLV_EXPORT NSString *const PLVSocketIOLinkMicUserUserTypekey; /* 用户类型，默认为空，老师为teacher，ppt学员为slice */
    PLV_EXPORT NSString *const PLVSocketIOLinkMicUserRoomIdkey; /* NSNumber, optional, 用户所在房间/频道号 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMicUserStatuskey; /* optional, 用户当前连麦状态 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMicUserUidkey; /* optional, 用户链接聊天室服务器uid，由服务器生成 */

/*!
 @constant    PLVSocketIOLinkMic_OPEN_MICROPHONE_EVENT
 @abstract    老师开启关闭连麦事件消息
 */
PLV_EXPORT NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_EVENT;
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_type; /* 连麦类型：audio(语音通话)；video(视频通话) */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_status; /* 状态：open(打开)、close(关闭) */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_teacherId; /* optional, 教师id */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_OPEN_MICROPHONE_userId; /* optional, 用户id，存在此字段时非关闭所有连麦 */

/*!
 @constant    PLVSocketIOLinkMic_JOIN_REQUEST_key
 @abstract    举手事件
 */
PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_REQUEST_key;
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_REQUEST_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_REQUEST_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */

/*!
 @constant    PLVSocketIOLinkMic_JOIN_RESPONSE_key
 @abstract    老师同意通话事件
 */
PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_key;
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_RESPONSE_value;

/*!
 @constant    PLVSocketIOLinkMic_JOIN_SUCCESS_key
 @abstract    加入声网成功事件消息
 */
PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_key;
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_SUCCESS_value;

/*!
 @constant    PLVSocketIOLinkMic_JOIN_LEAVE_key
 @abstract    结束发言事件消息
 */
PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_LEAVE_key;
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_LEAVE_roomId; /* NSNumber, 房间号 */
    PLV_EXPORT NSString *const PLVSocketIOLinkMic_JOIN_LEAVE_userKey; /* NSDictionary, 等同 PLVSocketIOLinkMicUserkey，学员信息 */
