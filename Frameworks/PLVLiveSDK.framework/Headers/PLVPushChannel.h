//
//  PLVPushChannel.h
//  PLVLiveSDK
//
//  Created by ftao on 31/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 推流频道信息
 */
@interface PLVPushChannel : NSObject

@property (nonatomic, copy, readonly) NSNumber *channelId;          // 频道号
@property (nonatomic, copy, readonly) NSString *rtmpUrl;            // 推流地址
@property (nonatomic, copy, readonly) NSString *stream;             // 流名

@property (nonatomic, copy, readonly) NSString *userId;             // 用户Id
@property (nonatomic, copy, readonly) NSString *nickName;           // 用户昵称
@property (nonatomic, copy, readonly) NSString *role;               // 用户角色
@property (nonatomic, copy, readonly) NSString *avatar;             // 用户头像地址

@property (nonatomic, readonly) BOOL isNgbEnabled;                  // NGB 是否开启
@property (nonatomic, readonly) BOOL isUrlProtected;                // 防盗链是否开
@property (nonatomic, copy, readonly) NSString *url;                // rtmp URL
@property (nonatomic, copy, readonly) NSString *ngbUrl;             // NGB URL
@property (nonatomic, copy, readonly) NSString *bakUrl;             // bakUrl URL

@property (nonatomic, copy, readonly) NSDictionary *channelDict;    // 推流频道信息

/**
 便利初始化方法
 */
+ (instancetype)pushChannelWithJsonDict:(NSDictionary *)jsonDict;

/**
 设置 rtmpUrl 方法
 */
- (void)setRtmpUrl:(NSString *)rtmpUrl;

@end
