//
//  PLVSocketChatRoomObject.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"

/// 聊天室事件
typedef NS_ENUM(NSUInteger, PLVSocketChatRoomEventType) {
    PLVSocketChatRoomEventType_LOGIN            = 0,    // 登录消息，登录房间的时候服务器会广播这一消息
    PLVSocketChatRoomEventType_LOGOUT           = 1,    // 退出消息，断开连接服务器广播的消息
    PLVSocketChatRoomEventType_GONGGAO          = 2,    // 公告消息，如有公告，登录房间的时候服务器会广播这一消息，公告即为管理员的发言信息
    PLVSocketChatRoomEventType_BULLETIN         = 3,    // 公告消息，POLYV 后台聊天室管理中，发布公告的内容
    PLVSocketChatRoomEventType_SPEAK            = 4,    // 发言，接收别人的发言消息和严禁词消息(不包括自己)
    
    PLVSocketChatRoomEventType_FLOWERS          = 5,    // 送花事件
    PLVSocketChatRoomEventType_LIKES            = 6,    // 点赞事件
    PLVSocketChatRoomEventType_REWARD           = 7,    // 打赏事件，目前需要通过HTTP接口进行支付后，由后台通知服务器
    PLVSocketChatRoomEventType_REDPAPER         = 8,    // 发红包，和打赏的情况类似，也是通过HTTP接口支付后由后台通知服务器
    
    PLVSocketChatRoomEventType_REMOVE_CONTENT   = 9,    // 删除某条聊天记录，目前需要通过HTTP接口调用
    PLVSocketChatRoomEventType_REMOVE_HISTORY   = 10,   // 清空聊天记录
    PLVSocketChatRoomEventType_CLOSEROOM        = 11,   // 关闭聊天室
    PLVSocketChatRoomEventType_CLOSE_DANMU      = 12,   // 关闭弹幕
    
    PLVSocketChatRoomEventType_BANIP            = 13,   // 禁言事件
    PLVSocketChatRoomEventType_UNSHIELD         = 14,   // 解禁言事件
    PLVSocketChatRoomEventType_KICK             = 15,   // 踢人事件
    
    PLVSocketChatRoomEventType_DEBUG            = 17,   // 调试模式，调试模式的开关在助教页面
    PLVSocketChatRoomEventType_CHATROOM_CONTROL = 16,   // 聊天室管理操作事件（关闭欢迎语、关闭点赞语）
    
    PLVSocketChatRoomEventType_S_QUESTION       = 18,  // 学生在观看端发起提问
    PLVSocketChatRoomEventType_T_ANSWER         = 19,  // 老师回答学生的提问
    PLVSocketChatRoomEventType_QUESTION         = 20,  // 老师提问，在客户端聊天室发起，可以了解下 http://dev.polyv.net/2016/08/clientchat/ 2.3问答功能
    PLVSocketChatRoomEventType_CLOSE_QUESTION   = 21,  // 关闭问答，老师发起问答后关闭问答
    PLVSocketChatRoomEventType_ANSWER           = 22,  // 学员在观看端回答老师提出的问题
    
    PLVSocketChatRoomEventType_CUSTOMER_MESSAGE = 23,  // 自定义消息接收事件，目前只能通过后台管理员调用HTTP接口发送消息，可参考http://dev.polyv.net/2016/12/send-chat/
    
    PLVSocketChatRoomEventType_ELSE             = 24,
};

/**
 聊天室消息对象
 */
@interface PLVSocketChatRoomObject : PLVSocketObject

/// 消息/事件类型
@property (nonatomic, assign, readonly) PLVSocketChatRoomEventType eventType;

/// 当前用户Id（生成登录对象时生成）
@property (nonatomic, strong, readonly) NSString *userId;

/**
 生成一个登录对象

 @param roomId 房间号/频道号
 @param nickName 用户昵称，为空或教师角色时使用默认昵称
 @param avatar 用户头像，为空时使用默认头像
 @param userType 用户类型：普通直播观看端使用 TypeStudent；云课堂直播观看端使用 TypeSlice；推流登录使用 TypeTeacher
 @return PLVSocketChatRoomObject 的登录事件对象
 */
+ (instancetype)chatRoomObjectForLoginEventTypeWithRoomId:(NSUInteger)roomId nickName:(NSString *)nickName avatar:(NSString *)avatar userType:(PLVSocketObjectUserType)userType;

/**
 生成一个发言对象

 @param roomId 发言内容
 @param content 当前房间号
 @return PLVSocketChatRoomObject 的发言事件对象
 */
+ (instancetype)chatRoomObjectForSpeakEventTypeWithRoomId:(NSUInteger)roomId content:(NSString *)content;

/**
 生成一个送花对象

 @param roomId 当前房间号
 @param nickName 送花人昵称，为空时使用默认昵称
 @param userImg 送花人头像地址，为空时使用默认头像
 @return PLVSocketChatRoomObject 的送花事件对象
 */
+ (instancetype)chatRoomObjectForFlowersEventTypeWithRoomId:(NSUInteger)roomId nickName:(NSString *)nickName userImg:(NSString *)userImg;

/**
 生成一个点赞对象

 @param roomId 当前房间号
 @param nickName 点赞人昵称，为空时使用默认昵称
 @return PLVSocketChatRoomObject 的点赞事件对象
 */
+ (instancetype)chatRoomObjectForLikesEventTypeWithRoomId:(NSUInteger)roomId nickName:(NSString *)nickName;

@end

