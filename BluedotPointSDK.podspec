Pod::Spec.new do |s|
  s.name = "BluedotPointSDK"
  s.version = "1.13.3"
  s.summary = "The Bluedot Point SDK is powering the most innovative location-based apps for iOS and Android."
  s.description = "Bluedot Innovation's cutting edge location services solution - the Bluedot Point SDK - is powering the most innovative location-based apps for iOS and Android.
  Deliver creative content and collect valuable analytics using Bluedot Innovation's powerful, precise and easy-to-use location services technology."
  s.homepage = "https://www.bluedot.io"
  s.license = {
    :type => 'Copyright',
    :text => <<-LICENSE

    Point SDK

    Created by Bluedot Innovation in 2019.
    Copyright © 2019 Bluedot Innovation. All rights reserved.

    By downloading or using the Bluedot Point SDK for iOS, You agree to the Bluedot Terms and Conditions
    https://www.bluedot.io/html/downloads/pdfs/terms-and-conditions-bluedot-070814.pdf and Privacy Policy https://www.bluedot.io/html/downloads/pdfs/privacy-policy-bluedot-170815.pdf
    and Billing Policy https://www.bluedot.io/html/downloads/pdfs/privacy-policy-bluedot-170815.pdf
    and acknowledge that such terms govern Your use of and access to the iOS SDK.

    LICENSE
  }
  s.author = { "Bluedot Innovation" => "https://www.bluedot.io" }
  s.source = { :git => 'https://github.com/Bluedot-Innovation/PointSDK-iOS.git', :tag => s.version.to_s }
  s.platform = :ios
  s.ios.deployment_target = '10.0'
  s.swift_version = '4.2'
  s.requires_arc = true
  s.documentation_url = 'http://docs.bluedot.io'
  s.frameworks = 'CoreGraphics', 'CoreLocation', 'CoreMotion', 'Foundation', 'MapKit', 'SystemConfiguration', 'UIKit'
  s.weak_framework = 'CoreData', 'Foundation'
  s.vendored_frameworks = 'PointSDK/BDPointSDK.framework'
end
