//
//  PLVSocketIO.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVSocketObject.h"
#import "PLVSocketChatRoomObject.h"
#import "PLVSocketLinkMicObject.h"

/// socketIO 连接状态
typedef NS_ENUM(NSInteger, PLVSocketIOState) {
    PLVSocketIOStatusNotConnected = 0,          // SocketIO 未连接
    PLVSocketIOStateDisconnected = 1,           // SocketIO 失去连接
    PLVSocketIOStateConnecting = 2,             // SocketIO 连接中
    PLVSocketIOStateConnected = 3,              // SocketIO 连接成功
    PLVSocketIOStateConnectError = 4,           // SocketIO 连接出错
};

@protocol PLVSocketIODelegate;

/**
 SocketIO 对象
 */
@interface PLVSocketIO : NSObject

@property (nonatomic, weak) id <PLVSocketIODelegate> delegate;
@property (nonatomic, strong, readonly) NSString *socketId;
@property (nonatomic, assign, readonly) NSUInteger channelId;
@property (nonatomic, strong, readonly) NSString *userId;

@property (nonatomic, assign, readonly) PLVSocketIOState socketIOState;

/**
 初始化 SocketIO，使用 -connect 连接

 @param connetToken 连接 token，Socket、连麦授权接口中获取
 @param enableLog 是否输出调试信息
 @return SocketIO 实例对象
 */
- (instancetype)initSocketIOWithConnectToken:(NSString *)connetToken enableLog:(BOOL)enableLog;
 
/**
 登录聊天室接口方法，等同 -emitMessageWithSocketObject: 方法提交一个 PLVSocketChatRoomObject 中的登录对象
    -socketIO:didConnectWithInfo: 后调用

 @param roomId 房间号/频道号
 @param nickName 用户昵称，为空或教师角色时使用默认昵称
 @param avatar 用户头像，nil 或空时为默认头像
 @param userType 用户类型：普通直播观看端使用 TypeStudent；云课堂直播观看端使用 TypeSlice；推流登录使用 TypeTeacher
 */
- (void)loginChatRoomWithRoomId:(NSUInteger)roomId nickName:(NSString *)nickName avatar:(NSString *)avatar userType:(PLVSocketObjectUserType)userType;

/**
 连接 SocketIO 服务器
 */
- (void)connect;

/**
 重新连接 SocketIO 服务器
 */
- (void)reconnect;

/**
 关闭 SocketIO 连接
 */
- (void)disconnect;

/**
 移除监听所有 SocketIO 事件
 */
- (void)removeAllHandlers;

/**
 发送消息

 @param socketObject Socket 对象
 */
- (void)emitMessageWithSocketObject:(PLVSocketObject *)socketObject;

/**
 发送消息(自定义)

 @param event 发送事件名
 @param dictContent 字典数据内容
 */
- (void)emitEvent:(NSString *)event withContent:(NSDictionary *)dictContent;

@end

@protocol PLVSocketIODelegate <NSObject>

@required
/// SocketIO 连接服务器成功
- (void)socketIO:(PLVSocketIO *)socketIO didConnectWithInfo:(NSString *)info;

@optional
/// SocketIO 收到聊天室消息
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveChatMessage:(PLVSocketChatRoomObject *)chatObject;

/// SocketIO 收到连麦消息
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveLinkMicMessage:(PLVSocketLinkMicObject *)linkMicObject;
/// TODO: SocketIO 收到PPT消息

/// SocketIO 和服务器失去连接
- (void)socketIO:(PLVSocketIO *)socketIO didDisconnectWithInfo:(NSString *)info;

/// SocketIO 连接服务器出错
- (void)socketIO:(PLVSocketIO *)socketIO connectOnErrorWithInfo:(NSString *)info;

/// SocketIO 重新连接服务器
- (void)socketIO:(PLVSocketIO *)socketIO reconnectWithInfo:(NSString *)info;

/// 本地出错信息回调
- (void)socketIO:(PLVSocketIO *)socketIO localError:(NSString *)description;

@end
