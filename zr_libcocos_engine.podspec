#
# Be sure to run `pod lib lint zr_libcocos_engine.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'zr_libcocos_engine'
  s.version          = '0.1.0'
  s.summary          = 'A short description of zr_libcocos_engine.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/Tmoson6224/zr_libcocos_engine'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'tmoson' => 'tmoson6224@gmail.com' }
  s.source           = { :git => 'https://github.com/Tmoson6224/zr_libcocos_engine.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform = :ios
  s.ios.deployment_target = '12.0'
  
  # 用户工程 bitcode 设置为关闭
  s.user_target_xcconfig = {
      'ENABLE_BITCODE' => 'NO',
  }
  
  # pod 根目录
  s.pod_target_xcconfig = {
      'USER_HEADER_SEARCH_PATH' => '${POD_ROOT}',
      'ARCHS' => 'arm64 x86_64',
      'ARCHS_STANDARD' => 'arm64 x86_64',
      'VALID_ARCHS' => 'arm64 x86_64',
      'VALID_ARCHS[sdk=iphoneos*]' => 'arm64',
      'VALID_ARCHS[sdk=iphonesimulator*]' => 'x86_64',
      'GCC_GENERATE_DEBUGGING_SYMBOLS' => 'YES',
      'CURRENT_PROJECT_VERSION' => s.version
  }

  s.source_files = 'zr_libcocos_engine/Classes/**/*'

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'CoreVideo', 'AudioToolbox', 'OpenGLES', 'CoreMotion', 'CoreText', 'CFNetwork', 'CoreFoundation', 'MobileCoreServices', 'GameController', 'WebKit', 'CoreMedia', 'AVKit', 'CoreGraphics', 'SystemConfiguration', 'QuartzCore', 'JavaScriptCore', 'Security', 'OpenAL', 'AVFoundation', 'Foundation', 'UIKit', 'Metal', 'MetalKit', 'MetalPerformanceShaders'
  s.librarys = 'c++', 'stdc++', 'z', 'sqlite3', 'iconv'
end
