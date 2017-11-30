//
//  PLVSocketLinkMicObject.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"

/// 连麦事件
typedef NS_ENUM(NSUInteger, PLVSocketLinkMicEventType) {
    /// 老师开启关闭连麦
    PLVSocketLinkMicEventType_OPEN_MICROPHONE = 0,
    
    /// 举手事件
    PLVSocketLinkMicEventType_JOIN_REQUEST,
    /// 老师同意通话事件
    PLVSocketLinkMicEventType_JOIN_RESPONSE,
    /// 加入声网成功事件
    PLVSocketLinkMicEventType_JOIN_SUCCESS,
    /// 结束发言事件
    PLVSocketLinkMicEventType_JOIN_LEAVE,
};

/**
 连麦消息对象
 */
@interface PLVSocketLinkMicObject : PLVSocketObject

/// 消息/事件类型
@property (nonatomic, assign) PLVSocketLinkMicEventType eventType;


/**
 生成一个连麦事件对象

 @param eventType 事件类型：只支持 PLVSocketLinkMicEventType_JOIN_REQUEST(举手) 和 PLVSocketLinkMicEventType_JOIN_LEAVE(结束发言) 两个类型
 @param roomId 房间号/频道号
 @param userNick 举手学员昵称
 @param userPic 举手学员头像
 @param userId 举手学员id(32位无符号整数,详见声网API)
 @param userType 用户类型：普通直播观看端使用 TypeStudent；云课堂直播观看端使用 TypeSlice；暂不支持 TypeTeacher 类型
 @return PLVSocketLinkMicObject 实例对象
 */
+ (instancetype)linkMicObjectWithEventType:(PLVSocketLinkMicEventType)eventType roomId:(NSUInteger)roomId userNick:(NSString *)userNick userPic:(NSString *)userPic userId:(NSUInteger)userId userType:(PLVSocketObjectUserType)userType;

@end
