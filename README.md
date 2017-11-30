# polyv-ios-live-sdk


## 概述

本仓库包含 Polyv 直播 SDK、pod 项目 demo 及 cocoaPods 项目配置说明等文件。


## 快速开始

### 文件结构

- 项目结构

```
├── Frameworks
	├── PLVLiveSDK.framework 	# 直播 SDK
├── LiveSDK-iOS.xcodeproj  		# Demo 演示
├── Podfile          			# 直播 SDK 依赖库
├── PolyvLiveSDK.podspec        	# SDK 的 CocoaPods 仓库说明
```

- SDK 文件结构（PLVLiveSDK.framework）

```
├── PLVLiveConfig 			# 直播 SDK 配置文件
├── PLVLive
       ├── PLVLiveAPI 			# 直播相关接口
       ├── PLVLiveChannel  		# 直播观看频道信息
       ├── PLVPushChannel 		# 推流频道信息
       └── PLVLiveReporter   		# 直播服务质量统计
└── PLVSocket
       ├── PLVSocketIOEventDef		# SocketIO 事件文档(字典，事件参数键)
       ├── PLVSocketIO   		# SocketIO 对象
       ├── PLVSocketObject 		# SocketObject 对象的基类
       ├── PLVSocketChatRoomObject	# 聊天室消息对象
       └── PLVSocketLinkMicObject 	# 连麦消息对象
```


### 集成与配置

#### 通过 CocoaPods 集成（建议） 

- 创建 podfile 并添加 `pod 'PolyvLiveSDK', '~>3.0.0'`  和 `use_frameworks!` 代码
- 终端执行 `pod install` 或 `pod update`

```ruby
platform :ios, "8.0"

use_frameworks!

target 'MyApp' do
    pod 'PolyvLiveSDK', '~>3.0.0'
end
```

*执行 `pod install` 成功后会下载 PolyvLiveSDK 及依赖库 Socket.IO-Client-Swift 和 Starscream*


备注：第三方依赖库 Starscream 部分版本未配置 Swift 版本说明，可能在编译时报错。需要手动设置 Starscream Target 的 Swift Language Version，操作如下

```
选择 Pods Project -> 选择 Starscream Target -> Build Settings -> Swift Language Version -> 手动选择 Swift 4.0
```

未安装或未使用过 Cocopods 同学可参考[官方文档说明](http://guides.cocoapods.org/using/using-cocoapods.html)。


#### 手动集成

- 下载 SDK，在本项目的 Frameworks 目录下
- 添加第三方依赖库，下载已打包的 SocketIO.framework 及 Starscream.framework
- 项目配置
  - 将 PLVLiveSDK.framework 添加至项目的 `Linked Framework and Libraries` 下（Xcode 9可能不会自动将添加进来的 framework 添加至改目录下）
  - 将  SocketIO.framework 及 Starscream.framework 库添加至项目的 `Embeded Binaries` 中
  - 设置 `Build Settings` -> `Always Embed Swift Standard Libraries` 为 `YES`
  - 编译、运行成功 PLVSocektIO 初始化接口即可


当前版本：[SocketIO v12.1.3](http://repo.polyv.net/ios/livesdk/socket.io/12.1.3/SocketIO.framework.zip) 和 [Starscream v2.1.1](http://repo.polyv.net/ios/livesdk/starscream/2.1.1/Starscream.framework.zip)


## Example

- 接口 API 使用

```objective-c
/// 1.1 获取直播频道信息
[PLVLiveAPI loadChannelInfoWithUserId:self.userId channelId:self.channelId completion:^(PLVLiveChannel *channel) {
    NSLog(@"++ %@",channel);
} failure:^(NSInteger errorCode, NSString *description) {
    NSLog(@"-- %ld, %@",errorCode,description);
}];

```

- 聊天室使用

```objective-c
@interface PLVTestSocketIOController () <PLVSocketIODelegate>	// 遵守协议

@property (nonatomic, strong) PLVSocketIO *socketIO;
@property (nonatomic, strong) NSString *chatToken;

@end
  
@implementation PLVTestSocketIOController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  /// 获取 chatToken
  __weak typeof(self)weakSelf = self;
  [PLVLiveAPI requestAuthorizationForLinkingSocketWithChannelId:103117 Appld:@"appId" appSecret:@"appSecret" completion:^(NSDictionary *responseDict) {
	weakSelf.chatToken = responseDict[@"chat_token"];
  } failure:^(PLVLiveErrorCode errorCode, NSString *description) {
      NSLog(@"-- %ld, %@",errorCode,description);
  }];
}

@end
```

SocketIO 控制

```
/// 连接聊天室
- (IBAction)connect:(id)sender {
  if(self.chatToken) {
    // ①初始化 SocketIO ②设置代理 ③开始连接
    self.socketIO = [[PLVSocketIO alloc] initSocketIOWithConnectToken:self.chatToken enableLog:NO];
    self.socketIO.delegate = self;
    [self.socketIO connect];
  }
}

/// 断开连接
- (IBAction)disconnect:(id)sender {
    [self.socketIO disconnect];
}
```

代理事件

```
#pragma mark - <PLVSocketIODelegate>

/// 连接成功
- (void)socketIO:(PLVSocketIO *)socketIO didConnectWithInfo:(NSString *)info {
  NSLog(@"socketIO:didConnectWithInfo: %@",info);
  // ④登录聊天室
  [socketIO loginChatRoomWithRoomId:self.roomId nickName:self.nickName avatar:@"" userType:self.userType];
}

/// 失去连接
- (void)socketIO:(PLVSocketIO *)socketIO didDisconnectWithInfo:(NSString *)info {
    NSLog(@"socketIO:didDisconnectWithInfo: %@",info);
}

/// 收到聊天室信息
- (void)socketIO:(PLVSocketIO *)socketIO didReceiveChatMessage:(PLVSocketChatRoomObject *)chatRoomObject {
    NSLog(@"socketIO:didReceiveChatMessage: type:%lu, event:%@",chatRoomObject.eventType,chatRoomObject.event);
    NSDictionary *dict = chatRoomObject.jsonDict;
    switch (chatRoomObject.eventType) {
        case PLVSocketChatRoomEventType_LOGIN: {
            NSDictionary *userInfo = dict[PLVSocketIOChatRoom_LOGIN_userKey];
            NSLog(@"登录 -- 昵称 = %@", userInfo[PLVSocketIOChatRoomUserNickKey]);
        } break;
        default: NSLog(@"聊天室其他事件");
          break;
    }
}
```


## DOCS

当前版本：v3.0.0

- [PLVLiveConfig](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVLiveConfig.html)


- [PLVLiveAPI](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVLiveAPI.html)

- [PLVLiveChannel](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVLiveChannel.html)

- [PLVPushChannel](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVPushChannel.html)

- [PLVLiveReporter](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVLiveReporter.html)


- [PLVSocketIOEventDef](https://github.com/polyv/polyv-ios-live-sdk/blob/master/Frameworks/PLVLiveSDK.framework/Headers/PLVSocketIOEventDef.h)
- [PLVSocketIO](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVSocketIO.html)
- [PLVSocketObject](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVSocketObject.html)
- [PLVSocketChatRoomObject](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVSocketChatRoomObject.html)
- [PLVSocketLinkMicObject](http://repo.polyv.net/ios/livesdk/docs/3.0.0/Classes/PLVSocketLinkMicObject.html)


历史版本

 [v3.0.0](http://repo.polyv.net/ios/livesdk/docs/3.0.0/index.html)
