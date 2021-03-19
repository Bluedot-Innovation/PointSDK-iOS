Pod::Spec.new do |s|
  s.name = "BluedotPointSDK"
  s.version = "15.4.3"
  s.summary = "The Bluedot Point SDK is powering the most innovative location-based apps for iOS and Android."
  s.description = "Bluedot Innovation's cutting edge location services solution - the Bluedot Point SDK - is powering the most innovative location-based apps for iOS and Android.
  Deliver creative content and collect valuable analytics using Bluedot Innovation's powerful, precise and easy-to-use location services technology."
  s.homepage = "https://bluedot.io"
  s.license = {
    :type => 'Copyright',
    :text => <<-LICENSE

    Point SDK

    Created by Bluedot Innovation in 2019.
    Copyright © 2019 Bluedot Innovation. All rights reserved.

    By downloading or using the Bluedot Point SDK for iOS, You agree to the Bluedot Terms and Conditions
    https://bluedot.io/agreements/#terms and Privacy Policy https://bluedot.io/agreements/#privacy
    and Billing Policy https://bluedot.io/agreements/#billing
    and acknowledge that such terms govern Your use of and access to the iOS SDK.

    LICENSE
  }
  s.author = { "Bluedot Innovation" => "https://www.bluedot.io" }
  s.source = { :git => 'https://github.com/Bluedot-Innovation/PointSDK-iOS.git', :tag => s.version.to_s }
  s.platform = :ios
  s.ios.deployment_target = '10.0'
  s.swift_version = '5.0'
  s.requires_arc = true
  s.documentation_url = 'http://docs.bluedot.io'
  s.frameworks = 'CoreGraphics', 'CoreLocation', 'CoreMotion', 'Foundation', 'MapKit', 'SystemConfiguration', 'UIKit'
  s.weak_framework = 'CoreData', 'Foundation'
  s.vendored_frameworks = 'PointSDK/BDPointSDK.framework'
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
end
