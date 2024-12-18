#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint nvs_streaming_sdk_core.podspec` to validate before publishing.
#
Pod::Spec.new do |spec|
  spec.name         = "nvshortvideo"
  spec.version      = "0.0.1"
  spec.summary      = "the editor module"
  spec.description  = "the media asset editor"
  spec.homepage     = "https://github.com"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "meishe" => "meicamapp@meishesdk.com" }
  spec.source       = { :git => "http://github.com/meicam/nvshortvideo.git", :tag => "#{spec.version}" }

  spec.platform              = :ios
  spec.static_framework      = false
  spec.ios.deployment_target = '12.0'
  spec.ios.requires_arc      = true


  # Flutter.framework does not contain a i386 slice.

  spec.ios.pod_target_xcconfig   = {
    'SWIFT_VERSION'                    => '5.0',
    'ENABLE_BITCODE'                   => 'NO',
    'DEFINES_MODULE'                   => 'YES',
    'BUILD_LIBRARIES_FOR_DISTRIBUTION' => 'YES',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386'
  }
  
  spec.subspec 'SourceFiles' do |s|
    s.source_files = 'Classes/*','Classes/MaterialLibraryRelated/*'
    s.public_header_files = 'Classes/*.h'
    s.resources = 'Assets/*'
  end
  

  spec.ios.vendored_frameworks = 'Frameworks/*.xcframework'
  
  spec.ios.dependency 'SSZipArchive'
  spec.ios.dependency 'SDWebImageWebPCoder'
  spec.ios.dependency 'Flutter'

end
