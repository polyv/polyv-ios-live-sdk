//
//  PLVLiveAPI.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PLVLiveChannel;
@class PLVPushChannel;

/// SDK 通用错误码
typedef NS_ENUM(NSInteger, PLVLiveErrorCode) {
    PLVLiveErrorCodeParamInvalid                = -10000,       // 参数无效/非法
    
    PLVLiveErrorCodeNetworkError                = -10010,       // 网络请求失败
    PLVLiveErrorCodeResponseCodeNot200          = -10011,       // 服务器响应非 200
    PLVLiveErrorCodeResponseCode403             = -10012,       // 服务器响应 403
    
    PLVLiveErrorCodeJsonDecodeFailure           = -10020,       // JSON 解析失败
    PLVLiveErrorCodeEncodeJsonDecodeFailure     = -10021,       // 加密 JSON 解析失败
    PLVLiveErrorCodeDecodeFailre                = -10022,       // 解密失败
    
    /* 多数为服务器对参数验证不通过*/
    PLVLiveErrorCodeLoginFailre                 = -10030,       // 登录失败(登录接口)
    PLVLiveErrorCodeRequestFailre               = -10031,       // 请求失败
    PLVLiveErrorCodeSettingFailre               = -10032,       // 设置失败
    
    PLVLiveErrorCodeUnknown                     = -9999,        // 未知类型
};

/// 返回 SDK 通用错误码对应的字符串符号
NSString *NameStringWithLiveErrorCode(PLVLiveErrorCode errorCode);

/// 直播状态
typedef NS_ENUM(NSInteger, PLVLiveStreamState) {
    PLVLiveStreamStateUnknown               = -1,           // 直播流状态未知
    PLVLiveStreamStateNoStream              = 0,            // 无直播流
    PLVLiveStreamStateLive                  = 1             // 直播中
};

/**
 直播相关接口，以下所有接口回调都在主线程中
 */
@interface PLVLiveAPI : NSObject

#pragma mark -  直播观看相关接口

/**
 获取直播频道信息

 @param userId 用户名
 @param channelId 频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)loadChannelInfoWithUserId:(NSString *)userId
                        channelId:(NSUInteger)channelId
                       completion:(void (^)(PLVLiveChannel *channel))completion
                          failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 同上接口；backup，缓存时间较短
 */
+ (void)loadChannelInfo_BUWithUserId:(NSString *)userId
                           channelId:(NSUInteger)channelId
                          completion:(void (^)(PLVLiveChannel *channel))completion
                             failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 根据流名获取当前流状态

 @param stream 流名
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)isLiveWithStream:(NSString *)stream
              completion:(void(^)(PLVLiveStreamState streamState))completion
                 failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 根据频道号获取当前流状态（是否直播中及直播模式）

 @param channelId 频道号
 @param stream 流名
 @param completion 请求完成，参数不能为 nil
        mode 推流模式：ppt(云课堂推流)/alone(直播助手推流)
 @param failure 请求失败
 */
+ (void)getStreamStatusWithChannelId:(NSUInteger)channelId
                              stream:(NSString *)stream
                          completion:(void(^)(PLVLiveStreamState streamState, NSString *mode))completion
                             failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark -  直播推流相关接口

/**
 获取推流信息

 @param channelId 频道号
 @param password 密码
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)loadStreamerInfoWithChannelId:(NSUInteger)channelId
                             password:(NSString *)password
                           completion:(void(^)(PLVPushChannel *channel))completion
                              failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 设置推流为单流模式

 @param channelId 频道号
 @param stream 当前频道号的流名
 @param completion 设置成功，参数不能为 nil
 @param failure 设置失败
 */
+ (void)configAloneStreamModeWithChannelId:(NSUInteger)channelId
                                    stream:(NSString *)stream
                                completion:(void (^)(NSString *sessionId))completion
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

#pragma mark -  聊天室/连麦/PPT 相关接口

/**
 Socket、连麦授权接口

 @param channelId 频道号
 @param appId appId（ POLYV 直播后台“API设置“中的参数）
 @param appSecret appSecret（同上）
 @param completion 请求完成，参数不能为 nil
 @param failure 设置失败
 */
+ (void)requestAuthorizationForLinkingSocketWithChannelId:(NSUInteger)channelId
                                                    Appld:(NSString *)appId
                                                appSecret:(NSString *)appSecret
                                               completion:(void (^)(NSDictionary *responseDict))completion
                                                  failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取聊天室历史记录

 @param roomId 房间号/频道号
 // startIndex 为 0 endIndex 为 -1 时，返回全部历史记录
 @param startIndex 开始下标
 @param endIndex 结束下标
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestChatRoomHistoryWithRoomId:(NSUInteger)roomId
                              startIndex:(NSUInteger)startIndex
                                endIndex:(NSInteger)endIndex
                              completion:(void (^)(NSArray *historyList))completion
                                 failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取聊天室所有在线成员列表

 @param roomId 房间号/频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestChatRoomListUsersWithRoomId:(NSUInteger)roomId
                                completion:(void (^)(NSDictionary *listUsers))completion
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取连麦状态

 @param roomId 房间号/频道号
 @param completion 请求完成，参数不能为 nil
        status 连麦状态：open(打开)/close(关闭)
        type 连麦类型：video(视频)/audio(音频)
 @param failure 请求失败
 */
+ (void)requestLinkMicStatusWithRoomId:(NSUInteger)roomId
                            completion:(void (^)(NSString *status, NSString *type))completion
                               failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

/**
 获取连麦在线人员列表
 
 @param roomId 房间号/频道号
 @param completion 请求完成，参数不能为 nil
 @param failure 请求失败
 */
+ (void)requestLinkMicOnlineListWithRoomId:(NSUInteger)roomId
                                completion:(void (^)(NSArray *onlineList))completion
                                   failure:(void (^)(PLVLiveErrorCode errorCode, NSString *description))failure;

@end
